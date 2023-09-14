/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PODArena_h
#define PODArena_h

#include <stdint.h>
#include <memory.h>
#include <memory>
#include <vector>

namespace WebCore {

// An arena which allocates only Plain Old Data (POD), or classes and
// structs bottoming out in Plain Old Data. NOTE: the constructors of
// the objects allocated in this arena are called, but _not_ their
// destructors.

static void* fastMalloc(size_t size) {
    return malloc(size);
}

static void fastFree(void* ptr) {
    free(ptr);
}

class PODArena{
public:
    // The arena is configured with an allocator, which is responsible
    // for allocating and freeing chunks of memory at a time.
    class Allocator {
    public:
        virtual void* allocate(size_t size) = 0;
        virtual void free(void* ptr) = 0;
    protected:
        virtual ~Allocator() { }
    };

    // The Arena's default allocator, which uses fastMalloc and
    // fastFree to allocate chunks of storage.
    class FastMallocAllocator : public Allocator {
    public:
        static std::shared_ptr<FastMallocAllocator> create()
        {
            return std::make_shared<FastMallocAllocator>();
        }

        void* allocate(size_t size) override { return fastMalloc(size); }
        void free(void* ptr) override { fastFree(ptr); }
        FastMallocAllocator() { }
    };

    // Creates a new PODArena configured with a FastMallocAllocator.
    static std::shared_ptr<PODArena> create()
    {
        return std::make_shared<PODArena>();
    }

    // Creates a new PODArena configured with the given Allocator.
    static std::shared_ptr<PODArena> create(std::shared_ptr<Allocator> allocator)
    {
        return std::make_shared<PODArena>(allocator);
    }

    // Allocates an object from the arena.
    template<class T> T* allocateObject()
    {
        return new (allocateBase<T>()) T();
    }

    // Allocates an object from the arena, calling a single-argument constructor.
    template<class T, class Argument1Type> T* allocateObject(const Argument1Type& argument1)
    {
        return new (allocateBase<T>()) T(argument1);
    }

    // The initial size of allocated chunks; increases as necessary to
    // satisfy large allocations. Mainly public for unit tests.
    enum {
        DefaultChunkSize = 16384
    };

    virtual ~PODArena() { }

    PODArena()
        : m_allocator(FastMallocAllocator::create())
        , m_current(nullptr)
        , m_currentChunkSize(DefaultChunkSize) { }

    explicit PODArena(std::shared_ptr<Allocator> allocator)
        : m_allocator(allocator)
        , m_current(nullptr)
        , m_currentChunkSize(DefaultChunkSize) { }

protected:
    // Returns the alignment requirement for classes and structs on the
    // current platform.
    template <class T> static size_t minAlignment()
    {
        return alignof(T);
    }

    template<class T> void* allocateBase()
    {
        void* ptr = nullptr;
        size_t roundedSize = roundUp(sizeof(T), minAlignment<T>());
        if (m_current)
            ptr = m_current->allocate(roundedSize);

        if (!ptr) {
            if (roundedSize > m_currentChunkSize)
                m_currentChunkSize = roundedSize;
            m_chunks.push_back(std::make_shared<Chunk>(m_allocator.get(), m_currentChunkSize));
            m_current = m_chunks.back().get();
            ptr = m_current->allocate(roundedSize);
        }
        return ptr;
    }

    // Rounds up the given allocation size to the specified alignment.
    size_t roundUp(size_t size, size_t alignment)
    {
        return (size + alignment - 1) & ~(alignment - 1);
    }

    // Manages a chunk of memory and individual allocations out of it.
    class Chunk {
    public:
        // Allocates a block of memory of the given size from the passed
        // Allocator.
        Chunk(Allocator* allocator, size_t size)
            : m_allocator(allocator)
            , m_size(size)
            , m_currentOffset(0)
        {
            m_base = static_cast<uint8_t*>(m_allocator->allocate(size));
        }

        // Frees the memory allocated from the Allocator in the
        // constructor.
        virtual ~Chunk()
        {
            m_allocator->free(m_base);
        }

        // Returns a pointer to "size" bytes of storage, or 0 if this
        // Chunk could not satisfy the allocation.
        void* allocate(size_t size)
        {
            // Check for overflow
            if (m_currentOffset + size < m_currentOffset)
                return nullptr;

            if (m_currentOffset + size > m_size)
                return nullptr;

            void* result = m_base + m_currentOffset;
            m_currentOffset += size;
            return result;
        }

    protected:
        Allocator* m_allocator;
        uint8_t* m_base;
        size_t m_size;
        size_t m_currentOffset;
    };

    std::shared_ptr<Allocator> m_allocator;
    Chunk* m_current;
    size_t m_currentChunkSize;
    std::vector<std::shared_ptr<Chunk> > m_chunks;
};

} // namespace WebCore

#endif // PODArena_h