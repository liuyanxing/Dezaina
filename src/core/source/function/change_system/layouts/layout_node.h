#pragma once

#include "desaina_node.h"
#include "include/core/SkMatrix.h"
#include "node_type.h"
struct LayoutNode {
  Vector size;
  SkMatrix transform;
  Node* node;
  float topLeftRadius;
  float topRightRadius;
  float bottomLeftRadius;
  float bottomRightRadius;
};