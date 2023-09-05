#pragma once

#include "layout.h"
#include "node_type.h"

class AutoLayout : public Layout {
  public:
    AutoLayout(Desaina* desaina) : Layout(desaina) {};
    ~AutoLayout() = default;
    
    bool processUpdatePropertiesAction(const UpdatePropertiesAction* action, kiwiPool& pool) override;
};
