#pragma once

#include "buffer.h"
#include "edit_system/editor/editor.h"
#include "event_system/mouse_event.h"
#include "node_editor.h"
#include "vector.h"
#include "vector_editor_data.h"

constexpr int kArenaAllocSize = 16 * 1024;
using ControllerVertex =  std::variant<VectorEditor::Vertex*, Vector*>;

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

class VectorNodeEditor : public Editor {
public:
  VectorNodeEditor(Desaina* desaina): desaina_(desaina), Editor(EditorType::kVector, desaina) {
    init();
  };

  void init();
  void update() override;
  void buildInteractionArea();
  void bindEvents();
  void buildNetWork();
  void updateBlob();
  void getPath(SkPath& fillPath, SkPath& strokePath) override;
  void getEditPath(SkPath& path) override;

  void handleDrag(MouseEvent* event);
private:
  ArenaAlloc arena_{kArenaAllocSize};
  VectorEditor::Network network_{};
  VectorNode* node_;
  Desaina* desaina_;
  vector<ControllerNode> hit_nodes_;
  vector<VectorEditor::Segment*> selected_segments_;

  void updateSelectedSegments();
  bool isSelected(const VectorEditor::Segment*) const;
};

