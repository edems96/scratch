#ifndef TEXTURE_H
#define TEXTURE_H

#include <cstdio>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <GL/gl.h>

#define GL_UNSIGNED_INT_8_8_8_8 0x8035

class Texture {
	
	private:
		GLuint mImage;
		
		Texture(const GLuint image);
		~Texture();
		
	public:
		static Texture *loadFromFile(const char *path);
		void Bind();
};

#endif