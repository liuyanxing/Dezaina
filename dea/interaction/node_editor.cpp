#include "node_editor.h"
#include "node/utility.h"
#include "base/algorithm.h"

namespace dea::interaction {

void NodeEditor::selectNearestCtrlNode(node::Vector worldPoint, std::function<bool(node::NodeConstPtr)> filter) {
	node::NodeIter iter{&frame_};
	node::NodeConstArary nodes;
	while (iter.isValid()) {
		auto* node = iter.get();
		if (filter(node)) {
			nodes.push_back(node);
		}
		++iter;
	}
	auto& nearestNode = base::min(nodes, [&worldPoint](const auto& node) {
		return (node::getNodeCenter(node) - worldPoint).lengthSquared();
	});
	selection_.setSelection({nearestNode});
}

} // namespace dea::interaction