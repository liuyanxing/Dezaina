#pragma once

#include "desaina_node.h"
#include <cstdint>
#include <memory>
#include <optional>
#include <functional>
#include <unordered_map>
#include "base/map.h"
#include "base/class_tool.h"
#include "event_system/event.h"
#include "guid.h"
#include "node_pool.h"
#include "page.h"
#include "frame.h"
#include "rectangle.h"
#include "editor/editor.h"
#include "base_type.h"
#include "container_node_base.h"

#include "services/services.h"
#include "editor/node_editor.h"

constexpr size_t NodeSize = max_size<PageNode, FrameNodeBase, RectangleNode>();
constexpr size_t NodePoolInitialSize = 1024;

using NodeMap = std::unordered_map<GUID, Node*>;

class Desaina;

class Document : public DocumentNodeBase, public ContainerNodeBase {
public:
	Document(Services* services): services_(services) {
    set_type(NodeType::DOCUMENT);
	};
	~Document() = default;
	void close();

	template<typename T>
	T* createNode(const GUID& id) {
		// void* ptr = nodePool.allocate();
		void* ptr = new T();
		// new (ptr) T();
		static_cast<Node*>(ptr)->set_guid(id);
		return static_cast<T*>(ptr);
	};

	template<typename T>
	T* createNode() {
		auto id = services_->idGenerator->genId();
		return createNode<T>(id);
	};

	std::optional<Node*> getNodeById(GUID id) {
		return getValueFromMap(idNodeMap_, id);
	}

	void iterateNode(Node* node, std::function<bool(Node*)> func);
	void iterateChildren(Node* node, std::function<bool(Node*)> func);
	std::vector<Node*> getAllNodes();

	void setLoaded(bool loaded) {
		isLoaded_ = loaded;
	}

	bool is_loaded() const {
		return isLoaded_;
	}

	void addNodeToMap(Node* node) {
		auto guid = node->get_guid();
		idNodeMap_[guid] = node;
	}

	void createDefaultFile();
	void encode(Desaina_Kiwi::Message& message, kiwi::MemoryPool& pool);

	void buildDocTree();
	void builPath();

  void bindEvents();
  void onEvents(Event* event);
  
  void addEventListener(EventType type, const ListenerFunc& func) {
  }

  void setHoverNode(Node* node) {
    hoverNode_ = node;
  }

  Node* getHoverNode() {
    return hoverNode_;
  }

  void addSelectedNode(Node* node) {
    selectedNodes_.push_back(node);
    if (!editor_ || !editor_->isNodeEditor()) {
      editor_ = std::make_unique<NodeEditor>(this);
    }
  }

  const std::vector<Node*>* getSelectedNodes() {
    return &selectedNodes_;
  }

  void clearSelectedNodes() {
    selectedNodes_.clear();
    editor_ = nullptr;
  }

  vector<DataSharedPtr>* getBlobs() {
    return &blobs_;
  }

private:
	bool isLoaded_ = false;
	NodePool<NodeSize> nodePool{NodePoolInitialSize};
	NodeMap idNodeMap_;
	Services* services_;
  std::unique_ptr<Editor> editor_ = nullptr;
  PageNode* currentPage_ = nullptr;
  Node* hoverNode_ = nullptr;
  vector<Node*> selectedNodes_{};
  vector<DataSharedPtr> blobs_;
};