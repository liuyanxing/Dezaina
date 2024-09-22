#pragma once

#include "base/array.h"
#include "node.h"
#include "schema/message.h"

namespace dea::node {

node::Matrix getTransfromMatrix(node::Node *node);
node::Size getSize(node::NodeConstPtr node);

class NodeIter {
public:
  enum IterDirection {
    Forward,
    Backword,
    Right,
    End,
  };

  using GetParentFunc = std::function<node::Node *(node::Node *)>;

  NodeIter(node::Node *node, const GetParentFunc &);
  IterDirection operator++();
  IterDirection operator--();
  bool isValid() { return node_ != nullptr; }
  auto *get() { return node_; }
  node::Node *getParent() {
    if (node_)
      return getParent_(node_);
    return nullptr;
  }
  void skipChild() { isSkipChild_ = true; }

protected:
    node::Node* node_{ nullptr };
  node::Node* root_{ nullptr };
  GetParentFunc getParent_;
  bool isSkipChild_{false};
};

class NodeIterWithWorldMatrix : public NodeIter {
public:
  NodeIterWithWorldMatrix(node::Node *node, const GetParentFunc &getParent);
  IterDirection operator++();
  IterDirection operator--();
  const auto &getWorldMatrix() const { return world_; }

protected:
  node::Matrix getWorldMatrixImpl(node::Node *node);
  node::Matrix world_;
  base::array<node::Matrix, 16> worldStack_;
};

  inline void invalidateFillPath(message::NodeChange *nodeChange, kiwi::MemoryPool &pool) {
    auto& pathes = nodeChange->set_fillGeometry(pool, 1);
    pathes[0].set_commandsBlob(UINT32_MAX);
  }

  inline void invalidateStrokePath(message::NodeChange *nodeChange, kiwi::MemoryPool &pool) {
    auto& pathes = nodeChange->set_strokeGeometry(pool, 1);
    pathes[0].set_commandsBlob(UINT32_MAX);
  }

  inline void invalidatePath(message::NodeChange *nodeChange, kiwi::MemoryPool &pool) {
    invalidateFillPath(nodeChange, pool);
    invalidateStrokePath(nodeChange, pool);
  }

  inline bool isFillPathValid(message::NodeChange *nodeChange) {
   auto* fillGeometry = nodeChange->fillGeometry();
   if (!fillGeometry) {
      return true;
    }
    return *fillGeometry->begin()->commandsBlob() != UINT32_MAX; 
  }

  inline bool isStrokePathValid(message::NodeChange *nodeChange) {
    auto* strokeGeometry = nodeChange->strokeGeometry();
    if (!strokeGeometry) {
      return true;
    }
    return *strokeGeometry->begin()->commandsBlob() != UINT32_MAX; 
  }

  inline bool isPathValid(message::NodeChange *nodeChange) {
    return isFillPathValid(nodeChange) && isStrokePathValid(nodeChange);
  }

  inline void updateFillPath(DefaultShapeNode* shape, message::NodeChange *nodeChange, const uint32_t & blobId, kiwi::MemoryPool &pool) {
    auto& fillGeometry = nodeChange->set_fillGeometry(pool, 1);
    toChangeImpl(fillGeometry, shape->getFillGeometry(), pool);
    fillGeometry[0].set_commandsBlob(blobId);
  }
  

} // namespace dea::node
