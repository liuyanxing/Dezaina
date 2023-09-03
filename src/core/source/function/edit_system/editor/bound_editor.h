#pragma once

#include "editor.h"
#include "include/core/SkRect.h"
#include <vector>

class BoundEditor {
public:
	BoundEditor(Editor* editor);
	void init();
	void update() {};


private:
	void bindEvents();
	void bindInteractionArea();
	void handleMouseMove(Event* event);
	void handleMouseDrag(Event* event);
	void handleDragBound(Event* event);
	void hanldeDrageCtrlNode(Event* event);
	void handleDragBoundCorner(Event* event);
	void handleDragBoundEdge(Event* event);
	void addHitNode(const EditorHitNode& node);
	
  Editor* editor_;
  SkRect bound_;
  vector<EditorHitNode> hit_nodes_;
};
