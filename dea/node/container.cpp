#include "container.h"
#include "type.generated.h"

namespace dea::node {

bool Container::append(Node* child, Node* parent) {
	if (!parent || !child) {
		return false;
	}

	auto container = node_cast<Container>(parent);
	if (container) {
		container->appendChild(child);
		child->setParent(parent);
	}
	return true;

};

}


