#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"

class Sphere {
	
	private:
		Vector origin;
		float radius;
		
	public:
		Sphere();
		Sphere(Vector origin, float radius);
		
		Sphere* setOrigin(const Vector origin);
		Vector getOrigin();
		
		float getRadius();
	
};

#endif