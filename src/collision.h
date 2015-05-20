#ifndef COLLISION_H
#define COLLISION_H

#include <cmath>
#include <cstdio>

#include "plane.h"
#include "sphere.h"

#define EPSILON 0.000001

using namespace std;

// http://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm

class Collision {
	
	private:
		static float triangleArea(Vector p1, Vector p2, Vector p3);
		
	public:
		static bool spherePlane(Sphere &sphere, Plane plane);
		static bool sphereSphere(Sphere &s1, Sphere &s2);
		static bool raySphere(Sphere sphere);
		static bool rayTriangle(Vector start, Vector direction, Vector t1, Vector t2, Vector t3, float *distance);
		static bool rayPlane(Vector start, Vector direction, Plane plane, float *distance, Vector *collisionPoint);
};

#endif