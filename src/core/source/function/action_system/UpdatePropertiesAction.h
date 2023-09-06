#pragma once

#include "action.h"
#include "base_type.h"
#include "desaina_node.h"
#include "node_type.h"
#include "util/node_props.h"
#include "util/skia.h"
#include "util/node_geometry.h"

enum class PropertyType  {
  kNone,
  kTransform,
  kSize,
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
    m.postTranslate(-deltaX, -deltaY);
    PropertyType type = PropertyType::kTransform;
    auto action = make_shared<UpdatePropertiesAction>(node->get_guid(), PropertyType::kTransform, util::toMatrix(m));
    return action;
  }

  static auto MakeRotate(Node* node, float delta) {
    auto m = util::getTransfromMatrix(node);
    m.postRotate(delta);
    PropertyType type = PropertyType::kTransform;
    auto action = make_shared<UpdatePropertiesAction>(node->get_guid(), PropertyType::kTransform, util::toMatrix(m));
    return action;
  }

  static auto MakeResizeDelta(Node* node, float deltaX, float deltaY) {
    auto size = util::getSize(node);
    size.x += deltaX;
    size.y += deltaY;
    PropertyType sizeType = PropertyType::kSize;
    PropertyValue sizeValue = size;
    auto action = make_shared<UpdatePropertiesAction>(node->get_guid(), sizeType, sizeValue);
    return action;
  }
};
