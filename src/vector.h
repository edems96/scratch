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
		
		void set(float x, float y);
		void setX(float x);
		void setY(float y);
		
		Vector operator+(const Vector &vector);
		Vector operator-(const Vector &vector);
		Vector operator*(const float n);
		Vector operator/(const float n);
		
		Vector operator+=(const Vector &vector);
		Vector operator-=(const Vector &vector);
		Vector operator*=(const float n);
		Vector operator/=(const float n);
		
		float length();
		
		void normalize();
		
		std::string toString();
		const char* toStr();
};

#endif