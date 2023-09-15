#pragma once

#include "include/core/SkPath.h"
#include "edit_system/editor/vector_editor_data.h"
namespace util {
  void networkToSkPath(VectorEditor::Network& network, SkPath& path);
  vector<SkPath> computeFillGeometryPath(const SkPath& path);
}
