#include "collision.h"

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