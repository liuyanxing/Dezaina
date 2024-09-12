#include "dezaina.h"
#include "document.h"
#include "change/change.h"

namespace dea::document {

void Document::flushEditor() {
	if (editor_.empty()) {
		return;
	}

	auto& change = Dezaina::instance().getChange();
	auto& pool = change.getPool();

	for (auto& record : editor_.getRecords()) {
		auto* node = getNodeById(record.nodeId);
		if (node == nullptr) {
			continue;
		}
		auto* nodeChange = change.addNodeChange(node);

		switch (record.type) {
		case RecordType::kSelection:
		{
			change.addChange(change::ChangeType::Select, std::get<node::NodeIdArray>(record.value));			
			continue;
		}
		case RecordType::kTransform:
		{
			nodeChange->set_transform(std::get<node::Matrix>(record.value).toChange(pool));
			break;
		}
		default:
			continue;
		}
		change.addChange(change::ChangeType::NodeChange, nodeChange);
	}

}

} // namespace dea::document