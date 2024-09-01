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
    this->at(++index) = value;
  }

  T pop_back() {
    return this->at(index--);
  }

  T& emplace_back() {
    return this->at(++index);
  }

  void clear() {
    index = -1;
  }

  bool empty() const {
    return index == -1;
  }

  bool full() const {
    return index == U - 1;
  }

  void forEach(const std::function<void(T&)>& func) {
    for (int i = 0; i <= index; i++) {
      func(this->at(i));
    }
  }

  void filter(const std::function<bool(T&)>& func) {
    for (int i = 0; i <= index; i++) {
      if (!func(this->at(i))) {
        this->at(i) = this->at(index--);
      }
    }
  }

  void remove(const T& value) {
    for (int i = 0; i <= index; i++) {
      if (this->at(i) == value) {
        this->at(i) = this->at(index--);
        return;
      }
    }
  }

  bool contains(const T& value) {
    for (int i = 0; i <= index; i++) {
      if (this->at(i) == value) {
        return true;
      }
    }
    return false;
  }

  T& top() {
    return this->at(index);
  }

  int size() const {
    return index + 1;
  }

private:
  int index = -1;
};

}