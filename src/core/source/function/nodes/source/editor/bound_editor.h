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


class SelectBoundEditor : public Editor {
public:
	SelectBoundEditor(Document* document) {
		document_ = document;
		build();
	};
	void build() {
		// update control nodes
		auto selections = document_.getSelections();
		SkRect bound = SkRect::MakeEmpty();
		for (auto& selection : selections) {
			bound.join(selection->getBound());
		}
		auto selectionBound = document_->getClientBoundFromWorldBound(bound);
		ctrl_nodes_.clear();
		ctrl_nodes_.push_back(ControlNode::Make(ControlNodeType::kResize, SkRect::MakeXYWH(selectionBound.fRight - 10, selectionBound.fBottom - 10, 10, 10)));
		ctrl_nodes_.push_back(ControlNode::Make(ControlNodeType::kKResize, SkRect::MakeXYWH(selectionBound.fRight - 10, selectionBound.fTop, 10, 10)));
		ctrl_nodes_.push_back(ControlNode::Make(ControlNodeType::kRotate, SkRect::MakeXYWH(selectionBound.fLeft, selectionBound.fTop, 10, 10)));
    mouse_event_emmiter_.buildHitTester(ctrl_nodes_);
	};
  void bindEvents() {
    mouse_event_emmiter_.addEventListener<MouseDrag>([this](MouseEvent event) {});
  };
};