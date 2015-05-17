#ifndef COLLISION_H
#define COLLISION_H

#include <cmath>
#include <cstdio>

#include "plane.h"
#include "sphere.h"

class Collision {
	
	public:
		static bool shperePlane(Sphere sphere, Plane plane);
		static bool sphereSphere(Sphere &s1, Sphere &s2);
		static bool raySphere(Sphere sphere);
		static bool rayPlane(Plane plane);
};

#endif