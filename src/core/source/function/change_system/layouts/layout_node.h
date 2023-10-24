#pragma once

#include "desaina_node.h"
#include "include/core/SkMatrix.h"
#include "node_type.h"
#include "services/blob_service.h"
struct LayoutNode {
  Vector size;
  SkMatrix transform;
  Node* node;
  Blob* vectorData;
  float topLeftRadius;
  float topRightRadius;
  float bottomLeftRadius;
  float bottomRightRadius;
};