#include "collision.h"

bool Collision::rayTriangle(Vector start, Vector direction, Vector t1, Vector t2, Vector t3, float *distance) {
	Vector e1 = t2 - t1;
	Vector e2 = t3 - t1;
	
	Vector P = Vector::crossProduct(direction, e2);
	float det = Vector::dotProduct(e1, P);
	
	if( det > -EPSILON && det < EPSILON )
		return false;
	
	float inv_det = 1.0f / det;
	
	Vector T = start - t1;
	
	float u = Vector::dotProduct(T, P) * inv_det;
	
	if( u < 0.0f || u > 1.0f )
		return false;
	
	Vector Q = Vector::crossProduct(T, e1);
	float v = Vector::dotProduct(direction, Q) * inv_det;
	
	if( v < 0.0f || u + v > 1.0f )
		return false;
	
	float t = Vector::dotProduct(e2, Q) * inv_det;
	
	if( t > EPSILON ) {
		*distance = t;
		return true;
	}
	
	return false;
}

bool Collision::rayPlane(Vector start, Vector direction, Plane plane, float *distance, Vector *collisionPoint) {
	if( rayTriangle(start, direction, plane.getVertex(0), plane.getVertex(1), plane.getVertex(2), distance) )
		return true;
	
	return rayTriangle(start, direction, plane.getVertex(0), plane.getVertex(2), plane.getVertex(3), distance);
}

/*bool Collision::rayPlane(Vector start, Vector direction, Plane plane, float *distance, Vector *collisionPoint) {
	float a = Vector::dotProduct(plane.getNormal(), direction);
	
	if( a == 0 )
		return false;
	
	float t = (Vector::dotProduct(plane.getNormal(), plane.getVertex(0)) - Vector::dotProduct(plane.getNormal(),  start)) / a;
	
	if( t < 0 )
		return false;
	
	printf("s: %f %f %f\n", start.x, start.y, start.z);
	printf("d: %f %f %f\n", direction.x, direction.y, direction.z);
	printf("n: %f %f %f\n", plane.getNormal().x, plane.getNormal().y, plane.getNormal().z);
	printf("t: %f\n\n", t);
	
	Vector cPoint(start + direction * t);

	float area1 = abs(triangleArea(plane.getVertex(0), plane.getVertex(1), plane.getVertex(2)) - (
			triangleArea(plane.getVertex(0), plane.getVertex(1), cPoint) +
			triangleArea(plane.getVertex(0), plane.getVertex(2), cPoint) +
			triangleArea(plane.getVertex(1), plane.getVertex(2), cPoint)));
	
	float area2 = abs(triangleArea(plane.getVertex(0), plane.getVertex(2), plane.getVertex(3)) - (
			triangleArea(plane.getVertex(0), plane.getVertex(2), cPoint) +
			triangleArea(plane.getVertex(0), plane.getVertex(3), cPoint) +
			triangleArea(plane.getVertex(2), plane.getVertex(3), cPoint)));
		
	
	if( area1 < 0.3f || area2 < 0.3f ) {

	if( distance != NULL ) {
		(*distance) = t;
			
		if( collisionPoint != NULL )
			collisionPoint->set(cPoint);
	}
		
	return true;
	}
	
	return false;
} */

bool Collision::sphereSphere(Sphere &s1, Sphere &s2) {
	float distance = Vector::distanceSquare(s1.getOrigin(), s2.getOrigin());
	float radius = s1.getRadius() + s2.getRadius();
	
	if( distance <= radius * radius ) {
		float a = sqrt(distance) - radius;
		
		Vector vec(s1.getOrigin() - s2.getOrigin());
		vec.normalize();
		
		s1.setOrigin(s1.getOrigin() + vec * a);
		
		return true;
	}
	
	return false;
}

bool Collision::spherePlane(Sphere &sphere, Plane plane) {
	float distance1 = 0, distance2 = 0;
	/*
	if( 
		rayPlane(sphere.getOrigin(), plane.getNormal() * (-1), plane, &distance1, NULL) ||
		rayPlane(sphere.getOrigin(), plane.getNormal(), Plane(plane.getNormal() * (-1), plane.getVertices()), &distance2, NULL) ) {

		if( distance1 > sphere.getRadius() || distance2 > sphere.getRadius() )
			return false;
	
		Vector move(sphere.getOrigin());
		
		if( distance1 > 0 )
			move += plane.getNormal() * (sphere.getRadius() - distance1);
		else
			move -= plane.getNormal() * (sphere.getRadius() - distance2);
		
		//printf("in1: %f %f %f\n", sphere.getOrigin().x, sphere.getOrigin().y, sphere.getOrigin().z);
		
		sphere.setOrigin(move);

		//printf("sp1: %f %f %f\n", sphere.getOrigin().x, sphere.getOrigin().y, sphere.getOrigin().z);
		return true;
	}*/
	return false;
}

float Collision::triangleArea(Vector p1, Vector p2, Vector p3) {
	float a = (p1-p2).length();
	float b = (p1-p3).length();
	float c = (p2-p3).length();
	
	float s = (a+b+c) / 2.0f;
	
	return sqrt( s * ( (s-a) * (s-b) * (s-c) ) );
}