#include "node_vector.h"
#include "base_type.h"
#include "include/core/SkPath.h"
#include "src/pathops/SkAddIntersections.h"
#include "src/pathops/SkOpCoincidence.h"
#include "src/pathops/SkOpContour.h"
#include "src/pathops/SkPathOpsCommon.h"
#include "src/pathops/SkPathWriter.h"
#include "src/pathops/SkOpEdgeBuilder.h"
#include "util/skia.h"
#include <memory>
#include <stack>

Buffer network2Buffer(util::Network& network) {
  Buffer buffer;
  const auto* vertecies = network.getVertecies();
  const auto* segments = network.getSegments();
  buffer.writeUint(vertecies->size());
  buffer.writeUint(segments->size());
  buffer.writeUint(0);
  std::unordered_map<util::Vertex*, int> vertexIndexMap;
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

SkPath networkToSkPath(util::Network& network) {
  SkPath path;
  for (auto* segment : *network.getSegments()) {
    auto [v0, v1] = segment->getEndVertecies();
    path.moveTo(v0->x(), v0->y());
    if (v0->hasTangent() || v1->hasTangent()) {
      auto t0 = v0->getTangentEnd();
      auto t1 = v1->getTangentEnd();
      path.cubicTo(
        t0.x, t0.y,
        t1.x, t1.y,
        v1->x(), v1->y()
      );
    } else {
      path.lineTo(v1->x(), v1->y());
    }
  }
  return path;
}

util::SegmentVertex* findTheLeftMostVertex(util::Segment* segment) {
  auto vertecies = segment->getVerticies();
  auto* leftMost = vertecies[0];
  for (int i = 1; i < vertecies.size(); i++) {
    auto* vertex = vertecies[i];
    if (vertex->x() < leftMost->x()) {
      leftMost = vertex;
    }
  }
  return leftMost;
}

util::SegmentVertex* findTheLeftMostVertex(vector<util::Segment*>& segments) {
  auto* leftMost = findTheLeftMostVertex(segments[0]);
  for (int i = 1; i < segments.size(); i++) {
    auto* vertex = findTheLeftMostVertex(segments[i]);
    if (vertex->x() < leftMost->x()) {
      leftMost = vertex;
    }
  }
  return leftMost;
}

static  auto getDirection = [](util::SegmentVertex* vertex) {
  auto* tangentOffset = vertex->getTangentOffset();
  if (tangentOffset->x == 0 && tangentOffset->y == 0) {
    auto another = vertex->segment()->getAnotherVertex(vertex);
    return SkVector{another->x() - vertex->x(), another->y() - vertex->y()};
  }
  return util::toSkVector(*tangentOffset);
};

util::SegmentVertex* getClockwiseMost(const SkVector& pre, util::SegmentVertex* vertex) {
  SkVector curV = pre;
  auto* next = vertex;
  auto* result = vertex;
  SkVector nextV = getDirection(next);
  bool isConvex = SkVector::CrossProduct(curV, nextV) > 0;
  next = next->next();
  while (next != vertex) {
    SkVector vertexV = getDirection(next);
    if (isConvex) {
      if (SkVector::CrossProduct(curV, vertexV) > 0 && SkVector::CrossProduct(vertexV, nextV) > 0) {
        result = next;
        nextV = vertexV;
        isConvex = SkVector::CrossProduct(curV, nextV) > 0;
      }
    } else {
      if (SkVector::CrossProduct(curV, vertexV) > 0 || SkVector::CrossProduct(nextV, vertexV) > 0) {
        result = next;
        nextV = vertexV;
        isConvex = SkVector::CrossProduct(curV, nextV) > 0;
      }
    }
    next = next->next();
  }
  return result;
}

util::SegmentVertex* getCounterClockwiseMost(const SkVector& pre, util::SegmentVertex* vertex) {
  SkVector curV = pre;
  auto* next = vertex->next();
  auto* result = vertex;
  SkVector nextV = getDirection(next);
  bool isConvex = SkVector::CrossProduct(curV, nextV) > 0;
  while (next != vertex) {
    SkVector vertexV = getDirection(next);
    if (isConvex) {
      if (SkVector::CrossProduct(vertexV, nextV) > 0 && SkVector::CrossProduct(vertexV, curV) > 0) {
        result = next;
        nextV = vertexV;
        isConvex = SkVector::CrossProduct(curV, nextV) > 0;
      }
    } else {
      if (SkVector::CrossProduct(vertexV, nextV) > 0 || SkVector::CrossProduct(vertexV, curV) > 0) {
        result = next;
        nextV = vertexV;
        isConvex = SkVector::CrossProduct(curV, nextV) > 0;
      }
    }
    next = next->next();
  }
  return result;
}

vector<util::Segment*> buildPlanarSegemts(SkPath& path, vector<util::Segment*>& segments, ArenaAlloc& allocator) {
  SkOpContour contour;
  SkOpContourHead* contourList = static_cast<SkOpContourHead*>(&contour);
  SkOpGlobalState globalState(contourList, &allocator, true, nullptr);
  SkOpCoincidence coincidence(&globalState);
  SkOpEdgeBuilder builder(SkPathWriter(path), contourList, &globalState);
  if (!builder.finish()) {
    return {};
  }
  if (!SortContourList(&contourList, false, false)) {
    return {};
  }
  SkOpContour* cur = contourList;
  do {
    SkOpContour* next = cur;
    while (AddIntersectTs(cur, next, &coincidence)
            && (next = next->next()));
  } while ((cur = cur->next()));

  bool success = HandleCoincidence(contourList, &coincidence);
  if (!success) {
    return {};
  }

  vector<util::Segment*> result;
  std::unordered_map<SkOpPtT*, vector<util::SegmentVertex*>> ptVertexMap;
  cur = contourList;
  int index = 0;
  while (cur) {
    auto segment = segments[index];
    // only one segment per contour, the order is the same as the order of the segments in the network
    auto* opSegment = cur->first();
    SkOpSpanBase* curSpan = opSegment->head(), *nextSpan = nullptr;
    util::SegmentVertex* segmentVertex0 = nullptr, *segmentVertex1 = nullptr;
    while (!curSpan->final() && (nextSpan = curSpan->upCast()->next())) {
      auto* newSegment = allocator.make<util::Segment>();
      auto curPtt = curSpan->ptT()->fT;
      auto curPt = curSpan->pt();
      auto nextPtt = nextSpan->ptT()->fT;
      auto nextPt = nextSpan->pt();

      SkDVector tangentOffset0{0, 0};
      SkDVector tangentOffset1{0, 0};

      if (opSegment->verb() == SkPath::kCubic_Verb) {
        SkDCubic cubic;
        cubic.set(opSegment->pts());
        auto subCubic = cubic.subDivide(curPtt, nextPtt);
        tangentOffset0 = subCubic.fPts[1] - subCubic.fPts[0];
        tangentOffset1 = subCubic.fPts[2] - subCubic.fPts[3];
      }

      segmentVertex0 = allocator.make<util::SegmentVertex>(nullptr, 0);
      if (segmentVertex1 != nullptr) {
        segmentVertex1->setNext(segmentVertex0);
      }
      segmentVertex1 = allocator.make<util::SegmentVertex>(nullptr, 1);

      ptVertexMap[curSpan->ptT()].push_back(segmentVertex0);
      ptVertexMap[nextSpan->ptT()].push_back(segmentVertex1);

      segmentVertex0->setTangentOffset(tangentOffset0.fX, tangentOffset0.fY);
      segmentVertex1->setTangentOffset(tangentOffset1.fX, tangentOffset1.fY);
      newSegment->setVertices(segmentVertex0, segmentVertex1);
      result.push_back(newSegment);
      curSpan = nextSpan;
    }
    cur = static_cast<SkOpContourHead*>(cur->next());
    index++;
  }

  cur = contourList;
  while (cur) {
    // only one segment per contour, the order is the same as the order of the segments in the network
    auto* opSegment = cur->first();
    SkOpSpanBase* span = opSegment->head();
    do {
      auto* pt = span->ptT();
      if (ptVertexMap.find(pt)->second.back()->hasLink()) {
        continue;
      }
      const auto& point = span->pt();
      auto* startPt = pt;
      auto* nextPt = pt->next();
      auto* vertex = allocator.make<util::Vertex>(point.x(), point.y());
      util::SegmentVertex* preSegmentVertex = nullptr;
      util::SegmentVertex* firstSegmentVertex = nullptr;
      do {
        auto& segmentVertices = ptVertexMap.find(pt)->second;
        auto first = segmentVertices.front();
        auto second = segmentVertices.back();
        if (!firstSegmentVertex) {
          firstSegmentVertex = first;
        }
        for (auto& segmentVertex : segmentVertices) {
          segmentVertex->setVertex(vertex);
        }
        if (preSegmentVertex) {
          preSegmentVertex->setNext(first);
        }
        preSegmentVertex = second;
        pt = pt->next();
      } while(pt && pt != startPt);
      preSegmentVertex->setNext(firstSegmentVertex);
    } while(!span->final() && (span = span->upCast()->next()));

    cur = static_cast<SkOpContourHead*>(cur->next());
  }
  return result;
}

vector<util::SegmentVertex*> walk(util::SegmentVertex* segmentVertex) {
  vector<util::SegmentVertex*> res;

  auto* vertex = segmentVertex->getVertex();
  auto* clockwiseMost = getClockwiseMost({0, 1}, segmentVertex);
  auto* cur = clockwiseMost;
  do {
    res.push_back(cur);
    auto* adjacent = cur->segment()->getAnotherVertex(cur);
    res.push_back(adjacent);
    cur = getCounterClockwiseMost(getDirection(cur), adjacent);
  } while (cur && cur->getVertex() != vertex);

  return res;
}

static void removeSegments(vector<util::SegmentVertex*>& cycleSegemtnVertices, vector<util::Segment*>& segments) {
  std::unordered_set<util::Segment*> set;
  for (auto* segmentVertex : cycleSegemtnVertices) {
    set.insert(segmentVertex->segment());
  }
  for (int i = 0; i < segments.size(); i++) {
    if (set.contains(segments[i])) {
      segments.erase(segments.begin() + i);
      i--;
    }
  }
}


util::CycleVertex buildCycle(vector<util::Segment*>& segments) {
  auto* leftMost = findTheLeftMostVertex(segments);
  auto cycleSegemtnVertices = walk(leftMost);
  // removeSegments(cycleSegemtnVertices, segments);
  std::stack<util::CycleVertex> stack;
  std::unordered_map<util::Vertex*, util::CycleVertex> map;
  util::SegmentVertex* last = nullptr;
  for (auto* segmentVertex : cycleSegemtnVertices) {
    util::CycleVertex cycleVertex{segmentVertex, {}};
    auto* vertex = segmentVertex->getVertex();
    stack.push(cycleVertex);
    if (last && last->getVertex() == vertex) {
      continue;
    }
    last = segmentVertex;
    if (map.contains(vertex)) {
      auto& cycleVertex = map[vertex];
      vector<util::CycleVertex> cycle;
      while(stack.size() > 1 && stack.top() != cycleVertex) {
        auto& topVertex =  stack.top();
        cycle.push_back(topVertex);
        map.erase(topVertex.vertex->getVertex());
        stack.pop();
      }
      std::reverse(cycle.begin(), cycle.end());
      stack.top().cycle = std::move(cycle);
      continue;
    }
    map.insert({vertex, cycleVertex});
  }
  assert(stack.size() == 1);
  return stack.top();
}

vector<util::CycleVertex> buildMinimalCycleBasis(vector<util::Segment*>& segments) {
  vector<util::CycleVertex> cycles;
  // 暂时不考虑多个环的情况
  // while (!segments.empty()) {
  //   cycles.push_back(buildCycle(segments));
  // }
  cycles.push_back(buildCycle(segments));
  return {};
}

void buildCyclesPath(vector<util::CycleVertex> &cycles) {
  for (auto& cycleVertex : cycles) {
    SkPath path;
    auto* cur = cycleVertex.vertex;
    auto& cycle = cycleVertex.cycle;
    path.moveTo(cur->x(), cur->y());
    int i = 0;
    while (i < cycle.size()) {
      auto& next = cycle[i]; 
      auto* nextVertex = next.vertex;
      if (cur->hasTangent() || nextVertex->hasTangent()) {
        auto t0 = cur->getTangentEnd();
        auto t1 = nextVertex->getTangentEnd();
        path.cubicTo(
          t0.x, t0.y,
          t1.x, t1.y,
          nextVertex->x(), nextVertex->y()
        );
      } else {
        path.lineTo(nextVertex->x(), nextVertex->y());
      }
      i++;
      if (i < cycle.size()) {
        cur = cycle[i].vertex;
      }
      i++;
    }
    cycleVertex.path = std::move(path);
  }
}

vector<util::CycleVertex> buildCycles(SkPath& path, util::Network& network, ArenaAlloc& allocator) {
  auto segments = buildPlanarSegemts(path, *network.getSegments(), allocator);
  auto mcb = buildMinimalCycleBasis(segments);
  buildCyclesPath(mcb);
  return mcb;
}

vector<util::CycleVertex> buildCyclesFromNetwork(util::Network& network, ArenaAlloc& allocator) {
  SkPath path = networkToSkPath(network);
  return buildCycles(path, network, allocator);
}

namespace util {
  Network::Network(const Blob& blob, ArenaAlloc& arena) {
    auto* data = blob.buffer()->data();
    auto* floatData = reinterpret_cast<float*>(data);
    auto* uintData = reinterpret_cast<uint32_t*>(data);

    auto vertexCount = uintData[0];
    auto segmentCount = uintData[1];
    auto pathCount = uintData[2];
    
    auto* vertecies = arena.makeArray<util::Vertex>(vertexCount);
    auto* segments = arena.makeArray<util::Segment>(segmentCount);

    vertecies_.reserve(vertexCount);
    segments_.reserve(segmentCount);
    
    int vertexOffset = 3;
    for (int i = 0; i < vertexCount; i++) {
      auto& vertex = vertecies[i];
      auto vertexStart = vertexOffset + 3 * i;
      vertex.setStyleID(floatData[vertexStart]);
      vertex.setXY(floatData[vertexStart + 1], floatData[vertexStart + 2]);
      vertecies_.push_back(&vertex);
    }
    
    int segmentOffset = 3 * vertexCount + 3;

    for (int i = 0; i < segmentCount; i++) {
      auto& segment = segments[i];
      auto segmentStart = segmentOffset + 7 * i;
      auto networkIndex = uintData[segmentStart];
      auto v0Index = uintData[segmentStart + 1];
      auto& vertex0 = vertecies[v0Index];
      auto* v0 = arena.make<util::SegmentVertex>(&vertex0, 0);
      v0->setTangentOffset(floatData[segmentStart + 2], floatData[segmentStart + 3]);

      auto v1Index = uintData[segmentStart + 4];
      auto& vertex1 = vertecies[v1Index];
      auto* v1 = arena.make<util::SegmentVertex>(&vertex1, 1);
      v1->setTangentOffset(floatData[segmentStart + 5], floatData[segmentStart + 6]);
      segment.setVertices(v0, v1);

      segments_.push_back(&segment);
    }
  }

  VectorDecodedData decodeVectorData(const Blob* blob) {
    constexpr int kArenaAllocSize = 16 * 1024;
    auto arena = make_shared<SkArenaAlloc>(kArenaAllocSize);
    auto* network = arena->make<Network>(*blob, *arena);
    auto* cycles = arena->make<vector<CycleVertex>>();
    *cycles = buildCyclesFromNetwork(*network, *arena);
    return { arena, network, cycles };
  }
}