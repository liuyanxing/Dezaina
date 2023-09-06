#include "buffer.h"
#include <stdint.h>

Buffer::Buffer() {
  data_ = new uint8_t[INITIAL_CAPACITY];
  capacity_ = INITIAL_CAPACITY;
  owns_data_ = true;
}

Buffer::Buffer(uint8_t *data, size_t size) {
  data_ = data;
  size_ = size;
  capacity_ = size;
  is_const_ = true;
}

Buffer::Buffer(const uint8_t *data, size_t size) {
  data_ = const_cast<uint8_t*>(data);
  size_ = size;
  capacity_ = size;
  is_const_ = true;
}

Buffer::~Buffer() {
  if (owns_data_ && data_ != nullptr) {
    delete[] data_;
  }
}

void Buffer::set(const uint8_t *data, size_t size) {
  if (owns_data_) {
    delete[] data_;
  }
  data_ = new uint8_t[size];
  size_ = size;
  memcpy(data_, data, size);
  capacity_ = size;
  is_const_ = false;
  owns_data_ = true;
}

Buffer Buffer::MakeWithCopy(const uint8_t* data, size_t size) {
  Buffer buffer;
  buffer.set(data, size);
  return buffer;
}

uint8_t Buffer::readByte() const {
  return data_[index_++];
}

float Buffer::readFloat() const {
  uint32_t value = readUint();
  return reinterpret_cast<float&>(value);
}

uint32_t Buffer::readUint() const {
  uint32_t value = 0;
  value |= data_[index_++];
  value |= data_[index_++] << 8;
  value |= data_[index_++] << 16;
  value |= data_[index_++] << 24;
  return value;
}

int32_t Buffer::readInt() const {
  uint32_t value = readUint();
  return reinterpret_cast<int32_t&>(value);
}

void Buffer::writeByte(uint8_t value) {
  growBy_(1);
  data_[index_++] = value;
}

void Buffer::writeFloat(float value) {
  writeUint(reinterpret_cast<uint32_t&>(value));
}

void Buffer::writeUint(uint32_t value) {
  growBy_(4);
  data_[index_++] = value;
  data_[index_++] = value >> 8;
  data_[index_++] = value >> 16;
  data_[index_++] = value >> 24;
}

void Buffer::writeInt(int32_t value) {
  growBy_(4);
  writeUint(reinterpret_cast<uint32_t&>(value));
}

void Buffer::growBy_(size_t amount) {
  if (index_ + amount > capacity_) {
    size_t newCapacity = capacity_ * 2;
    if (newCapacity < index_ + amount) {
      newCapacity = index_ + amount;
    }
    uint8_t *newData = new uint8_t[newCapacity];
    memcpy(newData, data_, size_);
    if (owns_data_) {
      delete[] data_;
    }
    data_ = newData;
    capacity_ = newCapacity;
    owns_data_ = true;
  }
}
