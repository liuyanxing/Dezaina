#pragma once

#include "base_type.h"
#include "node_type.h"

class ContainerNodeBase {
public:
	void appendChild(Node* node) { children.push_back(node); };
	const vector<Node*>& getChildren() const { return children; };
private:
  vector<Node*> children;
};
