#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <type_traits>
#include <array>
#include <algorithm>
#include <numeric>
#include <cassert>

namespace memory {


    template 
        < typename ElemT
        , unsigned short ChunkSize = 65534
        , typename Allocator = std::allocator<ElemT>
        >
    class MemoryPool final
    {
			using BlockType = union {
				BlockType* next;
				ElemT elem;
			};
    public:
        //---------------------------------------------------------------------
        MemoryPool()
            : MemoryPool(Allocator())
        {}

        explicit MemoryPool(Allocator& alloc)
            : allocator(allocator)
            , arena(reinterpret_cast<ElemT*>(std::allocator_traits<Allocator>::allocate(alloc, arena_size)))
            , freed(arena)
            , taken(0)
        {
					auto* head = freed;
					for (auto i = 1; i < ChunkSize; ++i) {
						freed->next = freed + 1;
						freed = freed->next;
					}
					freed = head;
        }

        //---------------------------------------------------------------------
        // Allocates as many chunks as needed to fit the initial size
        // Throws std::bad_alloc if cannot allocate required memory.
        explicit MemoryPool(size_t initialCapacity, Allocator& allocator = Allocator())
            : MemoryPool(allocator)
        {
            if (initialCapacity > ChunkSize)
                next = std::make_unique<MemoryPool>(initialCapacity - ChunkSize);
        }

        MemoryPool(const MemoryPool&) = delete;
        MemoryPool& operator=(const MemoryPool&) = delete;
        MemoryPool(MemoryPool&& other) = delete;
        MemoryPool& operator=(MemoryPool&&) = delete;

        ~MemoryPool()
        {
            std::allocator_traits<Allocator>::deallocate(allocator, arena, arena_size);
        }

        template<typename... Args>
        [[nodiscard]] ElemT* alloc(Args&& ...args)
        {
            auto elem = allocate();
            if constexpr(std::is_nothrow_constructible_v<ElemT, Args...>)
            {
                return ::new(elem) ElemT(std::forward<Args>(args)...);
            }
            else try {
                return ::new(elem) ElemT(std::forward<Args>(args)...);
            } catch(...) {
                free(elem);
                throw;
            }
        }

        //---------------------------------------------------------------------
        // Calls an element's destructor and returns a block of memory into the pool.
        // Never throws an excepton.
        void free(ElemT* elem) noexcept
        {
            if (elem == nullptr) return;

            elem->~ElemT();
            deallocate(elem);
        }

        //---------------------------------------------------------------------
        // Returns a pool chunk size.
        static size_t chunk_size() noexcept
        {
            return ChunkSize;
        }

        //---------------------------------------------------------------------
        // Returns a pool chunk size.
        // Use for diagnostic purposes only, as this probe method may return 
        // only approximate result when accessed concurrently.
        size_t chunk_count() const noexcept
        {
            return 1 + (next ? next->chunk_count() : 0);
        }
        //---------------------------------------------------------------------
        // Returns a current pool capacity.
        // Use for diagnostic purposes only, as this probe method may return 
        // only approximate result when accessed concurrently.
        size_t capacity() const noexcept
        {
            return ChunkSize + (next ? next->capacity() : 0);
        }

        //---------------------------------------------------------------------
        // Returns a current count of allocated elements.
        // Use for diagnostic purposes only, as this probe method may return 
        // only approximate result when accessed concurrently.
        size_t allocated() const noexcept
        {
            return (ChunkSize - count) + (next ? next->allocated() : 0);
        }

    private:
        using index_type = unsigned short;

        constexpr static auto arena_size = ChunkSize * sizeof(ElemT);
        constexpr static auto max_index = std::numeric_limits<index_type>::max();
        constexpr static auto TAKEN = max_index;
        
        static_assert(ChunkSize > 1             , "Chunk size is too small");
        static_assert(ChunkSize < max_index     , "Chunk size is too big");
        static_assert(std::is_same_v<ElemT, Allocator::value_type>, "Incompatible allocator type");
        static_assert(std::is_nothrow_destructible_v<ElemT>, "Element destructor must be noexcept");

        Allocator allocator;
        ElemT* arena;                       // could use std::array or std::vector, but they require ElemT be default-constructible
                                            
        std::unique_ptr<MemoryPool> next;
        BlockType* freed,      // points to the first free block. Increment to stake a next block aquisition
                                taken;      // points to the first taken block. Increment to stake a next block return

        bool contains(ElemT* elem) const noexcept { return elem >= arena && elem < arena + ChunkSize; }
        bool getIndex(ElemT* elem) const noexcept { return std::distance(arena, elem); }

        //---------------------------------------------------------------------
        // Gets an uninitialized block of memory from the pool.
        // No ElemT constructors are called, so you must use a placement new() 
        // on the returned pointr and choose which constructor to call.
        // Throws std::bad_alloc if allocation is failed.
        [[nodiscard]] ElemT* allocate()
        {
            // do we have free space in this chunk? If not, pass the request to a next chunk
            if (!freed)
                return allocate_next();

            ElemT* elem = freed->elem;
						freed = freed->next;
            return elem;
        }

        //---------------------------------------------------------------------
        // Returns a block of memory into the pool.
        // Never throws an excepton.
        void deallocate(ElemT* elem) noexcept
        {
            if (!contains(elem))
                return next ? next->deallocate(elem) : void();    // eligible for TCO
						auto* next = freed;
						freed = elem;
						freed->next = next;
        }

        //---------------------------------------------------------------------
        // Expands the pool adding a new chunk and allocate an element in the new chunk.
        // The pool expansion operation is syncronized for thread safety.
        ElemT* allocate_next()
        {
            // The pool expansion operation is very short and rare, and we never shrink,
            // so we can reuse a single local static mutex intead of carrying a separate mutex in every instance
                                                
            if (!next) {
                std::lock_guard<std::mutex> _(expansion);
                if (!next) next = std::make_unique<MemoryPool>();
            }
            return next->allocate();    // eligible for TCO
        }
    };

}


#endif // MEMPOOL_H