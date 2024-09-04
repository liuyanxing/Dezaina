#include "container.h"

namespace dea::node {

void Container::append(Node* child, Node* parent) {
	if (!parent || !child) {
		return;
	}

	auto container = node_cast<Container*>(parent);
	if (container) {
		container->appendChild(child);
	}

};

}


