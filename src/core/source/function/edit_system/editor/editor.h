#pragma once

#include "base_type.h"
#include "event_system/event.h"
#include "event_system/event_emitter.h"
#include "event_system/hit_tester.h"
#include "event_system/simple_hit_tester.h"

class Desaina;

enum class EditorType {
  kBound,
  kNode,
  kPath,
};

enum class EditorHitNodeType {
  kBoundEdge,
  kBoundCorner,
};

struct EditorHitNode : public HitTestNode {
  EditorHitNodeType type;
  int index = 0;
  static EditorHitNode Make(EditorHitNodeType type, int index, const SkRect& bound) {
    EditorHitNode node{};
    node.type = type;
    node.index = index;
    node.bound = bound;
    return node;
  } 
};

class Editor : public EventEmitter {
public:
  Editor(Desaina* desaina) {
    this->desaina = desaina;
    init();
  };
  virtual ~Editor() = default;
  virtual void update() {
    bound_ = buildEditingNodesBound();
  };

  void init();
  void bindEvents();

  void emit(Event* event) {
    if (event->isMouseEvent()) {
      mapEventToLocal(event);
      EventEmitter::emit(*event);
    }
  };

  bool isBoundEditor() { return type == EditorType::kBound; };
  bool isNodeEditor() { return type == EditorType::kNode; };
  bool isPathEditor() { return type == EditorType::kPath; };

  bool isDirty() { return this->dirty; };
  const SkRect& getBound() const { return bound_; };
  vector<Node*> getEditingNodes();
  vector<EditorHitNode*>& getSelectedHitNode() { return selected_hit_nodes_; };
  EditorHitNode* getFirstSelectedHitNode() { return !selected_hit_nodes_.empty() ? selected_hit_nodes_[0] : nullptr; };
  EditorHitNode* getHoverHitNode() { return hover_hit_node_; };
  void setDirty() { this->dirty = true; };
  
  Desaina* desaina;
  std::unique_ptr<HitTester> hit_tester = std::make_unique<SimpleHitTester>();
private:
  SkRect buildEditingNodesBound();
  void buildHitTester(const std::vector<HitTestNode*>& nodes) {
  }
  void mapEventToLocal(Event* event);
  
  void handleMouseEvent(Event* event);
  void handleMouseMove(Event* event);
  void handleMouseDown(Event* event);
  
  EditorType type;
  bool dirty = false;
  EditorHitNode* hover_hit_node_ = nullptr;
  vector<EditorHitNode*> selected_hit_nodes_{};
  SkRect bound_;
};
