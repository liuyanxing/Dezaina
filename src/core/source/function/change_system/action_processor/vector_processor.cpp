#include "vector_processor.h"
#include "change_system/change_system.h"
#include "desaina_node.h"
#include "services/blob_service.h"
#include <cassert>
#include <unordered_set>

void processVectorData(ChangeSystem* changeSystem, const UpdatePropertiesAction& action) {
  auto* blob = std::get<Blob*>(action.propertyValue);
  auto changeItem = changeSystem->getChangingItem(action.node_id);
  auto* pool = changeSystem->pool();
  auto* nodeChange = changeItem->changeNode;
  VectorData vectorData;
  vectorData.vectorNetworkBlob = changeSystem->addBlob(blob);
  nodeChange->set_vectorData(vectorData.toChange(*pool));

  changeItem->isFillGeometryDirty = true;
  changeItem->isStrokeGeometryDirty = true;
}

bool processVector(ChangeSystem* change_system, const UpdatePropertiesAction& action) {
  static unordered_set<PropertyType> relatedProperties = {PropertyType::kVectorData};
  if (!relatedProperties.contains(action.propertyType)) {
    return false;
  }
  switch (action.propertyType) {
  case PropertyType::kVectorData:
    processVectorData(change_system, action);
    break;
  default:
    break;
  }
  return true;
}
