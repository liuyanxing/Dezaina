#pragma once
#include "change/change.h"
#include "document.h"
#include "node.h"

namespace dea::layout {

class Layout {
public:
  virtual void add(const document::EditRecordItem *record) = 0;
  virtual void layout(change::Change &change) = 0;
};

} // namespace dea::layout
