#include "dezaina.h"
#include "document.h"
#include "node/node.generated.h"
#include <cmath>
#include <gtest/gtest.h>

// The purpose of these tests are just to  make sure that gtest was properly
// installed.

using namespace dea::document;
using namespace dea::node;
using namespace dea::event;

auto &deza = dea::Dezaina::instance();
auto &doc = deza.document();
auto &interaction = deza.interaction();

const uint32_t width = 1280;
const uint32_t height = 720;

void init() {
  deza.setViewport(width, height, 1);
  deza.loadEmptyDocument();
  auto *rect = doc.createNode<RectangleNode>(doc.currentPage());
  rect->setSize({100, 100});
  doc.editor().setImmediate(true);
}

TEST(NodeEditor, BuildWhenCursorDownOnNode) {
  deza.dispatchMouseEvent(width / 2, height / 2, EventType::MouseMove, 0, 0);
  deza.dispatchMouseEvent(width / 2, height / 2, EventType::MouseDown, 0, 0);
  deza.tick();
  auto &editor = interaction.getNodeEditor();
  EXPECT_TRUE(editor);
  deza.dispatchMouseEvent(width / 2 + 50, height / 2 + 50, EventType::MouseUp,
                          0, 0);
}

TEST(NodeEditor, DragEditorToMoveNode) {
  auto *node = interaction.getNodeEditor()->getFirstNode();
  auto *rect = node_cast<RectangleNode *>(node);

  deza.dragInterNode("bt", 50, 50);
  EXPECT_TRUE(rect->getTransform() == Matrix(1, 0, 50, 0, 1, 50));

  deza.dragInterNode("bt", -50, -50);
  EXPECT_TRUE(rect->getTransform() == Matrix());
}

TEST(NodeEditor, DragEditorRotateEdge) {
  auto *node = interaction.getNodeEditor()->getFirstNode();
  auto *rect = node_cast<RectangleNode *>(node);
  deza.dragInterNode("bt", -50, -50);

  auto sqrt = std::sqrt(100 * 100 + 100 * 100) / 2;

  deza.dragInterNode("br0", 50, 50, sqrt, 0);
  EXPECT_TRUE(rect->getTransform().getRotation() == 0.7853981852531433);
  deza.dragInterNode("br0", sqrt, 0, 50, 50);

  deza.dragInterNode("br1", 50, -50, 0, -sqrt);
  EXPECT_TRUE(rect->getTransform().getRotation() == 0.7853981852531433);
  deza.dragInterNode("br1", 0, -sqrt, 50, -50);

  deza.dragInterNode("br2", -50, -50, -sqrt, 0);
  EXPECT_TRUE(rect->getTransform().getRotation() == 0.7853981852531433);
  deza.dragInterNode("br2", -sqrt, 0, -50, -50);

  deza.dragInterNode("br3", -50, 50, 0, sqrt);
  EXPECT_TRUE(rect->getTransform().getRotation() == 0.7853981852531433);
  deza.dragInterNode("br3", 0, sqrt, -50, 50);

  deza.dragInterNode("bt", 50, 50);
}

TEST(NodeEditor, DragEditorResizeEdge) {
  auto *node = interaction.getNodeEditor()->getFirstNode();
  auto *rect = node_cast<RectangleNode *>(node);

  doc.editor().select({rect->getGuid()});
  doc.editor().setTransform(Matrix());

  deza.dragInterNode("be0", 0, -50);
  EXPECT_TRUE(rect->getTransform() == Matrix(1, 0, 0, 0, 1, -50));
  EXPECT_TRUE(rect->getSize() == Vector(100, 150));

  deza.dragInterNode("be1", 50, 0);
  EXPECT_TRUE(rect->getTransform() == Matrix(1, 0, 0, 0, 1, -50));
  EXPECT_TRUE(rect->getSize() == Vector(150, 150));

  deza.dragInterNode("be2", 0, 50);
  EXPECT_TRUE(rect->getTransform() == Matrix(1, 0, 0, 0, 1, -50));
  EXPECT_TRUE(rect->getSize() == Vector(150, 200));

  deza.dragInterNode("be3", -50, 0);
  EXPECT_TRUE(rect->getTransform() == Matrix(1, 0, -50, 0, 1, -50));
  EXPECT_TRUE(rect->getSize() == Vector(200, 200));
}

TEST(NodeEditor, DragEditorResizeNode) {
  auto *node = interaction.getNodeEditor()->getFirstNode();
  auto *rect = node_cast<RectangleNode *>(node);

  doc.editor().select({rect->getGuid()});
  doc.editor().setSize(100, 100);
  doc.editor().setTransform(Matrix());
  doc.editor().translate(-50, -50);

  deza.dragInterNode("bs1", -50, 50);
  EXPECT_TRUE(rect->getTransform() == Matrix(1, 0, -50, 0, 1, 0));
  EXPECT_TRUE(rect->getSize() == Vector(50, 50));
  deza.dragInterNode("bs1", 50, -50);

  deza.dragInterNode("bs2", -50, -50);
  EXPECT_TRUE(rect->getTransform() == Matrix(1, 0, -50, 0, 1, -50));
  EXPECT_TRUE(rect->getSize() == Vector(50, 50));
  deza.dragInterNode("bs2", 50, 50);

  deza.dragInterNode("bs3", 50, -50);
  EXPECT_TRUE(rect->getTransform() == Matrix(1, 0, 0, 0, 1, -50));
  EXPECT_TRUE(rect->getSize() == Vector(50, 50));
  deza.dragInterNode("bs3", -50, 50);

  deza.dragInterNode("bs0", 50, 50);
  EXPECT_TRUE(rect->getTransform() == Matrix(1, 0, 0, 0, 1, 0));
  EXPECT_TRUE(rect->getSize() == Vector(50, 50));
  deza.dragInterNode("bs0", -50, -50);
}

// The main entry point for running the tests
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  init();
  return RUN_ALL_TESTS();
}
