#pragma once

#include <array>
#include <cassert>
#include <cstddef>
#include <functional>
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

private:
  int size_ = -1;
};

}