#include "creation.h"

namespace interaction {

void Creation::onMouseDrag(MouseEvent* event) {
	if (creating_node_ == nullptr) {
		return;
	}
}

void Creation::onMouseUp(MouseEvent* event) {
	creating_node_ = nullptr;
}

} // namespace interaction

