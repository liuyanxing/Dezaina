#include "base_type.h"
#include "buffer.h"
#include "desaina_node.h"
#include "include/core/SkPoint.h"
#include "services/blob_service.h"
#include "src/base/SkArenaAlloc.h"
#include <array>

namespace VectorEditor {
  class Segment;
  class Path;
  class Vertex : public Vector {
  public:
    static Vertex Make(float x, float y, int styleID) {
      Vertex v; 
      v.x = x;
      v.y = y;
      v.styleID_ = styleID;
      return v;
    }
    void setXY(float x, float y) {
      this->x = x;
      this->y = y;
    }

    void setStyleID(int styleID) {
      styleID_ = styleID;
    }

  
  private:
    int styleID_ = 0;
  };

  class SegmentVertex {
  public:
    SegmentVertex(Vertex* vertex) {
      this->vertex = vertex;
    }
    float x() const {
      return vertex->x;
    }
    float y() const {
      return vertex->y;
    }
    void setTangentOffset(float x, float y) {
      tangentOffset.x = x;
      tangentOffset.y = y;
    }

    void setVertex(Vertex* vertex) {
      this->vertex = vertex;
    }

    Vector* getTangentOffset() {
      return &tangentOffset;
    }

    Vector getTangentEnd() const {
      return {vertex->x + tangentOffset.x, vertex->y + tangentOffset.y};
    }

    bool hasTangent() const {
      return tangentOffset.x != 0 || tangentOffset.y != 0;
    }

    Vector* getVertex() {
      return vertex;
    }

  private:
    mutable Vector tangentOffset{};
    Vertex* vertex;
  };

  class Segment {
  public:
    void setVertices(SegmentVertex* v0, SegmentVertex* v1) {
      vertices[0] = v0;
      vertices[1] = v1;
    }
    auto& getVertecies() {
      return vertices;
    }
    bool hasVertex(Vertex* vertex) {
      return vertices[0]->getVertex() == vertex || vertices[1]->getVertex() == vertex;
    }
    bool hasTangent(Vector* tangent) {
      return vertices[0]->getTangentOffset() == tangent || vertices[1]->getTangentOffset() == tangent;
    }
  private:
      std::array<SegmentVertex*, 2> vertices;
      Segment* prev;
      Segment* next;
      Path* path;
  };
  class Network {
  public:
    Network() = default;
    Network(vector<Vertex*>&& vertecies, vector<Segment*>&& segments) {
      this->vertecies = std::move(vertecies);
      this->segments = std::move(segments);
    }
    vector<Vertex*>& getVertecies() {
      return vertecies;
    }
    vector<Segment*>& getSegments() {
      return segments;
    }
    bool empty() {
      return vertecies.empty() && segments.empty();
    }
    private:
      vector<Vertex*> vertecies;
      vector<Segment*> segments;
  };
}

using ArenaAlloc = SkArenaAlloc;
VectorEditor::Network buildNetworkFromBlob(const Blob& buffer, ArenaAlloc& arena);

