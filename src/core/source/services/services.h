#pragma once

#include "id_generator.h"
#include "services/blob_service.h"
#include <memory>

struct Services {
  std::unique_ptr<IdGenerator> idGenerator = nullptr;
  std::unique_ptr<BlobService> blobService = nullptr;
};