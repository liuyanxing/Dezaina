#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <memory>
#include <string_view>

namespace dea::base {
class Buffer {
public:
  Buffer();
  Buffer(uint8_t *data, size_t size);
  Buffer(const uint8_t *data, size_t size);
  Buffer(const Buffer& other) { *this = other; };
  Buffer& operator=(const Buffer& other) noexcept;
  Buffer(Buffer&& other) noexcept { *this = std::move(other); };
  Buffer& operator=(Buffer&& other) noexcept;

  ~Buffer();
  bool operator==(const Buffer& other) const {
    return size_ == other.size_ && memcmp(data_, other.data_, size_) == 0;
  }


  static Buffer MakeEmpty() { return Buffer(static_cast<uint8_t*>(nullptr), 0); };
  static Buffer MakeWithCopy(const uint8_t* data, size_t size);

  uint8_t *data() const { return data_; }
  size_t size() const { return size_; }
  size_t index() const { return index_; }
  bool isEnd() const { return index_ >= size_; }
  void set(const uint8_t *data, size_t size);
  void seek(size_t offset) const { index_ = offset; };

  uint8_t readByte() const;
  float readFloat() const;
  uint32_t readUint() const;
  int readInt() const;

  void writeByte(uint8_t value);
  void writeFloat(float value);
  void writeUint(uint32_t value);
  void writeInt(int32_t value);

private:
  void growBy_(size_t amount);

  enum { INITIAL_CAPACITY = 256 };
  uint8_t *data_ = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;
  mutable size_t index_ = 0;
  bool is_owned_ = false;
};



using shData = std::shared_ptr<Data>;
using wkData = std::weak_ptr<Data>;

}

namespace std {
  template<>
  struct hash<dea::base::Buffer> {
    size_t operator()(const dea::base::Buffer& Buffer) const {
      return std::hash<std::string_view>()(std::string_view(reinterpret_cast<const char*>(Buffer.data()), Buffer.size()));
    }
  };
}