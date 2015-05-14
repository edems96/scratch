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

void Vector::set(float x, float y) {
	this->x = x;
	this->y = y;
}

void Vector::setX(float x) {
	this->x = x;
}

void Vector::setY(float y) {
	this->y = y;
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

float Vector::length() {
	return sqrt((x*x) + (y*y));
}

void Vector::normalize() {
	float l = length();
	
	if( l != 0 ) {
		x /= l;
		y /= l;
	}
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