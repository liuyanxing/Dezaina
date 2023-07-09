#include "RtreeHitester"

class ContainerMixin {
public:
  std::vector<Node*> children;
  void appendChild(BaseNodeMixin* node) { children.push_back(node); }
private:
  RtreeHitester hit_tester_; 
}