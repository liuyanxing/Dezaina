#include "desaina.h"
#include "node_props.h"

namespace util {
  vector<SkPath> getGeometry(const TextNode* node, Desaina* desaina) {
    vector<SkPath> paths;
    SkPath path;
    SkMatrix matrix;
    const auto& textData = node->get_textData();
    const auto& glyphs = textData.get_glyphs();
    const auto& decorations = textData.get_decorations();
    for (const auto& glyph : glyphs) {
      auto fontSize = glyph.fontSize;
      matrix.setScaleTranslate(fontSize, -fontSize, glyph.position.x, glyph.position.y);
      const auto& glyphPath = desaina->document.getGeometry(glyph.commandsBlob)->getPath();
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

    paths.push_back(std::move(path));
    return paths;

  }

  vector<SkPath> getGeometry(const Node* node, Desaina* desaina) {
    vector<SkPath> paths;
    if (util::isText(node)) {
      return getGeometry(static_cast<const TextNode*>(node), desaina);
    } else if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      const auto& geometry = shape->get_fillGeometry();
      for (const auto& geo : geometry) {
        paths.push_back(desaina->document.getGeometry(geo.commandsBlob)->getPath());
      }
    }
    return paths;
  }
}