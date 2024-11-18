#include "paint.h"
#include <variant>

namespace dea::render {

using namespace dea::node;

static PaintDrawers paintDrawers{};

static void pushPaintDrawer(const node::SolidPaint& paint) {
  paintDrawers.push_back(SolidPaintDrawer{paint});
}

static void pushPaintDrawer(const node::GradientPaint& paint) {
  paintDrawers.push_back(GradientPaintDrawer{paint});
}

static void pushPaintDrawer(const node::ImagePaint& paint) {
  paintDrawers.push_back(ImagePaintDrawer{paint});
}

static void pushPaintDrawer(const node::PaintUnion& paint) {
  std::visit([](auto&& p) {
    pushPaintDrawer(p);
  }, paint);
}

static void pushPaintDrawer(const std::vector<PaintUnion>& paints, const node::Rect& region) {
  for (const auto& paint : paints) {
    std::visit([&region](auto&& p) {
      pushPaintDrawer(p);
      auto& drawer = paintDrawers.back();
      std::visit([&region](auto&& d) {
        d.setRegion(region);
      }, drawer);
    }, paint);
  }
}

void buildPaintDrawers(const std::vector<node::PaintUnion>& paints) {
  paintDrawers.clear();
  for (const auto& paint : paints) {
    pushPaintDrawer(paint);
  }
}

PaintDrawers& buildFillPaintDrawers(const node::TextNode* node) {
  paintDrawers.clear();

  const auto& textData = node->getTextData();
  const auto& characterStyleIDs = textData.getCharacterStyleIDs();
  const auto& derivedTextData = node->getDerivedTextData();
  const auto& glyphs = derivedTextData.getGlyphs();
  const auto& decorations = derivedTextData.getDecorations();
  const auto& baselines = derivedTextData.getBaselines();
  const auto& styleOverrideTable = textData.getStyleOverrideTable();

  kiwi::ByteBuffer buffer(styleOverrideTable.data(), styleOverrideTable.size());

  kiwi::MemoryPool pool;
  uint32_t count;
  buffer.readVarUint(count);
  auto changes = pool.array<message::NodeChange>(count);
  std::unordered_map<uint32_t, SubTextMixin> map;

  for (auto& change : changes) {
    change.decode(buffer, pool);
    SubTextMixin subText;
    subText.applyChange(change);
    uint32_t styleID = subText.getStyleID();
    map[styleID] = std::move(subText);
  }

  int32_t lastStyleID = -1;
  const std::vector<PaintUnion>* lastPaint{nullptr};
  Rect rect;
  int32_t curBaseline = -1;
  Baseline baseline{};

  float lineAscentPosition = 0;
  float lineDescentPosition = 0;

  for (int i = 0; i < glyphs.size(); i++) {
    auto& glyph = glyphs[i];
    if (curBaseline == -1 || glyph.getPosition().y != baseline.position.y) {
      if (lastPaint) pushPaintDrawer(*lastPaint, rect);
      curBaseline++;
      baseline = baselines[curBaseline];
      lineAscentPosition = baseline.position.y - baseline.lineAscent;
      lineDescentPosition = baseline.position.y + baseline.lineHeight - baseline.lineAscent;
      rect.reset();
      lastPaint = nullptr;
      lastStyleID = -1;
    }

    auto fontSize = glyph.getFontSize();
    auto advance = glyph.getAdvance()* fontSize;
    auto styleID = characterStyleIDs[i];
    auto glyphRect = Rect::MakeXYWH(glyph.getPosition().x, lineAscentPosition, advance, lineDescentPosition - lineAscentPosition);

    if (lastStyleID != styleID ) {
      if (lastPaint) pushPaintDrawer(*lastPaint, rect);
      rect = glyphRect;
      lastPaint = map.contains(styleID) ? &map[styleID].getFillPaints() : &node->getFillPaints();
    } else {
      rect.join(glyphRect);
    }

    lastStyleID = styleID;
  }
  if (lastPaint) pushPaintDrawer(*lastPaint, rect);
  return paintDrawers;
}

PaintDrawers& buildFillPaintDrawers(node::NodeConstPtr node) {
  if (auto* textNode = node::node_cast<const node::TextNode>(node)) {
    return buildFillPaintDrawers(textNode);
  }
  auto* shapeNode = node::node_cast<const node::DefaultShapeNode>(node);
  assert(shapeNode);
  buildPaintDrawers(shapeNode->getFillPaints());
  return paintDrawers;
}

PaintDrawers& buildStrokePaintDrawers(node::NodeConstPtr node) {
  auto* shapeNode = node::node_cast<const node::DefaultShapeNode>(node);
  buildPaintDrawers(shapeNode->getStrokePaints());
  return paintDrawers;
}

} // namespace dea::render