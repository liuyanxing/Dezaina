#pragma once

#include "event_handler.h"
#include "event_system/event.h"
#include "event_system/mouse_event.h"

class EditModeEventHandler : public EventHandler {
public:
  void onMouseMove(const MouseEvent *event) override {
    if (dragStartEvent_.has_value()) {
      onMouseDrag(event);
      return;
    }
    const auto* target = event->target;
    if (target->isPage()) {
      return;
    }
    const auto* root_container = util::getRootContainer(target);
    const auto* parent = target->parent();

    if (root_container->isPage()) {
      if (!target->isFrame()) {
        document_->setHoverNode(target);
        return;
      }
      if (event->local_x < 0) {
        document_->setHoverNode(target);
      }
      return;
    }
    
    if (root_container == parent) {
      document_->setHoverNode(target);
      return;
    }

    const auto* ancestor = util::getAncestorInContainer(target, root_container);
    document_->setHoverNode(ancestor);
  }

  void onMouseDown(const MouseEvent *event) override {
    auto* target = document_->getHoverNode(); 
    if (!target) {
      dragStartEvent_ = *event;
      return;
    }
    document_->addSelectedNode(target);
  }

  void onMouseDrag(const MouseEvent* event) {
  }

  void onMouseUp(const MouseEvent *event) override {
    dragStartEvent_ = std::nullopt;
  }
};