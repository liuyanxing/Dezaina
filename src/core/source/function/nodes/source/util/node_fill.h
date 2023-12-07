#include "change/change_type.h"
#include "desaina_node.h"
#include "node_type.h"

namespace node {
  inline SolidPaint MakeSolidPaint(float r, float g, float b, float a) {
    SolidPaint paint;
    paint.type = PaintType::SOLID;
    paint.blendMode = BlendMode::PASS_THROUGH; 
    paint.set_color({r, g, b, a});
    return paint;
  }

  inline void setFillPaints(Node* node, const IVector<PaintUnion>& paints) {
    static_cast<DefaultShapeNode*>(node)->set_fillPaints(paints);
  }
}