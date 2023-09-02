#pragma once

#include "action_system/UpdatePropertiesAction.h"
#include "node_type.h"

class Desaina;
class Layout {
  public:
    Layout(Desaina* desaina) : desaina_(desaina) {};
    ~Layout() = default;
    
    virtual bool processUpdatePropertiesAction(UpdatePropertiesAction* action, vector<NodeChange*>& changes, kiwiPool& pool) = 0;
  protected:
    Desaina* desaina_;
};
