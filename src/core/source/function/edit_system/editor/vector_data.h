#include "base_type.h"
#include "buffer.h"
#include "include/core/SkPoint.h"
#include "src/base/SkArenaAlloc.h"

namespace EditVector {
  class Segment;
  class Path;
  class Vertex : public SkPoint {
  public:
    static Vertex Make(float x, float y, int styleID) {
      Vertex v = Make(x, y); 
      v.styleID = styleID;
      return v;
    }
    static Vertex Make(float x, float y) {
      Vertex v; 
      v.fX = x;
      v.fY = y;
      return v;
    }
    void setXY(float x, float y) {
      fX = x;
      fY = y;
    }

    void setStyleID(int styleID) {
      this->styleID = styleID;
    }
    Vertex& operator+(const Vertex& other) {
      this->fX += other.fX;
      this->fY += other.fY;
      return *this;
    }
  private:
      int styleID = 0;
  };
  class Segment {
  public:
    void setVertices(Vertex* v0, Vertex* v1, Vertex* v2, Vertex* v3) {
      vertices[0] = v0;
      vertices[1] = v1;
      vertices[2] = v2;
      vertices[3] = v3;
    }
  private:
      Vertex* vertices[4];
      Segment* prev;
      Segment* next;
      Path* path;
  };
  class Path {
    private:
      Segment* segments;
  };
  class Network {
    private:
      vector<Path*> paths;
  };
}

using ArenaAlloc = SkArenaAlloc;
static EditVector::Network* buildNetworkFromBlob(const Blob& buffer, ArenaAlloc& arena);
