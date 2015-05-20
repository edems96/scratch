#include "plane.h"

Plane::Plane() {
	
}

Plane::Plane(Vector normal, Vector vertices[4]) {
	this->normal.set(normal);
	
	for(uint i = 0; i < 4; i++) {
		this->vertices[i].set(vertices[i]);
	}
}

Vector* Plane::getEdges() {
	return edges;
}

Vector Plane::getNormal() {
	return normal;
}

Plane& Plane::setNormal(const Vector normal) {
	this->normal.set(normal); return *this;
}

Vector Plane::getVertex(uint n) {
	return vertices[n];
}

Plane& Plane::setVertex(uint n, const Vector vector) {
	vertices[n].set(vector); return *this;
}