#pragma once
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

    Vector* getVertex() {
      return vertex_;
    }

    Segment* getSegment() {
      return segment;
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
    Segment* segment;
  };

  class Segment {
  public:
    void setVertices(SegmentVertex* v0, SegmentVertex* v1) {
      vertices[0] = v0;
      vertices[1] = v1;
    }

    void setVertex(SegmentVertex* vertex) {
      if (vertex->t() == 0) {
        vertices[0] = vertex;
      } else {
        vertices[1] = vertex;
      }
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

