#pragma once
#include "vendor/figma/kiwi.h"

namespace dea::change {
class Change {
public:
		Change();
		bool applyMessage(kiwi::ByteBuffer& buffer);
};

} // namespace dea::change