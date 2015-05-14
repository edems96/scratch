#include "vector.h"

Vector::Vector() {
	x = 0;
	y = 0;
}

Vector::Vector(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector::Vector(const Vector &vector) {
	this->x = vector.x;
	this->y = vector.y;
}

float Vector::getX() {
	return x;
}

float Vector::getY() {
	return y;
}

Vector Vector::set(float x, float y) {
	this->x = x;
	this->y = y;
	
	return *this;
}

Vector Vector::set(const Vector &vector) {
	x = vector.x;
	y = vector.y;
	
	return *this;
}

Vector Vector::setX(float x) {
	this->x = x; return *this;
}

Vector Vector::setY(float y) {
	this->y = y; return *this;
}

Vector Vector::operator+(const Vector &vector) {
	return Vector(x + vector.x, y + vector.y);
}

Vector Vector::operator-(const Vector &vector) {
	return Vector(x - vector.x, y - vector.y);
}

Vector Vector::operator*(const float n) {
	return Vector(x * n, y * n);
}

Vector Vector::operator/(const float n) {
	return n != 0 ? Vector(x / n, y / n) : Vector(*this);
}

Vector Vector::operator+=(const Vector &vector) {
	x += vector.x;
	y += vector.y;
	
	return *this;
}

Vector Vector::operator-=(const Vector &vector) {
	x -= vector.x;
	y -= vector.y;
	
	return *this;
}

Vector Vector::operator*=(const float n) {
	x *= n;
	y *= n;
	
	return *this;
}

Vector Vector::operator/=(const float n) {
	if( n != 0 ) {
		y /= n;
		y /= n;
	}
	
	return *this;
}

bool Vector::operator==(const Vector &vector) {
	return x == vector.x && y == vector.y;
}

float Vector::length() {
	return sqrt((x*x) + (y*y));
}

Vector Vector::normalize() {
	float l = length();
	
	if( l != 0 ) {
		x /= l;
		y /= l;
	}
	
	return *this;
}

std::string Vector::toString() {
	std::string str;
	str += "(";
	str += x;
	str += "; ";
	str += y;
	str += ")";

	return str;
}

const char* Vector::toStr() {
	return toString().c_str();
}