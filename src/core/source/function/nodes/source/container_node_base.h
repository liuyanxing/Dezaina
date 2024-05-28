#pragma once

#include "base_type.h"
#include "node_type.h"

class ContainerNodeBase {
public:
	void appendChild(Node* node) { children.push_back(node); };
	const vector<Node*>& getChildren() const { return children; };
  bool findChild(Node* node) { return std::find(children.begin(), children.end(), node) != children.end(); };
  void removeChild(Node* node) { children.erase(std::remove(children.begin(), children.end(), node), children.end()); };
	
	// x, y is local coordinate
	void getNodesUnderPoint(float x, float y, vector<Node*>& nodes);
  void clear() { children.clear(); };
  void addChild(Node* node) { children.push_back(node); };
private:
  vector<Node*> children;
};
