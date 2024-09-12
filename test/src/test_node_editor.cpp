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
auto& interaction = deza.interaction();

const uint32_t width = 1280;
const uint32_t height = 720;

void init() {
    deza.setViewport(width, height, 1);
    deza.loadEmptyDocument();
    auto* rect = doc.createNode<RectangleNode>(doc.currentPage());
    rect->setSize({100, 100});
}

TEST(NodeEditor, BuildWhenCursorDownOnNode) {
    deza.dispatchMouseEvent(width / 2, height / 2, EventType::MouseMove, 0, 0);
    deza.dispatchMouseEvent(width / 2, height / 2, EventType::MouseDown, 0, 0);
    deza.tick();
    auto& editor = interaction.getNodeEditor();
    EXPECT_TRUE(editor);
}

TEST(NodeEditor, DragEditorToMoveNode) {
    deza.dispatchMouseEvent(width / 2 + 50, height / 2 + 50, EventType::MouseUp, 0, 0);
    deza.dispatchMouseEvent(width / 2 + 50, height / 2 + 50, EventType::MouseMove, 0, 0);
    deza.dispatchMouseEvent(width / 2 + 50, height / 2 + 50, EventType::MouseDown, 0, 0);
    deza.dispatchMouseEvent(width / 2 + 100, height / 2 + 100, EventType::MouseMove, 0, 0);
    deza.tick();
    auto& editor = interaction.getNodeEditor();
    auto& editeNode = editor->getEditNodes()[0];
    auto* rect = node_cast<RectangleNode*>(editeNode);
    EXPECT_TRUE(rect);
    auto transform = rect->getTransform();
    EXPECT_TRUE(transform.m02 == 50 && transform.m12 == 50);
}


// The main entry point for running the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    init();
    return RUN_ALL_TESTS();
}
