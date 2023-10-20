
#include "vector_node_helper.h"
#include "base/math.h"
#include "desaina_node.h"
#include "edit_system/editor/vector_editor_data.h"
#include "include/core/SkPath.h"
#include "include/core/SkPoint.h"
#include "src/base/SkArenaAlloc.h"
#include "src/pathops/SkOpContour.h"
#include "src/pathops/SkPathOpsCubic.h"
#include "src/pathops/SkPathOpsLine.h"
#include "src/pathops/SkPathOpsPoint.h"
#include "src/pathops/SkPathOpsTypes.h"
#include "src/pathops/SkOpCoincidence.h"
#include "src/pathops/SkOpEdgeBuilder.h"
#include "src/pathops/SkPathOpsCommon.h"
#include "src/pathops/SkAddIntersections.h"
#include "src/pathops/SkPathWriter.h"
#include "util/skia.h"
#include <stack>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using Vertices = vector<VectorEditor::SegmentVertex*>;

namespace util {
  void networkToSkPath(VectorEditor::Network& network, SkPath& path) {
    for (auto* segment : network.getSegments()) {
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
  }

  VectorEditor::SegmentVertex* findTheLeftMostVertex(VectorEditor::Segment* segment) {
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

  VectorEditor::SegmentVertex* findTheLeftMostVertex(vector<VectorEditor::Segment*>& segments) {
    auto* leftMost = findTheLeftMostVertex(segments[0]);
    for (int i = 1; i < segments.size(); i++) {
      auto* vertex = findTheLeftMostVertex(segments[i]);
      if (vertex->x() < leftMost->x()) {
        leftMost = vertex;
      }
    }
    return leftMost;
  }

  static  auto getDirection = [](VectorEditor::SegmentVertex* vertex) {
    auto* tangentOffset = vertex->getTangentOffset();
    if (tangentOffset->x == 0 && tangentOffset->y == 0) {
      auto another = vertex->segment()->getAnotherVertex(vertex);
      return SkVector{another->x() - vertex->x(), another->y() - vertex->y()};
    }
    return util::toSkVector(*tangentOffset);
  };

  VectorEditor::SegmentVertex* getClockwiseMost(const SkVector& pre, VectorEditor::SegmentVertex* vertex) {
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

  VectorEditor::SegmentVertex* getCounterClockwiseMost(const SkVector& pre, VectorEditor::SegmentVertex* vertex) {
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

  vector<VectorEditor::Segment*> buildPlanarSegemts(SkPath& path, vector<VectorEditor::Segment*> segments, ArenaAlloc& allocator) {
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

    vector<VectorEditor::Segment*> result;
    std::unordered_map<SkOpPtT*, vector<VectorEditor::SegmentVertex*>> ptVertexMap;
    cur = contourList;
    int index = 0;
    while (cur) {
      auto segment = segments[index];
      // only one segment per contour, the order is the same as the order of the segments in the network
      auto* opSegment = cur->first();
      SkOpSpanBase* curSpan = opSegment->head(), *nextSpan = nullptr;
      VectorEditor::SegmentVertex* segmentVertex0 = nullptr, *segmentVertex1 = nullptr;
      while (!curSpan->final() && (nextSpan = curSpan->upCast()->next())) {
        auto* newSegment = allocator.make<VectorEditor::Segment>();
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

        segmentVertex0 = allocator.make<VectorEditor::SegmentVertex>(nullptr, 0);
        if (segmentVertex1 != nullptr) {
          segmentVertex1->setNext(segmentVertex0);
        }
        segmentVertex1 = allocator.make<VectorEditor::SegmentVertex>(nullptr, 1);

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
        auto* vertex = allocator.make<VectorEditor::Vertex>(point.x(), point.y());
        VectorEditor::SegmentVertex* preSegmentVertex = nullptr;
        VectorEditor::SegmentVertex* firstSegmentVertex = nullptr;
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

  vector<VectorEditor::SegmentVertex*> walk(VectorEditor::SegmentVertex* segmentVertex) {
    vector<VectorEditor::SegmentVertex*> res;

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

  static void removeSegments(vector<VectorEditor::SegmentVertex*>& cycleSegemtnVertices, vector<VectorEditor::Segment*>& segments) {
    std::unordered_set<VectorEditor::Segment*> set;
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

  struct CycleVertex {
    VectorEditor::SegmentVertex* vertex;
    vector<CycleVertex> cycle;
    bool operator==(const CycleVertex& other) const {
      return vertex == other.vertex;
    }
  };

  CycleVertex buildCycle(vector<VectorEditor::Segment*>& segments) {
    auto* leftMost = findTheLeftMostVertex(segments);
    auto cycleSegemtnVertices = walk(leftMost);
    // removeSegments(cycleSegemtnVertices, segments);
    std::stack<CycleVertex, std::vector<CycleVertex>> stack;
    std::unordered_map<VectorEditor::Vertex*, CycleVertex> map;
    VectorEditor::SegmentVertex* last = nullptr;
    for (auto* segmentVertex : cycleSegemtnVertices) {
      CycleVertex cycleVertex{segmentVertex, {}};
      auto* vertex = segmentVertex->getVertex();
      stack.push(cycleVertex);
      if (last && last->getVertex() == vertex) {
        continue;
      }
      last = segmentVertex;
      if (map.contains(vertex)) {
        auto& cycleVertex = map[vertex];
        vector<CycleVertex> cycle;
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

  vector<CycleVertex> buildMinimalCycleBasis(vector<VectorEditor::Segment*>& segments) {
    vector<CycleVertex> cycles;
    // 暂时不考虑多个环的情况
    // while (!segments.empty()) {
    //   cycles.push_back(buildCycle(segments));
    // }
    cycles.push_back(buildCycle(segments));
    return {};
  }

  vector<SkPath> cycles2SkPaht(vector<CycleVertex> &cycles) {
    vector<SkPath> paths;
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
      paths.push_back(path);
    }
    return paths;
  }

  vector<SkPath> computeFillGeometry(SkPath& path, VectorEditor::Network& network, ArenaAlloc& allocator) {
    auto segments = buildPlanarSegemts(path, network.getSegments(), allocator);
    auto mcb = buildMinimalCycleBasis(segments);
    return cycles2SkPaht(mcb);
  }
}
