#include <gtest/gtest.h>
#include "dezaina.h"

// The purpose of these tests are just to  make sure that gtest was properly installed.

using namespace dea::document;
using namespace dea::node;
using namespace dea::event;

auto& deza = dea::Dezaina::instance();
auto& viewport = deza.viewport();

const uint32_t width = 1280;
const uint32_t height = 720;

void init() {
	deza.setViewport(width, height, 1);
	deza.loadEmptyDocument();
}

TEST(Viewport, WorldCoordinates1xScreen) {
	viewport.reset();
	MouseEvent e(width / 2, height / 2);
	deza.dispatchEvent(e);
	EXPECT_TRUE(e.worldX == 0);
	EXPECT_TRUE(e.worldY == 0);
	e.x += 100; e.y += 100;
	deza.dispatchEvent(e);
	EXPECT_TRUE(e.worldX == 100);
	EXPECT_TRUE(e.worldY == 100);
}


TEST(Viewport, ScaleCenter1xScreen) {
	viewport.reset();
	viewport.scale(2, 2, 0, 0);
	MouseEvent e(width / 2, height / 2);
	deza.dispatchEvent(e);
	EXPECT_TRUE(e.worldX == 0);
	EXPECT_TRUE(e.worldY == 0);
	e.x += 100; e.y += 100;
	deza.dispatchEvent(e);
	EXPECT_TRUE(e.worldX == 50);
	EXPECT_TRUE(e.worldY == 50);
}

TEST(Viewport, WorldCoordinates2xScreen) {
	deza.setViewport(width, height, 2);
	MouseEvent e(width / 2, height / 2);
	deza.dispatchEvent(e);
	EXPECT_TRUE(e.worldX == 0);
	EXPECT_TRUE(e.worldY == 0);
	e.x += 100; e.y += 100;
	deza.dispatchEvent(e);
	EXPECT_TRUE(e.worldX == 200);
	EXPECT_TRUE(e.worldY == 200);
}

TEST(Viewport, ScaleCenter2xScreen) {
	viewport.reset();
	viewport.scale(2, 2, 0, 0);
	MouseEvent e(width / 2, height / 2);
	deza.dispatchEvent(e);
	EXPECT_TRUE(e.worldX == 0);
	EXPECT_TRUE(e.worldY == 0);
	e.x += 100; e.y += 100;
	deza.dispatchEvent(e);
	EXPECT_TRUE(e.worldX == 100);
	EXPECT_TRUE(e.worldY == 100);
}

// The main entry point for running the tests
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	init();
	return RUN_ALL_TESTS();
}
