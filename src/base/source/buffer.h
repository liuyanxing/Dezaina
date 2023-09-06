#pragma once

#include <cstring>
#include <stddef.h>
#include <stdint.h>
#include <string_view>

class Buffer {
public:
  Buffer();
  Buffer(uint8_t *data, size_t size);
  Buffer(const uint8_t *data, size_t size);
  Buffer(const Buffer& other) { *this = other; };
  Buffer& operator=(const Buffer& other) {
    if (this != &other) {
      if (owns_data_) {
        delete[] data_;
      }
      data_ = new uint8_t[capacity_];
      memcpy(data_, other.data_, size_);
      owns_data_ = true;
      size_ = other.size_;
    }
    return *this;
  }

  ~Buffer();
  bool operator==(const Buffer& other) const {
    return size_ == other.size_ && memcmp(data_, other.data_, size_) == 0;
  }


  static Buffer MakeWithCopy(const uint8_t* data, size_t size);

  uint8_t *data() const { return data_; }
  size_t size() const { return size_; }
  size_t index() const { return index_; }
  void setIndex(size_t index) { index_ = index; }
  void set(const uint8_t *data, size_t size);

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
  bool owns_data_ = false;
  bool is_const_ = false;
};

namespace std {
  template<>
  struct hash<Buffer> {
    size_t operator()(const Buffer& buffer) const {
      return std::hash<std::string_view>()(std::string_view(reinterpret_cast<const char*>(buffer.data()), buffer.size()));
    }
  };
}