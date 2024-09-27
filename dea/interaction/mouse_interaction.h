#pragma once

#include "event.h"
#include "node/type.h"
#include "node/utility.h"
#include "selection.h"
#include "utility.h"

namespace dea::interaction {

class MouseInteraction : public InteractionListener {
public:
  MouseInteraction(node::NodeConstPtr root, const GetIntersectBound& getInterBound = DefaultGetIntersectBound) : selection_(root, getInterBound) {}
  void onEvent(event::Event &e) override {
    selection_.onEvent(e);
    InteractionListener::onEvent(e);
  }

  auto *getHoverNode() { return selection_.getHoverNode(); }

private:
  Selection selection_;
  node::NodeConstPtr root_;
  void onMouseMove(event::MouseEvent &event) override {
    if (!event.target) {
      return;
    }
    auto *emitter = interaction::node_cast<event::EventEmitter>(event.target);
    emitter->emit(event);
  }
  void onMouseDrag(event::MouseEvent &event) override {
    if (selection_.empty()) {
      return;
    }
    setEventLocalPosition(event, node::NodeIterWithWorldMatrix(event.target));
    for (auto *node : selection_.getSelection()) {
      auto *emitter = interaction::node_cast<event::EventEmitter>(node);
      emitter->emit(event);
    }
  }
};

} // namespace dea::interaction
