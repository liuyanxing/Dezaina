#include "hit_tester.h"

class SimpleHitTester : public HitTester {
public:
  std::vector<HitTestNode*> getNodeContainsPoint(const SkPoint& point) override {
    std::vector<HitTestNode*> nodes;
    for (auto& node : nodes_) {
      if (node.area.contains(point)) {
        nodes.push_back(&node);
      }
    }
    return nodes;
  }

  std::vector<HitTestNode*> getNodesIntersectWithRect(const SkRect& rect) override {
    std::vector<HitTestNode*> nodes;
    for (auto& node : nodes_) {
      if (node.area.intersects(rect)) {
        nodes.push_back(&node);
      }
    }
    return nodes;
  }

  void insertNode(HitTestNode* node) override {
    nodes_.push_back(*node);
  }

  void deleteNode(HitTestNode* node) override {
    for (auto iter = nodes_.begin(); iter != nodes_.end(); iter++) {
      if (iter->index == node->index) {
        nodes_.erase(iter);
        break;
      }
    }
  }

private:
  std::vector<HitTestNode> nodes_;
};