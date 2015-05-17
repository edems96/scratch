#include "sphere.h"

Sphere::Sphere() {
	radius = 0;
}

Sphere::Sphere(Vector origin, float radius) {
	this->origin.set(origin);
	this->radius = radius;
}

Sphere* Sphere::setOrigin(const Vector vector) {
	this->origin.set(origin); return this;
}		

Vector Sphere::getOrigin() {
	return origin;
}

float Sphere::getRadius() {
	return radius;
}