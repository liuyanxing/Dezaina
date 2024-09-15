#include "constraint_layout.h"
#include "change/change.h"
#include "dezaina.h"
#include "document.h"
#include "document/document.h"
#include "node/container.h"
#include "node/node_base.generated.h"

namespace dea::layout {

using namespace document;
using namespace node;

void ContraintLayout::add(const document::EditRecordItem *record) {
  items_.push_back(record);
}

void ContraintLayout::layoutCild(node::Node *node, node::Vector oldSize,
                                 change::Change *change) {
  // Document::Iter iter(node);
  // ++iter;
  // iter.skipChild();
  // while (iter.isValid()) {
  //   auto *child = iter.get();
  //   auto *shape = node_cast<DefaultShapeNode *>(child);
  //
  //   auto *childChange = nodeChange->getChange(child);
  //   auto transform = shape->getTransform();
  //   auto anchorPoint = transform * (child->getAnchor() * shape->getSize());
  //   auto newAnchorPoint = transform * (child->getAnchor() * size);
  //   auto diff = newAnchorPoint - anchorPoint;
  //   transform.translate(diff.x, diff.y);
  //   childChange->set_transform(transform.toChange(pool));
  //   ++iter;
  //   auto constraint = node_cast<ConstraintMixin>(child);
  //   switch (constraint.getHorizontalConstraint()) {}
  // }
}

void ContraintLayout::layout(change::Change &change) {
  auto &pool = change.getPool();
  for (const auto &item : items_) {
    auto &doc = Dezaina::instance().getDocument();
    auto *node = doc.getNodeById(item->nodeId);
    if (!node) {
      continue;
    }
    auto *shape = node_cast<DefaultShapeNode *>(node);
    auto oldSize = shape->getSize();
    auto *nodeChange = change.getNodeChange(node);

    switch (item->type) {
    case RecordType::kSetSize: {
      auto &[size, direction] = std::get<SetSizeValue>(item->value);
      nodeChange->set_size(size.toChange(pool));

      node::Vector achor{0, 0};
      if (direction.x < 0) {
        achor.x = 1;
      }
      if (direction.y < 0) {
        achor.y = 1;
      }

      auto transform = shape->getTransform();
      auto anchorPonit = transform * (achor * shape->getSize());
      auto newAnchorPonit = transform * (achor * size);
      auto diff = newAnchorPonit - anchorPonit;
      transform.translate(-diff.x, -diff.y);
      nodeChange->set_transform(transform.toChange(pool));
      if (node_cast<Container *>(node)) {
        layoutCild(node, oldSize, &change);
      }
      break;
    }
    case RecordType::kTransform: {
      auto &transform = std::get<Matrix>(item->value);
      nodeChange->set_transform(transform.toChange(pool));
      break;
    }
    default:
      assert(false);
      break;
    }
  }
}

} // namespace dea::layout
