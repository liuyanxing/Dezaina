#pragma once

#include <stdint.h>
#include "buffer.h"
#include "base_type.h"

struct BlobAttachment {
  virtual ~BlobAttachment() = default;
};

class Blob {
public:
  Blob(Buffer data, BlobAttachment* attachment): data_(data), attachment(attachment) {};
  Blob(Buffer data): data_(data), attachment(nullptr) {};
  ~Blob() {
    if (attachment) {
      delete attachment;
    }
  }

  bool operator==(const Blob& other) const {
    return data_ == other.data_;
  }

  template<typename T, typename ...Args>
  T* setAttachment(const Args&... args) {
    attachment = new T(args...);
    return static_cast<T*>(attachment);
  }

  template<typename T>
  T* getAttachment() {
    return static_cast<T*>(attachment);
  }
  
  const Buffer* buffer() const { return &data_; }
  auto* data() const { return data_.data(); }
  auto size() const { return data_.size(); }

  private:
    Buffer data_;
    BlobAttachment* attachment;
};

namespace std {
  template<>
  struct hash<Blob> {
    size_t operator()(const Blob& blob) const {
      const auto& buffer = *(blob.buffer());
      return std::hash<std::string_view>()(std::string_view(reinterpret_cast<const char*>(buffer.data()), buffer.size()));
    }
  };
}

using BlobPair = std::pair<uint32_t, Blob*>;
class BlobService {
public:
  uint32_t addBlob(const Blob& blob);
  Blob* getBlob(uint32_t index) {
    return index_to_blobs_.at(index);
  }

private:
  unordered_map<Blob, int> blobs_to_index_;
  unordered_map<uint32_t, Blob*> index_to_blobs_;
  unordered_set<uint32_t> blob_sizes_;
};


