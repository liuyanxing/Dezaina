#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "event_system/event.h"
#include "event_system/event_emitter.h"
#include "event_system/hit_tester.h"
#include "event_system/simple_hit_tester.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPath.h"
#include "include/core/SkPoint.h"
#include "include/private/base/SkPoint_impl.h"
#include "node_type.h"
#include <array>
#include <functional>
#include <optional>
#include <variant>
#include <vector>

class Desaina;

enum class EditorType {
  kNode,
  kVector,
  kRectangle,
  kFrame,
};

enum class EditorHitNodeType {
  kBoundEdge,
  kBoundCorner,
  kBoundRotate,
  kController,
};

struct EditorHitNode : public HitTestNode {
  EditorHitNodeType type;
  int index = 0;
  void* data = nullptr;
  static EditorHitNode Make(EditorHitNodeType type, int index, const SkRect& bound) {
    EditorHitNode node{};
    node.type = type;
    node.index = index;
    node.bound = bound;
    return node;
  } 
  static EditorHitNode Make(EditorHitNodeType type, void* data, const SkRect& bound) {
    EditorHitNode node{};
    node.type = type;
    node.data = data;
    node.bound = bound;
    return node;
  }
};

class EditorView : public EventEmitter {
public:
  EditorView(EditorType type, Desaina* desaina) {
    this->desaina = desaina;
    this->type = type;
    init();
  };
  virtual ~EditorView() = default;
  virtual void update() {
    hit_tester->clear();
    buildEditingNodesBound();
  };
  virtual void getPath(SkPath& fillPath, SkPath& strokePath) {};
  virtual void getEditPath(SkPath& path) {};

  auto getType() { return type; };

  void init();
  void bindEvents();

  void emit(Event* event) {
    if (event->isMouseEvent()) {
      mapEventToLocal(event);
      EventEmitter::emit(*event);
    }
  };

  bool isDirty() { return this->dirty; };
  const SkRect& getEditBound() const { return edit_bound_; };
  const SkMatrix& getEditTransform() const { return edit_transform_; };
  vector<Node*> getEditingNodes();
  vector<EditorHitNode*>& getSelectedHitNode() { return selected_hit_nodes_; };
  EditorHitNode* getFirstSelectedHitNode() { return !selected_hit_nodes_.empty() ? selected_hit_nodes_[0] : nullptr; };
  EditorHitNode* getHoverHitNode() { return hover_hit_node_; };
  void setDirty() { this->dirty = true; };
  void insertHitNode(EditorHitNode* node) {
    hit_tester->insert(node);
  };
  void updateHitNodes(const vector<EditorHitNode*>& nodes, std::function<bool(EditorHitNode*, EditorHitNode*)> isSameHitNode);
  EditorHitNode* getNodeUnderPoint(const SkPoint& point);
  void setSelectNodeByPoint(const SkPoint& point);

  void rotate(float degrees, std::optional<GUID> id = std::nullopt);
  void translate(float x, float y, std::optional<GUID> id = std::nullopt);
  void resize(float width, float height, std::optional<GUID> id = std::nullopt);
  void setRotatation(float degrees, std::optional<GUID> id = std::nullopt);
  void setTranslate(float x, float y, std::optional<GUID> id = std::nullopt);
  void setTranslateX(float x, std::optional<GUID> id = std::nullopt);
  void setTranslateY(float y, std::optional<GUID> id = std::nullopt);
  void setSize(float width, float height, std::optional<GUID> id = std::nullopt);
  void setTransform(const SkMatrix& transform, std::optional<GUID> id = std::nullopt);
  
  Desaina* desaina;
  std::unique_ptr<HitTester> hit_tester = std::make_unique<SimpleHitTester>();
  
private:
  void buildEditingNodesBound();
  void buildHitTester(const std::vector<HitTestNode*>& nodes) {
  }
  void mapEventToLocal(Event* event);
  
  void handleMouseEvent(Event* event);
  void handleMouseMove(Event* event);
  void handleMouseDown(Event* event);
  void handleMouseUp(Event* event);

  Node* getEditNodeById(const std::optional<GUID>& id);
  
  EditorType type;
  bool dirty = false;
  EditorHitNode* hover_hit_node_ = nullptr;
  vector<EditorHitNode*> selected_hit_nodes_{};
  SkRect edit_bound_;
  SkMatrix edit_transform_;
};

enum class RecordType {
  kRotate,
  kResize,
  kTransform,
};

using ResizeValue = std::array<SkPoint, 2>; 

using RecordValue = std::variant<float, SkMatrix, std::array<float, 2>, ResizeValue>;

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

class Editor {
public:
  explicit Editor(Desaina* desaina) {
    this->desaina = desaina;
  };

  bool setSelectedNodeToEdit();
  Editor* setEditNodes(vector<Node*> nodes);
  Editor* rotate(float degrees);
  Editor* translate(float x, float y);
  Editor* resize(float width, float height, const SkPoint& anchor);
  Editor* resize(float width, float height);
  Editor* setRotatation(float degrees);
  Editor* setTranslate(float x, float y);
  Editor* setTranslateX(float x);
  Editor* setTranslateY(float y);
  Editor* setSize(float width, float height, const SkPoint& anchor);
  Editor* setSize(float width, float height);
  Editor* setTransform(const SkMatrix& transform);
  ~Editor() = default;
private:
  Desaina* desaina;
  vector<Node*> edit_nodes_;
  vector<EditRecordItem> records_;

  void editNodes(std::function<void(Node*)>);
  void addRecord(const EditRecordItem& item);
  void addRecord(const GUID& layerId, const RecordType& type, const RecordValue& value);
};
