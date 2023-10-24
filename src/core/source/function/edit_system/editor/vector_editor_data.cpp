#include "vector_editor_data.h"
#include "buffer.h"
#include <iostream>
#include <unordered_map>

VectorEditor::Network buildNetworkFromBlob(const Blob& blob, ArenaAlloc& arena) {
  auto* data = blob.buffer()->data();
  auto* floatData = reinterpret_cast<float*>(data);
  auto* uintData = reinterpret_cast<uint32_t*>(data);

  auto vertexCount = uintData[0];
  auto segmentCount = uintData[1];
  auto pathCount = uintData[2];
  
  auto* vertecies = arena.makeArray<VectorEditor::Vertex>(vertexCount);
  auto* segments = arena.makeArray<VectorEditor::Segment>(segmentCount);

  vector<VectorEditor::Vertex*> verteciesVector;
  vector<VectorEditor::Segment*> segmentsVector;
  verteciesVector.reserve(vertexCount);
  segmentsVector.reserve(segmentCount);
  
  int vertexOffset = 3;
  for (int i = 0; i < vertexCount; i++) {
    auto& vertex = vertecies[i];
    auto vertexStart = vertexOffset + 3 * i;
    vertex.setStyleID(floatData[vertexStart]);
    vertex.setXY(floatData[vertexStart + 1], floatData[vertexStart + 2]);
    verteciesVector.push_back(&vertex);
  }
  
  int segmentOffset = 3 * vertexCount + 3;

  for (int i = 0; i < segmentCount; i++) {
    auto& segment = segments[i];
    auto segmentStart = segmentOffset + 7 * i;
    auto networkIndex = uintData[segmentStart];
    auto v0Index = uintData[segmentStart + 1];
    auto& vertex0 = vertecies[v0Index];
    auto* v0 = arena.make<VectorEditor::SegmentVertex>(&vertex0, 0);
    v0->setTangentOffset(floatData[segmentStart + 2], floatData[segmentStart + 3]);

    auto v1Index = uintData[segmentStart + 4];
    auto& vertex1 = vertecies[v1Index];
    auto* v1 = arena.make<VectorEditor::SegmentVertex>(&vertex1, 1);
    v1->setTangentOffset(floatData[segmentStart + 5], floatData[segmentStart + 6]);
    segment.setVertices(v0, v1);

    segmentsVector.push_back(&segment);
  }

  return VectorEditor::Network(std::move(verteciesVector), std::move(segmentsVector));
}

Buffer network2Buffer(VectorEditor::Network& network) {
  Buffer buffer;
  const auto* vertecies = network.getVertecies();
  const auto* segments = network.getSegments();
  buffer.writeUint(vertecies->size());
  buffer.writeUint(segments->size());
  buffer.writeUint(0);
  std::unordered_map<VectorEditor::Vertex*, int> vertexIndexMap;
  int index = 0;
  for (auto& vertex : *vertecies) {
    vertexIndexMap.insert({vertex, index++});
    buffer.writeFloat(vertex->styleID());
    buffer.writeFloat(vertex->x);
    buffer.writeFloat(vertex->y);
  }
  for (auto& segment : *segments) {
    auto vertecies = segment->getVerticies();
    auto vertex0 = vertecies[0]->getVertex();
    auto vertex1 = vertecies[1]->getVertex();
    buffer.writeUint(0);
    buffer.writeUint(vertexIndexMap[vertex0]);
    buffer.writeFloat(vertecies[0]->getTangentOffset()->x);
    buffer.writeFloat(vertecies[1]->getTangentOffset()->y);
    buffer.writeUint(vertexIndexMap[vertex1]);
    buffer.writeFloat(vertecies[1]->getTangentOffset()->x);
    buffer.writeFloat(vertecies[1]->getTangentOffset()->y);
  }
  return buffer;
}

