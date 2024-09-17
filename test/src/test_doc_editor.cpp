#include <gtest/gtest.h>
#include "dezaina.h"
#include "document.h"
#include "node/node.generated.h"

// The purpose of these tests are just to  make sure that gtest was properly installed.

using namespace dea::document;
using namespace dea::node;
using namespace dea::event;

auto& deza = dea::Dezaina::instance();
auto& doc = deza.document();
auto& editor = doc.editor();
auto& interaction = deza.interaction();

const uint32_t width = 1280;
const uint32_t height = 720;

void init() {
    deza.setViewport(width, height, 1);
    deza.loadEmptyDocument();
    auto* rect = doc.createNode<RectangleNode>(doc.currentPage());
    rect->setSize({100, 100});
		editor.setImmediate(true);
}

TEST(DocEditor, Selection) {
		editor.select({doc.currentPage()->firstChild()->getGuid()});
		auto& selection = doc.currentPage()->getSelection();
    EXPECT_TRUE(selection.size() == 1);
    // EXPECT_TRUE(selection[0] == doc.currentPage()->firstChild()->getGuid());
}

TEST(DocEditor, Resize) {
		editor.resize(200, 200, {0, 0});
		auto* rect = node_cast<RectangleNode>(doc.currentPage()->firstChild());
		// EXPECT_TRUE(rect->getSize() == Vector{200, 200});
}

TEST(DocEditor, Translate) {
		editor.setTranslate(10, 10);
		auto* rect = node_cast<RectangleNode>(doc.currentPage()->firstChild());
		EXPECT_TRUE(rect->getTransform().m02 == 10);
		EXPECT_TRUE(rect->getTransform().m12 == 10);
}

// The main entry point for running the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    init();
    return RUN_ALL_TESTS();
}
