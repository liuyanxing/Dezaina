#pragma once

#include "common/object.h"
#include "node.h"
#include "schema/message.h"
#include <variant>
#include <vector>
#include "undoRedo.h"

namespace dea::change {

enum class ChangeType {
	Select,
	NodeChange,
};

using ChangeValue = std::variant<message::NodeChange*, node::NodeArary>;

struct ChangeItem {
	ChangeType type;
	ChangeValue value;	
};

class Change : public base::NonCopyable {
public:
	message::NodeChange* addNodeChange(node::Node* node) {
		if (changeMap_.find(node) == changeMap_.end()) {
			changeMap_[node] = pool_.allocate<message::NodeChange>();
		}
		return changeMap_[node];
	}

	void addChange(ChangeType type, ChangeValue&& value) { items_.emplace_back(type, std::move(value)); }
	auto& getPool() { return pool_; }
	void clear() { items_.clear(); }
	void flush();

private:
  std::vector<ChangeItem> items_;
	UndoRedo<ChangeItem> undoRedo_;
	kiwi::MemoryPool pool_;
	std::unordered_map<node::Node*, message::NodeChange*> changeMap_{};

};

} // namespace dea