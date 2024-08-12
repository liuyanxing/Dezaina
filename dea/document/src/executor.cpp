#include "executor.h"

namespace dea::document {

bool Executor::execute() {
	const auto& editRecords = editor_.getRecords();
	for (const auto& record : editRecords) {
		auto* node = !doc_.getNodeById(record.nodeId);
		if (!node) continue;

		switch (record.type) {
		case RecordType::kRotate:
			rotate(record.nodeId, std::get<float>(record.value));
			break;
		case RecordType::kResize:
			resize(record.nodeId, std::get<ResizeValue>(record.value));
			break;
		case RecordType::kTransform:
			transform(record.nodeId, std::get<node::Matrix>(record.value));
			break;
		default:
			break;
		}
	}

	return true;
}

void Executor::rotate(node::NodeConstPtr node, float degrees) {
	node->rotate(degrees);
}

void Executor::transform(node::NodeConstPtr node, const node::Matrix& matrix) {
	node->transform(matrix);
}

void Executor::resize(node::NodeConstPtr node, const node::ResizeValue& values) {
	node->resize(values[0], values[1]);
}

}