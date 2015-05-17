#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <string>

class Vector {
	
	public:
		float x, y, z;
		
		Vector();
		Vector(float x, float y, float z);
		Vector(const Vector &vector);
		
		Vector set(float x, float y, float z);
		Vector set(const Vector &vector);
		
		Vector operator+(const Vector &vector);
		Vector operator-(const Vector &vector);
		Vector operator*(const float n);
		Vector operator/(const float n);
		
		Vector operator+=(const Vector &vector);
		Vector operator-=(const Vector &vector);
		Vector operator*=(const float n);
		Vector operator/=(const float n);
		
		bool operator==(const Vector &vector);
		
		float length();
		float lengthSquare();
		
		Vector normalize();
		
		static float distance(Vector v1, Vector v2);
		static float distanceSquare(Vector v1, Vector v2);
};

#endif