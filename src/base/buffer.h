#include <stdint.h>

class buffer {
public:
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

};