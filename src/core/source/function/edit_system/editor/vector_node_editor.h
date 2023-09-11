#pragma once

#include "buffer.h"
#include "node_editor.h"
#include "vector.h"
#include "vector_data.h"

constexpr int kArenaAllocSize = 16 * 1024;

class VectorNodeEditor : public NodeEditor {
public:
  VectorNodeEditor(Desaina* desaina): desaina_(desaina), NodeEditor(desaina) {
    init();
  };

  void bindEvents() {}
  void init();
  void buildNetWork();
  void updateBlob();
private:
  ArenaAlloc arena_{kArenaAllocSize};
  EditVector::Network* network_;
  VectorNode* node_;
  Desaina* desaina_;
};

