#include "event.h"
#include <functional>
#include <vector>

class MouseEventEmmiter {
public:
  void dispatchEvent(MouseEvent event) {
    auto* node = hitTester_.getNodeContainsPoint(SkPoint::Make(0, 0));
    if (event.type == MouseDown) {
      nodeOnMouseDown_ = node;
      for (const auto& listener : mouseDownEventListeners_) {
        listener(event);
      }
    }
  }

  template<typename T>
  void addEventListener() {}

  template<>
  void addEventListener<MouseEvent>(std::function<void(MouseEvent)> func) {
    mouseEventListeners_.push_back(func);
  }

  void addHitTestNode(HitTestNode* node) {
    hitTester_.add(node);
  }

  void buildHitTester(const std::vector<HitTestNode*>& nodes) {
    hitTester_.build(nodes);
  }

private:
  SimpleHitTester hitTester_;
  HitTestNode* nodeOnMouseDown_ = nullptr;
  std::vector<std::function<void(MouseEvent)>> mouseDownEventListeners_;
  std::vector<std::function<void(MouseEvent)>> mouseUpEventListeners_;
  std::vector<std::function<void(MouseEvent)>> mouseMoveEventListeners_;
  std::vector<std::function<void(MouseEvent)>> mouseDragEventListeners_;
};