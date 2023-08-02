#pragma once

#include "event_system/event.h"
#include "event_system/mouse_event_emmiter.h"

class Document;
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

class Editor {
public:
  Editor(Document* document) {
    document_ = document;
  };

  void onEvent(Event* event) {
    if (event->isMouseEvent()) {
      mouseEventEmmiter_.dispatchEvent(static_cast<MouseEvent*>(event));
    }
  };

  void addEventListener(EventType type, const ListenerFunc& func) {
    if (Event::isMouseEvent(type)) {
      mouseEventEmmiter_.addEventListener(type, func);
      return;
    }
  }

  bool isBoundEditor() { return type == EditorType::kBound; };
  bool isNodeEditor() { return type == EditorType::kNode; };
  bool isPathEditor() { return type == EditorType::kPath; };

  void buildHitTester(const std::vector<HitTestNode*>& nodes) {
    mouseEventEmmiter_.buildHitTester(nodes);
  }

  EditorType type;
  Document* document_;
  MouseEventEmmiter mouseEventEmmiter_;
};