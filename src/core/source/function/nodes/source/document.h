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
#include "event_system/event_emitter.h"
#include "event_system/event_system.h"
#include "guid.h"
#include "include/core/SkPath.h"
#include "node_pool.h"
#include "page.h"
#include "frame.h"
#include "rectangle.h"
#include "star.h"
#include "polygon.h"
#include "line.h"
#include "text.h"
#include "system/system.h"
#include "vector.h"
#include "ellipse.h"
#include "base_type.h"
#include "container_node_base.h"
#include "util/skia.h"

#include "services/services.h"

constexpr size_t NodeSize = max_size<PageNode, FrameNodeBase, RectangleNode>();
constexpr size_t NodePoolInitialSize = 1024;

using NodeMap = std::unordered_map<GUID, Node*>;

struct Geometry {
  SkPath path;
  DataSharedPtr commandsBlob;
  const SkPath& getPath() {
    if (path.isEmpty()) {
      path = util::toSkPath(commandsBlob);
    }
    return path;
  }
  static auto Make(const DataSharedPtr& commandsBlob) {
    Geometry geometry;
    geometry.commandsBlob = commandsBlob;
    geometry.path = util::toSkPath(commandsBlob);
    return geometry;
  }
};

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

	std::optional<Node*> getNodeById(GUID id) const {
    auto it = idNodeMap_.find(id);
    if (it == idNodeMap_.end()) {
      return std::nullopt;
    }
    return it->second;
	}

	void iterateNode(Node* node, std::function<bool(Node*)> func);
	void iterateChildren(Node* node, std::function<bool(Node*)> func);
	std::vector<Node*> getAllNodes();

	void setLoaded(bool loaded) {
		isLoaded_ = loaded;
	}

	bool isLoaded() const {
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

  void clearSelectedNodes() {
    selectedNodes_.clear();
  }

  void appendGeometryByBlob(const DataSharedPtr& blob) {
    geometries_.push_back(Geometry::Make(blob));
  }

  void setDefaultPage() {
    const auto& children = getChildren();
    currentPage_ = static_cast<PageNode*>(children[1]);
  }

  Geometry* getGeometry(size_t index) {
    if (index >= geometries_.size()) {
      return nullptr;
    }
    return &geometries_[index];
  }

  PageNode* getCurrentPage() {
    return currentPage_;
  }

  Node* getHoverNode() const;
  void setHoverNode(Node* node) {
    if (node == nullptr) {
      hover_node_id_ = std::nullopt;
      return;
    }
    hover_node_id_ = node->get_guid();
  }
  void setSelectedNodes(const vector<Node*>& ids) {
    selectedNodes_.clear();
    for (auto node : ids) {
      selectedNodes_.push_back(node->get_guid());
    }
  }
  vector<Node*> getSelectedNodes() const;
  
private:
	bool isLoaded_ = false;
	NodePool<NodeSize> nodePool{NodePoolInitialSize};
	NodeMap idNodeMap_;
	Services* services_;
  PageNode* currentPage_ = nullptr;
  std::optional<GUID>hover_node_id_{};
  vector<GUID> selectedNodes_{};
  vector<Geometry> geometries_{};
};
