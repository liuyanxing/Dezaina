#pragma once

#include "id_generator.h"
#include <memory>

struct Services {
  std::unique_ptr<IdGenerator> idGenerator = nullptr;
};