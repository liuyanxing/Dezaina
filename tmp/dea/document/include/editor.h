#pragma once

#include "node/include/node.h"
#include "node/src/node-base/node.generated.h"
#include <array>
#include <functional>
#include <variant>

namespace dea::document {

enum class RecordType {
  kRotate,
  kResize,
  kTransform,
};

using ResizeValue = std::array<node::Vector, 2>; 
using RecordValue = std::variant<float, node::Matrix, std::array<float, 2>, std::array<float, 4>, ResizeValue>;

struct EditRecordItem {
  EditRecordItem(const node::GUID& layerId, const RecordType& type, const RecordValue& value) : nodeId(layerId), type(type), value(value) {}
  node::GUID nodeId;
  RecordType type;
  RecordValue value;
  static EditRecordItem Make(const node::GUID& layerId, const RecordType& type, const RecordValue& value) {
    EditRecordItem item{layerId, type, value};
    return item;
  }
};

class Editor {
public:
  Editor(bool editSelectedNodes = true);

  bool empty() const { return records_.empty(); }

  bool editSelectedNodes();
  Editor& createAndSelect(node::NodeType type, node::Node* parent);
  Editor& setEditNodes(std::vector<node::Node*> nodes);
  Editor& rotate(float degrees);
  Editor& translate(float x, float y);
  Editor& resize(float width, float height, const node::Vector& anchor);
  Editor& resize(float width, float height);
  Editor& setRotatation(float degrees);
  Editor& setTranslate(float x, float y);
  Editor& setTranslateX(float x);
  Editor& setTranslateY(float y);
  Editor& setSize(float width, float height, const node::Vector& anchor);
  Editor& setSize(float width, float height);
  Editor& setTransform(const node::Matrix& transform);
  ~Editor() = default;

private:
  std::vector<node::Node*> nodes_;
  std::vector<EditRecordItem> records_;

  void editNodes(std::function<void(node::Node*)>);
  void addRecord(const EditRecordItem& item);
  void addRecord(const GUID& layerId, const RecordType& type, const RecordValue& value);
};

} // namespace dea::document
