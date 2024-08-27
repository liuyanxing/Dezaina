#include "executor.h"
#include "document.h"
#include "schema/message.h"

namespace dea::document {
	bool Executor::execute() {
		if (editor_.empty()) {
			return true;
		}

		change_.clearNodeChanges();
		auto pool = kiwi::MemoryPool();

		for (auto& record : editor_.getRecords()) {
			auto* node = doc_.getNodeById(record.nodeId);
			if (node == nullptr) {
				continue;
			}
			auto* change = change_.addNodeChange(node, pool);

			switch (record.type) {
			case RecordType::kTransform:
			{
				auto matrix = pool.allocate<message::Matrix>();
				auto m = std::get<node::Matrix>(record.value);
				matrix->set_m00(m.getM00()); matrix->set_m01(m.getM01()); matrix->set_m02(m.getM02());
				matrix->set_m10(m.getM10()); matrix->set_m11(m.getM11()); matrix->set_m12(m.getM12());
				change->set_transform(matrix);
				break;
			}
			default:
				break;
			}
		}

		change_.applyChanges();
		change_.clearNodeChanges();

		return true;
	}

}