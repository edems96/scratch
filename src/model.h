#ifndef MODEL_H
#define MODEL_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <GL/gl.h>

#include <string>
#include <vector>

#include "texture.h"
#include "utils.h"
#include "plane.h"

using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;

struct Vertex {
	float x, y, z; // w
};

struct TextureCoordinate {
	float u, v; // w
};

struct Normal {
	float x, y, z;
};

struct Face {
	bool quad, 
		hasTextureCoordinate, 
		hasNormal;
	
	uint material;
	
	uint vertex[4];
	uint texture[4];
	uint normal[4];
	
	Face() : quad(false), hasTextureCoordinate(false), hasNormal(false), material(0) {}
};

struct Material {
	char name[64];
	
	float Ka[3]; // ambient color 
	float Kd[3]; // diffuse color
	float Ks[3]; // specular color
	float Ns; // specular exponent
	float d; // dissolved or Tr
	uint illum; // illumination models
	
	bool hasTexture;
	char map_Kd[64];
	
	Material() : hasTexture(false) {}
};

class Model {
	
	private:
		GLuint model;
		
		Plane *planes;
		uint planes_count;
		
	public:
		static Model *loadFromFile(const char* path);
		
		Model();
		Model(GLuint model);
		
		void Draw();
		void setPlanes(Plane *planes, uint count);
		
		Plane* getPlanes();
		uint getPlanesCount();
			
};

#endif