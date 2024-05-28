#include "base_type.h"
#include "desaina.h"
#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "include/core/SkSurface.h"
#include "node_type.h"

class InteractionUtil {
public:
  InteractionUtil(Desaina* desaina) : desaina_(desaina) {
    init();
  };
  vector<Node*> getNodesUnderCursor();
  SkColor readColorAtPointOfNode(float x, float y, const Node* node, const vector<SkPaint>& paints);
  bool isCursorOnNodePixel(float x, float y, const Node* node);
private:
  Desaina* desaina_ = nullptr;
  sk_sp<SkSurface> read_color_surface_;
  uint8_t* pixes_;

  void init();
};