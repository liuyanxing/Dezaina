
#include "node.generated.h"
#include <cmath>

namespace dea::node {

	float Vector::length() const {
		return std::sqrt(x * x + y * y);
	}

	void Vector::normalize() {
		float len = length();
		if (len != 0) {
			x /= len;
			y /= len;
		}
	}

	Vector Vector::operator+(const Vector& rhs) const {
		return Vector{x + rhs.x, y + rhs.y};
	}

	Vector Vector::operator-(const Vector& rhs) const {
		return Vector{x - rhs.x, y - rhs.y};
	}

	Vector Vector::operator*(float rhs) const {
		return Vector{x * rhs, y * rhs};
	}

	Vector Vector::operator/(float rhs) const {
		return Vector{x / rhs, y / rhs};
	}

	Vector Vector::operator-() const {
		return Vector{-x, -y};
	}

	Vector& Vector::operator+=(const Vector& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector& Vector::operator-=(const Vector& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vector& Vector::operator*=(float rhs) {
		x *= rhs;
		y *= rhs;
		return *this;
	}

	Vector& Vector::operator/=(float rhs) {
		x /= rhs;
		y /= rhs;
		return *this;
	}

	bool Vector::operator==(const Vector& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool Vector::operator!=(const Vector& rhs) const {
		return x != rhs.x || y != rhs.y;
	}

	float Vector::dot(const Vector& rhs) const {
		return x * rhs.x + y * rhs.y;
	}

	float Vector::cross(const Vector& rhs) const {
		return x * rhs.y - y * rhs.x;
	}
}