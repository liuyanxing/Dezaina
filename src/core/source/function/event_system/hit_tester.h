// a member of container node
#include <vector>
struct HitTestNode {
  int index = 0;
  SkRect area;
  static HitTestNode Make(int index, const SkRect& area) {
    HitTestNode node;
    node.index = index;
    node.area = area;
    return node;
  }
};

class HitTester {
public:
  virtual std::vector<HitTestNode*> getNodeContainsPoint(const SkPoint& point) = 0;
  virtual std::vector<HitTestNode*> getNodesIntersectWithRect(const SkRect& point) = 0;
  virtual void insertNode(HitTestNode* node) = 0;
  virtual void deleteNode(HitTestNode* node) = 0;
}; 