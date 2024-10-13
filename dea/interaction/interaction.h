#pragma once

#include "creation.h"
#include "document.h"
#include "event.h"
#include "listener.h"
#include "mouse_interaction.h"
#include "node.h"
#include "node/node.h"
#include "node_editor.h"
#include "selection.h"
#include <memory>

namespace dea::interaction {

class Interaction : public InteractionListener {
public:
  Interaction(document::Document &doc);

  auto *root() { return &container_; }
  auto &getNodeEditor() { return node_editor_; }
  void onEvent(event::Event &event) override;

  void dump();
  bool dragInterNode(const std::string &query, float dx, float dy);
  bool dragInterNode(const std::string &query, float worldX, float worldY,
                     float newWorldX, float newWorldY);
  bool dragInterNode(const std::string &query, event::MouseEvent &event);
  node::NodeConstPtr queryByName(const std::string &query);

  auto *getHoverInterNode() { return mouseInter_.getHoverInterNode(); }
  auto *getHoverDocNode() { return mouseInter_.getHoverDocNode(); }

  auto &getDocSelection() { return docSelection_; }
  auto &getInterSelection() { return interSelection_; }
  auto *getInterPage() { return &container_; }

  static node::Vector GetDocNodeScreenBound(node::Vector size);

private:
  Frame container_;
  std::unique_ptr<NodeEditor> node_editor_ = nullptr;
  node::NodeConstArary docSelection_;
  node::NodeConstArary interSelection_;
  MouseInteraction mouseInter_{*this};

  Creation creation_;
  document::Document &doc_;

  void appendToContainer(node::Node *child) {
    node::Container::append(&container_, child);
  }

  void handleSelectionChange(const node::NodeConstArary &selection);
  void update();
  void handleHover();
  // void onBeforeTick(event::Event* event) override;
  void onMouseWheel(event::MouseEvent &event) override;
  void onMouseDrag(event::MouseEvent &event) override;
  void onAfterFlushed(event::Event &event) override;
  void onAfterTick(event::Event &event) override;
};

} // namespace dea::interaction
