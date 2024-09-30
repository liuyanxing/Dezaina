#include <gtest/gtest.h>
#include "dezaina.h"
#include "event/mouse.h"

// The purpose of these tests are just to  make sure that gtest was properly installed.

using namespace dea::document;
using namespace dea::node;
using namespace dea::event;

auto& deza = dea::Dezaina::instance();
auto& viewport = deza.viewport();
auto& doc = deza.document();
auto& inter = deza.interaction();

const uint32_t width = 1280;
const uint32_t height = 720;

void init() {
	deza.setImmediate(true);
	deza.setViewport(width, height, 1);
	deza.loadEmptyDocument();
	auto* rect = doc.createNode<RectangleNode>(doc.currentPage());
	rect->setSize({100, 100});
}

TEST(Selection, MouseLocal) {
	viewport.reset();
	auto mx = width / 2 + 1;
	auto my = height / 2 + 1;
	MouseEvent em(mx, my, EventType::MouseMove);
	deza.completeEvent(em);
	inter.onEvent(em);
	EXPECT_TRUE(em.localX == 1 && em.localY == 1);
	EXPECT_TRUE(em.localWorldX == 1 && em.localWorldY == 1);
	viewport.scale(2, 2);
	inter.onEvent(em);
	EXPECT_TRUE(em.localX == 1 && em.localY == 1);
	EXPECT_TRUE(em.localWorldX == 0.5 && em.localWorldY == 0.5);
}

TEST(Selection, SelectByMouseDown) {
	viewport.reset();
	auto mx = width / 2 + 1;
	auto my = height / 2 + 1;
	MouseEvent em(mx, my, EventType::MouseMove);
	MouseEvent ed(mx, my, EventType::MouseDown);
	deza.dispatchEvent(em);
	deza.dispatchEvent(ed);
	deza.tick();
	auto& selection = doc.getSelection();
	EXPECT_TRUE(selection.size() == 1);
}

// The main entry point for running the tests
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	init();
	return RUN_ALL_TESTS();
}
