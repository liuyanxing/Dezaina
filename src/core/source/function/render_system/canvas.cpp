#include "include/core/SkCanvas.h"
#include "canvas.h"

#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "include/core/SkRect.h"
#include "node_type.h"
#include "page.h"
#include "rectangle.h"
#include "util/container.h"
#include "util/node_type.h"
#include "util/skia.h"

void Canvas::tick() {
	if (document_->is_loaded()) {
		clear();
		if (document_->getCurrentPage() != nullptr) {
			canvas_->setMatrix(vp_matrix_);
			drawNode(document_->getCurrentPage());
			surface_->flush();
		}
	}
}

void Canvas::drawNode(const Node *node) {
	SkAutoCanvasRestore auto_save(canvas_, true);

	if (node == nullptr) {
		return;
	}
	
  if (util::isDefaultShapeNode(node)) {
    auto shape = static_cast<const DefaultShapeNode*>(node);
    canvas_->concat(util::toSkiaMatrix(shape->get_transform()));
    auto const& fillGeometry = shape->get_fillGeometry();
    for (const auto& geometry : fillGeometry) {
      const auto& blob = document_->getBlobs()[geometry.get_commandsBlob()];
    }
  }
	if (util::isFrame(node)) {
		auto frame = static_cast<const FrameNode*>(node);
	  canvas_->concat(util::toSkiaMatrix(frame->get_transform()))	;
		SkPaint paint;
		paint.setColor(SK_ColorWHITE);
		canvas_->drawRect(SkRect::MakeXYWH(0, 0, frame->get_size().get_x(), frame->get_height()), paint);
		const auto& children = frame->get_children();
		for (const auto& child : children) {
			drawNode(child);
		}
		return;
	}

	if (util::isRectangle(node)) {
		auto rect = static_cast<const RectangleNode*>(node);
	  canvas_->concat(util::toSkiaMatrix(rect->get_transform()));
		SkPaint paint;
		paint.setColor(SK_ColorRED);
		canvas_->drawRect(SkRect::MakeXYWH(0, 0, rect->get_width(), rect->get_height()), paint);
		return;
	}

};

void Canvas::clear() {
	canvas_->clear(SK_ColorRED);
}