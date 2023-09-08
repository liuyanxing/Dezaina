#pragma once

#include "editor.h"
#include "include/core/SkPath.h"
#include "include/core/SkRect.h"
#include <vector>

class BoundEditor {
public:
	BoundEditor(Editor* editor);
	void init();
	void update() { hit_nodes_.clear(); bindInteractionArea(); };
  void getPath(SkPath& fillPath, SkPath& strokePath);

private:
	void bindEvents();
	void bindInteractionArea();
	void handleMouseMove(Event* event);
	void handleMouseDrag(Event* event);
	void handleDragBound(Event* event);
	void hanldeDrageCtrlNode(Event* event);
	void handleDragBoundResize(Event* event);
  void handleDragBoundRotate(Event* event);
	void handleDragBoundEdge(Event* event);
  void handleDragBoundEdge(int index, float deltaX, float deltaY);

	void addHitNode(EditorHitNodeType type, int index, const SkRect& rect);
	
  Editor* editor_;
  SkRect bound_;
  vector<EditorHitNode> hit_nodes_;
};
