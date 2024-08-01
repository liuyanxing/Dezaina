#include "util.h"
#include "include/core/SkCanvas.h"
#include "util/node_geometry.h"
#include "util/node_props.h"
#include "desaina.h"

void InteractionUtil::init() {
  int width = 2;
  int height = 2;

  int pixelLen = width * height * 4;
  pixes_ = (uint8_t*)malloc(pixelLen);
  SkImageInfo imageInfo =
      SkImageInfo::Make(width, height, SkColorType::kRGBA_8888_SkColorType,
                        SkAlphaType::kOpaque_SkAlphaType);
  int rowBytes = width * 4;
  read_color_surface_ = SkSurfaces::WrapPixels(imageInfo, pixes_, rowBytes, nullptr);
}

bool InteractionUtil::isCursorOnNodePixel(float x, float y, const Node* node) {
  SkPaint paint;
  paint.setColor(SK_ColorWHITE);
  return readColorAtPointOfNode(x, y, node, {paint}) != SK_ColorTRANSPARENT;
}

SkColor InteractionUtil::readColorAtPointOfNode(float x, float y, const Node* node, const vector<SkPaint>& paints) {
  auto geometryWithPaints = util::getFillGeometryWithPaints(node, desaina_);
  auto& path = geometryWithPaints.geometry[0];
  if (path.isEmpty()) {
    return SK_ColorTRANSPARENT;
  }
  auto matrix = util::getWorldMatrix(node, &desaina_->document);
  auto* canvas = read_color_surface_->getCanvas();
  canvas->clear(SK_ColorTRANSPARENT);
  SkAutoCanvasRestore acr(canvas, true);
  
  canvas->resetMatrix();
  canvas->translate(-x, -y);
  canvas->concat(matrix);
  
  for (const auto& paint : paints) {
    canvas->drawPath(path, paint);
  }
  return SkColorSetARGB(pixes_[3], pixes_[0], pixes_[1], pixes_[2]);
}

namespace interaction_util {

void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const SkRect& frame) {
  SkMatrix matrix;
  matrix.setTranslate(frame.left(), frame.top());
  auto const frameWidth = frame.width();
  auto const frameHeight = frame.height();
  const SkVector offsets[4] = {
    { -rects[0].get_size().x / 2, -rects[0].get_size().y / 2 },
    { frameWidth - rects[1].get_size().x / 2, -rects[1].get_size().y / 2 },
    { frameWidth - rects[2].get_size().x / 2, frameHeight - rects[2].get_size().y / 2 },
    { -rects[0].get_size().x / 2, frameHeight - rects[3].get_size().y / 2 }
  };

  for (int i = 0; i < 4; i++) {
    auto& offset = offsets[i];
    auto& rect = rects[i];
    matrix.setTranslate(offset.x(), offset.y());
    rect.set_transform(util::toMatrix(matrix));
  }
}

}
