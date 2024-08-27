#pragma once

#include "document/src/editor.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "node/rectangle.h"
#include "node/frame.h"
#include "node/container.h"
#include "node/src/container.h"
#include "node.h"
#include "listener.h"
#include "node/src/node-base/node.h"
#include <array>
#include <vector>

namespace dea::interaction {

class Desaina;

class NodeEditor : public InteractionListener {
public:
  NodeEditor(const SkMatrix& transform, const SkSize& size) {
    buildEditor();
    update(transform, size);
  }

  NodeEditor() {
    buildEditor();
  };

  NodeEditor(const node::NodeArary* nodes) : editNodes_(nodes), editor_(*nodes) {
    buildEditor();
  };

  virtual ~NodeEditor() {
    if (auto* parent = node::node_cast<node::Container*>(container_.getParent())) {
      parent->removeChild(&container_);
    }
  };

  Frame* getContainer() { return &container_; }
  virtual void update(const std::vector<node::Node*>& nodes) {};
  void update(const SkMatrix& transform, const SkSize& bound);
  void appendToContainer(node::Node* node) {
    appendChild(&container_, node);
  }

protected:
  Frame container_;
  Rectangle bound_ctrl_;
  std::array<Rectangle, 4> nodeResizeCtrls_;
  std::array<Rectangle, 4> nodeRotateCtrls_;
  std::vector<node::Node*> selectedNodes_;
  std::vector<node::Node*> getNodesWithRadius(const SkPoint& point, float radius);
  node::Node* hoverNode_ = nullptr;
  document::Editor editor_;
  const node::NodeArary* editNodes_;

  void buildEditor();
  SkRect caculateSelectionBound();
  void handleDragResizeCtrlNode(int index, event::MouseEvent &event);
  void handleDragRotateCtrlNode(int index, event::MouseEvent &event);
  void handleDragResizeCtrlEdge(event::MouseEvent &event);
  void onMouseMove(event::MouseEvent& event) override;
  void onMouseDown(event::MouseEvent& event) override;
  void onMouseDrag(event::MouseEvent& event) override;
};

}
