#include "creation.h"
#include "dezaina.h"

namespace dea::interaction {

void Creation::onMouseDrag(event::MouseEvent& event) {
	if (creatingNode_) {
		return;
	}
	auto dx = event.x - event.dragStartX, dy = event.y - event.dragStartY;
	if (dx > 6 && dy > 6) {
		auto& editor = document_.editor();
		document_.append(creatingNode_, event.target);
		auto size = Dezaina::instance().viewport().getWorldSize({dx, dy});
		auto pos = node::Vector{event.localWorldX, event.localWorldY};
		editor.setSize(size, {0, 0});
		editor.setTranslate(pos - size);
		editor.appendSolidPaint({1, 1, 1, 1});
		if (onCreateNode_) {
			onCreateNode_(creatingNode_, event);
		}
		creatingNode_ = nullptr;
	}
}

void Creation::onMouseUp(event::MouseEvent& event) {
	creatingNode_ = nullptr;
}

} // namespace interaction

