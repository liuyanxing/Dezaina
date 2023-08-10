#pragma once

#include "base_type.h"

class ContainerNodeBase {
public:
	void appendChild(BaseNodeMixin* node);
	vector<Node*>& getChildren() { return children; };
private:
  vector<Node*> children;
};
