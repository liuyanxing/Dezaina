#include "creation.h"

namespace dea::interaction {

void Creation::onMouseDrag(event::MouseEvent& event) {
	if (creatingNode_ == nullptr) {
		return;
	}
}

void Creation::onMouseUp(event::MouseEvent& event) {
	creatingNode_ = nullptr;
}

} // namespace interaction

