// a member of container node
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
  virtual getChildContainsPoint(const SkPoint& point);
  virtual getChildIntersectWithRect(const SkRect& point);
  void updateChild(node* node);
  void update(std::vector<node*> nodes);
}; 