#ifndef PLANE_H
#define PLANE_H

#include "vector.h"

typedef unsigned int uint;

class Plane {
	
	private:
		Vector normal;
		Vector edges[4];
		
	public:
		Plane();
		Plane(Vector normal, Vector edges[4]);
		
		Vector* getEdges();
		
		Vector getNormal();
		Vector getEdge(uint n);
		
		Plane& setNormal(const Vector normal);
		Plane& setEdge(uint n, const Vector vector);
		
};

#endif