#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "node.h"
#include "resource.h"
#include "schema/message.h"
#include "command.h"
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
	if (items_.empty() && nodeChanges_.empty()) {
		return;
	}

	if (!nodeChanges_.empty()) {
		NodeChangesCommand::Make(nodeChanges_, pool_)->execute();
	}
	std::unique_ptr<Command> command;
	auto& doc = Dezaina::instance().document();
	for (auto& item : items_) {
		switch (item.type) {
			case ChangeType::Select:
				command = SelectionCommand::Make(std::get<NodeIdArray>(item.value));
				break;
			default:
				assert(false);
				break;
		}
		command->execute();
	}
	clear();
}

} // namespace dea