#include "creation.h"

namespace dea::interaction {

void Creation::onMouseDrag(MouseEvent* event) {
	if (creating_node_ == nullptr) {
		return;
	}
}

void Creation::onMouseUp(MouseEvent* event) {
	creating_node_ = nullptr;
}

} // namespace interaction

