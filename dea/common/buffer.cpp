#include "buffer.h"

namespace dea::base {

Buffer::Buffer() {
  data_ = new uint8_t[INITIAL_CAPACITY];
  capacity_ = INITIAL_CAPACITY;
  is_owned_ = true;
}

Buffer::Buffer(uint8_t *data, size_t size) {
  data_ = data;
  size_ = size;
  capacity_ = size;
}

Buffer::Buffer(const uint8_t *data, size_t size) {
  data_ = const_cast<uint8_t*>(data);
  size_ = size;
  capacity_ = size;
}

Buffer& Buffer::operator=(const Buffer& other) noexcept {
  if (this != &other) {
    if (is_owned_) {
      delete[] data_;
    }
    size_ = other.size_;
    capacity_ = other.capacity_;
    is_owned_ = true;
    data_ = new uint8_t[size_];
    memcpy(data_, other.data_, size_);
  }
  return *this;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept {
  if (this != &other) {
    if (is_owned_) {
      delete[] data_;
    }
    data_ = other.data_;
    is_owned_ = other.is_owned_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.data_ = nullptr;
    other.is_owned_ = false;
    other.size_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}

Buffer::~Buffer() {
  if (is_owned_ && data_ != nullptr) {
    delete[] data_;
  }
}

void Buffer::set(const uint8_t *data, size_t size) {
  if (is_owned_) {
    delete[] data_;
  }
  data_ = new uint8_t[size];
  size_ = size;
  memcpy(data_, data, size);
  capacity_ = size;
  is_owned_ = true;
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
  size_ = index_;
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
  size_ = index_;
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
    if (is_owned_) {
      delete[] data_;
    }
    data_ = newData;
    capacity_ = newCapacity;
    is_owned_ = true;
  }
}

}