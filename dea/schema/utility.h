#include "message.h"

namespace dea::schema
{
  inline void invalidateFillPath(message::NodeChange *nodeChange, kiwi::MemoryPool &pool) {
    auto& pathes = nodeChange->set_fillGeometry(pool, 1);
    pathes[0].set_commandsBlob(UINT32_MAX);
  }

  inline void invalidateStrokePath(message::NodeChange *nodeChange, kiwi::MemoryPool &pool) {
    auto& pathes = nodeChange->set_strokeGeometry(pool, 1);
    pathes[0].set_commandsBlob(UINT32_MAX);
  }

  inline void invalidatePath(message::NodeChange *nodeChange, kiwi::MemoryPool &pool) {
    invalidateFillPath(nodeChange, pool);
    invalidateStrokePath(nodeChange, pool);
  }

  inline bool isFillPathValid(message::NodeChange *nodeChange) {
    if (nodeChange->fillGeometry()->size() == 0) {
      return true;
    }
    return *nodeChange->fillGeometry()->begin()->commandsBlob() != UINT32_MAX; 
  }

  inline bool isStrokePathValid(message::NodeChange *nodeChange) {
    if (nodeChange->strokeGeometry()->size() == 0) {
      return true;
    }
    return *nodeChange->strokeGeometry()->begin()->commandsBlob() != UINT32_MAX; 
  }

  inline bool isPathValid(message::NodeChange *nodeChange) {
    return isFillPathValid(nodeChange) && isStrokePathValid(nodeChange);
  }
  
} // namespace dea::schema
