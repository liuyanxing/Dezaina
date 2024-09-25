#include "node_editor.h"
#include "bound_editor.h"
#include "radius_editor.h"

namespace dea::interaction {

class RectangleEditor : public NodeEditor, public BoundEditor, public RadiusEditor {
public:
	RectangleEditor(node::RectangleNode& node, document::Editor& editor) :
		NodeEditor(node),
		BoundEditor{frame_, editor},
		RadiusEditor(frame_, editor) {};
	void update() override;
};

} // namespace dea::interaction