#include "node_editor.h"
#include "bound_editor.h"

namespace dea::interaction {

class FrameEditor : public NodeEditor, public BoundEditor {
public:
	FrameEditor(node::FrameNode& node, document::Editor& editor, Frame& parent) :
		NodeEditor(node, parent),
		BoundEditor{frame_, editor} {
			update();
		}

		void update() override {
			auto* node = node::node_cast<node::FrameNode>(&node_);
			assert(node);
			frame_.setTransform(GetWorldMatrix(node));
			frame_.setSize(getSize(node));
			BoundEditor::update();
		}
};

} // namespace dea::interaction