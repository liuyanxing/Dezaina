#include "blob_service.h"
#include <algorithm>
#include <stdint.h>

uint32_t BlobService::addBlob(const Blob& blob) {
  if (blob_sizes_.find(blob.buffer()->size()) == blob_sizes_.end()) {
    goto insert;
  }
  if (auto it = blobs_to_index_.find(blob); it != blobs_to_index_.end()) {
    return it->second;
  }
insert:
  auto size = blob.buffer()->size();
  uint32_t index = blobs_to_index_.size();
  auto pair = blobs_to_index_.insert({blob, index});
  index_to_blobs_[index] = const_cast<Blob*>(&pair.first->first);
  blob_sizes_.insert(size);
  return index;
}
