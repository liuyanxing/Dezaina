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
    deza.initViewport(width, height, 1);
    auto* page = doc.createNode<PageNode>();
    doc.setCurrentPage(page);
    auto* rect = doc.createNode<RectangleNode>();
    rect->setSize({100, 100});
    doc.append(rect, page);
}

TEST(NodeEditor, BuildWhenCursorDownOnNode) {
    deza.dispatchMouseEvent(width / 2, height / 2, EventType::MouseMove, 0, 0);
    deza.dispatchMouseEvent(width / 2, height / 2, EventType::MouseDown, 0, 0);
    deza.tick();
    auto& editor = interaction.getNodeEditor();
    EXPECT_TRUE(editor);
}


// The main entry point for running the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    init();
    return RUN_ALL_TESTS();
}
