#pragma once
#include <vector>
#include "node.h"

namespace dea::node {

class Container {
public:
	void appendChild(Node* node) { children_.push_back(node); };
	const std::vector<Node*>& getChildren() const { return children_; };
  bool findChild(Node* node) { return std::find(children_.begin(), children_.end(), node) != children_.end(); };
  void removeChild(Node* node) { children_.erase(std::remove(children_.begin(), children_.end(), node), children_.end()); };
	
  void clear() { children_.clear(); };
  void addChild(Node* node) { children_.push_back(node); };
protected:
  std::vector<Node*> children_;
};

} // namespace dea::node
