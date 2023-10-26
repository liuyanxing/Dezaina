#pragma once

#include "base_type.h"
#include "include/core/SkPath.h"
#include "services/blob_service.h"
#include "desaina_node.h"
#include "src/base/SkArenaAlloc.h"
#include <array>
#include <memory>
#include <vector>

using ArenaAlloc = SkArenaAlloc;

namespace node {
  class Segment;
  class Path;
  class Vertex : public Vector {
  public:
    static Vertex Make(float x, float y, int styleID) {
      Vertex v{0, 0}; 
      v.x = x;
      v.y = y;
      v.styleID_ = styleID;
      return v;
    }
    Vertex() = default;
    Vertex(float x, float y) {
      setXY(x, y);
    }

    void setXY(float x, float y) {
      this->x = x;
      this->y = y;
    }

    void setStyleID(int styleID) {
      styleID_ = styleID;
    }

    int styleID() {
      return styleID_;
    }

  
  private:
    int styleID_ = 0;
  };

  class SegmentVertex {
  public:
    SegmentVertex(Vertex* vertex, float t) {
      vertex_ = vertex;
      t_ = t;
    }
    float x() const {
      return vertex_->x;
    }
    float y() const {
      return vertex_->y;
    }
    float t() const {
      return t_;
    }

    void setTangentOffset(float x, float y) {
      tangentOffset.x = x;
      tangentOffset.y = y;
    }

    void setVertex(Vertex* vertex) {
      this->vertex_ = vertex;
    }

    void setT(float t) {
      t_ = t;
    }

    Vector* getTangentOffset() {
      return &tangentOffset;
    }

    Vector getTangentEnd() const {
      return {vertex_->x + tangentOffset.x, vertex_->y + tangentOffset.y};
    }

    bool hasTangent() const {
      return tangentOffset.x != 0 || tangentOffset.y != 0;
    }

    Vertex* getVertex() {
      return vertex_;
    }

    Segment* segment() {
      return segment_;
    }

    void setSegment(Segment* segment) {
      segment_ = segment;
    }

    void setNext(SegmentVertex* next) {
      next_ = next;
    }

    SegmentVertex* next() {
      return next_;
    }

    bool hasLink() const {
      return next_ != nullptr;
    }

  private:
    mutable Vector tangentOffset{};
    Vertex* vertex_;
    float t_;
    SegmentVertex* next_ = nullptr; // next intersection
    Segment* segment_;
  };

  class Segment {
  public:
    void setVertices(SegmentVertex* v0, SegmentVertex* v1) {
      vertices[0] = v0;
      vertices[1] = v1;
      v0->setSegment(this);
      v1->setSegment(this);
    }

    void setVertex(SegmentVertex* vertex) {
      if (vertex->t() == 0) {
        vertices[0] = vertex;
      } else {
        vertices[1] = vertex;
      }
      vertex->setSegment(this);
    }

    auto& getVerticies() {
      return vertices;
    }
    std::array<SegmentVertex*, 2> getEndVertecies() {
      return {vertices[0], vertices[1]};
    }
    bool hasVertex(Vertex* vertex) {
      return vertices[0]->getVertex() == vertex || vertices[1]->getVertex() == vertex;
    }
    bool hasTangent(Vector* tangent) {
      return vertices[0]->getTangentOffset() == tangent || vertices[1]->getTangentOffset() == tangent;
    }
    SegmentVertex* getT(float t) {
      for (auto v : vertices) {
        if (v->t() == t) {
          return v;
        }
      }
      return nullptr;
    }

    SegmentVertex* getAnotherVertex(SegmentVertex* vertex) {
      if (vertex->t() == 0) {
        return vertices[1];
      }
      return vertices[0];
    }
  private:
      std::array<SegmentVertex*, 2> vertices;
      int id = nextID++;
      inline static int nextID = 0;
  };

  class Network {
  public:
    Network() = default;
    Network(vector<Vertex*>&& vertecies, vector<Segment*>&& segments) {
      this->vertecies_ = std::move(vertecies);
      this->segments_ = std::move(segments);
    }
    Network(const Blob& blob, ArenaAlloc& arena);
    Network(Network&& that) {
      vertecies_ = std::move(that.vertecies_);
      segments_ = std::move(that.segments_);
    }
    vector<Vertex*>* getVertecies() {
      return &vertecies_;
    }
    vector<Segment*>* getSegments() {
      return &segments_;
    }
    bool empty() {
      return vertecies_.empty() && segments_.empty();
    }
    private:
      vector<Vertex*> vertecies_;
      vector<Segment*> segments_;
  };

  struct CycleVertex {
    SegmentVertex* vertex;
    SkPath path;
    vector<CycleVertex> cycle;
    bool operator==(const CycleVertex& other) const {
      return vertex == other.vertex;
    }
  };

  struct ContourCycles {
    vector<CycleVertex> cycles;
  };

  struct VectorDecodedData : BlobAttachment {
    VectorDecodedData(const shared_ptr<SkArenaAlloc>& alloc, Network* network, vector<CycleVertex>* cycles, SkPath* path) {
      this->alloc = alloc;
      this->network = network;
      this->cycles = cycles;
      this->path = path;
    }
    shared_ptr<SkArenaAlloc> alloc = nullptr;
    Network* network = nullptr;
    vector<CycleVertex>* cycles = nullptr;
    SkPath* path;
  };

  VectorDecodedData decodeVectorData(const Blob* blob);
}

namespace util {
  Buffer network2Buffer(node::Network& network);
}