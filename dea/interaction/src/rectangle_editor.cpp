#include "rectangle_editor.h"
#include "include/private/base/SkPoint_impl.h"
#include "node/rectangle.h"
#include "dezaina.h"
#include <cassert>

namespace dea::interaction {

using namespace node;

RectangleEditor::RectangleEditor(node::RectangleNode* node) : node_(node), NodeEditor() {
    auto& doc = Dezaina::instance().getDocument();
    NodeEditor::update(utility::getTransfromMatrix(node), utility::getScreenSize(node));
    
    buildEditor();
}

void RectangleEditor::buildEditor() {
  SkVector moveAxises[4] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
  for (int i = 0; i < 4; i++) {
    SkVector::Normalize(&moveAxises[i]);
    auto& ctrl = cornerSizeCtrls_[i];
    ctrl.setSize({20, 20});
    ctrl.addEventListener(event::EventType::MouseDrag, [this, i, moveAxises](event::Event &event) {
      handleDragResizeCornerCtrl(i, moveAxises[i], static_cast<event::MouseEvent&>(event));
    });
    appendToContainer(&ctrl);
  }
}

void RectangleEditor::handleDragResizeCornerCtrl(int index, const SkVector& moveAxis, event::MouseEvent &event) {
  auto delta = moveAxis.cross({event.dx, event.dy});
  // auto* editor = desaina_->getEditor();
  // editor->resizeCornerRadius(delta);
}

void RectangleEditor::update(const std::vector<Node*> &nodes) {
  if (nodes.size() != 1) {
    assert(false);
  }
  RectangleNode* node = node::node_cast<RectangleNode*>(nodes[0]); 
  NodeEditor::update(nodes);
}

}
