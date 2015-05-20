#include "plane.h"

Plane::Plane() {
	
}

Plane::Plane(Vector normal, Vector edges[4]) {
	this->normal.set(normal);
	
	for(uint i = 0; i < 4; i++) {
		this->edges[i].set(edges[i]);
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

Vector Plane::getEdge(uint n) {
	return edges[n];
}

Plane& Plane::setEdge(uint n, const Vector vector) {
	edges[n].set(vector); return *this;
}