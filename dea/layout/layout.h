#pragma once
#include "change/change.h"
#include "document.h"
#include "node.h"
#include <vector>
#include "document.h"

namespace dea::layout {

class Layout {
public:
	virtual void add(const document::EditRecordItem* record) = 0;
	virtual void layout() = 0;
};

} // namespace dea::layout
