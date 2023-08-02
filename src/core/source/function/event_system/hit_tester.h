#pragma once

#include <vector>
#include "include/core/SkRect.h"
struct HitTestNode {
  SkRect rect;
  static HitTestNode Make(const SkRect& rect) {
    HitTestNode node;
    node.rect = rect;
    return node;
  }
};

class HitTester {
public:
  virtual HitTestNode* getNodeContainsPoint(const SkPoint& point) = 0;
  virtual std::vector<HitTestNode*> getNodesIntersectWithRect(const SkRect& point) = 0;
  virtual void insertNode(HitTestNode* node) = 0;
  virtual void deleteNode(HitTestNode* node) = 0;
}; 