#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
#include "node_type.h"
#include <array>
#include <functional>
#include <variant>

enum class RecordType {
  kRotate,
  kResize,
  kTransform,
};

using ResizeValue = std::array<SkPoint, 2>; 

using RecordValue = std::variant<float, SkMatrix, std::array<float, 2>, std::array<float, 4>, ResizeValue>;

struct EditRecordItem {
  EditRecordItem(const GUID& layerId, const RecordType& type, const RecordValue& value) : nodeId(layerId), type(type), value(value) {}
  GUID nodeId;
  RecordType type;
  RecordValue value;
  static EditRecordItem Make(const GUID& layerId, const RecordType& type, const RecordValue& value) {
    EditRecordItem item{layerId, type, value};
    return item;
  }
};

class Desaina;

class Editor {
public:
  Editor(Desaina* desaina, bool editSelectedNodes = true);

  bool editSelectedNodes();
  Editor& createAndSelect(NodeType type, Node* parent);
  Editor& setEditNodes(vector<Node*> nodes);
  Editor& rotate(float degrees);
  Editor& translate(float x, float y);
  Editor& resize(float width, float height, const SkPoint& anchor);
  Editor& resize(float width, float height);
  Editor& setRotatation(float degrees);
  Editor& setTranslate(float x, float y);
  Editor& setTranslateX(float x);
  Editor& setTranslateY(float y);
  Editor& setSize(float width, float height, const SkPoint& anchor);
  Editor& setSize(float width, float height);
  Editor& setTransform(const SkMatrix& transform);
  ~Editor() = default;

private:
  Desaina* desaina;
  vector<Node*> edit_nodes_;
  vector<EditRecordItem> records_;

  void editNodes(std::function<void(Node*)>);
  void addRecord(const EditRecordItem& item);
  void addRecord(const GUID& layerId, const RecordType& type, const RecordValue& value);
};
