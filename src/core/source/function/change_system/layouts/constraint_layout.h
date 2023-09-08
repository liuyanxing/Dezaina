#pragma once

#include "layout.h"
#include "node_type.h"

class ConstraintLayout : public Layout {
  public:
    ConstraintLayout(Desaina* desaina) : Layout(desaina) {};
    ~ConstraintLayout() = default;

    void hanldeTransfrom(const UpdatePropertiesAction* action, kiwiPool& pool);
    void hanldeResize(const UpdatePropertiesAction* action, kiwiPool& pool);
    void hanldeResizeDelta(const UpdatePropertiesAction* action, kiwiPool& pool);
    
    bool processUpdatePropertiesAction(const UpdatePropertiesAction* action, kiwiPool& pool) override;
};
