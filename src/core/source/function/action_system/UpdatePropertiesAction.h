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
  kRezieDelta,
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

  static auto MakeTranslate(Node* node, float deltaX, float deltaY) {
    auto m = util::getTransfromMatrix(node);
    m.preTranslate(deltaX, deltaY);
    PropertyType type = PropertyType::kTransform;
    auto action = make_shared<UpdatePropertiesAction>(node->get_guid(), PropertyType::kTransform, util::toMatrix(m));
    return action;
  }

  static auto MakeRotateDelta(Node* node, float degrees) {
    auto m = util::getTransfromMatrix(node);
    auto size = util::getSize(node);
    SkMatrix rotationMatrix;
    rotationMatrix.setRotate(degrees, size.x / 2, size.y / 2);
    m.preConcat(rotationMatrix);
    PropertyType type = PropertyType::kTransform;
    auto action = make_shared<UpdatePropertiesAction>(node->get_guid(), PropertyType::kTransform, util::toMatrix(m));
    return action;
  }

  static auto MakeResizeDelta(Node* node, float deltaX, float deltaY) {
    PropertyType sizeType = PropertyType::kRezieDelta;
    PropertyValue sizeValue = Vector{deltaX, deltaY};
    auto action = make_shared<UpdatePropertiesAction>(node->get_guid(), sizeType, sizeValue);
    return action;
  }
};
