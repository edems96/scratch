#ifndef MODEL_H
#define MODEL_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>

using namespace std;

typedef unsigned int uint;

struct Coordinate {
	float x, y, z;
	Coordinate(float x, float y, float z) : x(x), y(y), z(z) {}
};

struct Face {
	int facen;
	bool four;
	
	
};

struct Material {
	string name;
	float alpha, ni, ns;
	
	float dif[3], amb[3], spec[3];
	int illum;
	int texture;
	
};

struct TextureCoordinate {
	float u, v;
	TextureCoordinate(float u, float v) : u(u), v(v) {}
};

class Model {
	
	private:
		Coordinate *vertex;
		uint vertexCount;
		
	public:
		Model();
		
		static Model* loadFromFile(const char* path);
		
		void addVertex(const Coordinate *vertex);
		
};

#endif