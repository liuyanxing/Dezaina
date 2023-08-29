#include "base_type.h"
#include "desaina.h"
#include "desaina_node.h"
#include "document.h"
#include "include/core/SkCanvas.h"
#include "canvas.h"

#include "include/core/SkColor.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkRect.h"
#include "node_type.h"
#include "page.h"
#include "rectangle.h"
#include "text.h"
#include "util/container.h"
#include "node_type.h"
#include "util/skia.h"
#include "util/node_props.h"

#include <iostream>

Canvas::Canvas(Desaina* desaina) : desaina_(desaina) {
  document_ = &desaina_->document;
}

void Canvas::tick() {
  if (document_->getCurrentPage() != nullptr) {
    canvas_->setMatrix(desaina_->viewPortSystem.getProjectionMatrix());
    drawNode(document_->getCurrentPage());
  }
  surface_->flush();
}

void Canvas::drawGeometry(const vector<SkPath> &geometry, const vector<PaintWithRect> &paintsWithRect) {
  for (const auto& geo : geometry) {
    const auto& path = geo;
    SkAutoCanvasRestore auto_save(canvas_, true);
    canvas_->clipPath(path, true);
    for (const auto& paintWithRect : paintsWithRect) {
      SkAutoCanvasRestore auto_save(canvas_, true);
      if (paintWithRect.rect.has_value()) {
        canvas_->clipRect(paintWithRect.rect.value(), true);
      }
      canvas_->drawPaint(paintWithRect.paint);
    }
  }
}

void Canvas::drawNode(const Node *node) {
	if (node == nullptr) {
		return;
	}
	
	SkAutoCanvasRestore auto_save(canvas_, true);

  canvas_->concat(util::getTransfromMatrix(node));
  if (util::isPage(node)) {
    auto page = static_cast<const PageNode*>(node);
    const auto& color = page->get_backgroundColor();
    canvas_->drawColor(util::toSkColor(color));
  }

  if (util::isDefaultShapeNode(node)) {
    auto shape = static_cast<const DefaultShapeNode*>(node);
    drawGeometry(util::getGeometry(node, desaina_), util::getFillPaintsWithRect(node));
    drawGeometry(util::getGeometry(node, desaina_), util::getStrokePaintsWithRect(node));
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
