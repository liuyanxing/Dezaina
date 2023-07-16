#include "editor.h"

enum class ControlNodeType {
	kResize,
	kKResize,
	kRotate,
};

struct ControlNode : public HitTestNode {
	ControlNodeType type;
};


class BoundEditor : public Editor {
	void init() {
		mouseEventEmmiter_.addHitTestNode(HitTestNode::Make(0, SkRect::MakeXYWH(0, 0, 100, 100)));
		 mouseEventEmitter_.addEventListener<MouseEvent>([this](MouseEvent event) {
			 if (event.type == MouseEvent::Type::kDown) {
				 auto node = hitTester_.getChildContainsPoint(event.point);
				 if (node) {
					 node->setSelected(true);
				 }
			 }
		 });
	}
};