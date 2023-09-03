#pragma once

#include <vector>
#include "include/core/SkRect.h"
struct HitTestNode {
  SkRect bound;
  static HitTestNode Make(const SkRect& rect) {
    HitTestNode node;
    node.bound = rect;
    return node;
  }
};

class HitTester {
public:
  virtual ~HitTester() = default;
  virtual HitTestNode* getNodeUnderPoint(float x, float y) = 0;
  virtual std::vector<HitTestNode*> getNodesIntersectWithRect(const SkRect& point) = 0;
  virtual void insert(HitTestNode* node) = 0;
  virtual void clear() = 0;
}; 
