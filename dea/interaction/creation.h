#pragma once

#include "document.h"
#include "event.h"
#include "node.h"
#include "listener.h"

namespace dea::interaction {

using OnCreateNode = std::function<void(node::Node*, event::MouseEvent& event)>;

class Creation : public InteractionListener {
public:
	Creation(document::Document& doc) : document_(doc) {};

	template<typename T>
	void startCreateNode() {
		// todo delete creatingNode_ if it is not nullptr
		creatingNode_ = document_.createNode<T>();
	}

	void onCreateNode(const OnCreateNode& onCreateNode) {
		onCreateNode_ = onCreateNode;
	}

private:
	void onMouseDrag(event::MouseEvent& event) override;
	void onMouseUp(event::MouseEvent& event) override;
  node::Node* creatingNode_ = nullptr;
	document::Document& document_;
	OnCreateNode onCreateNode_;
};

}