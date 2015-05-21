#include "plane.h"

Plane::Plane() {
	
}

Plane::Plane(const Vector vertices[4]) {
	for(uint i = 0; i < 4; i++) {
		this->vertices[i].set(vertices[i]);
	}
}

Plane::Plane(const Vector vertices[4], const Vector normal) {
	for(uint i = 0; i < 4; i++) {
		this->vertices[i].set(vertices[i]);
	}
	
	this->normal.set(normal);
}

Vector* Plane::getVertices() {
	return vertices;
}

Vector Plane::getNormal() {
	return normal;
}

Plane& Plane::setNormal(const Vector normal) {
	this->normal.set(normal); return *this;
}

Vector Plane::getVertex(const uint n) {
	return vertices[n];
}

Plane& Plane::setVertex(const uint n, const Vector vector) {
	vertices[n].set(vector); return *this;
}