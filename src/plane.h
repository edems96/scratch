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
		Plane(const Vector vertices[4]);
		Plane(const Vector vertices[4], const Vector normal);
		
		Vector* getVertices();
		
		Vector getNormal();
		Vector getVertex(const uint n);
		
		Plane& setNormal(const Vector normal);
		Plane& setVertex(const uint n, const Vector vector);
		
};

#endif