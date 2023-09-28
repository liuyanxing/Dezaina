#pragma once

#include "base_type.h"
#include "node_type.h"

class ContainerNodeBase {
public:
	void appendChild(Node* node) { children.push_back(node); };
	const vector<Node*>& getChildren() const { return children; };
	
	// x, y is local coordinate
	void getNodesUnderPoint(float x, float y, vector<Node*>& nodes);
  void clear() { children.clear(); };
  void addChild(Node* node) { children.push_back(node); };
private:
  vector<Node*> children;
};
