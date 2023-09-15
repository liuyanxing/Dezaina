
#include "vector_node_helper.h"
#include "src/base/SkArenaAlloc.h"
#include "src/pathops/SkOpContour.h"
#include "src/pathops/SkPathOpsTypes.h"
#include "src/pathops/SkOpCoincidence.h"
#include "src/pathops/SkOpEdgeBuilder.h"
#include "src/pathops/SkPathOpsCommon.h"
#include "src/pathops/SkAddIntersections.h"
#include "src/pathops/SkPathWriter.h"

namespace util {
  void networkToSkPath(VectorEditor::Network& network, SkPath& path) {
    for (auto* segment : network.getSegments()) {
      auto& [v0, v1] = segment->getVertecies();
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

  vector<SkPath> computeFillGeometryPath(SkPath& path) {
    path.dump();
    SkSTArenaAlloc<4096> allocator;
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
    SkOpContour* current = contourList;
    do {
      SkOpContour* next = current;
      while (AddIntersectTs(current, next, &coincidence)
              && (next = next->next()));
    } while ((current = current->next()));

    bool success = HandleCoincidence(contourList, &coincidence);
    if (!success) {
      return {};
    }

    return {};
  }
}
