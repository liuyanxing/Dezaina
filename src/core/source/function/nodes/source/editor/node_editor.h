#pragma once

#include "editor.h"
#include "editor/bound_editor.h"

class NodeEditor : public Editor {
public:
  NodeEditor(Document* document): Editor(document), boundEditor_(this) {};
  BoundEditor boundEditor_;
};