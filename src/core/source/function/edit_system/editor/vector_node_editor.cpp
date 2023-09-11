#include "vector_node_editor.h"
#include "desaina.h"
#include "text.h"
#include "vector.h"

void VectorNodeEditor::init() {
  node_ = static_cast<VectorNode*>(getEditingNodes()[0]);
  buildNetWork();
}

void VectorNodeEditor::buildNetWork() {
  getEditingNodes();
  auto blobId = node_->get_vectorData().vectorNetworkBlob;
  auto blob = desaina_->getBlob(blobId);
  network_ = buildNetworkFromBlob(*blob, arena_);
}
