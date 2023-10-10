#include "desaina_node.h"
#include "document.h"
#include "node_type.h"
#include "node_pool.h"
#include "node_container.h"

template<typename T>
Node* cloneNodeImpl(const T* node, Document& pool) {
  auto* baseNodeRef = pool.createNode<T>();
  *baseNodeRef = *static_cast<const T*>(node);
  return baseNodeRef;
}

namespace util {
  inline Node* cloneNodeDeep(Node* node, Document& doc) {
    if (node == nullptr) {
      return nullptr;
    }

    Node* clone = nullptr;

    if (util::isPage(node)) {
      clone = cloneNodeImpl(static_cast<const PageNode*>(node), doc); 
    } else if (util::isFrame(node)) {
      clone = cloneNodeImpl(static_cast<const FrameNode*>(node), doc); 
    } else if (util::isVector(node)) {
      clone = cloneNodeImpl(static_cast<const VectorNodeBase*>(node), doc); 
    } else if (util::isLine(node)) {
      clone = cloneNodeImpl(static_cast<const LineNodeBase*>(node), doc); 
    } else if (util::isPolygon(node)) {
      clone = cloneNodeImpl(static_cast<const PolygonNodeBase*>(node), doc); 
    } else if (util::isRectangle(node)) {
      clone = cloneNodeImpl(static_cast<const RectangleNodeBase*>(node), doc); 
    } else if (util::isStar(node)) {
      clone = cloneNodeImpl(static_cast<const StarNodeBase*>(node), doc); 
    } else if (util::isEllipse(node)) {
      clone = cloneNodeImpl(static_cast<const EllipseNodeBase*>(node), doc); 
    } else if (util::isText(node)) {
      clone = cloneNodeImpl(static_cast<const TextNodeBase*>(node), doc); 
    }
    if (util::isContainer(node)) {
      auto* nodeConatainer = util::getContainer(node);
      auto* cloneContainer = util::getContainer(clone);
      cloneContainer->clear();
      for (auto* child : nodeConatainer->getChildren()) {
        auto* cloneChild = cloneNodeDeep(child, doc);
        cloneContainer->addChild(child);
      }
    }
    return clone;
  }

}
