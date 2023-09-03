#pragma once

#include "hit_tester.h"

class SimpleHitTester : public HitTester {
public:
  HitTestNode* getNodeUnderPoint(float x, float y) override {
    std::vector<HitTestNode*> nodes;
    for (auto& node : nodes_) {
      if (node.rect.contains(x, y)) {
        return &node;
      }
    }
    return nullptr;
  }

  std::vector<HitTestNode*> getNodesIntersectWithRect(const SkRect& rect) override {
    std::vector<HitTestNode*> nodes;
    for (auto& node : nodes_) {
      if (node.rect.intersects(rect)) {
        nodes.push_back(&node);
      }
    }
    return nodes;
  }

  void insertNode(HitTestNode* node) override {
    nodes_.push_back(*node);
  }

  void deleteNode(HitTestNode* node) override {
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
