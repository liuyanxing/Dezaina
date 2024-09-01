#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "change.h"
#include "dezaina.h"

namespace dea::change {

void Change::flush() {
	auto& dezaina = Dezaina::instance();
	auto& doc = dezaina.getDocument();
	for (auto& item : items_) {
		undoRedo_.recordChange(item);

		switch (item.type) {
			case ChangeType::Select:
				doc.setSelection(std::move(std::get<node::NodeIdArray>(item.value)));
				break;
			case ChangeType::NodeChange:
				doc.updateNode(std::get<message::NodeChange*>(item.value));
				break;
		}
	}
	clear();
}

} // namespace dea