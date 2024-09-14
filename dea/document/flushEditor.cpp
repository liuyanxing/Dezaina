#include "change/change.h"
#include "dezaina.h"
#include "document.h"
#include "change/change.h"
#include "layout.h"

namespace dea::document {

void Document::flushEditor() {
  if (editor_.empty()) {
    return;
  }

	layout::ContraintLayout cLayout{};

	auto& change = Dezaina::instance().getChange();
	auto& pool = change.getPool();

	for (auto& record : editor_.getRecords()) {
		auto* node = getNodeById(record.nodeId);
		if (node == nullptr) {
			continue;
		}
		if (record.type >= RecordType::kLayoutRelation) {
			cLayout.add(&record);
			continue;
		}
		auto* nodeChange = change.addNodeChange(node);

		switch (record.type) {
		case RecordType::kSelection:
		{
			change.addChange(change::ChangeType::Select, std::get<node::NodeIdArray>(record.value));			
			continue;
		}
		default:
			continue;
		}
		change.addChange(change::ChangeType::NodeChange, nodeChange);
	}

    switch (record.type) {
    case RecordType::kSelection: {
      change.addChange(change::ChangeType::Select,
                       std::get<node::NodeIdArray>(record.value));
      continue;
    }
    default:
      continue;
    }
  }
  cLayout.layout(change);
  editor_.clear();
}

} // namespace dea::document
