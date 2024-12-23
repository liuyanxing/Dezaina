#pragma once

#include "editor.h"
#include "event.h"
#include "node.h"
#include "vendor/figma/kiwi.h"
#include <cstdint>

namespace dea::document {

using NodeMap = std::unordered_map<node::GUID, node::Node *>;

class Document : public event::EventEmitter {
public:
  Document(uint32_t sessionId);

  template <typename T> T *buildNode(const node::GUID &id) {
    auto *node = new T();
    node->setGuid(id);
    nodeMap_[id] = node;
    return node;
  };

  template <typename T> T *buildNode() {
    return buildNode<T>(node::GUID{sessionId_, localId_++});
  };

  template <typename T> T *createNode(const node::GUID &id, bool sync = true) {
    auto *node = new T();
    node->setGuid(id);
    nodeMap_[id] = node;
    if (sync) {
      editor_.create(node);
    }
    return node;
  };

  template <typename T> T *createNode(bool sync = true) {
    return createNode<T>(node::GUID{sessionId_, localId_++}, sync);
  };

  template <typename T> T *createNode(node::NodePtr parent) {
    auto *node = createNode<T>();
    append(node, parent);
    return node;
  };

  bool load(char *data, size_t size) {
    kiwi::ByteBuffer buffer(reinterpret_cast<uint8_t *>(data), size);
    auto res = applyMessage(buffer);
    if (!root_->empty()) {
      setCurrentPage(static_cast<node::PageNode *>(root_->firstChild()));
    }
    return res;
  }

  void loadEmpty();

  void unload() {}

  void append(node::Node *child);
  void append(node::Node *child, node::Node *parent);
  void applyNodeChange(message::NodeChange *change);
  void remove(node::Node *node) {}

  void setRoot(node::DocumentNode *root) { root_ = root; }
  auto *root() const { return root_; }
  bool loaded() const { return root_ != nullptr; }

  auto *currentPage() const { return currentPage_; }
  node::DocumentNode *getRoot() { return root_; }
  node::Node *getParent(node::Node *node) {
    if (node::node_cast<node::DocumentNode>(node)) {
      return nullptr;
    }
    return getNodeById(node->getParentIndex().guid);
  }

  std::vector<node::Node *> getNodes(float x, float y);

  void setCurrentPage(node::PageNode *page);
  node::Node *getNodeById(const node::GUID &id) const;
  void handleViewMatrixChange(const node::Matrix &matrix);
  void flushEditor();

  auto &editor() { return editor_; }

  bool applyMessage(kiwi::ByteBuffer &buffer);
  bool applyMessage(message::Message &message);
  bool processBlobMessage(kiwi::Array<message::Blob> &blobs);
  bool processNodeChanges(message::Message &message);

  auto &getSelection() { return currentPage_->getSelection(); }
  void setSelection(const std::vector<node::GUID> &ids) {
    node::NodeArary nodes;
    nodes.reserve(ids.size());

    currentPage_->setSelection(ids);
    for (auto id : currentPage_->getSelection()) {
      if (auto *node = getNodeById(id)) {
        nodes.push_back(node);
      }
    }
    editor_.setEditNodes(move(nodes));
  }

  void dump();
  void dump(node::Node *node) const;

private:
  NodeMap nodeMap_{100};
  node::DocumentNode *root_{};
  node::PageNode *currentPage_{};
  Editor editor_;
  uint32_t sessionId_{};
  uint32_t localId_{1};
  std::unordered_map<uint32_t, uint32_t> blobIdMap_{};
};

} // namespace dea::document
