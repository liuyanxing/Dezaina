#include "include/core/SkScalar.h"
#include "src/gpu/ganesh/GrEagerVertexAllocator.h"

class CpuVertexAllocator : public GrEagerVertexAllocator {
public:
    CpuVertexAllocator() = default;
    ~CpuVertexAllocator() override = default;

    void* lock(size_t stride, int eagerCount) override {
        fStride = stride;
        fEagerCount = eagerCount;
        fData = std::make_unique<SkScalar[]>(stride * eagerCount);
        return fData.get();
    }

    void unlock(int actualCount) override {
        fActualCount = actualCount;
    }

    int actualCount() const { return fActualCount; }
    int eagerCount() const { return fEagerCount; }
    size_t stride() const { return fStride; }

    SkScalar* release() { return fData.release(); }
    SkScalar* data() { return fData.get(); }
private:
    size_t fStride = 0;
    int fEagerCount = 0;
    int fActualCount = 0;
    std::unique_ptr<SkScalar[]> fData;
};