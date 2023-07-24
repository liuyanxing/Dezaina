#pragma once

#include "hit_tester.h"

class SimpleHitTester : public HitTester {
public:
  HitTestNode* getNodeContainsPoint(const SkPoint& point) override {
    std::vector<HitTestNode*> nodes;
    for (auto& node : nodes_) {
      if (node.area.contains(point.x(), point.y())) {
        return &node;
      }
    }
    return nullptr;
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


  void build(const std::vector<HitTestNode*>& nodes) {
    nodes_.clear();
    for (auto& node : nodes) {
      nodes_.push_back(*node);
    }
  }

private:
  std::vector<HitTestNode> nodes_;
};