#include "include/core/SkCanvas.h"
#include "canvas.h"

#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "include/core/SkRect.h"
#include "node_type.h"
#include "page.h"
#include "rectangle.h"
#include "util/container.h"
#include "node_type.h"
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
	if (node == nullptr) {
		return;
	}
	
	SkAutoCanvasRestore auto_save(canvas_, true);

  if (util::isDefaultShapeNode(node)) {
    auto shape = static_cast<const DefaultShapeNode*>(node);
    canvas_->concat(util::toSkiaMatrix(shape->get_transform()));
    auto const& fillGeometry = shape->get_fillGeometry();
    for (const auto& geometry : fillGeometry) {
      auto* geo = document_->getGeometry(geometry.get_commandsBlob());
      const auto& path = geo->getPath();
      SkAutoCanvasRestore auto_save(canvas_, true);
      canvas_->clipPath(path, true);
      canvas_->drawColor(SK_ColorWHITE);
    }
  }

  if (util::isContainer(node)) {
    const auto& children = util::getChildren(node);
    for (const auto& child : children) {
      drawNode(child);
    }
  }

};

void Canvas::clear() {
	canvas_->clear(SK_ColorRED);
}