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
	void handleMouseDrag(Event* event);
	void handleDragBound(Event* event);
	void hanldeDrageCtrlNode();
	void handleDragBoundCorner();
	void handleDragBoundEdge();
	void addHitNode(const EditorHitNode& node);
	
  Editor* editor_;
  SkRect bound_;
  vector<EditorHitNode> hit_nodes_;
};
