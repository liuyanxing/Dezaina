#include "gfx/network.h"
#include "node_editor.h"
#include "bound_editor.h"
#include "include/src/base/SkArenaAlloc.h"

namespace dea::interaction {

class VectorEditor : public NodeEditor, public BoundEditor {
public:
	enum Mode {
		Bound,
		Vector,
	};

	class VertexNode {
	public:
		VertexNode(gfx::SegmentVertex* vertex, Frame& parent);
		~VertexNode() {
			node::Container::remove(&node_, node_.getParent());
		}
		void select();
		auto& getNode() { return node_; }
		auto* getVertex() { return vertex_; }
		auto  getPos() { return pos_; }
		auto getTangentEnd() {
			auto tagentOffset = vertex_->getTangentOffset();
			return pos_ + node::Vector{tagentOffset.x(), tagentOffset.y()};
		}
		auto getTagentLength() {
			auto t = vertex_->getTangentOffset();
			return node::Vector{t.x(), t.y()}.length();
		}
		auto getTangentAngle() {
			auto t = vertex_->getTangentOffset();
			return node::Vector{t.x(), t.y()}.angle({0, -1});
		}
	private:
		Rectangle node_;
		node::Vector pos_;
		gfx::SegmentVertex* vertex_;
	};

	class CtrlHandleNode {
	public:
		CtrlHandleNode(VertexNode& vertexNode, Frame& parent);
		~CtrlHandleNode() {
			node::Container::remove(&node_, node_.getParent());
			node::Container::remove(&line_, node_.getParent());
		}
		auto& getNode() { return node_; }
		auto& getVertexNode() { return vertexNode_; }
	private:
		Rectangle node_;
		Rectangle line_;
		VertexNode& vertexNode_;
	};

	using OnSelectVertexNodeCb = std::function<void(VertexNode*)>;

	VectorEditor(node::NodePtr node, document::Editor& editor, Frame* parent) :
		NodeEditor(node, parent),
		BoundEditor{frame_, editor} {
			update();
	}

	void update() override {
		NodeEditor::update();
		if (editMode_ == Bound) {
			updateBound();
			return;
		}
	}

	void updateBound() {
		auto* node = node::node_cast<node::VectorNode>(node_);
		assert(node);
		BoundEditor::update();
	}

	void startEditVector();
	void buildCtrlNodes();

	// if depth is 0, select node and another node of the same segment
	// or select all nodes of the segment that contains the node
	void selectVertexNode(VertexNode* node, int depth = 1);
	void onSelectVertexNode(const OnSelectVertexNodeCb& cb) { onSelectVertexNodeCb_ = cb; }

private:
	Mode editMode_ = Bound;
	gfx::Network network_;
	std::unique_ptr<SkArenaAlloc> arena_;
	std::vector<VertexNode> vertexNodes_;
	std::vector<VertexNode*> selectedVertexNodes_;
	std::vector<CtrlHandleNode> ctrlHandleNodes_;
	std::unordered_map<gfx::SegmentVertex*, VertexNode*> vertexNodeMap_;
	OnSelectVertexNodeCb onSelectVertexNodeCb_;

	void saveNetwork();
};

} // namespace dea::interaction