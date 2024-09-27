#pragma once

#include "layout.h"

namespace dea::layout {

class ContraintLayout : public Layout {
public:
  void layout(change::Change &change) override;
  void add(const document::EditRecordItem *record) override;
  static void layoutCild(node::Node *node, node::Vector newSize,
                         change::Change *nodeChange = nullptr);

private:
  std::vector<const document::EditRecordItem *> items_;
};

} // namespace dea::layout
