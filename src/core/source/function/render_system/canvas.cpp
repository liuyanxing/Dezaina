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

void Canvas::drawGeometry(const vector<Path> &geometry, const vector<PaintUnion> &paints) {
  for (const auto& g : geometry) {
    auto* geo = document_->getGeometry(g.commandsBlob);
    const auto& path = geo->getPath();
    SkAutoCanvasRestore auto_save(canvas_, true);
    canvas_->clipPath(path, true);
    for (const auto& paint : paints) {
      canvas_->drawPaint(util::toSkPaint(paint));
    }
  }
}

void Canvas::drawText(const TextNode *text) {
  SkPath path;
  SkMatrix matrix;
  const auto& textData = text->get_textData();
  const auto& glyphs = textData.get_glyphs();
  const auto& decorations = textData.get_decorations();
  for (const auto& glyph : glyphs) {
    auto fontSize = glyph.fontSize;
    matrix.setScaleTranslate(fontSize, -fontSize, glyph.position.x, glyph.position.y);
    const auto& glyphPath = document_->getGeometry(glyph.commandsBlob)->getPath();
    path.addPath(glyphPath, matrix);
  }

  SkPath decorationPath;
  for (const auto& decoration : decorations) {
    const auto& rects = decoration.get_rects();
    for (const auto& [x, y, w, h] : rects) {
      decorationPath.addRect(SkRect::MakeXYWH(x, y, w, h));
    }
  }

  path.addPath(decorationPath);

  SkAutoCanvasRestore auto_save(canvas_, true);
  canvas_->clipPath(path, true);
  for (const auto& paint : text->get_fillPaints()) {
    canvas_->drawPaint(util::toSkPaint(paint));
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

  if (util::isText(node)) {
    drawText(static_cast<const TextNode*>(node));
    return;
  }

  if (util::isDefaultShapeNode(node)) {
    auto shape = static_cast<const DefaultShapeNode*>(node);
    drawGeometry(shape->get_fillGeometry(), shape->get_fillPaints());
    drawGeometry(shape->get_strokeGeometry(), shape->get_strokePaints());
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
