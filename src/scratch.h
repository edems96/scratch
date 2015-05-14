#ifndef SCRATCH_H
#define SCRATCH_H

// C++ Sources
#include <cstdio>

// SDL Sources
#include <SDL2/SDL.h>

// GL Sources
#include <GL/gl.h>

// Game Sources
#include "background.h"

#define TITLE "Scratch"
#define MAX_FPS 60

using namespace std;

typedef unsigned int uint;

class Scratch {
	private:
		uint SCREEN_WIDTH, SCREEN_HEIGHT;
		bool fullscreen, running;
		
		SDL_Window *mWindow;
		SDL_GLContext mGLContext;
		
		Background *background;
		
		void Init();
		void Run();
		
		void HandleEvent(SDL_Event event);
		
		void Update();
		void Draw();
		
		void Log(const char* str);
		void SDLError(const char *str);
		
	public:
		Scratch(uint width, uint height);
		Scratch(uint width, uint height, bool fullscreen);
		~Scratch();
		
};

#endif