#pragma once

#include <array>
#include <cassert>
#include <cstddef>
#include <functional>
#include <iostream>
namespace dea::base {

template <typename T, std::size_t U>
class array : public std::array<T, U> {
public:
  void push_back(const T& value) {
    this->at(++size_) = value;
  }

  T pop_back() {
    return this->at(size_--);
  }

  void clear() {
    size_ = -1;
  }

  bool empty() const {
    return size_ == -1;
  }

  bool full() const {
    return size_ == U - 1;
  }

  void forEach(const std::function<void(T&)>& func) {
    for (int i = 0; i <= size_; i++) {
      func(this->at(i));
    }
  }

  void filter(const std::function<bool(T&)>& func) {
    for (int i = 0; i <= size_; i++) {
      if (!func(this->at(i))) {
        this->at(i) = this->at(size_--);
      }
    }
  }

  void remove(const T& value) {
    for (int i = 0; i <= size_; i++) {
      if (this->at(i) == value) {
        this->at(i) = this->at(size_--);
        return;
      }
    }
  }

  bool contains(const T& value) {
    for (int i = 0; i <= size_; i++) {
      if (this->at(i) == value) {
        return true;
      }
    }
    return false;
  }

private:
  int size_ = -1;
};

}