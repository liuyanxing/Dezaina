#include "node_editor.h"
#include "bound_editor.h"

namespace dea::interaction {

class TextEditor : public NodeEditor, public BoundEditor {
public:
	TextEditor(node::NodePtr node, document::Editor& editor, Frame* parent) :
		NodeEditor(node, parent),
		BoundEditor{frame_, editor} {
			update();
		}

		void update() override {
			auto* node = node::node_cast<node::TextNode>(node_);
			assert(node);
			NodeEditor::update();
			BoundEditor::update();
		}
};

} // namespace dea::interaction