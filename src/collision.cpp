#include "collision.h"

bool Collision::rayPlane(Vector start, Vector direction, Plane plane, float *distance, Vector *collisionPoint) {
	float a = Vector::dotProduct(plane.getNormal(), direction);
	
	if( a == 0 )
		return false;
	
	float t = (Vector::dotProduct(plane.getNormal(), plane.getEdge(0)) - Vector::dotProduct(plane.getNormal(),  start)) / a;
	
	if( t < 0 )
		return false;
	
	printf("s: %f %f %f\n", start.x, start.y, start.z);
	printf("d: %f %f %f\n", direction.x, direction.y, direction.z);
	printf("n: %f %f %f\n", plane.getNormal().x, plane.getNormal().y, plane.getNormal().z);
	printf("t: %f\n\n", t);
	
	Vector cPoint(start + direction * t);

	float area1 = abs(triangleArea(plane.getEdge(0), plane.getEdge(1), plane.getEdge(2)) - (
			triangleArea(plane.getEdge(0), plane.getEdge(1), cPoint) +
			triangleArea(plane.getEdge(0), plane.getEdge(2), cPoint) +
			triangleArea(plane.getEdge(1), plane.getEdge(2), cPoint)));
	
	float area2 = abs(triangleArea(plane.getEdge(0), plane.getEdge(2), plane.getEdge(3)) - (
			triangleArea(plane.getEdge(0), plane.getEdge(2), cPoint) +
			triangleArea(plane.getEdge(0), plane.getEdge(3), cPoint) +
			triangleArea(plane.getEdge(2), plane.getEdge(3), cPoint)));
			
	/* if( area >= 0.3f ) {
		
		
		if( area >= 0.3f )
			return false;
	} */
	
	if( area1 < 0.3f || area2 < 0.3f ) {

	if( distance != NULL ) {
		(*distance) = t;
			
		if( collisionPoint != NULL )
			collisionPoint->set(cPoint);
	}
		
	return true;
	}
	
	return false;
}

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
	
	if( 
		rayPlane(sphere.getOrigin(), plane.getNormal() * (-1), plane, &distance1, NULL) ||
		rayPlane(sphere.getOrigin(), plane.getNormal(), Plane(plane.getNormal() * (-1), plane.getEdges()), &distance2, NULL) ) {

		if( distance1 > sphere.getRadius() || distance2 > sphere.getRadius() )
			return false;
	
		Vector move(sphere.getOrigin());
		
		if( distance1 > 0 )
			move += plane.getNormal() * (sphere.getRadius() - distance1);
		else
			move -= plane.getNormal() * (sphere.getRadius() - distance2);
		
		printf("in1: %f %f %f\n", sphere.getOrigin().x, sphere.getOrigin().y, sphere.getOrigin().z);
		
		sphere.setOrigin(move);

		printf("sp1: %f %f %f\n", sphere.getOrigin().x, sphere.getOrigin().y, sphere.getOrigin().z);
		return true;
	}
	return false;
}

float Collision::triangleArea(Vector p1, Vector p2, Vector p3) {
	float a = (p1-p2).length();
	float b = (p1-p3).length();
	float c = (p2-p3).length();
	
	float s = (a+b+c) / 2.0f;
	
	return sqrt( s * ( (s-a) * (s-b) * (s-c) ) );
}