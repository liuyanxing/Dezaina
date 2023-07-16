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
		init();
	};
	void init() {
		// add control nodes
		auto selections = document_.getSelections();
		SkRect bound = SkRect::MakeEmpty();
		for (auto& selection : selections) {
			bound.join(selection->getBound());
		}
		auto selectionBound = document_->getClientBoundFromWorldBound(bound);
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
	}
private:
	Document* document_;
	std::vector<CtrlNode> ctrl_nodes_;
};