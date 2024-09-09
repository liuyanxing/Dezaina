#include <iostream>
#include "dezaina.h"
#include "node.h"
#include "node/node.generated.h"

using namespace std;
using namespace dea;
using namespace event;
using namespace node;

int main(int argc, char** argv) {
	auto& deza = Dezaina::instance();
	auto width = 1280, height = 720;
	deza.setViewport(width, height, 1);
	deza.loadEmptyDocument();
	auto &doc = deza.document();
	auto* rect = doc.createNode<node::RectangleNode>(doc.currentPage());
	rect->setSize({100, 100});
	deza.dispatchMouseEvent(width / 2 + 1, height / 2 + 1, EventType::MouseMove, 0, 0);
	deza.dispatchMouseEvent(width / 2 + 1, height / 2 + 1, EventType::MouseDown, 0, 0);
	deza.tick();
	std::cout << "selection size: " << doc.getSelection().size() << std::endl;
	return 0;
}