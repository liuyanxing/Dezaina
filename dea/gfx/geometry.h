#include "base/data.h"
#include "node.h"

namespace dea::gfx {

enum PathVerb : uint8_t { CLOSE = 0, MOVE = 1, LINE = 2, QUAD = 3, CUBIC = 4 };
base::Data buildFill(node::NodeConstPtr node);

} // namespace dea::geometry
