#pragma once

#include "editor.h"
#include "include/core/SkRect.h"
#include <vector>

class BoundEditor {
public:
	BoundEditor(Editor* editor);
	void init();
	void buildBound();
	void bindEvents();
	void bindInteractionArea();
	void update() {};

	void handleMouseDrag(Event* event);

private:
  Editor* editor_;
  SkRect bound_;
};
