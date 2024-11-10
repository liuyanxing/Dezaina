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
	VectorEditor(node::NodePtr node, document::Editor& editor, Frame* parent) :
		NodeEditor(node, parent),
		BoundEditor{frame_, editor} {
			update();
	}

	void update() override {
		if (editMode_ == Bound) {
			updateBound();
			return;
		}
	}

	void updateBound() {
		auto* node = node::node_cast<node::VectorNode>(node_);
		assert(node);
		NodeEditor::update();
		BoundEditor::update();
	}

	void startEditVector();

private:
	Mode editMode_ = Bound;
	gfx::Network network_;
	std::unique_ptr<SkArenaAlloc> arena_;
};

} // namespace dea::interaction