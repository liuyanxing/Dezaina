
#include "vector_node_helper.h"
#include "base/math.h"
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

  VectorEditor::SegmentVertex* findVertexOfTheLeftMostEdge(VectorEditor::SegmentVertex* vertex) {
    auto* leftMost = vertex;
    auto* next = vertex->getNext();
    while (next != vertex) {
      auto angle = base::vectorsAngle(util::toSkPoint(*(leftMost->getTangentOffset())), util::toSkPoint(*(next->getTangentOffset()))); 
      if (angle > 0) {
        leftMost = next;
      }
      next = next->getNext();
    }
    return leftMost;
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

  vector<VectorEditor::Segment*> buildSegemtsWithoutIntersection(SkOpContourHead* contourList, vector<VectorEditor::Segment*> segments, ArenaAlloc& allocator) {
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
          auto* vertex = allocator.make<VectorEditor::Vertex>(pt.x(), pt.y());
          auto* segmentVertex1 = allocator.make<VectorEditor::SegmentVertex>(vertex, 1);
          segmentVertex1->setTangentOffset(tangentEndPoint.fX, tangentEndPoint.fY);
          newSegment->setVertex(segmentVertex1);
          ptVertexMap[span->ptT()].push_back(segmentVertex1);
          newSegment = allocator.make<VectorEditor::Segment>();
          result.push_back(newSegment);
          tangentEndPoint = cubicPair.second().fPts[1];
          vertex = allocator.make<VectorEditor::Vertex>(pt.x(), pt.y());
          auto segmentVertex2 = allocator.make<VectorEditor::SegmentVertex>(vertex, 0);
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

  vector<vector<VectorEditor::SegmentVertex*>> buildMinimalCycleBasis(vector<VectorEditor::Segment*>& segments) {
    vector<vector<VectorEditor::SegmentVertex*>> result;
    unordered_set<VectorEditor::SegmentVertex*> visited;
    std::stack<VectorEditor::SegmentVertex*> stack;
    auto* current = findTheLeftMostVertex(segments);
    do {
      current = findVertexOfTheLeftMostEdge(current);
      stack.push(current);
      visited.insert(current);
      auto* next = current;
      while (next != current) {
        visited.insert(next);
        next = current->getNext();
      }

    } while (leftMost->hasLink());
    return result;
  }

  vector<SkPath> computeFillGeometryPath(SkPath& path, VectorEditor::Network& network, ArenaAlloc& allocator) {
    auto* contourList = buildSkOpContourWithIntersection(path, allocator);
    auto segments = buildSegemtsWithoutIntersection(contourList, network.getSegments(), allocator);
    auto mcb = buildMinimalCycleBasis(segments);

    return {};
  }
}
