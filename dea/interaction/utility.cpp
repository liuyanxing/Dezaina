#include "dezaina.h"
#include "event/ui_event.h"
#include "node.h"
#include "document.h"
#include "node/rectangle.h"
#include "event.h"

namespace dea::interaction {

using namespace node;

void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const Rect& frame) {
  // node::Matrix matrix;
  // matrix.setTranslate(frame.left(), frame.top());
  // auto const frameWidth = frame.width();
  // auto const frameHeight = frame.height();
  // const node::Vector offsets[4] = {
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


node::Vector getEventLocalPosition(const event::UIEvent& event, const node::NodeIterWithWorldMatrix& iter) {
  auto& viewport = Dezaina::instance().getViewport();
  auto matrix = viewport.getVPMatrix() * iter.getWorldMatrix();
  auto worldLocal = matrix.getInverse().value_or(Matrix{}).mapPoint({event.x, event.y});
  return {viewport.mapWorldToScreen(worldLocal.x), viewport.mapWorldToScreen(worldLocal.y)};
}

}