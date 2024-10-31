#include "node.generated.h"
#include "node/node_base.generated.h"

namespace dea::node {
	Rect Rect::MakeXYWH(float x, float y, float w, float h) {
		return Rect{x, y,  w, h};
	}

	Rect Rect::MakeWH(float width, float height) {
		return Rect{0, 0, width, height};
	}

	bool Rect::contains(const Vector& point) const {
		return point.x >= x && point.x < x + w && point.y >= y && point.y < y + h;
	}

	bool Rect::intersects(const Rect& rect) const {
		return x < rect.x + rect.w && x + w > rect.x && y < rect.y + rect.h && y + h > rect.y;		
	}

	Rect Rect::intersection(const Rect& rect) const {
		float x0 = std::max(x, rect.x);
		float x1 = std::min(x + w, rect.x + rect.w);
		float y0 = std::max(y, rect.y);
		float y1 = std::min(y + h, rect.y + rect.h);
		return Rect::MakeXYWH(x0, y0, x1 - x0, y1 - y0);
	}

	Rect Rect::unite(const Rect& rect) const {
		float x0 = std::min(x, rect.x);
		float x1 = std::max(x + w, rect.x + rect.w);
		float y0 = std::min(y, rect.y);
		float y1 = std::max(y + h, rect.y + rect.h);
		return Rect::MakeXYWH(x0, y0, x1 - x0, y1 - y0);
	}

	Rect Rect::makeOutset(float dx, float dy) {
		return Rect::MakeXYWH(x - dx, y - dy, w + 2 * dx, h + 2 * dy);
	}

	void Rect::join(const Rect& rect) {
		*this = unite(rect);
	}
}