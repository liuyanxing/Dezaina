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
  kResize,
  kCornerResize,
  kRotate,
  kNormal,
};

struct EditorHitNode : public HitTestNode {
  EditorHitNodeType type;
  int index = 0;
};

class Editor : public EventEmitter {
public:
  Editor(Desaina* desaina) {
    this->desaina = desaina;
  };
  virtual ~Editor() = default;
  virtual void update() {};

  void emit(Event* event) {
    if (event->isMouseEvent()) {
      EventEmitter::emit(*event);
    }
  };

  bool isBoundEditor() { return type == EditorType::kBound; };
  bool isNodeEditor() { return type == EditorType::kNode; };
  bool isPathEditor() { return type == EditorType::kPath; };

  void buildHitTester(const std::vector<HitTestNode*>& nodes) {
  }

  bool isDirty() { return this->dirty; };
  void setDirty() { this->dirty = true; };
  
  vector<Node*> getEditingNodes();
  vector<EditorHitNode*>& getSelectedHitNode() { return selected_hit_nodes_; };
  EditorHitNode* getHoverHitNode() { return hover_hit_node_; };
  
  Desaina* desaina;
private:
  void handleMouseEvent(Event* event);
  void handleMouseMove(Event* event);
  void handleMouseDown(Event* event);
  
  EditorType type;
  bool dirty = false;
  EditorHitNode* hover_hit_node_ = nullptr;
  vector<EditorHitNode*> selected_hit_nodes_{};
  std::unique_ptr<HitTester> hit_tester_ = std::make_unique<SimpleHitTester>();
};
