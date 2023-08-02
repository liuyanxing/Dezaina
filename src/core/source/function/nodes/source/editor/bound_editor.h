#pragma once

#include "editor.h"
#include <vector>

enum class ControlNodeType {
	kResize,
	kKResize,
	kRotate,
};

struct ControlNode : public HitTestNode {
	ControlNodeType type;
};

class BoundEditor {
public:
	BoundEditor(Editor* editor) {
	};

private:
  Editor* editor_;
};