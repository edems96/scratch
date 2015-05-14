#include "scratch.h"

Scratch::Scratch(uint width, uint height) {
	Log("Scratch()");
	
	this->SCREEN_WIDTH = width;
	this->SCREEN_HEIGHT = height;
	this->fullscreen = false;
	
	Init();
}

Scratch::Scratch(uint width, uint height, bool fullscreen) {
	Log("Scratch()");
	
	this->SCREEN_WIDTH = width;
	this->SCREEN_HEIGHT = height;
	this->fullscreen = fullscreen;
	
	Init();
}

Scratch::~Scratch() {
	Log("~Scratch()");
	
	SDL_GL_DeleteContext(mGLContext);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Scratch::Init() {
	Log("Init()");
	
	if( SDL_Init(SDL_INIT_EVERYTHING) != 0 ) {
		SDLError("Failed to initialize SDL!");
		return;
	}
	
	mWindow = SDL_CreateWindow(
		TITLE,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_OPENGL | (fullscreen ? SDL_WINDOW_FULLSCREEN : 0) );

	if( mWindow == NULL ) {
		SDLError("Failed to initialize window!");
		return;
	}
	
	mGLContext = SDL_GL_CreateContext(mWindow);
	
	if( mGLContext == NULL ) {
		SDLError("Failed to initialize OpenGL Context!");
		return;
	}
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	
	background = new Background(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	running = true;
	Run();
}

void Scratch::Run() {
	Uint32 time;
	SDL_Event event;
	
	while( running ) {
		time = SDL_GetTicks();
		
		HandleEvent(event);
		
		Update();
		Draw();
		
		SDL_GL_SwapWindow(mWindow);
		
		if( 1000.0f / MAX_FPS > ( SDL_GetTicks() - time ) )
			SDL_Delay( 1000.0f / MAX_FPS - ( SDL_GetTicks() - time ) );
	}
}

void Scratch::HandleEvent(SDL_Event event) {
	
	while( SDL_PollEvent(&event) ) {
		
		switch( event.type ) {
			case SDL_QUIT: running = false; break;
			
			case SDL_KEYDOWN:
				switch( event.key.keysym.sym ) {
					case SDLK_ESCAPE: running = false; break;
				}
				break;
		}
		
	}
	
}

void Scratch::Update() {
	
}

void Scratch::Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	background->Draw();
}

void Scratch::Log(const char* str) {
	printf("Log: %s\n", str);
}

void Scratch::SDLError(const char *str) {
	printf("SDL Error(%d): %s\n", SDL_GetError(), str);
}