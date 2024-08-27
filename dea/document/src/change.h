#pragma once

#include "node.h"
#include "vendor/figma/kiwi.h"
#include "schema/message.h"
#include <unordered_map>

namespace dea::document {

class Document;
class Change {
public:
	Change(Document& doc) : doc_(doc) {};
	bool applyMessage(kiwi::ByteBuffer& buffer);
	bool processMessage(message::Message& message);
	bool processBlobMessage(kiwi::Array<message::Blob>& blobs);
	bool processNodeChanges(message::Message& message);
	message::NodeChange* addNodeChange(node::Node* node, kiwi::MemoryPool& pool) {
		if (changeMap_.find(node) == changeMap_.end()) {
			changeMap_[node] = pool.allocate<message::NodeChange>();
		}
		return changeMap_[node];
	}
	void clearNodeChanges() {
		changeMap_.clear();
	}

	void applyChanges();

private:
	Document& doc_;
	std::unordered_map<uint32_t, uint32_t> blobIdMap_{};
	std::unordered_map<node::Node*, message::NodeChange*> changeMap_{};
};

} // namespace dea::change