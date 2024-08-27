#include "node_editor.h"
#include "config/size.h"
#include "event/src/primitives.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "node/rectangle.h"
#include "node/type.h"
#include "utility.h"
#include "config/config.h"

namespace dea::interaction {

using namespace node;
using namespace event;

std::vector<node::Node*> NodeEditor::getNodesWithRadius(const SkPoint& point, float radius) {
  std::vector<node::Node*> nodes;
  IterWithWorldMatrix iter{container_};
  while (iter.valid()) {
    if (iter->getBounds().contains(point)) {
      nodes.push_back(iter->getNode());
    }
    ++iter;
  }
  return nodes;
}

void NodeEditor::onMouseMove(MouseEvent& event) {
  auto nodes = getNodesWithRadius({event.worldX, event.worldY}, 6);
  if (nodes.empty()) {
    hoverNode_ = nullptr;
    return;
  }
  hoverNode_ = nodes.front();
}


void NodeEditor::onMouseDown(event::MouseEvent& event) {
  selectedNodes_.clear();
  if (hoverNode_) {
    selectedNodes_.push_back(hoverNode_);
  }
}

void NodeEditor::onMouseDrag(event::MouseEvent& event) {
  if (selectedNodes_.empty()) {
    return;
  }
  for (auto* node : selectedNodes_) {
    if (auto* emitter = interaction::node_cast<EventEmitter*>(node)) {
      emitter->emit(event);
    }
  }
}

void NodeEditor::handleDragResizeCtrlNode(int index, event::MouseEvent& event) {
  // if (desaina_->document.getSelectedNodes().size() == 1) {
  //   const std::array<SkVector, 4> directions = {{ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } } };
  //   const std::array<SkPoint, 4> anchors = {{ { 1, 1 }, { 0, 1 }, { 0, 0 }, { 1, 0 } } };
  //   auto [dx, dy] = SkVector{event->deltaX, event->deltaY} * directions[index];
  //   desaina_->getEditor()->resize(dx, dy, anchors[index]);
  // } else {
  //   // todo 处理选中多个图层
  // }

}

void NodeEditor::handleDragResizeCtrlEdge(event::MouseEvent& event) {
  // const auto& transform = bound_ctrl_.get_transform();
  // const auto [x, y] = base::mapPointToLocal({event->clientX, event->clientY}, util::toSkMatrix(transform));
  // const auto [width, height] = bound_ctrl_.get_size();
  // int index = 0;
  // auto pointerRadius = config::pointerRadius;
  // if (x > width - pointerRadius) {
  //   index = 1;
  // } else if (y > height - pointerRadius) {
  //   index = 2;
  // } else if (x < pointerRadius) {
  //   index = 3;
  // }

  // if (desaina_->document.getSelectedNodes().size() == 1) {
  // } else {
  //   // todo 处理选中多个图层
  // }
}

void NodeEditor::buildEditor() {
    SolidPaint strokePaint;
    auto& [r, g, b, a] = config::color::Primary;
    strokePaint.setColor({r, g, b, a});
    container_.setStrokePaints({strokePaint});
    container_.setStrokeWeight(config::size::Min);
    container_.addEventListener(EventType::MouseDrag, [this](Event& event) {
      // todo: handleDragMoveNode(static_cast<MouseEvent*>(event));
    });

    bound_ctrl_.setStrokePaints({strokePaint});
    bound_ctrl_.setStrokeWeight(config::size::Min);
    bound_ctrl_.addEventListener(EventType::MouseDrag, [this](Event& event) {
      handleDragResizeCtrlEdge(static_cast<MouseEvent&>(event));
    });
    appendToContainer(&bound_ctrl_);

    int nodeIndex = 0;

    SolidPaint fillPaint;
    fillPaint.setColor({1, 1, 1, 1});
    for (auto& ctrl : nodeResizeCtrls_) {
      ctrl.setFillPaints({fillPaint});
      ctrl.setStrokePaints({strokePaint});
      ctrl.setStrokeWeight(config::size::Min);
      ctrl.setSize({config::size::Small, config::size::Small});
      ctrl.addEventListener(EventType::MouseDrag, [this, nodeIndex](Event& event) {
        handleDragResizeCtrlNode(nodeIndex, static_cast<MouseEvent&>(event));        
      });
      nodeIndex++;
      // appendToContainer(&ctrl);
    }

    nodeIndex = 0;
    for (auto& ctrl : nodeRotateCtrls_) {
      ctrl.setSize({config::size::Small, config::size::Small});
      ctrl.addEventListener(EventType::MouseDrag, [this, nodeIndex](Event& event) {
        // handleDragRotateCtrlNode(nodeIndex, static_cast<MouseEvent*>(event));
      });
      nodeIndex++;
    }
}

void NodeEditor::update(const SkMatrix& transform, const SkSize& size) {
  container_.setTransform(utility::toMatrix(transform));
  container_.setSize({size.width(), size.height()});
  bound_ctrl_.setSize({size.width(), size.height()});
  SkRect bound = SkRect::MakeWH(size.width(), size.height()); 
  layoutRectsToCornersOfRect(nodeResizeCtrls_, bound.makeOutset(2, 2));
  layoutRectsToCornersOfRect(nodeRotateCtrls_, bound.makeOutset(6, 6));
}

}