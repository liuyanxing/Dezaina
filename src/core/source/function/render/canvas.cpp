#include "include/core/SkCanvas.h"
#include "canvas.h"

#include "include/core/SkColor.h"
#include "page.h"
#include "rectangle.h"
#include "util/node_children.h"
#include "util/skia.h"

void Canvas::tick() {
	if (document_->is_loaded()) {
		clear();
		if (document_->getCurPage() != nullptr) {
			drawNode(document_->getCurPage());
		}
	}
}

void Canvas::drawNode(const Node *node) {
	SkAutoCanvasRestore auto_save(canvas_, true);

	if (node == nullptr) {
		return;
	}
	
	if (!node->isSceneNode()) {
		if (!node->isPage()) {
			return;
		}

		auto page = static_cast<const PageNode*>(node);
		const auto& children = page->get_children();
		for (const auto& child : children) {
			drawNode(child);
		}
	}
	if (node->isFrame()) {
		auto frame = static_cast<const FrameNode*>(node);
	  canvas_->concat(util::toSkiaMatrix(frame->get_transform()))	;
		SkPaint paint;
		paint.setColor(SK_ColorWHITE);
		canvas_->drawRect(SkRect::MakeXYWH(0, 0, frame->get_width(), frame->get_height()), paint);
		const auto& children = frame->get_children();
		for (const auto& child : children) {
			drawNode(child);
		}
		return;
	}

	if (node->isRect()) {
		auto rect = static_cast<const RectangleNode*>(node);
	  canvas_->concat(util::toSkiaMatrix(rect->get_transform()))	;
		SkPaint paint;
		paint.setColor(SK_ColorDKGRAY);
		canvas_->drawRect(SkRect::MakeXYWH(0, 0, rect->get_width(), rect->get_height()), paint);
		return;
	}

};

void Canvas::clear() {
	canvas_->clear(SK_ColorWHITE);
}