#pragma once

#include "event.h"
#include "event/listener.h"
#include "node/type.h"
#include "node/utility.h"
#include "selection.h"
#include "utility.h"

namespace dea::interaction {

class Interaction;

class MouseInteraction : public event::MouseListener,
                         public document::Listener {
public:
  MouseInteraction(Interaction &interaction);

  void onEvent(event::Event &e) {
    interSelection_.onEvent(e);
    docSelection_.onEvent(e);
    event::MouseListener::onEvent(e);
    document::Listener::onEvent(e);
  }

  auto *getHoverInterNode() { return interSelection_.getHoverNode(); }
  auto *getHoverDocNode() { return docSelection_.getHoverNode(); }

private:
  Selection docSelection_;
  Selection interSelection_;
  Interaction &interaction_;

  void onMouseMove(event::MouseEvent &event) override;
  void onMouseDrag(event::MouseEvent &event) override;
  void onPageChange(event::Event &event) override;
  void hanldeDragCreateNode(event::MouseEvent &event);

  void handleSelectionChange(const node::NodeConstArary &selection);
};

} // namespace dea::interaction
