#include "vector.h"

Vector::Vector() {
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(const Vector &vector) {
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

Vector Vector::set(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
	
	return *this;
}

Vector Vector::set(const Vector &vector) {
	x = vector.x;
	y = vector.y;
	z = vector.z;
	
	return *this;
}


Vector Vector::operator+(const Vector &vector) {
	return Vector(x + vector.x, y + vector.y, z + vector.z);
}

Vector Vector::operator-(const Vector &vector) {
	return Vector(x - vector.x, y - vector.y, z - vector.z);
}

Vector Vector::operator*(const float n) {
	return Vector(x * n, y * n, z * n);
}

Vector Vector::operator/(const float n) {
	return n != 0 ? Vector(x / n, y / n, z / n) : Vector(*this);
}

Vector Vector::operator+=(const Vector &vector) {
	x += vector.x;
	y += vector.y;
	z += vector.z;
	
	return *this;
}

Vector Vector::operator-=(const Vector &vector) {
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	
	return *this;
}

Vector Vector::operator*=(const float n) {
	x *= n;
	y *= n;
	z *= n;
	
	return *this;
}

Vector Vector::operator/=(const float n) {
	if( n != 0 ) {
		y /= n;
		y /= n;
		z /= n;
	}
	
	return *this;
}

bool Vector::operator==(const Vector &vector) {
	return x == vector.x && y == vector.y && z == vector.z;
}

float Vector::length() {
	return sqrt((x*x) + (y*y) + (z*z));
}

float Vector::lengthSquare() {
	return (x*x) + (y*y) + (z*z);
}

Vector Vector::normalize() {
	float l = length();
	
	if( l != 0 ) {
		x /= l;
		y /= l;
		z /= l;
	}
	
	return *this;
}

float Vector::distance(Vector v1, Vector v2) {
	return (v1-v2).length();
}

float Vector::distanceSquare(Vector v1, Vector v2) {
	return (v1-v2).lengthSquare();
}