#pragma once

#include "data.h"
#include "object.h"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>

namespace dea::base {
class Buffer : public NonCopyable {
public:
  Buffer();
  Buffer(uint8_t *data, size_t size);
  Buffer(const uint8_t *data, size_t size);
  Buffer(const Buffer &other) { *this = other; };
  Buffer &operator=(const Buffer &other) noexcept;
  Buffer(Buffer &&other) noexcept { *this = std::move(other); };
  Buffer &operator=(Buffer &&other) noexcept;

  ~Buffer();
  bool operator==(const Buffer &other) const {
    return size() == other.size() && memcmp(data_, other.data_, cursor_) == 0;
  }

  Data toData() {
    Data data(reinterpret_cast<char *>(data_), size());
    data_ = nullptr;
    return data;
  };

  static Buffer MakeEmpty() {
    return Buffer(static_cast<uint8_t *>(nullptr), 0);
  };
  static Buffer MakeWithCopy(const uint8_t *data, size_t size);

  uint8_t *data() const { return data_; }
  size_t size() const { return size_; }
  void set(const uint8_t *data, size_t size);
  void seek(size_t offset) const { cursor_ = offset; };
  bool isEnd() const { return cursor_ >= size(); }

  uint8_t readByte() const;
  float readFloat() const;
  uint32_t readUint() const;
  int readInt() const;

  void writeByte(uint8_t value);
  void writeFloat(float value);
  void writeUint(uint32_t value);
  void writeInt(int32_t value);
  void writeV2f(float x, float y);

  template <typename T> void write(T value) {
    if (sizeof(T) == 1) {
      writeByte(*reinterpret_cast<const uint8_t *>(&value));
    } else if (sizeof(T) == 4) {
      writeUint(*reinterpret_cast<const uint32_t *>(&value));
    } else if (sizeof(T) == 8) {
      writeUint(*reinterpret_cast<const uint64_t *>(&value));
    } else {
      static_assert(sizeof(T) == 1 || sizeof(T) == 4 || sizeof(T) == 8,
                    "Not supported type");
    }
  }

  template <typename... F> void write(F... args) {
    auto size = (sizeof(F) + ...);
    growBy_(size);
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

} // namespace dea::base
