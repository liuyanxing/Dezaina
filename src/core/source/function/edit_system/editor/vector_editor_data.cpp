#include "vector_editor_data.h"
#include <iostream>

VectorEditor::Network buildNetworkFromBlob(const Blob& blob, ArenaAlloc& arena) {
  auto* data = blob.buffer()->data();
  auto* floatData = reinterpret_cast<float*>(data);
  auto* intData = reinterpret_cast<uint32_t*>(data);

  auto vertexCount = intData[0];
  auto segmentCount = intData[1];
  auto pathCount = intData[2];
  
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
    auto networkIndex = intData[segmentStart];
    auto v0Index = intData[segmentStart + 1];
    auto& vertex0 = vertecies[v0Index];
    auto* v0 = arena.make<VectorEditor::SegmentVertex>(&vertex0, 0);
    v0->setTangentOffset(floatData[segmentStart + 2], floatData[segmentStart + 3]);

    auto v1Index = intData[segmentStart + 4];
    auto& vertex1 = vertecies[v1Index];
    auto* v1 = arena.make<VectorEditor::SegmentVertex>(&vertex1, 1);
    v1->setTangentOffset(floatData[segmentStart + 5], floatData[segmentStart + 6]);
    segment.setVertices(v0, v1);

    segmentsVector.push_back(&segment);
  }

  return VectorEditor::Network(std::move(verteciesVector), std::move(segmentsVector));
}

