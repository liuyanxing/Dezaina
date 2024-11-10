#include "node_editor.h"
#include "bound_editor.h"

namespace dea::interaction {

class StarEditor : public NodeEditor, public BoundEditor {
public:
	StarEditor(node::NodePtr node, document::Editor& editor, Frame* parent) :
		NodeEditor(node, parent),
		BoundEditor{frame_, editor} {
			update();
		}

		void update() override {
			auto* node = node::node_cast<node::StarNode>(node_);
			assert(node);
			NodeEditor::update();
			BoundEditor::update();
		}
};

} // namespace dea::interaction