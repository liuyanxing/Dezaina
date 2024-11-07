#pragma once

#include <vector>
#include "base/type.h"

namespace dea::gfx {

class Segment;
class Path;

class Vector {
public:
	Vector() = default;
	Vector(float x, float y) {
		this->x_ = x;
		this->y_ = y;
	}
	auto x() const {
		return x_;
	}
	auto y() const {
		return y_;
	}
	void set(float x, float y) {
		x_ = x;
		y_ = y;
	}

protected:
	float x_ = 0;
	float y_ = 0;
};

class Vertex : public Vector {
public:
	static Vertex Make(float x, float y, int styleID) {
		Vertex v{0, 0}; 
		v.setXY(x, y);
		v.setStyleID(styleID);

		return v;
	}
	Vertex() = default;
	Vertex(float x, float y) {
		setXY(x, y);
	}

	void setXY(float x, float y) {
		this->x_ = x;
		this->y_ = y;
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
		return vertex_->x();
	}
	float y() const {
		return vertex_->y();
	}
	float t() const {
		return t_;
	}

	void setTangentOffset(float x, float y) {
		tangentOffset.set(x, y);
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
		return {vertex_->x() + tangentOffset.x(), vertex_->y() + tangentOffset.y()};
	}

	bool hasTangent() const {
		return tangentOffset.x() != 0 || tangentOffset.y() != 0;
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
	Vector tangentOffset{};
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
		return vertex->t() == 0 ? vertices[1] : vertices[0]; 
	}
private:
		base::v2<SegmentVertex*> vertices;
		int id = nextID++;
		inline static int nextID = 0;
};

using VertexPtrArray = std::vector<Vertex*>;
using SegmentPtrArray = std::vector<Segment*>;

struct CycleVertex {
	SegmentVertex* vertex;
	bool operator==(const CycleVertex& other) const {
		return vertex == other.vertex;
	}
};

using ContourCycles = std::vector<CycleVertex>; 

} // namespace gfx
