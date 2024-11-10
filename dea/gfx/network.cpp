#include <stack>
#include <unordered_map>
#include "include/src/pathops/SkAddIntersections.h"
#include "include/src/pathops/SkOpCoincidence.h"
#include "include/src/pathops/SkOpEdgeBuilder.h"
#include "include/src/pathops/SkPathOpsCommon.h"
#include "network.h"

namespace dea::gfx {

Network Network::buildFromData(const base::Data& networkData, SkArenaAlloc& arena) {
    Network network;
    auto* data = networkData.data();
    auto* floatData = reinterpret_cast<const float*>(data);
    auto* uintData = reinterpret_cast<const uint32_t*>(data);

    auto vertexCount = uintData[0];
    auto segmentCount = uintData[1];
    auto pathCount = uintData[2];
    
    auto* vertecies = arena.makeArray<Vertex>(vertexCount);
    auto* segments = arena.makeArray<Segment>(segmentCount);

    network.vertecies_.reserve(vertexCount);
    network.segments_.reserve(segmentCount);
    
    // decode vertecies
    int vertexOffset = 3;
    for (int i = 0; i < vertexCount; i++) {
      auto& vertex = vertecies[i];
      auto vertexStart = vertexOffset + 3 * i;
      vertex.setStyleID(floatData[vertexStart]);
      vertex.setXY(floatData[vertexStart + 1], floatData[vertexStart + 2]);
      network.vertecies_.push_back(&vertex);
    }
    
    // decode segments
    int segmentOffset = 3 * vertexCount + 3;
    for (int i = 0; i < segmentCount; i++) {
      auto& segment = segments[i];
      auto segmentStart = segmentOffset + 7 * i;
      // unknown
      auto networkIndex = uintData[segmentStart];

      auto v0Index = uintData[segmentStart + 1];
      auto* v0 = arena.make<SegmentVertex>(network.vertecies_[v0Index], 0);
      v0->setTangentOffset(floatData[segmentStart + 2], floatData[segmentStart + 3]);

      auto v1Index = uintData[segmentStart + 4];
      auto* v1 = arena.make<SegmentVertex>(network.vertecies_[v1Index], 1);
      v1->setTangentOffset(floatData[segmentStart + 5], floatData[segmentStart + 6]);
      segment.setVertices(v0, v1);

      network.segments_.push_back(&segment);
    }

		return network;
}

static SegmentVertex* findTheLeftMostVertex(Segment* segment) {
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

static SegmentVertex* findTheLeftMostVertex(SegmentPtrArray& segments) {
  auto* leftMost = findTheLeftMostVertex(segments[0]);
  for (int i = 1; i < segments.size(); i++) {
    auto* vertex = findTheLeftMostVertex(segments[i]);
    if (vertex->x() < leftMost->x()) {
      leftMost = vertex;
    }
  }
  return leftMost;
}

static auto getDirection = [](SegmentVertex* vertex) {
  auto* tangentOffset = vertex->getTangentOffset();
  if (tangentOffset->x() == 0 && tangentOffset->y() == 0) {
    auto another = vertex->segment()->getAnotherVertex(vertex);
    return SkVector{another->x() - vertex->x(), another->y() - vertex->y()};
  }
  return SkVector{tangentOffset->x(), tangentOffset->y()};
};

static SegmentVertex* getClockwiseMost(const SkVector& pre, SegmentVertex* vertex) {
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

static SegmentVertex* getCounterClockwiseMost(const SkVector& pre, SegmentVertex* vertex) {
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

static std::vector<SegmentVertex*> walk(SegmentVertex* segmentVertex) {
  std::vector<SegmentVertex*> res;

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

static CycleVertex buildCycle(SegmentPtrArray& segments) {
  auto* leftMost = findTheLeftMostVertex(segments);
  auto cycleSegemtnVertices = walk(leftMost);
  // removeSegments(cycleSegemtnVertices, segments);
  std::stack<CycleVertex> stack;
  std::unordered_map<Vertex*, CycleVertex> map;
  SegmentVertex* last = nullptr;
  for (auto* segmentVertex : cycleSegemtnVertices) {
    CycleVertex cycleVertex{segmentVertex};
    auto* vertex = segmentVertex->getVertex();
    stack.push(cycleVertex);
    if (last && last->getVertex() == vertex) {
      continue;
    }
    last = segmentVertex;
    if (map.contains(vertex)) {
      auto& cycleVertex = map[vertex];
      std::vector<CycleVertex> cycle;
      while(stack.size() > 1 && stack.top() != cycleVertex) {
        auto& topVertex =  stack.top();
        cycle.push_back(topVertex);
        map.erase(topVertex.vertex->getVertex());
        stack.pop();
      }
      std::reverse(cycle.begin(), cycle.end());
     // stack.top().cycle = std::move(cycle);
      continue;
    }
    map.insert({vertex, cycleVertex});
  }
  assert(stack.size() == 1);
  return stack.top();
}

static std::vector<CycleVertex> buildMinimalCycleBasis(SegmentPtrArray& segments) {
  std::vector<CycleVertex> cycles;
  // 暂时不考虑多个环的情况
  // while (!segments.empty()) {
  //   cycles.push_back(buildCycle(segments));
  // }
  cycles.push_back(buildCycle(segments));
  return cycles;
}
void Network::buildCycles(SkArenaAlloc& arena) {
  auto segments = buildPlanarSegemts(arena);
  auto mcb = buildMinimalCycleBasis(segments);
  // buildCyclesPath(mcb);
  // return mcb;
}

void Network::buildSKPath() {
  for (auto* segment : segments_) {
    auto [v0, v1] = segment->getEndVertecies();
    skPath_.moveTo(v0->x(), v0->y());
    if (v0->hasTangent() || v1->hasTangent()) {
      auto t0 = v0->getTangentEnd();
      auto t1 = v1->getTangentEnd();
      skPath_.cubicTo(
        t0.x(), t0.y(),
        t1.x(), t1.y(),
        v1->x(), v1->y()
      );
    } else {
      skPath_.lineTo(v1->x(), v1->y());
    }
  }
}

SegmentPtrArray Network::buildPlanarSegemts(SkArenaAlloc& allocator) {
  SkOpContour contour;
  SkOpContourHead* contourList = static_cast<SkOpContourHead*>(&contour);
  SkOpGlobalState globalState(contourList, &allocator, true, nullptr);
  SkOpCoincidence coincidence(&globalState);
  SkOpEdgeBuilder builder(SkPathWriter(skPath_), contourList, &globalState);
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

  SegmentPtrArray result;
  std::unordered_map<SkOpPtT*, std::vector<SegmentVertex*>> ptVertexMap;
  cur = contourList;
  int index = 0;
  while (cur) {
    auto segment = segments_[index];
    // only one segment per contour, the order is the same as the order of the segments in the network
    auto* opSegment = cur->first();
    SkOpSpanBase* curSpan = opSegment->head(), *nextSpan = nullptr;
    SegmentVertex* segmentVertex0 = nullptr, *segmentVertex1 = nullptr;
    while (!curSpan->final() && (nextSpan = curSpan->upCast()->next())) {
      auto* newSegment = allocator.make<Segment>();
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

      segmentVertex0 = allocator.make<SegmentVertex>(nullptr, 0);
      if (segmentVertex1 != nullptr) {
        segmentVertex1->setNext(segmentVertex0);
      }
      segmentVertex1 = allocator.make<SegmentVertex>(nullptr, 1);

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
      auto* vertex = allocator.make<Vertex>(point.x(), point.y());
      SegmentVertex* preSegmentVertex = nullptr;
      SegmentVertex* firstSegmentVertex = nullptr;
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

} // namespace gfx