#include "bound_editor.h"
#include "UI/ui.h"
#include "config/size.h"
#include "document.h"
#include "layout.h"
#include "layout/constraint_layout.h"
#include "node/node_base.generated.h"
#include "node/rectangle.h"
#include "event.h"
#include "node/utility.h"
#include <array>

namespace dea::interaction {

using namespace node;
using namespace event;
using namespace ui;

void BoundEditor::initCtrls() {
  float edgeSize = 100;
  Vector size{edgeSize, edgeSize};
  container_.setSize(size);
  container_.setName("bound");

  SolidPaint strokePaint;
  auto &[r, g, b, a] = config::color::Primary;
  strokePaint.setColor({r, g, b, a});

  translateCtrl_.setName("bt");
  translateCtrl_.setSize(size);
  translateCtrl_.setVerticalConstraint(ConstraintType::SCALE);
  translateCtrl_.setHorizontalConstraint(ConstraintType::SCALE);
  translateCtrl_.setStrokePaints({strokePaint});
  translateCtrl_.setStrokeWeight(config::size::Min);
  appendToContainer(&translateCtrl_);

  auto nodeD = config::size::Small;
  auto nodeR = nodeD / 2;
  auto offset = nodeR;

  base::v4<base::v2<node::ConstraintType>> edgeConstraints = {{
      {node::ConstraintType::STRETCH, node::ConstraintType::MIN},
      {node::ConstraintType::MAX, node::ConstraintType::STRETCH},
      {node::ConstraintType::STRETCH, node::ConstraintType::MAX},
      {node::ConstraintType::MIN, node::ConstraintType::STRETCH},
  }};
  std::array<Vector, 4> edgeTranslate = {{{offset, -0.5f},
                                       {edgeSize - 0.5f, offset},
                                       {offset, edgeSize - 0.5f},
                                       {-0.5, offset}}};
  auto edgeS = edgeSize - nodeD;
  std::array<Vector, 4> sizes = {
      {{edgeS, 1}, {1, edgeS}, {edgeS, 1}, {1, edgeS}}};
  for (int i = 0; i < resizeEdgeCtrls_.size(); i++) {
    auto &ctrl = resizeEdgeCtrls_[i];
    ctrl.setName("be" + std::to_string(i));
    ctrl.setTransform(Matrix().translate(edgeTranslate[i].x, edgeTranslate[i].y));
    ctrl.setSize(sizes[i]);
    ctrl.setHorizontalConstraint(edgeConstraints[i][0]);
    ctrl.setVerticalConstraint(edgeConstraints[i][1]);
    appendToContainer(&ctrl);
  }

  SolidPaint fillPaint;
  fillPaint.setColor({1, 1, 1, 1});
  std::array<std::array<node::ConstraintType, 2>, 4> constraints = {{
      {node::ConstraintType::MIN, node::ConstraintType::MIN},
      {node::ConstraintType::MAX, node::ConstraintType::MIN},
      {node::ConstraintType::MAX, node::ConstraintType::MAX},
      {node::ConstraintType::MIN, node::ConstraintType::MAX},
  }};

  std::array<Vector, 4> rotateTranslate = {{{-offset * 3, -offset * 3},
                                       {offset + edgeSize, -offset * 3},
                                       {offset + edgeSize, offset + edgeSize},
                                       {-offset * 3, offset + edgeSize}}};
  for (int i = 0; i < 4; i++) {
    auto &rotateCtrl = rotateCtrls_[i];
    rotateCtrl.setName("br" + std::to_string(i));
    rotateCtrl.setTransform(
        Matrix().translate(rotateTranslate[i].x, rotateTranslate[i].y));
    rotateCtrl.setHorizontalConstraint(constraints[i][0]);
    rotateCtrl.setVerticalConstraint(constraints[i][1]);
    rotateCtrl.setSize({config::size::Small, config::size::Small});
    appendToContainer(&rotateCtrl);
  }

  base::v4<Vector> resizeTranslate = {{{-offset, -offset},
                                       {-offset + edgeSize, -offset},
                                       {-offset + edgeSize, -offset + edgeSize},
                                       {-offset, -offset + edgeSize}}};
  for (int i = 0; i < 4; i++) {
    auto &resizectrl = resizeNodeCtrls_[i];
    resizectrl.setName("bs" + std::to_string(i));
    resizectrl.setTransform(
        Matrix().translate(resizeTranslate[i].x, resizeTranslate[i].y));
    resizectrl.setHorizontalConstraint(constraints[i][0]);
    resizectrl.setVerticalConstraint(constraints[i][1]);
    resizectrl.setFillPaints({fillPaint});
    resizectrl.setStrokePaints({strokePaint});
    resizectrl.setStrokeWeight(config::size::Min);
    resizectrl.setSize({config::size::Small, config::size::Small});
    appendToContainer(&resizectrl);
  }
}

void BoundEditor::bindEvents() {
  translateCtrl_.addEventListener(EventType::MouseMove, [this](Event &e) {
    UI::setCursor(CursorType::Default);
  });
  translateCtrl_.addEventListener(EventType::MouseDrag, [this](Event &e) {
    UI::setCursor(CursorType::Handle);
    auto &event = static_cast<MouseEvent &>(e);
    editor_.translate({event.localWorldDx, event.localWorldDy});
  });

  for (int i = 0; i < 4; i++) {
    auto &resizeCtrl = resizeNodeCtrls_[i];
    resizeCtrl.addEventListener(EventType::MouseMove, [this, i](Event &e) {
      if (i == 0 || i == 2) {
        UI::setCursor(CursorType::SIZENWSE);
      } else {
        UI::setCursor(CursorType::SIZENESW);
      }
    });
    resizeCtrl.addEventListener(EventType::MouseDrag, [this, i](Event &e) {
      const std::array<node::Vector, 4> directions = {
          {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}}};
      auto &event = static_cast<MouseEvent &>(e);
      auto direction = directions[i];
      auto d = direction * node::Vector{event.localWorldDx, event.localWorldDy};
      editor_.resize(d.x, d.y, directions[i]);
    });

    auto &edgeCtrl = resizeEdgeCtrls_[i];
    edgeCtrl.addEventListener(EventType::MouseMove, [this, i](Event &e) {
      if (i == 0 || i == 2) {
        UI::setCursor(CursorType::SIZENS);
      } else {
        UI::setCursor(CursorType::SIZEWE);
      }
    });
    edgeCtrl.addEventListener(EventType::MouseDrag, [this, i](Event &e) {
      const std::array<node::Vector, 4> directions = {
          {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}};
      auto &event = static_cast<MouseEvent &>(e);
      auto direction = directions[i];
      auto d = direction * node::Vector{event.localWorldDx, event.localWorldDy};
      editor_.resize(d.x, d.y, directions[i]);
    });

    auto &rotateCtrl = rotateCtrls_[i];
    rotateCtrl.addEventListener(EventType::MouseMove, [this, i](Event &e) {
      UI::setCursor(CursorType::Handle);
    });
    rotateCtrl.addEventListener(EventType::MouseDrag, [this, i](Event& e) {
        auto& event = static_cast<MouseEvent&>(e);
        auto center = getNodeCenter(&translateCtrl_);
        auto v1 = Vector{event.worldX, event.worldY} - center;
        auto v2 = Vector{ event.worldX - event.worldDx , event.worldY - event.worldDy } - center;
        auto angle = v1.angle(v2);
        editor_.rotate(angle);
    });
  }
}

void BoundEditor::buildEditor() {
  initCtrls();
  bindEvents();
}

void BoundEditor::update() {
  auto size = getSize(container_.getParent());
  auto transform = getTransfromMatrix(container_.getParent());
  layout::ContraintLayout::layoutCild(&container_, size);
  container_.setTransform(transform);
  container_.setSize(size);
}

} // namespace dea::interaction
