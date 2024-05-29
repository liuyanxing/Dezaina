#include "layout_processor.h"
#include "desaina_node.h"
#include "edit/editor.h"
#include "change_system/change_system.h"
#include "include/core/SkMatrix.h"

namespace LayoutProcessor {
  void processSetSize(const EditRecordItem& record, ChangeSystem* changeSystem) {
    if (record.type != RecordType::kResize) {
      return;
    }
    auto changeItem = changeSystem->getChangingItem(record.nodeId);
    const auto& sizeAndAnchor = get<ResizeValue>(record.value);
    auto& size_val = sizeAndAnchor[0];
    auto& anchor = sizeAndAnchor[1];
    Vector size{size_val.x(), size_val.y()};
    changeItem->layoutNode->size = size;
  }

  void processSetTransform(const EditRecordItem& record, ChangeSystem* changeSystem) {
    if (record.type != RecordType::kTransform) {
      return;
    }
    auto changeItem = changeSystem->getChangingItem(record.nodeId);
    const auto& transform = get<SkMatrix>(record.value);
    changeItem->layoutNode->transform = transform;
  }

  void processSetRotate(const EditRecordItem&, ChangeSystem* changeSystem) {

  }
}