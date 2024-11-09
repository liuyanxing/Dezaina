#pragma once

#include "document.h"
#include "event.h"
#include "listener.h"
#include "mouse_interaction.h"
#include "node.h"
#include "node/node.h"
#include "node_editor.h"
#include "selection.h"
#include <memory>
#include <string>

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

  template <typename T> void startCreateNode() {
    endCreateNode();
    creatingNode_ = doc_.createNode<T>(false);
  }

  void startCreateNode(const std::string& name) {
    endCreateNode();
    creatingNode_ = doc_.createNode(name, false);
  }

  auto *getCreatingNode() { return creatingNode_; }
  void endCreateNode();

  static node::Vector GetDocNodeScreenBound(node::Vector size);

  struct Status {
    node::NodeConstPtr hoverDocNode = nullptr;
    node::NodeConstPtr hoverInterNode = nullptr;
    node::Vector mouseWorldPos;
  } status;

private:
  Frame container_;
  std::unique_ptr<NodeEditor> node_editor_ = nullptr;
  node::NodeConstArary docSelection_;
  node::NodeConstArary interSelection_;
  MouseInteraction mouseInter_{*this};
  node::Node *creatingNode_ = nullptr;

  document::Document &doc_;

  void appendToContainer(node::Node *child) {
    node::Container::append(&container_, child);
  }

  void handleSelectionChange(const node::NodeConstArary &selection);
  void update();
  void updateDocSelection();
  void updateNodeEditor();

  template <typename T>
  void createNodeEditorImpl(node::NodePtr node) {
    node_editor_ = std::make_unique<T>(node, doc_.editor(), &container_);
  }

  void handleHover();
  // void onBeforeTick(event::Event* event) override;
  void onMouseWheel(event::MouseEvent &event) override;
  void onMouseDrag(event::MouseEvent &event) override;
  void onAfterFlushed(event::Event &event) override;
  void onAfterTick(event::Event &event) override;
};

} // namespace dea::interaction
