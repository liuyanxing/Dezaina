#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "change.h"
#include "dezaina.h"

namespace dea::change {

void Change::addChange(ChangeType type, ChangeValue&& value) {
	items_.emplace_back(type, std::move(value));
}

void Change::flush() {
	if (items_.empty() && changeMap_.empty()) {
		return;
	}
	auto& dezaina = Dezaina::instance();
	auto& doc = dezaina.getDocument();
	for (auto& [_, nodeChange] : changeMap_) {
		doc.applyNodeChange(nodeChange);
	}
	for (auto& item : items_) {
		undoRedo_.recordChange(item);

		switch (item.type) {
			case ChangeType::Select:
				doc.setSelection(std::move(std::get<node::NodeIdArray>(item.value)));
				break;
			default:
				assert(false);
				break;
		}
	}
	clear();
}

} // namespace dea