#include "blob_service.h"
#include <stdint.h>

uint32_t BlobService::addBlob(Blob&& blob) {
  if (blob_sizes_.find(blob.size()) == blob_sizes_.end()) {
    goto insert;
  }
  if (auto it = blobs_to_index_.find(blob); it != blobs_to_index_.end()) {
    return it->second;
  }
insert:
  uint32_t index = blobs_to_index_.size();
  blobs_to_index_[blob] = index;
  index_to_blobs_[index] = blob;
  blob_sizes_.insert(blob.size());
  return index;
}