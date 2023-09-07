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
#include "util/node_geometry.h"
#include "config/color.h"

#include <iostream>

Canvas::Canvas(Desaina* desaina) : desaina_(desaina) {
  document_ = &desaina_->document;
}

void Canvas::tick() {
  if (document_->getCurrentPage() != nullptr) {
    canvas_->setMatrix(desaina_->viewPortSystem.getProjectionMatrix());
    drawNode(document_->getCurrentPage());
    drawHoverSelectionNode();
  }
  surface_->flush();
}

void Canvas::drawGeometry(const GeometryWithPaints& geometryWithPaints) {
  for (const auto& geo : geometryWithPaints.geometry) {
    const auto& path = geo;
    SkAutoCanvasRestore auto_save(canvas_, true);
    canvas_->clipPath(path, true);
    for (const auto& paintWithRect : geometryWithPaints.paints) {
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
    drawGeometry(util::getFillGeometryWithPaints(shape, desaina_));
    drawGeometry(util::getStrokeGeometryWithPaints(shape, desaina_));
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

void Canvas::drawHoverSelectionNode() {
  drawHoverNode();
  drawEditor();
}

void Canvas::drawHoverNode() {
  const auto hoverNode = desaina_->document.getHoverNode();
  if (hoverNode == nullptr) {
    return;
  }
  SkAutoCanvasRestore auto_save(canvas_, true);
  canvas_->concat(util::getWorldMatrix(hoverNode, document_));
  if (util::isDefaultShapeNode(hoverNode)) {
    auto shape = static_cast<const DefaultShapeNode*>(hoverNode);
    auto geometry = util::getHoverGeometry(shape, desaina_);
    SkPaint paint;
    paint.setColor(Config::primaryColor);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(2);
    canvas_->drawPath(geometry.path, paint);
  }
}

void Canvas::drawEditor() {
  SkAutoCanvasRestore auto_save(canvas_, true);
  auto* editor = desaina_->editSystem.getEditor();
  if (editor == nullptr) {
    return;
  }
  canvas_->concat(editor->getEditTransform());
  SkPath fillPath, strokePath;
  editor->getPath(fillPath, strokePath);
  
  SkPaint paint;
  paint.setColor(Config::primaryColor);
  paint.setStyle(SkPaint::kStroke_Style);
  paint.setStrokeWidth(1);
  canvas_->drawPath(fillPath, paint);
  canvas_->drawPath(strokePath, paint);

  paint.setStyle(SkPaint::kFill_Style);
  paint.setColor(SK_ColorWHITE);
  canvas_->drawPath(fillPath, paint);
}

void Canvas::drawMouseEvents(MouseEvent* event) {
}

