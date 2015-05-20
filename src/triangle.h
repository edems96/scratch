#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector.h"

typedef unsigned int uint;

class Triangle {
	
	private:
		Vector vertices[3];
		Vector normal;
		
	public:
		Triangle();
		Triangle(Vector vertices[3]);
		Triangle(Vector vertices[3], const Vector normal);
		
		Vector* getVertices();
		Triangle setVertices(Vector vertices[3]);
		
		Vector getVertex(const uint n);
		Triangle setVertex(const uint n, const Vector vertex);
		
		Vector getNormal();
		Triangle setNormal(const Vector normal);
		
		Vector* getEdges();
		Vector getEdge(const uint n);
};

#endif