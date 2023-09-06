#pragma once

#include <stdint.h>
#include "buffer.h"
#include "base_type.h"
using Blob = Buffer;


class BlobService {
public:
  uint32_t addBlob(const Blob& blob);
  const Blob* getBlob(uint32_t index) const {
    return index_to_blobs_.at(index);
  }

private:
  unordered_map<Blob, int> blobs_to_index_;
  unordered_map<uint32_t, const Blob*> index_to_blobs_;
  unordered_set<uint32_t> blob_sizes_;
};
