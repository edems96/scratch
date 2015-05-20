#include "triangle.h"

Triangle::Triangle() {
	
}

Triangle::Triangle(Vector vertices[3]) {
	this->vertices = vertices;
}

Triangle::Triangle(Vector vertices[3], const Vector normal) {
	this->vertices = vertices;
	this->normal.set(normal);
}
		
Vector* Triangle::getVertices() {
	return vertices;
}

Triangle Triangle::setVertices(Vector vertices[3]) {
	this->vertices = vertices; return *this;
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
	Vector edges[3];
	edges[0] = vertices[0] - vertices[1];
	edges[1] = vertices[0] - vertices[3];
	edges[2] = vertices[1] - vertices[3];
	
	return edges;
}

Vector Triangle::getEdge(const uint n) {
	return getEdges()[n];
}