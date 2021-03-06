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
		
	public:
		static Texture* loadFromFile(const char *path);
		
		Texture();
		Texture(GLuint image);
		~Texture();
		
		Texture setImage(GLuint image);
		GLuint getImage();
		
		void Bind();
};

#endif