#include "interaction.h"
#include "UI/primitives.h"
#include "UI/ui.h"
#include "dezaina.h"
#include "document.h"
#include "frame_editor.h"
#include "rectangle_editor.h"
#include "vector_editor.h"
#include "text_editor.h"
#include "star_editor.h"
#include "ellipse_editor.h"
#include "polygon_editor.h"
#include "line_editor.h"
#include "interaction/interaction.h"
#include "node.h"
#include "node/node.generated.h"
#include "node/node.h"

#include "selection.h"
#include "spdlog/spdlog.h"

namespace dea::interaction {

using namespace event;
using namespace node;
using namespace document;
using namespace ui;

Interaction::Interaction(Document &doc) : doc_(doc) {
  container_.setName("inter");
  container_.setSize({FLT_MAX, FLT_MAX});
  container_.addEventListener(EventType::MouseMove, [this](Event &event) {
    if (node_editor_) {
      UI::setCursor(CursorType::Default);
    }
  });
}

void Interaction::handleSelectionChange(const node::NodeConstArary &selection) {
}

node::Vector Interaction::GetDocNodeScreenBound(node::Vector size) {
  return Dezaina::instance().getViewport().getScreenSize(size);
}

void Interaction::updateDocSelection() {
  docSelection_ = doc_.getSelectionNodes();
}

void Interaction::createNodeEditor(node::NodePtr node) {
  if (auto *rectangleNode = node::node_cast<node::RectangleNode>(node)) {
    createNodeEditorInernal<RectangleEditor>(rectangleNode);
  } else if (auto *frameNode = node::node_cast<node::FrameNode>(node)) {
    createNodeEditorInernal<FrameEditor>(frameNode);
  } else if (auto *vectorNode = node::node_cast<node::VectorNode>(node)) {
    createNodeEditorInernal<VectorEditor>(vectorNode);
  } else if (auto *textNode = node::node_cast<node::TextNode>(node)) {
    createNodeEditorInernal<TextEditor>(textNode);
  } else if (auto *starNode = node::node_cast<node::StarNode>(node)) {
    createNodeEditorInernal<StarEditor>(starNode);
  } else if (auto *ellipseNode = node::node_cast<node::EllipseNode>(node)) {
    createNodeEditorInernal<EllipseEditor>(ellipseNode);
  } else if (auto *lineNode = node::node_cast<node::LineNode>(node)) {
    createNodeEditorInernal<LineEditor>(lineNode);
  } else if (auto *polygonNode = node::node_cast<node::PolygonNode>(node)) {
    createNodeEditorInernal<PolygonEditor>(polygonNode);
  } else {
    assert(false);
  }
}

void Interaction::updateNodeEditor() {
  if (docSelection_.empty()) {
    node_editor_ = nullptr;
    return;
  }

  if (docSelection_.size() > 1) {
    return;
  } 

  auto *node = docSelection_.front();
  if (!node_editor_ || node_editor_->getEditNode() != node) {
      node_editor_ = nullptr;
      createNodeEditor(const_cast<node::NodePtr>(node));
      return;
  }
  node_editor_->update();
}

void Interaction::update() {
  if (!doc_.currentPage()) {
    return;
  }

  updateDocSelection();
  updateNodeEditor();
}

void Interaction::handleHover() {}

void Interaction::onEvent(event::Event &event) {
  if (!doc_.loaded()) {
    return;
  }

  mouseInter_.onEvent(event);
  InteractionListener::onEvent(event);
}

node::NodeConstPtr Interaction::queryByName(const std::string &query) {
  NodeIter iter(&container_);
  while (iter.isValid()) {
    auto *node = iter.get();
    if (query == node->getName()) {
      return node;
    }
    ++iter;
  }
  return nullptr;
}

void Interaction::onAfterFlushed(event::Event &event) { update(); };
void Interaction::onAfterTick(Event &event) {}
bool Interaction::dragInterNode(const std::string &query,
                                event::MouseEvent &event) {
  if (!node_editor_) {
    return false;
  }

  auto *node = queryByName(query);
  if (!node) {
    return false;
  }

  interaction::node_cast<event::EventEmitter>(node)->emit(event);
  return true;
}

bool Interaction::dragInterNode(const std::string &query, float dx, float dy) {
  MouseEvent event;
  event.type = EventType::MouseDrag;
  event.localWorldDx = dx;
  event.localWorldDy = dy;

  return dragInterNode(query, event);
}

bool Interaction::dragInterNode(const std::string &query, float worldX,
                                float worldY, float newWorldX,
                                float newWorldY) {
  MouseEvent event;
  event.type = EventType::MouseDrag;
  event.localWorldX = newWorldX;
  event.localWorldY = newWorldY;
  event.localWorldDx = newWorldX - worldX;
  event.localWorldDy = newWorldY - worldY;

  event.worldX = newWorldX;
  event.worldY = newWorldY;
  event.worldDx = newWorldX - worldX;
  event.worldDy = newWorldY - worldY;

  return dragInterNode(query, event);
}

void Interaction::dump() {
  NodeIter iter(&container_);
  spdlog::info("dumping page");
  while (iter.isValid()) {
    auto *node = iter.get();
    auto *parent = node->getParent();
    spdlog::info("node: {}, parent: {}", getNodeTypeString(node),
                 getNodeTypeString(parent));
    ++iter;
  }
  spdlog::info("dump end");
}

void Interaction::endCreateNode() {
  if (!creatingNode_) {
    return;
  }

  Dezaina::ImmediateModeScope scope;

  if (!creatingNode_->getParent()) {
    doc_.remove(creatingNode_);
    creatingNode_ = nullptr;
    return;
  }

  doc_.editor().select({creatingNode_->getGuid()});
  update();
  creatingNode_ = nullptr;
  assert(node_editor_);
  node_editor_->selectNearestCtrlNode({0, 0}, [](node::NodeConstPtr node) {
    return node->getName().starts_with("rs");
  });
}

} // namespace dea::interaction
