#pragma once

#include "buffer.h"
#include "edit_system/editor/editor.h"
#include "event_system/mouse_event.h"
#include "include/core/SkPath.h"
#include "node_editor.h"
#include "util/node_vector.h"
#include "vector.h"

constexpr int kArenaAllocSize = 16 * 1024;
using ControllerVertex =  std::variant<node::Vertex*, Vector*>;

struct ControllerNode : public EditorHitNode {
  ControllerVertex vertex;
  static ControllerNode Make(ControllerVertex vertex, const SkRect& bound) {
    ControllerNode node{};
    node.type = EditorHitNodeType::kController;
    node.vertex = vertex;
    node.bound = bound;
    return node;
  }
};

class VectorNodeEditor : public EditorView {
public:
  VectorNodeEditor(Desaina* desaina): desaina_(desaina), EditorView(EditorType::kVector, desaina) {
    init();
  };

  void init();
  void update() override;
  void buildInteractionArea();
  void bindEvents();
  void updateBlob();
  void getPath(SkPath& fillPath, SkPath& strokePath) override;
  void getEditPath(SkPath& path) override;

  void handleDrag(MouseEvent* event);
private:
  ArenaAlloc arena_{kArenaAllocSize};
  node::Network network_;
  VectorNode* node_;
  Desaina* desaina_;
  vector<ControllerNode> hit_nodes_;
  vector<node::Segment*> selected_segments_;
  SkPath* vector_path_;

  void updateSelectedSegments();
  bool isSelected(const node::Segment*) const;
};

