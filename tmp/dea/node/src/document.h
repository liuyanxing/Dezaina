#pragma once

#include "container.h"
#include "page.h"

constexpr size_t NodePoolInitialSize = 1024;

namespace dea::node {

class DocumentNode : public DocumentNodeBase, public Container {
public:
	DocumentNode() {
    type = NodeType::DOCUMENT;
	};
	~DocumentNode() = default;
	void close();

	bool empty() const {
    return children_.empty(); 
	}

	void encode(message::Message& message, kiwi::MemoryPool& pool);

  void setDefaultPage() {
    currentPage_ = static_cast<PageNode*>(children_[0]);
  }

  PageNode* getCurrentPage() {
    return currentPage_;
  }

private:
  PageNode* currentPage_ = nullptr;
};

} // namespace dea::node