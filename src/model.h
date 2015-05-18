#ifndef MODEL_H
#define MODEL_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <GL/gl.h>

#include <string>
#include <vector>

#include "texture.h"

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
	bool quad;
	bool hasTextureCoordinate, hasNormal;
	uint material;
	
	uint vertex[4];
	uint texture[4];
	uint normal[4];
};

struct Material {
	char name[64];
	
	float Ka[3]; // ambient color 
	float Kd[3]; // diffuse color
	float Ks[3]; // specular color
	float Ns; // specular exponent
	float d; // dissolved or Tr
	uint illum; // illumination models
	
	char map_Kd[64];
};

class Model {
	
	private:
		GLuint model;
		
	public:
		static Model *loadFromFile(const char* path);
		
		Model();
		Model(GLuint model);
		
		void Draw();
			
};

#endif