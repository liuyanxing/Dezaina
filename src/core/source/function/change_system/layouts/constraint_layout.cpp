#include "constraint_layout.h"

bool ConstraintLayout::processUpdatePropertiesAction(UpdatePropertiesAction *action, vector<NodeChange*> &changes, kiwiPool &pool) {
  auto nodeOpt = desaina_->document.getNodeById(action->node_id);
  if (!nodeOpt.has_value()) {
    return true;
  }
  auto* node = nodeOpt.value();
  if (action->propertyType == PropertyType::kSize) {
    auto size = get<Vector>(action->propertyValue);
    auto* nodeChange = pool.allocate<NodeChange>();
    nodeChange->set_size(size.toChange(pool));
		changes.push_back(nodeChange);
	}
    
  return true;
}
