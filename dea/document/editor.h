#pragma once

#include "node.h"
#include "node/node.h"
#include <array>
#include <functional>
#include <tuple>
#include <variant>

namespace dea::document {

enum class RecordType {
  kCreate,
  kSetParent,
  kSelection,
  kTranslate,
  kRotate,
  kResize,
  kTransform,
};

using ResizeValue = std::array<node::Vector, 2>; 
using CreateNodeValue = std::tuple<node::NodeType, node::Node*>;
using RecordValue = std::variant<float, node::Matrix, node::Node*, std::array<float, 2>, std::array<float, 4>, ResizeValue, node::NodeIdArray, CreateNodeValue>;

struct EditRecordItem {
  node::GUID nodeId;
  RecordType type;
  RecordValue value;
  static EditRecordItem Make(const node::GUID& layerId, const RecordType& type, const RecordValue& value) {
    EditRecordItem item{layerId, type, value};
    return item;
  }
  static EditRecordItem Make(const RecordType& type, const RecordValue& value) {
    EditRecordItem item{{}, type, value};
    return item;
  }
};

class Editor {
public:
  Editor() = default;
  Editor(const std::vector<node::Node*>& nodes) : nodes_(nodes) {};
  void setNodes(std::vector<node::Node*> nodes) { nodes_ = nodes; }

  bool empty() const { return records_.empty(); }

  bool editSelectedNodes();
  Editor& create(node::Node* node);
  Editor& setParent(node::Node* node) { addRecord(EditRecordItem::Make(RecordType::kSetParent, node)); return *this; }
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

  Editor& select(const node::NodeIdArray& selection) {
    addRecord(EditRecordItem::Make(RecordType::kSelection, selection));
    return *this;
  }

  void setImmediate(bool immediate) { immediate_ = immediate; }

  static const auto& getRecords() { return records_; }
  ~Editor() = default;

private:
  std::vector<node::Node*> nodes_;
  inline static std::vector<EditRecordItem> records_;
  inline static bool immediate_ = false;

  void editNodes(std::function<void(node::Node*)>);
  void addRecord(const EditRecordItem& item);
  void addRecord(const node::GUID& layerId, const RecordType& type, const RecordValue& value);
};

} // namespace dea::document
