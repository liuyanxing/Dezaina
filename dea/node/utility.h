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

  NodeIter(node::Node *node);
  IterDirection operator++();
  IterDirection operator--();
  bool isValid() { return node_ != nullptr; }
  auto *get() { return node_; }
  void skipChild() { isSkipChild_ = true; }
  void rest() { node_ = root_; }

protected:
  node::Node *node_{nullptr};
  node::Node *root_{nullptr};
  bool isSkipChild_{false};
};

class NodeIterWithWorldMatrix : public NodeIter {
public:
  NodeIterWithWorldMatrix(node::Node *node);
  IterDirection operator++();
  IterDirection operator--();
  const auto &getWorldMatrix() const { return world_; }
  void rest();
  void update();

protected:
  node::Matrix getWorldMatrixImpl(node::Node *node);
  node::Matrix world_;
  base::array<node::Matrix, 16> worldStack_;
};

inline void invalidateFillPath(message::NodeChange *nodeChange,
                               kiwi::MemoryPool &pool) {
  auto &pathes = nodeChange->set_fillGeometry(pool, 1);
  node::Path path{node::WindingRule::NONZERO, UINT32_MAX};
  toChangeImpl(pathes[0], path, pool);
}

inline void invalidateStrokePath(message::NodeChange *nodeChange,
                                 kiwi::MemoryPool &pool) {
  auto &pathes = nodeChange->set_strokeGeometry(pool, 1);
  node::Path path{node::WindingRule::NONZERO, UINT32_MAX};
  toChangeImpl(pathes[0], path, pool);
}

inline void invalidatePath(message::NodeChange *nodeChange,
                           kiwi::MemoryPool &pool) {
  invalidateFillPath(nodeChange, pool);
  invalidateStrokePath(nodeChange, pool);
}

inline bool isFillPathValid(message::NodeChange *nodeChange) {
  auto *fillGeometry = nodeChange->fillGeometry();
  if (!fillGeometry) {
    return true;
  }
  return *fillGeometry->begin()->commandsBlob() != UINT32_MAX;
}

inline bool isStrokePathValid(message::NodeChange *nodeChange) {
  auto *strokeGeometry = nodeChange->strokeGeometry();
  if (!strokeGeometry) {
    return true;
  }
  return *strokeGeometry->begin()->commandsBlob() != UINT32_MAX;
}

inline bool isPathValid(message::NodeChange *nodeChange) {
  return isFillPathValid(nodeChange) && isStrokePathValid(nodeChange);
}

inline void updateFillPath(DefaultShapeNode *shape,
                           message::NodeChange *nodeChange,
                           const uint32_t &blobId, kiwi::MemoryPool &pool) {
  auto &fillGeometry = nodeChange->set_fillGeometry(pool, 1);
  toChangeImpl(fillGeometry, shape->getFillGeometry(), pool);
  fillGeometry[0].set_commandsBlob(blobId);
}

} // namespace dea::node
