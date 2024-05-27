#pragma once

#include "base_type.h"

class ChangeSystem;
struct EditRecordItem;

namespace LayoutProcessor {
  void processSetSize(const EditRecordItem&, ChangeSystem* ChangeSystem);
  void processSetTransform(const EditRecordItem&, ChangeSystem* ChangeSystem);
  void processSetRotate(const EditRecordItem&, ChangeSystem* ChangeSystem);
}
