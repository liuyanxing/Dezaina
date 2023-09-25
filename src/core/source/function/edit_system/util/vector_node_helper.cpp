
#include "vector_node_helper.h"
#include "base/math.h"
#include "desaina_node.h"
#include "edit_system/editor/vector_editor_data.h"
#include "src/base/SkArenaAlloc.h"
#include "src/pathops/SkOpContour.h"
#include "src/pathops/SkPathOpsCubic.h"
#include "src/pathops/SkPathOpsTypes.h"
#include "src/pathops/SkOpCoincidence.h"
#include "src/pathops/SkOpEdgeBuilder.h"
#include "src/pathops/SkPathOpsCommon.h"
#include "src/pathops/SkAddIntersections.h"
#include "src/pathops/SkPathWriter.h"
#include "util/skia.h"
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

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

  VectorEditor::SegmentVertex* getClockwiseMost(const Vector& pre, VectorEditor::SegmentVertex* vertex) {
    SkVector curV = {vertex->x() - pre.x, vertex->y() - pre.y};
    auto* next = vertex;
    auto* result = vertex;
    SkVector nextV = util::toSkVector(*next->getTangentOffset());
    bool isConvex = SkVector::CrossProduct(nextV, curV) > 0;
    next = next->next();
    while (next != vertex) {
      SkVector vertexV = util::toSkVector(*next->getTangentOffset());
      if (isConvex) {
        if (SkVector::CrossProduct(nextV, vertexV) > 0 && SkVector::CrossProduct(vertexV, curV) > 0) {
          result = next;
          nextV = vertexV;
          isConvex = SkVector::CrossProduct(nextV, curV) <= 0;
        }
      } else {
        if (SkVector::CrossProduct(curV, vertexV) < 0 || SkVector::CrossProduct(vertexV, nextV) < 0) {
          result = next;
          nextV = vertexV;
          isConvex = SkVector::CrossProduct(nextV, curV) <= 0;
        }
      }
      next = next->next();
    }
    return result;
  }

  VectorEditor::SegmentVertex* getCounterClockwiseMost(const Vector* pre, VectorEditor::SegmentVertex* vertex) {
    SkVector curV = {vertex->x() - pre->x, vertex->y() - pre->y};
    auto* next = vertex;
    auto* result = vertex;
    SkVector nextV = util::toSkVector(*next->getTangentOffset());
    bool isConvex = SkVector::CrossProduct(nextV, curV) > 0;
    next = next->next();
    while (next != vertex) {
      SkVector vertexV = util::toSkVector(*next->getTangentOffset());
      if (isConvex) {
        if (SkVector::CrossProduct(nextV, vertexV) < 0 || SkVector::CrossProduct(vertexV, curV) < 0) {
          result = next;
          nextV = vertexV;
          isConvex = SkVector::CrossProduct(nextV, curV) <= 0;
        }
      } else {
        if (SkVector::CrossProduct(curV, vertexV) > 0 && SkVector::CrossProduct(vertexV, nextV) > 0) {
          result = next;
          nextV = vertexV;
          isConvex = SkVector::CrossProduct(nextV, curV) <= 0;
        }
      }
      next = next->next();
    }
    return result;
  }

  SkOpContourHead* buildSkOpContourWithIntersection(SkPath& path, ArenaAlloc& allocator) {
    SkOpContour contour;
    SkOpContourHead* contourList = static_cast<SkOpContourHead*>(&contour);
    SkOpGlobalState globalState(contourList, &allocator, true, nullptr);
    SkOpCoincidence coincidence(&globalState);
    SkOpEdgeBuilder builder(SkPathWriter(path), contourList, &globalState);
    if (!builder.finish()) {
      return nullptr;
    }
    if (!SortContourList(&contourList, false, false)) {
      return nullptr;
    }
    SkOpContour* current = contourList;
    do {
      SkOpContour* next = current;
      while (AddIntersectTs(current, next, &coincidence)
              && (next = next->next()));
    } while ((current = current->next()));

    bool success = HandleCoincidence(contourList, &coincidence);
    if (!success) {
      return nullptr;
    }
    return contourList;
  }

  vector<VectorEditor::Segment*> buildPlanarSegemts(SkOpContourHead* contourList, vector<VectorEditor::Segment*> segments, ArenaAlloc& allocator) {
    vector<VectorEditor::Segment*> result;
    std::unordered_map<SkOpPtT*, vector<VectorEditor::SegmentVertex*>> ptVertexMap;
    auto current = contourList;
    int index = 0;
    while (current) {
      auto segment = segments[index];
      auto& verticies = segment->getVerticies();
      // only one segment per contour, the order is the same as the order of the segments in the network
      auto* opSegment = current->first();
      SkOpSpanBase* span = opSegment->head();
      auto* newSegment = allocator.make<VectorEditor::Segment>();
      do {
        auto ptt = span->ptT()->fT;
        auto pt = span->pt();
        if (ptt == 0 || ptt == 1) {
          auto* segmentVertex = verticies[ptt];
          segmentVertex->setT(ptt);
          newSegment->setVertex(segmentVertex);
          if (ptt == 1) {
            result.push_back(newSegment);
            newSegment = allocator.make<VectorEditor::Segment>();
          }
          ptVertexMap[span->ptT()].push_back(segmentVertex);
        } else {
          SkDCubic cubic;
          cubic.set(opSegment->pts());
          auto cubicPair = cubic.chopAt(ptt);
          auto tangentEndPoint = cubicPair.first().fPts[2];
          auto* segmentVertex1 = allocator.make<VectorEditor::SegmentVertex>(nullptr, 1);
          segmentVertex1->setTangentOffset(tangentEndPoint.fX, tangentEndPoint.fY);
          newSegment->setVertex(segmentVertex1);
          ptVertexMap[span->ptT()].push_back(segmentVertex1);
          newSegment = allocator.make<VectorEditor::Segment>();
          result.push_back(newSegment);
          tangentEndPoint = cubicPair.second().fPts[1];
          auto segmentVertex2 = allocator.make<VectorEditor::SegmentVertex>(nullptr, 0);
          segmentVertex2->setTangentOffset(tangentEndPoint.fX, tangentEndPoint.fY);
          newSegment->setVertex(segmentVertex1);
          ptVertexMap[span->ptT()].push_back(segmentVertex2);
          segmentVertex1->setNext(segmentVertex2);
        }
      } while(!span->final() && (span = span->upCast()->next()));

      current = static_cast<SkOpContourHead*>(current->next());
      index++;
    }

    current = contourList;
    while (current) {
      // only one segment per contour, the order is the same as the order of the segments in the network
      auto* opSegment = current->first();
      SkOpSpanBase* span = opSegment->head();
      do {
        auto* pt = span->ptT();
        auto* startPt = pt;
        auto* nextPt = pt->next();
        auto* vertex = allocator.make<VectorEditor::Vertex>(0, 0);
        while (nextPt && (nextPt != startPt)) {
          VectorEditor::SegmentVertex* segmentVertex = ptVertexMap.find(pt)->second.back();
          if (segmentVertex->hasLink()) {
            break;
          }
          auto* nextSegmentVertex = ptVertexMap.find(nextPt)->second.front();
          segmentVertex->setNext(nextSegmentVertex);
          pt = nextPt;
          nextPt = nextPt->next();
        }
        auto* startSegmentVertex = ptVertexMap.find(startPt)->second.front();
        auto* endSegmentVertex = ptVertexMap.find(pt)->second.back();
        endSegmentVertex->setNext(startSegmentVertex);
      } while(!span->final() && (span = span->upCast()->next()));

      current = static_cast<SkOpContourHead*>(current->next());
    }
    return result;
  }

  struct Cycle {
    vector<VectorEditor::SegmentVertex*> vertecies;
    vector<Cycle> children;
  };

  vector<VectorEditor::SegmentVertex*> walk(VectorEditor::SegmentVertex* segmentVertex) {
    vector<VectorEditor::SegmentVertex*> res;
    res.push_back(segmentVertex);

    auto* vertex = segmentVertex->getVertex();
    auto* clockwiseMost = getClockwiseMost({vertex->x, vertex->y + 1}, segmentVertex);
    if (clockwiseMost == segmentVertex) {
      return res;
    }
    res.push_back(clockwiseMost);

    auto next = getCounterClockwiseMost(clockwiseMost->getTangentOffset(), clockwiseMost->segment()->getAnotherVertex(clockwiseMost));
    while (next && vertex != next->getVertex()) {
      res.push_back(next);
      next = getCounterClockwiseMost(next->getTangentOffset(), next->segment()->getAnotherVertex(next));
    }
    return res;
  }

  VectorEditor::SegmentVertex* buildCycle(Vertices& vertecies, int index, Vertices &res, std::unordered_set<VectorEditor::SegmentVertex*>& visited) {
    auto* vertex = vertecies[index];
    if (visited.contains(vertex)) {
      res.push_back(vertex);
      return vertex;
    }
    auto* cycleVertext = buildCycle(vertecies, index + 1, res, visited);
    res.push_back(vertex);
    if (cycleVertext == vertex) {
    }
    return nullptr;
  }

  vector<Cycle> buildCycle(vector<VectorEditor::Segment*>& segments) {
    auto* leftMost = findTheLeftMostVertex(segments);
    auto cycleSegemtnVertices = walk(leftMost);
    Cycle cycle;
    return {};
  }

  vector<vector<VectorEditor::SegmentVertex*>> buildMinimalCycleBasis(vector<VectorEditor::Segment*>& segments) {
    vector<vector<VectorEditor::SegmentVertex*>> result;
    return result;
  }

  vector<SkPath> computeFillGeometryPath(SkPath& path, VectorEditor::Network& network, ArenaAlloc& allocator) {
    auto* contourList = buildSkOpContourWithIntersection(path, allocator);
    auto segments = buildPlanarSegemts(contourList, network.getSegments(), allocator);
    auto mcb = buildMinimalCycleBasis(segments);

    return {};
  }
}