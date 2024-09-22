#include "editor.h"
#include "dezaina.h"
#include <array>

namespace dea::document {
using namespace dea::node;

Editor &Editor::create(node::Node *node) {
  addRecord(node->getGuid(), RecordType::kCreate, node);
  return *this;
}

void Editor::editNodes(std::function<void(Node *)> cb) {
  for (auto *node : nodes_) {
    cb(node);
  }
}

void Editor::addRecord(const GUID &layerId, const RecordType &type,
                       const RecordValue &value) {
  records_.emplace_back(layerId, type, value);
  if (immediate_ || Dezaina::isImmediate()) {
    Dezaina::instance().flush();
  }
}

void Editor::addRecord(const RecordType &type, const RecordValue &value) {
  addRecord({}, type, value);
}

Editor &Editor::resize(float width, float height, const Vector &direction) {
  editNodes([width, height, &direction, this](Node *node) {
    if (auto *shape = node_cast<DefaultShapeNode>(node)) {
      auto newSize = shape->getSize() + Vector{width, height};
      addRecord(node->getGuid(), RecordType::kSetSize,
                SetSizeValue{newSize, direction});
    }
  });
  return *this;
}

Editor &Editor::setSize(float width, float height, const Vector &direction) {
  editNodes([width, height, &direction, this](Node *node) {
    addRecord(node->getGuid(), RecordType::kSetSize,
              SetSizeValue{Vector{width, height}, direction});
  });
  return *this;
}

Editor &Editor::setTranslate(float x, float y) {
  editNodes([x, y, this](Node *node) {
    if (auto *shape = node_cast<DefaultShapeNode>(node)) {
      auto m = shape->getTransform();
      m.setM02(x);
      m.setM12(y);
      addRecord(node->getGuid(), RecordType::kTransform, m);
    }
  });
  return *this;
}

Editor &Editor::translate(float x, float y) {
  editNodes([x, y, this](Node *node) mutable {
    if (auto *shape = node_cast<DefaultShapeNode>(node)) {
      auto m = shape->getTransform();
      m.translate(x, y);
      addRecord(node->getGuid(), RecordType::kTransform, m);
    }
  });
  return *this;
}

Editor &Editor::rotate(float angle) {
  editNodes([angle, this](Node *node) {
    if (auto *shape = node_cast<DefaultShapeNode>(node)) {
      auto m = shape->getTransform();
      m.preRotate(angle, shape->getSize() / 2);
      addRecord(node->getGuid(), RecordType::kTransform, m);
    }
  });
  return *this;
}

Editor &Editor::setTransform(const Matrix &matrix) {
  editNodes([&matrix, this](Node *node) {
    addRecord(node->getGuid(), RecordType::kTransform, matrix);
  });
  return *this;
}

} // namespace dea::document
