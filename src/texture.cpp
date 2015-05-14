#include "texture.h"

Texture::Texture() {
}

Texture::Texture(GLuint *image) {
	mImage = image;
}

Texture::~Texture() {
	glDeleteTextures(1, mImage);
}

Texture *Texture::loadFromFile(const char *path) {
	SDL_Surface *image;
	image = IMG_Load(path);
	
	if( image == NULL ) {
		printf("Failed to load image: %s! Error: %s\n", path, IMG_GetError());
		return NULL;
	}
	
	SDL_PixelFormat form = {
		SDL_PIXELFORMAT_RGBA8888,
		NULL, 
		32, 4, 
		0, 0, 0, 0}; /*, 
		8, 8, 8, 8,
		0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff,
		0, NULL }; // 55
		*/
							
	SDL_Surface *image2 = SDL_ConvertSurface(image, &form, SDL_SWSURFACE);
	
	GLuint id[1];
	glGenTextures(1, &id[0]);
	
	glBindTexture(GL_TEXTURE_2D, id[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image2->w, image2->h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, image2->pixels);
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	SDL_FreeSurface(image);
	SDL_FreeSurface(image2);
	
	printf("Imaged loaded(%d): %s\n", id[0], path);
	
	return new Texture(id);
}

Texture Texture::setImage(GLuint *image) {
	mImage = image; return *this;
}

GLuint* Texture::getImage() {
	return mImage;
}

void Texture::Bind() {
	printf("bind: %d\n", mImage[0]); // error here
	glBindTexture(GL_TEXTURE_2D, mImage[0]);
}