#include "container_node_base.h"
#include "util/node_container.h"
#include "util/node_props.h"
#include "util/node_geometry.h"

void ContainerNodeBase::getNodesUnderPoint(float x, float y, vector<Node *> &nodes) {
  for (auto *child : children) {
    auto transform = util::getTransfromMatrix(child);
    SkMatrix inverse;
    if (!transform.invert(&inverse)) {
      continue;
    }
    auto point = inverse.mapXY(x, y);
    if (util::isContainer(child)) {
      auto* container = util::getContainer(child);
      container->getNodesUnderPoint(point.x(), point.y(), nodes);
    } else {
      if (util::isPointInNodeGeometry(child, point.x(), point.y())) {
        nodes.push_back(child);
      }
    }
  }
}
