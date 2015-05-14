#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <string>

class Vector {
	
	private:
		float x, y;
		
	public:
		Vector();
		Vector(float x, float y);
		Vector(const Vector &vector);
		
		float getX();
		float getY();
		
		Vector set(float x, float y);
		Vector set(const Vector &vector);
		Vector setX(float x);
		Vector setY(float y);
		
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
		
		Vector normalize();
		
		std::string toString();
		const char* toStr();
};

#endif