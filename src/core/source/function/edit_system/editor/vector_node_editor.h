#pragma once

#include "buffer.h"
#include "edit_system/editor/editor.h"
#include "event_system/mouse_event.h"
#include "node_editor.h"
#include "vector.h"
#include "vector_editor_data.h"

constexpr int kArenaAllocSize = 16 * 1024;

class VectorNodeEditor : public Editor {
public:
  VectorNodeEditor(Desaina* desaina): desaina_(desaina), Editor(EditorType::kVector, desaina) {
    init();
  };

  void init();
  void update() override;
  void bindInteractionArea();
  void addHitNode(EditorHitNodeType type, void* data, const SkRect& rect);
  void bindEvents();
  void buildNetWork();
  void updateBlob();
  void getPath(SkPath& fillPath, SkPath& strokePath) override;
  void getEditPath(SkPath& path) override;

  void hanleDrag(MouseEvent* event);
private:
  ArenaAlloc arena_{kArenaAllocSize};
  VectorEditor::Network network_{};
  VectorNode* node_;
  Desaina* desaina_;
  vector<EditorHitNode> hit_nodes_;
};

