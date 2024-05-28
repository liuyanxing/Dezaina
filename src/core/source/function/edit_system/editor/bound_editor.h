#pragma once

#include "editor.h"
#include "include/core/SkPath.h"
#include "include/core/SkPoint.h"
#include "include/core/SkRect.h"
#include <vector>

struct BoundEditorHitNode : public EditorHitNode {
	SkVector direction;
	static BoundEditorHitNode Make(EditorHitNodeType type, int index, const SkVector& direction, const SkRect& bound) {
		BoundEditorHitNode node{};
		node.type = type;
		node.index = index;
		node.bound = bound;
		node.direction = direction;
		return node;
	}
};

class NodeEditor {
public:
	NodeEditor(EditorView* editor);
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

	void addHitNode(EditorHitNodeType type, int index, const SkPoint& direction, const SkRect& rect);
	
  EditorView* editor_view_;
  SkRect bound_;
  vector<BoundEditorHitNode> hit_nodes_;
};
