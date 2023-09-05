#pragma once

#include <cstring>
#include <stddef.h>
#include <stdint.h>

class Buffer {
public:
  Buffer() : size_(0), data_(nullptr) {}
  Buffer(const Buffer& other) = delete;
  Buffer(Buffer&& other) {
    this->data_ = other.data_;
    this->size_ = other.size_;
    other.data_ = nullptr;
  };
  ~Buffer() {
    if (is_owned) {
      delete[] data_;
    }
  }

  uint8_t* data() const {
    return data_;
  }

  size_t size() const {
    return size_;
  }

  void set(const uint8_t* data, size_t size) {
    if (is_owned) {
      delete[] this->data_;
    }
    this->data_ = new uint8_t[size];
    this->size_ = size;
    this->is_owned = true;
    memcpy(this->data_, data, size);
  }

  static Buffer MakeWithCopy(const uint8_t* data, size_t size) {
    Buffer buffer;
    buffer.data_ = new uint8_t[size];
    buffer.size_ = size;
    buffer.is_owned = true;
    memcpy(buffer.data_, data, size);
    return buffer;
  }

  static char readByte(const uint8_t* buffer, int offset) {
    return buffer[offset];
  }

  static int readInt32(const uint8_t* buffer, int offset) {
    return buffer[offset + 3] << 24 | buffer[offset + 2] << 16 | buffer[offset + 1] << 8 | buffer[offset];
  }

  static float readFloat(const uint8_t* buffer, int offset) {
    int i = readInt32(buffer, offset);
    return *reinterpret_cast<float*>(&i);
  }
private:
  size_t size_;
  uint8_t* data_;
  bool is_owned = false;
};
