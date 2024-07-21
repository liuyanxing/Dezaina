#pragma once

#include "document/include/document.h"
#include "vendor/figma/kiwi.h"
#include "schema/include/message.h"

namespace dea::change {
class Change {
public:
	Change(document::Document& doc) : doc_(doc) {};
	bool applyMessage(kiwi::ByteBuffer& buffer);
	bool processMessage(const message::Message& message);
	bool processBlobChanges(const kiwi::Array<message::Blob>& blobs);
	bool processNodeChanges(const message::Message& message);
private:
	document::Document& doc_;
};

} // namespace dea::change