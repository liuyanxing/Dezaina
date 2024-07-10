#include "editor.h"
#include "include/core/SkMatrix.h"
#include "include/private/base/SkPoint_impl.h"
#include <array>

void Editor::editNodes(std::function<void(Node*)> cb) {
  for (auto* node : edit_nodes_) {
    cb(node);
  } 
}

void Editor::addRecord(const EditRecordItem& record) {
  records_.push_back(record);
}

void Editor::addRecord(const GUID& layerId, const RecordType& type, const RecordValue& value) {
  records_.emplace_back(layerId, type, value);
}

Editor& Editor::resize(float width, float height, const SkPoint& anchor) {
  editNodes([width, height, &anchor, this](Node* node) {
    addRecord(node->get_guid(), RecordType::kResize, std::array<SkPoint, 2>{SkPoint{width, height}, anchor});
  });
  return *this;
}

Editor& Editor::setSize(float width, float height, const SkPoint& anchor) {
  editNodes([width, height, &anchor, this](Node* node) {
    addRecord(node->get_guid(), RecordType::kResize, std::array<SkPoint, 2>{SkPoint{width, height}, anchor});
  });
  return *this;
}

Editor& Editor::setTranslate(float x, float y) {
  editNodes([x, y, this](Node* node) {
    addRecord(node->get_guid(), RecordType::kResize, std::array<float, 2>{x, y});
  });
  return *this;
}

Editor& Editor::setTransform(const SkMatrix& matrix) {
  editNodes([&matrix, this](Node* node) {
    addRecord(node->get_guid(), RecordType::kTransform, matrix);
  });
  return *this;
}
