#pragma once

#include <cstdint>
#include <stddef.h>
#include <stdlib.h>

namespace dea::base {
class Data {
public:
  static const Data& MakeWithCopy(const uint8_t* data, size_t size) {
		Data* d = new Data();
		d->size_ = size;
		memcpy(d->data_, data, size);
		return *d;
	}
private:
  size_t size_ = 0;
  char data_[1];
};

} // namespace dea::base