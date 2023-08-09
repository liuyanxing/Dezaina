#include "base_type.h"

class BaseNodeMixin;

struct ContainerNodeBase {
	vector<BaseNodeMixin*> children;
	vector<BaseNodeMixin*>* getChildren() { return &children; };
	void appendChild(BaseNodeMixin* node);
};
