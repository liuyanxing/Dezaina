#include "change/change.h"
#include "dezaina.h"
#include "document.h"
#include "layout.h"

namespace dea::document {

void Document::flushEditor() {
  if (editor_.empty()) {
    return;
  }

  layout::ContraintLayout cLayout{};

  auto &change = Dezaina::instance().getChange();
  auto &pool = change.getPool();
  auto& records = editor_.getRecords();
  for (auto &record : records) {
    auto *node = getNodeById(record.nodeId);
    if (node == nullptr) {
      continue;
    }
    change.addNodeChange(node);
    if (node::node_cast<node::DefaultShapeNode
    >(node) && record.type >= RecordType::kLayoutRelation) {
      cLayout.add(&record);
      continue;
    }

    switch (record.type) {
    case RecordType::kSelection: {
      change.addChange(change::ChangeType::Select,
                       std::get<node::NodeIdArray>(record.value));
      continue;
    }
    default:
      continue;
    }
  }
  cLayout.layout(change);
  editor_.clear();
}

} // namespace dea::document
