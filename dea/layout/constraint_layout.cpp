#include "constraint_layout.h"
#include "change/change.h"
#include "dezaina.h"
#include "document.h"
#include "document/document.h"
#include "node/container.h"
#include "node/node_base.generated.h"
#include <array>
#include <optional>

namespace dea::layout {

using namespace document;
using namespace node;

static std::array<float, 2> layoutImpl(float pos, float size, float parentSize,
                                       float parentNewSize,
                                       ConstraintType constraint) {
  float newPos = pos;
  float newSize = size;
  if (constraint == ConstraintType::MAX) {
    newPos = pos + (parentNewSize - parentSize);
  } else if (constraint == ConstraintType::CENTER) {
    newPos = ((pos + size / 2) / parentSize) * parentNewSize - size / 2;
  } else if (constraint == ConstraintType::STRETCH) {
    newSize = parentNewSize - (parentSize - size);
  } else if (constraint == ConstraintType::SCALE) {
    newSize = size * parentNewSize / parentSize;
    newPos = ((pos + size / 2) / parentSize) * parentNewSize - newSize / 2;
  }
  return {newPos, newSize};
}

void ContraintLayout::add(const document::EditRecordItem *record) {
  items_.push_back(record);
}

void ContraintLayout::layoutCild(node::Node *node, node::Vector newSize,
                                 change::Change *change) {
  auto *parentShape = node_cast<DefaultShapeNode>(node);
  if (!parentShape) {
    return;
  }
  auto parentSize = parentShape->getSize();
  Document::Iter iter(node);
  ++iter;
  iter.skipChild();
  while (iter.isValid()) {
    auto *child = iter.get();
    auto *shape = node_cast<DefaultShapeNode>(child);
    auto *constraint = node_cast<ConstraintMixin>(child);
    if (!child || !constraint) {
      ++iter;
      continue;
    }

    auto hConstraint = constraint->getHorizontalConstraint();
    auto vConstraint = constraint->getVerticalConstraint();
    auto transform = shape->getTransform();
    auto size = shape->getSize();
    // todo: pos is not correct, should consider the rotation
    auto pos =
        node::Vector(transform.getTranslateX(), transform.getTranslateY());

    auto [newX, newWidth] =
        layoutImpl(pos.x, size.x, parentSize.x, newSize.x, hConstraint);
    auto [newY, newHeight] =
        layoutImpl(pos.y, size.y, parentSize.y, newSize.y, vConstraint);

    auto *nodeChange = change ? change->getNodeChange(child) : nullptr;
    if (node::Vector(newX, newY) != pos) {
      transform.setTranslate(newX, newY);
      nodeChange
          ? nodeChange->set_transform(transform.toChange(change->getPool()))
          : shape->setTransform(transform);
    }

    if (node::Vector(newWidth, newHeight) != size) {
      auto newSize = node::Vector(newWidth, newHeight);
      nodeChange ? nodeChange->set_size(newSize.toChange(change->getPool()))
                 : shape->setSize(newSize);
    }
    ++iter;
  }
}

void ContraintLayout::layout(change::Change &change) {
  auto &pool = change.getPool();
  for (const auto &item : items_) {
    auto &doc = Dezaina::instance().getDocument();
    auto *node = doc.getNodeById(item->nodeId);
    if (!node) {
      continue;
    }
    auto *shape = node_cast<DefaultShapeNode>(node);
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
      auto diff =
          transform * (achor * size) - transform * (achor * shape->getSize());
      transform.translate(-diff.x, -diff.y);
      nodeChange->set_transform(transform.toChange(pool));
      if (node_cast<Container>(node)) {
        layoutCild(node, size, &change);
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
