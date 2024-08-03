#include "editor.h"
#include <array>

namespace dea::document {
using namespace dea::node;

void Editor::editNodes(std::function<void(Node*)> cb) {
  for (auto* node : nodes_) {
    cb(node);
  } 
}

void Editor::addRecord(const EditRecordItem& record) {
  records_.push_back(record);
}

void Editor::addRecord(const GUID& layerId, const RecordType& type, const RecordValue& value) {
  records_.emplace_back(layerId, type, value);
}

Editor& Editor::resize(float width, float height, const Vector& anchor) {
  editNodes([width, height, &anchor, this](Node* node) {
    addRecord(node->getGuid(), RecordType::kResize, std::array<Vector, 2>{Vector{width, height}, anchor});
  });
  return *this;
}

Editor& Editor::setSize(float width, float height, const Vector& anchor) {
  editNodes([width, height, &anchor, this](Node* node) {
    addRecord(node->getGuid(), RecordType::kResize, std::array<Vector, 2>{Vector{width, height}, anchor});
  });
  return *this;
}

Editor& Editor::setTranslate(float x, float y) {
  editNodes([x, y, this](Node* node) {
    addRecord(node->getGuid(), RecordType::kResize, std::array<float, 2>{x, y});
  });
  return *this;
}

Editor& Editor::setTransform(const Matrix& matrix) {
  editNodes([&matrix, this](Node* node) {
    addRecord(node->getGuid(), RecordType::kTransform, matrix);
  });
  return *this;
}

} // namespace dea::document
