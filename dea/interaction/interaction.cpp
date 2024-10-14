#include "interaction.h"
#include "UI/primitives.h"
#include "UI/ui.h"
#include "dezaina.h"
#include "document.h"
#include "frame_editor.h"
#include "interaction/interaction.h"
#include "node.h"
#include "node/node.generated.h"
#include "node/node.h"
#include "rectangle_editor.h"
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
  return Dezaina::instance().getViewport().mapWorldToScreen(
      node::Vector{size.x, size.y});
}

void Interaction::update() {
  if (!doc_.currentPage()) {
    return;
  }
  auto &selection = doc_.getSelection();
  docSelection_.clear();
  for (auto &id : selection) {
    auto *node = doc_.getNodeById(id);
    if (node) {
      docSelection_.push_back(node);
    }
  }

  if (docSelection_.empty()) {
    if (node_editor_ != nullptr) {
      auto *editorContainer = node_editor_->getContainer();
      container_.removeChild(editorContainer);
      node_editor_ = nullptr;
      return;
    }
    return;
  }

  if (docSelection_.size() > 1) {
  } else {
    auto *node = docSelection_.front();
    if (!node_editor_) {
      if (auto *rectangleNode = node::node_cast<node::RectangleNode>(node)) {
        node_editor_ = std::make_unique<RectangleEditor>(
            *rectangleNode, doc_.editor(), container_);
      } else if (auto *frameNode = node::node_cast<node::FrameNode>(node)) {
        node_editor_ = std::make_unique<FrameEditor>(*frameNode, doc_.editor(),
                                                     container_);
      } else {
        assert(false);
      }
    }
  }

  if (node_editor_ == nullptr) {
    return;
  }

  node_editor_->update();
  auto *editorContainer = node_editor_->getContainer();
  if (!container_.findChild(editorContainer)) {
    appendToContainer(editorContainer);
  }
  // dump();
}

void Interaction::handleHover() {}

void Interaction::onEvent(event::Event &event) {
  if (!doc_.loaded()) {
    return;
  }

  // creation_.onEvent(event);
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
