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
		case RecordType::kTransform:
		{
			auto matrix = pool.allocate<message::Matrix>();
			auto m = std::get<node::Matrix>(record.value);
			matrix->set_m00(m.getM00()); matrix->set_m01(m.getM01()); matrix->set_m02(m.getM02());
			matrix->set_m10(m.getM10()); matrix->set_m11(m.getM11()); matrix->set_m12(m.getM12());
			nodeChange->set_transform(matrix);
			break;
		}
		default:
			break;
		}
		change.addChange(change::ChangeType::NodeChange, nodeChange);
	}

}

} // namespace dea::document