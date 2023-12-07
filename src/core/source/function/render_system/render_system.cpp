#include "render_system.h"
#include "base_type.h"
#include "event_system/event.h"
#include "event_system/ui_event.h"
#include "canvas.h"
#include "desaina.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "util/node_props.h"
#include "util/node_geometry.h"
#include "include/gpu/ganesh/SkSurfaceGanesh.h"
#include "include/core/SkSurface.h"
#include "include/gpu/GrDirectContext.h"

RenderSystem::RenderSystem(Desaina* desaina) : desaina_(desaina), canvas_(desaina) {
  bindEvents();
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

void RenderSystem::bindEvents() {
  addEventListener(EventType::kWindowResize, [this](const Event* event) {
    const auto& [width, height, devicePixelRatio] = desaina_->getWindowInfo();
    canvas_.onWindowResize(width, height, devicePixelRatio);
  });
}

SkColor RenderSystem::readColorAtPointOfNode(const Node* node, float x, float y, const vector<SkPaint>& paints) {
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
