#pragma once

#include "desaina_node.h"
#include <cstdint>
#include <vector>
#include <memory>
#include <optional>
#include <functional>
#include <unordered_map>
#include "base/map.h"
#include "base/class_tool.h"
#include "guid.h"
#include "node_pool.h"
#include "page.h"
#include "frame.h"
#include "rectangle.h"

#include "services/services.h"

constexpr size_t NodeSize = max_size<PageNode, FrameNodeBase, RectangleNode>();
constexpr size_t NodePoolInitialSize = 1024;

using Node = BaseNodeMixin;
using NodeMapType = std::unordered_map<GUID, Node*>;

class Desaina;

class Document : public DocumentNodeBase
{
public:
	Document(Services* services): services_(services) {
		set_type(NodeType::DOCUMENT);
		auto id = services->idGenerator->genId();
		set_id(id);
	};
	~Document() = default;
	void close();

	template<typename T>
	T* createNode(const GUID& id) {
		void* ptr = new T();
		static_cast<Node*>(ptr)->set_id(id);
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

	void set_loaded(bool loaded) {
		isLoaded = loaded;
	}

	bool is_loaded() const {
		return isLoaded;
	}

	void addNodeToMap(Node* node) {
		auto guid = node->get_id();
		idNodeMap_[guid] = node;
	}

	PageNode* getCurPage() {
		return curPage_;
	}
	void setDefaultPage() {
		const auto& children_ref = get_children();
		curPage_ = static_cast<PageNode*>(children_ref[0]);
	}

	void createDefaultFile();
	void encode(Desaina_Kiwi::Message& message, kiwi::MemoryPool& pool);

	void buildDocTree();
	void builPath();

private:
	bool isLoaded = false;
	NodePool<NodeSize> nodePool{NodePoolInitialSize};
	NodeMapType idNodeMap_;
	Services* services_{nullptr};
	PageNode* curPage_{nullptr};
};