#pragma once

#include <functional>
#include <vector>
#include "event.h"
#include "include/core/SkPoint.h"
#include "mouse_event.h"
#include "hit_tester.h"
#include "simple_hit_tester.h"

class MouseEventEmmiter {
public:
  void dispatchEvent(MouseEvent event) {
    auto* node = hitTester_.getNodeContainsPoint(SkPoint::Make(0, 0));
    if (event.type == EventType::kMouseDown) {
      nodeOnMouseDown_ = node;
      for (const auto& listener : listeners_) {
        if (listener.type == EventType::kMouseDown) {
          listener.func(event);
        }
      }
    }
  }

  void addEventListener(EventType type, const std::function<void(const Event& event)>& func) {
    listeners_.emplace_back(type, func);
  }

  void addHitTestNode(HitTestNode* node) {
    hitTester_.insertNode(node);
  }

  void buildHitTester(const std::vector<HitTestNode*>& nodes) {
    hitTester_.build(nodes);
  }

private:
  SimpleHitTester hitTester_;
  HitTestNode* nodeOnMouseDown_ = nullptr;
  std::vector<EventListener> listeners_;
};