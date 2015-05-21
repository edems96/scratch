#include "triangle.h"

Triangle::Triangle() {
	
}

Triangle::Triangle(const Vector vertices[3]) {
	for(uint i = 0; i < 3; i++) {
		this->vertices[i].set(vertices[i]);
	}
}

Triangle::Triangle(const Vector vertices[3], const Vector normal) {
	for(uint i = 0; i < 3; i++) {
		this->vertices[i].set(vertices[i]);
	}
	
	this->normal.set(normal);
}
		
Vector* Triangle::getVertices() {
	return vertices;
}

Triangle Triangle::setVertices(const Vector vertices[3]) {
	for(uint i = 0; i < 3; i++) {
		this->vertices[i].set(vertices[i]);
	}
	
	return *this;
}
		
Vector Triangle::getVertex(const uint n) {
	return vertices[n];
}

Triangle Triangle::setVertex(const uint n, const Vector vertex) {
	vertices[n].set(vertex); return *this;
}

Vector Triangle::getNormal() {
	return normal;
}

Triangle Triangle::setNormal(const Vector normal) {
	this->normal.set(normal);
}
		
Vector* Triangle::getEdges() {
	Vector *edges;
	edges = (Vector*) malloc(sizeof(Vector) * 3);
	
	if( edges == NULL )
		return NULL;
	
	edges[0] = vertices[0] - vertices[1];
	edges[1] = vertices[0] - vertices[3];
	edges[2] = vertices[1] - vertices[3];
	
	return edges;
}

Vector Triangle::getEdge(const uint n) {
	return getEdges()[n];
}