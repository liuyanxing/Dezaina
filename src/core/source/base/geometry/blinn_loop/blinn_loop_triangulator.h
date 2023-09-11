#pragma once

#include "base/geometry/blinn_loop/apple_source/LoopBlinnPathCache.h"
#include "base/geometry/blinn_loop/apple_source/LoopBlinnPathProcessor.h"
#include "buffer.h"
#include "include/core/SkPath.h"
#include "include/core/SkPoint.h"
#include "include/core/SkPoint3.h"
#include "include/private/SkColorData.h"
#include "src/gpu/ganesh/GrColor.h"
#include "src/gpu/ganesh/GrEagerVertexAllocator.h"
#include "src/gpu/ganesh/geometry/GrTriangulator.h"
#include "cpu_vertex_allocator.h"

namespace base {
  inline Buffer skPathToBLBuffer(const SkPath& path) {
    WebCore::LoopBlinnPathProcessor processor;
    WebCore::LoopBlinnPathCache cache;
    
    WebCore::Tessellator tessellator = [](const SkPath& path, WebCore::LoopBlinnPathCache& cache) {
      bool isLinear = false;
      auto clipBounds = SkRect::MakeEmpty();
      CpuVertexAllocator allocator;
      GrTriangulator::PathToTriangles(path, 1, clipBounds, &allocator, &isLinear);
      auto actualCount= allocator.actualCount();
      auto* data = allocator.data();
      for (int i = 0; i < actualCount; ++i) {
          cache.addInteriorVertex(data[2 * i], data[2 * i + 1]);
      }
    };
   
    CpuVertexAllocator allocator;
    processor.process(path, cache, tessellator);
    const float* vertices = cache.vertices();
    const float* interiorVertices = cache.interiorVertices();
    const float* texCoords = cache.texcoords();
    if (!vertices || !texCoords) {
        return Buffer::MakeEmpty();
    }
    const int totalVertices = cache.numberOfVertices() + cache.numberOfInteriorVertices();
    skgpu::VertexWriter writer = allocator.lockWriter(sizeof(SkPoint) + sizeof(SkPoint3), totalVertices);
    for (unsigned i = 0; i < cache.numberOfVertices(); ++i) {
        SkPoint point = {vertices[2 * i], vertices[2 * i + 1]};
        writer << point;
        SkPoint3 klm = {texCoords[3 * i], texCoords[3 * i + 1], texCoords[3 * i + 2]};
        writer << klm;
    }
    for (unsigned i = 0; i < cache.numberOfInteriorVertices(); ++i) {
        SkPoint point = {interiorVertices[2 * i], interiorVertices[2 * i + 1]};
        writer << point;
        SkPoint3 klm = {0, 0, 0};
        writer << klm;
    }
    
    allocator.unlock(totalVertices);
    const uint8_t* release = reinterpret_cast<const uint8_t*>(allocator.release());
    return Buffer(release, allocator.actualCount());
  }
}