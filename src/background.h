#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL2/SDL.h>

#include "texture.h"

typedef unsigned int uint;

class Background {
	
	private:
		Texture *texture;
		int mList;
		
	public:
		Background(uint width, uint height);
		~Background();
		
		void Draw();
};

#endif