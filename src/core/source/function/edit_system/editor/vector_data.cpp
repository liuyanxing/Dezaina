#include "vector_data.h"

static EditVector::Network* buildNetworkFromBlob(const Blob& buffer, ArenaAlloc& arena) {
  auto* data = buffer.data();
  auto* floatData = reinterpret_cast<float*>(data);
  auto* intData = reinterpret_cast<uint32_t*>(data);

  auto vertexCount = intData[0];
  auto segmentCount = intData[1];
  auto pathCount = intData[2];
  
  auto* vertecies = arena.makeArray<EditVector::Vertex>(vertexCount);
  auto* segments = arena.makeArray<EditVector::Segment>(segmentCount);
  
  int vertexOffset = 3;
  for (int i = 0; i < vertexCount; i++) {
    auto& vertex = vertecies[i];
    auto vertexStart = vertexOffset + 3 * i;
    vertex.setStyleID(floatData[vertexStart]);
    vertex.setXY(floatData[vertexStart + 1], floatData[vertexStart + 2]);
  }
  
  int segmentOffset = 3 * vertexCount + 3;

  for (int i = 0; i < segmentCount; i++) {
    auto& segment = segments[i];
    auto segmentStart = segmentOffset + 7 * i;
    auto networkIndex = intData[segmentStart];
    auto v0Index = intData[segmentStart + 1];
    auto& v0 = vertecies[v0Index];
    auto* v1 = arena.make<EditVector::Vertex>();
    *v1 = v0 + EditVector::Vertex::Make(floatData[segmentOffset + 2], floatData[segmentOffset + 3]);

    auto v3Index = intData[segmentStart + 4];
    auto& v3 = vertecies[v3Index];
    auto* v2 = arena.make<EditVector::Vertex>();
    *v2 = v3 + EditVector::Vertex::Make(floatData[segmentOffset + 5], floatData[segmentOffset + 6]);
    segment.setVertices(&v0, v1, v2, &v3);
  }
}

