// a member of container node
class HitTester {
public:
  virtual getChildContainsPoint(const SkPoint& point);
  virtual getChildIntersectWithRect(const SkRect& point);
  void updateChild(node* node);
  void update(std::vector<node*> nodes);
}