#pragma once

#include "document.h"
#include "event_system/event.h"

enum class EditorType {
  kBound,
  kNode,
  kPath,
};

class Editor {
public:
  virtual void onEvent(const Event* event);

  bool isBoundEditor() { return type == EditorType::kBound; };
  bool isNodeEditor() { return type == EditorType::kNode; };
  bool isPathEditor() { return type == EditorType::kPath; };

  EditorType type;
  Document* document_;
};