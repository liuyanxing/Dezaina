#pragma once

#include "UI/ui.h"
#include "listener.h"
#include "mouse_interaction.h"
#include "node.h"
#include "node/container.h"
#include "node/frame.h"
#include "node/rectangle.h"
#include "utility.h"
#include <array>
#include <vector>

namespace dea::interaction {

class Desaina;

class NodeEditor {
public:
  NodeEditor(const node::NodeArary &nodes)
      : editNodes_(nodes), editor_(nodes),
        selection_(
            [&](node::Vector size) { return node::Size{size.x, size.y}; },
            IterWithWorldMatrix{&container_}) {
    buildEditor();
  };

  virtual ~NodeEditor() {
    if (auto *parent =
            node::node_cast<node::Container>(container_.getParent())) {
      parent->removeChild(&container_);
    }
  };

  Frame *getContainer() { return &container_; }
  auto getFirstNode() { return editNodes_[0]; }
  auto *getHoverNode() { return selection_.getHoverNode(); }

  virtual void update(const std::vector<node::Node *> &nodes) {};
  void update();
  void appendToContainer(node::Node *node) { appendChild(&container_, node); }

  void onEvent(event::Event &event) {
    mouseInteraction_.onEvent(event);
    if (event.target) {
      event.stop();
    } else if (event.type == event::EventType::MouseMove) {
      ui::UI::setCursor(ui::CursorType::Default);
    }
  }

  auto &getEditNodes() { return editNodes_; }

protected:
  Frame container_;
  Rectangle translateCtrl_;
  std::array<Rectangle, 4> resizeNodeCtrls_;
  std::array<Rectangle, 4> resizeEdgeCtrls_;
  std::array<Rectangle, 4> rotateCtrls_;
  document::Editor editor_;
  const node::NodeArary editNodes_;
  Selection selection_;
  MouseInteraction mouseInteraction_{selection_};

  void initCtrls();
  void bindEvents();
  void buildEditor();
  void handleDragRotateCtrlNode(int index, event::MouseEvent &event);
  void handleDragResizeCtrlEdge(event::MouseEvent &event);
};

} // namespace dea::interaction
