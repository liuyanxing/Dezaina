#include "desaina_node.h"

class Node : public BaseNodeMixin {
public:
  Node(const GUID &id, const string &name) : BaseNodeMixin() {}
  Node(const Node &other) : BaseNodeMixin(other) {}
  Node(Node &&other) : BaseNodeMixin(std::move(other)) {}
  Node &operator=(const Node &other) {
    BaseNodeMixin::operator=(other);
    return *this;
  }
  Node &operator=(Node &&other) {
    BaseNodeMixin::operator=(std::move(other));
    return *this;
  }
  virtual ~Node() {}
};
