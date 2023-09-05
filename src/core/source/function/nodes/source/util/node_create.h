#include "desaina_node.h"
#include "node_type.h"
#include "node_pool.h"

namespace util {
  inline Node* cloneNodeBase(const Node* node, NodePool& pool) {
  if (util::isPage(node)) {
    auto* baseNodeRef = pool.createNode<PageNodeBase>();
    *baseNodeRef = *static_cast<const PageNodeBase*>(node);
    return baseNodeRef;
  }
}

}
