#include "node_editor.h"
#include "bound_editor.h"

namespace dea::interaction {

class PolygonEditor : public NodeEditor, public BoundEditor {
public:
	PolygonEditor(node::NodePtr node, document::Editor& editor, Frame* parent) :
		NodeEditor(node, parent),
		BoundEditor{frame_, editor} {
			update();
		}

		void update() override {
			auto* node = node::node_cast<node::PolygonNode>(node_);
			assert(node);
			NodeEditor::update();
			BoundEditor::update();
		}
};

} // namespace dea::interaction