#include "mouse_interaction.h"
#include "dezaina.h"
#include "interaction.h"
#include "interaction/bound_editor.h"

namespace dea::interaction {
MouseInteraction::MouseInteraction(Interaction &inter)
    : docSelection_(inter.getDocSelection(), nullptr,
                    Interaction::GetDocNodeScreenBound),
      interSelection_(inter.getInterSelection(), inter.getInterPage()),
      interaction_(inter) {
  docSelection_.onSelectionChange([this](const node::NodeConstArary &nodes) {
    handleSelectionChange(nodes);
  });

  docSelection_.onHover([this](node::NodeConstPtr node) {
    interaction_.status.hoverDocNode = node;
  });

  // frame cannot be selected, it acts as a container
  interSelection_.setMouseHoverFilter([this](node::NodeConstPtr node) {
    return !interaction::node_cast<Frame>(node);
  });


}

void MouseInteraction::onMouseMove(event::MouseEvent &event) {
  auto *node = interSelection_.getHoverNode();
  if (!node || node::node_cast<node::PageNode>(node))
    return;
  auto *emitter = interaction::node_cast<event::EventEmitter>(node);
  emitter->emit(event);
}

void MouseInteraction::onMouseDrag(event::MouseEvent &event) {
  setEventLocalPosition(event, node::NodeIterWithWorldMatrix(event.target));

  if (auto *creatingNode = interaction_.getCreatingNode()) {
    hanldeDragCreateNode(event);
    return;
  }

  if (interSelection_.empty()) {
    return;
  }
  for (auto *node : interSelection_.getSelection()) {
    auto *emitter = interaction::node_cast<event::EventEmitter>(node);
    emitter->emit(event);
  }
}

void MouseInteraction::onPageChange(event::Event &event) {
  docSelection_.setRoot(Dezaina::instance().document().currentPage());
}

void MouseInteraction::handleSelectionChange(
    const node::NodeConstArary &selection) {
  if (selection.empty()) {
    return;
  }

  node::NodeIdArray ids;
  for (auto *node : selection) {
    ids.push_back(node->getGuid());
  }
  Dezaina::editor().select(ids);
}

void MouseInteraction::hanldeDragCreateNode(event::MouseEvent &event) {
  auto dx = event.x - event.dragStartX, dy = event.y - event.dragStartY;
  if (dx > 6 && dy > 6) {
    auto &document = Dezaina::document();
    auto &editor = document.editor();
    auto *node = interaction_.getCreatingNode();
    editor.create(node);
    document.append(node, event.target);
    auto size = Dezaina::instance().viewport().getWorldSize({dx, dy});
    auto pos = node::Vector{event.localWorldX, event.localWorldY};
    editor.setSize(size, {0, 0});
    editor.setTranslate(pos - size);
    editor.appendSolidPaint({1, 1, 1, 1});
    interaction_.endCreateNode();
  }
}

} // namespace dea::interaction
