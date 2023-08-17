#include <stdint.h>

namespace buffer {
  inline char readByte(const uint8_t* buffer, int offset) {
    return buffer[offset];
  }

  inline int readInt32(const uint8_t* buffer, int offset) {
    return buffer[offset] << 24 | buffer[offset + 1] << 16 | buffer[offset + 2] << 8 | buffer[offset + 3];
  }

  inline float readFloat(const uint8_t* buffer, int offset) {
    int i = readInt32(buffer, offset);
    return *(float*)&i;
  }

}