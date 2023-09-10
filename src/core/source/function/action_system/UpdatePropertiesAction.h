#pragma once

#include "action.h"
#include "base_type.h"
#include "desaina_node.h"
#include "include/core/SkMatrix.h"
#include "node_type.h"
#include "util/node_props.h"
#include "util/skia.h"
#include "util/node_geometry.h"

enum class PropertyType  {
  kNone,
  kTransform,
  kSize,
  kResizeDelta,
  kRotation,
};
using PropertyValue = variant<float, int, Vector, Matrix>;

struct UpdatePropertiesAction : public Action {
  UpdatePropertiesAction(GUID id, const PropertyType& property_type, const PropertyValue& property_value) : 
    node_id(id), propertyType(property_type), propertyValue(property_value), Action(ActionType::kUpdateProperties) {};
  
  const PropertyType propertyType;
  const PropertyValue propertyValue;
  const GUID node_id;

  static auto Make(const GUID id, const PropertyType& property_type, const PropertyValue& property_value) {
    auto action = make_shared<UpdatePropertiesAction>(id, property_type, property_value);
    return action;
  }

  static auto MakeSetTransform(const SkMatrix& transform, const Node* node) {
    PropertyType type = PropertyType::kTransform;
    return Make(node->get_guid(), PropertyType::kTransform, util::toMatrix(transform));
  }

  static auto MakeSetTranslate(float x, float y, const Node* node) {
    SkMatrix transform = util::computeTransform({x, y}, util::getRotation(node), node);
    return MakeSetTransform(transform, node);
  }


  static auto MakeSetRotate(float rotation, const Node* node) {
    SkMatrix transform = util::computeTransform(util::getTranslate(node), rotation, node);
    return MakeSetTransform(transform, node);
  }

  static auto MakeSetSize(float width, float height, const Node* node) {
    PropertyType sizeType = PropertyType::kSize;
    PropertyValue sizeValue = Vector{width, height};
    return Make(node->get_guid(), sizeType, sizeValue);
  }
};
