#pragma once

#include "base_type.h"
#include "document.h"
#include "node_type.h"
namespace util {
  inline auto getNodesUnderPoint(Document& document, float x, float y) {
    vector<Node*> nodes;
    if (auto* curPage = document.getCurrentPage()) {
      curPage->getNodesUnderPoint(x, y, nodes);
    }
    return nodes;
  }
}
