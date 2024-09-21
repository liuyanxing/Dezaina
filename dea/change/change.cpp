#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "node/type.generated.h"
#include "resource/blob.h"
#include "schema/message.h"


#include "change.h"
#include "dezaina.h"
#include "geometry/geometry.h"

namespace dea::change {

using namespace base;
using namespace node;

void Change::addChange(ChangeType type, ChangeValue&& value) {
	items_.emplace_back(type, std::move(value));
}

void Change::flush() {
	if (items_.empty() && nodeChangesMap_.empty()) {
		return;
	}

	auto& doc = Dezaina::instance().document();
	for (auto& item : items_) {
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