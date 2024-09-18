#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include "object.h"
#include "data.h"

namespace dea::base {
class Buffer : public NonCopyable {
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

  Data toData() const {  Data data(reinterpret_cast<char*>(data_) , size_); data_ = nullptr; return data; };
  static Buffer MakeEmpty() { return Buffer(static_cast<uint8_t*>(nullptr), 0); };
  static Buffer MakeWithCopy(const uint8_t* data, size_t size);

  uint8_t *data() const { return data_; }
  size_t size() const { return cursor_; }
  void set(const uint8_t *data, size_t size);
  void seek(size_t offset) const { cursor_ = offset; };

  uint8_t readByte() const;
  float readFloat() const;
  uint32_t readUint() const;
  int readInt() const;

  void writeByte(uint8_t value);
  void writeFloat(float value);
  void writeUint(uint32_t value);
  void writeInt(int32_t value);
  void writeV2f(float x, float y);

  template<typename ...F>
  void write(F... args) {
    (write(args), ...);
  }


private:
  void growBy_(size_t amount);

  enum { INITIAL_CAPACITY = 256 };
  uint8_t *data_ = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;
  mutable size_t cursor_ = 0;
  bool is_owned_ = false;
};

}

