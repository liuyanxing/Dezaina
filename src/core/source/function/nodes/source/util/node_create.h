#include "desaina_node.h"
#include "node_type.h"
#include "node_pool.h"

template<typename T>
Node* cloneNodeBaseImpl(const T* node, NodePool& pool) {
  auto* baseNodeRef = pool.createNode<T>();
  *baseNodeRef = *static_cast<const T*>(node);
  return baseNodeRef;
}

namespace util {
  inline Node* cloneNodeBase(const Node* node, NodePool& pool) {
    if (node == nullptr) {
      return nullptr;
    }

    if (util::isPage(node)) {
      return cloneNodeBaseImpl(static_cast<const PageNodeBase*>(node), pool); 
    } else if (util::isFrame(node)) {
      return cloneNodeBaseImpl(static_cast<const FrameNodeBase*>(node), pool); 
    } else if (util::isVector(node)) {
      return cloneNodeBaseImpl(static_cast<const VectorNodeBase*>(node), pool); 
    } else if (util::isLine(node)) {
      return cloneNodeBaseImpl(static_cast<const LineNodeBase*>(node), pool); 
    } else if (util::isPolygon(node)) {
      return cloneNodeBaseImpl(static_cast<const PolygonNodeBase*>(node), pool); 
    } else if (util::isRectangle(node)) {
      return cloneNodeBaseImpl(static_cast<const RectangleNodeBase*>(node), pool); 
    } else if (util::isStar(node)) {
      return cloneNodeBaseImpl(static_cast<const StarNodeBase*>(node), pool); 
    } else if (util::isEllipse(node)) {
      return cloneNodeBaseImpl(static_cast<const EllipseNodeBase*>(node), pool); 
    } else if (util::isText(node)) {
      return cloneNodeBaseImpl(static_cast<const TextNodeBase*>(node), pool); 
    }
    return nullptr;
  }

}
