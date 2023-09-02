#pragma once

#include "layout.h"
#include "node_type.h"

class ConstraintLayout : public Layout {
  public:
    ConstraintLayout(Desaina* desaina) : Layout(desaina) {};
    ~ConstraintLayout() = default;

    void hanldeTransfrom(UpdatePropertiesAction* action, vector<NodeChange*>& changes, kiwiPool& pool);
    void hanldeSize(UpdatePropertiesAction* action, vector<NodeChange*>& changes, kiwiPool& pool);
    
    bool processUpdatePropertiesAction(UpdatePropertiesAction* action, vector<NodeChange*>& changes, kiwiPool& pool) override;
};
