#pragma once

#include "base/object.h"
#include <cstdint>
#include <stddef.h>
#include <stdlib.h>
#include <new>
#include <cassert>
#include <string_view>
#include <cstring>

namespace dea::base {
class Data : public NonCopyable {
public:
  static Data MakeWithCopy(const uint8_t* data, size_t size) {
		void* d = malloc(size);
		if (!d) {
			assert(false);
		}
    memcpy(d, data, size);
		Data res(static_cast<char*>(d), size);
		return res;
	}

	Data() : size_(0), data_(nullptr) {}
	Data(char* ptr, size_t size) : size_(size), data_(ptr), isOwner_{false} {}
	Data(Data&& other) : size_(other.size_), data_(other.data_) {
		other.size_ = 0;
		other.data_ = nullptr;
	}

  ~Data() {
		if (data_ && isOwner_) {
			free(data_);
		}
	}

	Data& operator=(Data&& other) {
		size_ = other.size_;
		data_ = other.data_;
		other.size_ = 0;
		other.data_ = nullptr;
		return *this;
	}

	bool operator==(const Data& other) const {
		return size_ == other.size_ && memcmp(data_, other.data_, size_) == 0;
	}

	size_t size() const { return size_; }
  template<typename T>
	const T data() const { return T(data_); }
  const char* data() const { return data_; }
	const uint8_t* dataU8() const { return reinterpret_cast<uint8_t*>(data_); }
private:
  size_t size_ = 0;
	char* data_ = nullptr;
	bool isOwner_ = true;
};

} // namespace dea::base

namespace std {
  template<>
  struct hash<dea::base::Data> {
    size_t operator()(const dea::base::Data& data) const {
      return std::hash<std::string_view>()(std::string_view(reinterpret_cast<const char*>(data.data()), data.size()));
    }
  };
}