#ifndef SCRATCH_H
#define SCRATCH_H

// C++ Sources
#include <cstdio>

// SDL Sources
#include <SDL2/SDL.h>

// GL Sources
#include <GL/gl.h>
#include <GL/Glu.h>

// Game Sources
#include "camera.h"
#include "player.h"
#include "collision.h"
#include "sphere.h"

#define TITLE "Scratch"
#define MAX_FPS 60

using namespace std;

typedef unsigned int uint;

class Scratch {
	
	private:
		uint SCREEN_WIDTH, SCREEN_HEIGHT;
		bool fullscreen, running;
		
		SDL_Window *window;
		SDL_GLContext mGLContext;
		
		Player *player;
		
		void Init();
		void InitOpenGL();
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
		
		SDL_Window *getWindow();
		
		int getScreenWidth();
		int getScreenHeight();
};

#endif