#pragma once

#include <stdint.h>
#include "base/buffer.h"
#include "base_type.h"
using Blob = Buffer;

namespace std {
  template<>
  struct hash<Blob> {
    size_t operator()(const Blob& buffer) const {
      return std::hash<std::string_view>()(std::string_view(reinterpret_cast<const char*>(buffer.data()), buffer.size()));
    }
  };
}

class BlobService {
public:
  uint32_t addBlob(Blob&& blob);
  const Blob& getBlob(uint32_t index) const {
    return index_to_blobs_.at(index);
  }

private:
  unordered_map<Blob, int> blobs_to_index_;
  unordered_map<uint32_t, Blob> index_to_blobs_;
  unordered_set<uint32_t> blob_sizes_;
};
