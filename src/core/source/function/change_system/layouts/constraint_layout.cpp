#include "desaina.h"
#include "constraint_layout.h"

bool ConstraintLayout::processUpdatePropertiesAction(UpdatePropertiesAction *action, vector<NodeChange*> &changes, kiwiPool &pool) {
  auto nodeOpt = desaina_->document.getNodeById(action->node_id);
  if (!nodeOpt.has_value()) {
    return true;
  }

  switch (action->propertyType) {
    case PropertyType::kTransform:
      hanldeTransfrom(action, changes, pool);
      break;
    case PropertyType::kSize:
      hanldeSize(action, changes, pool);
      break;
    default:
      break;
  }
    
  return true;
}

void ConstraintLayout::hanldeTransfrom(UpdatePropertiesAction *action, vector<NodeChange*> &changes, kiwiPool &pool) {
  auto nodeOpt = desaina_->document.getNodeById(action->node_id);
  if (!nodeOpt.has_value()) {
    return;
  }
  auto* nodeChange = pool.allocate<NodeChange>();
  auto transform = get<Matrix>(action->propertyValue);
  nodeChange->set_guid(action->node_id.toChange(pool));
  nodeChange->set_transform(transform.toChange(pool));
  changes.push_back(nodeChange);
}

void ConstraintLayout::hanldeSize(UpdatePropertiesAction *action, vector<NodeChange*> &changes, kiwiPool &pool) {
    auto size = get<Vector>(action->propertyValue);
    auto* nodeChange = pool.allocate<NodeChange>();
    nodeChange->set_guid(action->node_id.toChange(pool));
    nodeChange->set_size(size.toChange(pool));
		changes.push_back(nodeChange);
}
