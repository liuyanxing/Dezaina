#pragma once

#include "desaina.h"
#include "layout.h"
#include "node_type.h"

class AutoLayout : public Layout {
  public:
    AutoLayout(Desaina* desaina) : Layout(desaina) {};
    ~AutoLayout() = default;
    
    bool processUpdatePropertiesAction(UpdatePropertiesAction* action, vector<NodeChange*>& changes, kiwiPool& pool) override;
};
