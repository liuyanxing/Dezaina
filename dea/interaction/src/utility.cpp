#include "dezaina.h"
#include "geometry/geometry.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkSurface.h"

#include "node.h"
#include "document.h"
#include "node/rectangle.h"

namespace dea::interaction {

using namespace node;

static sk_sp<SkSurface> readColorSurface = nullptr;

constexpr int width = 2;
constexpr int height = 2;
constexpr int pixelLen = width * height * 4;
static auto* pixes = (uint8_t*)malloc(pixelLen);

void initSurface() {
  SkImageInfo imageInfo =
      SkImageInfo::Make(width, height, SkColorType::kRGBA_8888_SkColorType,
                        SkAlphaType::kOpaque_SkAlphaType);
  int rowBytes = width * 4;
  readColorSurface = SkSurfaces::WrapPixels(imageInfo, pixes, rowBytes, nullptr);
}

SkColor readColorAtPointOfNode(float x, float y, Node* node, const std::vector<SkPaint>& paints) {
  auto geometry = geometry::getOrBuildFill(node);
  if (geometry.isEmpty()) {
    return SK_ColorTRANSPARENT;
  }
  auto matrix = utility::getWorldMatrix(node);
  if (!readColorSurface) {
    initSurface();
  }

  auto* canvas = readColorSurface->getCanvas();
  canvas->clear(SK_ColorTRANSPARENT);
  SkAutoCanvasRestore acr(canvas, true);
  
  canvas->resetMatrix();
  canvas->translate(-x, -y);
  canvas->concat(matrix);
  
  for (const auto& paint : paints) {
    canvas->drawPath(geometry, paint);
  }
  return SkColorSetARGB(pixes[3], pixes[0], pixes[1], pixes[2]);
}

bool isCursorOnNodePixel(float x, float y, Node* node) {
  SkPaint paint;
  paint.setColor(SK_ColorWHITE);
  return readColorAtPointOfNode(x, y, node, {paint}) != SK_ColorTRANSPARENT;
}

void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const SkRect& frame) {
  // SkMatrix matrix;
  // matrix.setTranslate(frame.left(), frame.top());
  // auto const frameWidth = frame.width();
  // auto const frameHeight = frame.height();
  // const SkVector offsets[4] = {
  //   { -rects[0].get_size().x / 2, -rects[0].get_size().y / 2 },
  //   { frameWidth - rects[1].get_size().x / 2, -rects[1].get_size().y / 2 },
  //   { frameWidth - rects[2].get_size().x / 2, frameHeight - rects[2].get_size().y / 2 },
  //   { -rects[0].get_size().x / 2, frameHeight - rects[3].get_size().y / 2 }
  // };

  // for (int i = 0; i < 4; i++) {
  //   auto& offset = offsets[i];
  //   auto& rect = rects[i];
  //   matrix.setTranslate(offset.x(), offset.y());
  //   rect.set_transform(util::toMatrix(matrix));
  // }
}

}