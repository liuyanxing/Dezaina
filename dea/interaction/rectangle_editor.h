#include "node_editor.h"
#include "bound_editor.h"
#include "radius_editor.h"

namespace dea::interaction {

class RectangleEditor : public NodeEditor, public BoundEditor, public RadiusEditor {
public:
	RectangleEditor(node::RectangleNode* node, document::Editor& editor, Frame* parent) :
		NodeEditor(node, parent),
		BoundEditor{frame_, editor},
		RadiusEditor(frame_, editor) {
			update();
	};
	void update() override;
};

} // namespace dea::interaction