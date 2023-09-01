#pragma once

#include "desaina.h"
#include "layout.h"
#include "node_type.h"

class ConstraintLayout : public Layout {
  public:
    ConstraintLayout(Desaina* desaina) : Layout(desaina) {};
    ~ConstraintLayout() = default;
    
    bool processUpdatePropertiesAction(UpdatePropertiesAction* action, vector<NodeChange*>& changes, kiwiPool& pool) override;
};
