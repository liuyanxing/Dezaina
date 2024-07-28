#pragma once

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
private:
	Document& doc_;
	std::unordered_map<uint32_t, uint32_t> blobIdMap_{};
};

} // namespace dea::change