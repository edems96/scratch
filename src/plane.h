#ifndef PLANE_H
#define PLANE_H

#include "vector.h"

typedef unsigned int uint;

class Plane {
	
	private:
		Vector normal;
		Vector vertices[4];
		
	public:
		Plane();
		Plane(Vector normal, Vector vertices[4]);
		
		Vector* getEdges();
		
		Vector getNormal();
		Vector getVertex(uint n);
		
		Plane& setNormal(const Vector normal);
		Plane& setVertex(uint n, const Vector vector);
		
};

#endif