#pragma once

#include "creation.h"
#include "document.h"
#include "event.h"
#include "listener.h"
#include "node.h"
#include "node_editor.h"
#include "selection.h"
#include "mouse_interaction.h"
#include <memory>

namespace dea::interaction {

class Interaction : public InteractionListener {
public:
  Interaction(document::Document &doc);

  auto *root() { return &page_; }
  auto &getNodeEditor() { return node_editor_; }
  auto *getHoverNode() { return selection_.getHoverNode(); }
  void onEvent(event::Event &event) override;

  void dump();
  bool dragInterNode(const std::string &query, float dx, float dy);
  bool dragInterNode(const std::string &query, float worldX, float worldY,
                     float newWorldX, float newWorldY);
  bool dragInterNode(const std::string &query, event::MouseEvent &event);

  auto *getHoverInterNode() { return mouseInter_.getHoverNode(); }

  static node::Vector GetItersectBound(node::Vector size);

private:
  node::PageNode page_;
  std::unique_ptr<NodeEditor> node_editor_ = nullptr;
  Selection selection_{nullptr, GetItersectBound};
  Creation creation_;
  document::Document &doc_;
  MouseInteraction mouseInter_{&page_};

  void appendToContainer(node::Node *child) { node::Container::append(&page_, child); }

  void handleSelectionChange(const node::NodeConstArary &selection);
  void updateNodeEditor();
  void handleHover();
  // void onBeforeTick(event::Event* event) override;
  void onMouseWheel(event::MouseEvent &event) override;
  void onMouseDrag(event::MouseEvent &event) override;
  void onWindowResize(event::Event &event) override;
  void onAfterFlushed(event::Event &event) override;
  void onAfterTick(event::Event &event) override;
};

} // namespace dea::interaction
