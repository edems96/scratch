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
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Scratch::Init() {
	Log("Init()");
	
	if( SDL_Init(SDL_INIT_EVERYTHING) != 0 ) {
		SDLError("Failed to initialize SDL!");
		return;
	}
	
	window = SDL_CreateWindow(
		TITLE,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_OPENGL | (fullscreen ? SDL_WINDOW_FULLSCREEN : 0) );

	if( window == NULL ) {
		SDLError("Failed to initialize window!");
		return;
	}
	
	mGLContext = SDL_GL_CreateContext(window);
	
	if( mGLContext == NULL ) {
		SDLError("Failed to initialize OpenGL Context!");
		return;
	}
	
	InitOpenGL();
	
	player = new Player(Vector(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f, 0));
	
	Sphere s1(Vector(), 10);
	Sphere s2(Vector(11, 0, 0), 1);
	
	if( Collision::sphereSphere(s1, s2) )
		Log("COLL");
	else
		Log("No COLL");

	running = true;
	Run();
}

void Scratch::InitOpenGL() {
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(45, SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 500.0f);
	
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND);
}

void Scratch::Run() {
	Uint32 time;
	SDL_Event event;
	
	while( running ) {
		time = SDL_GetTicks();
		
		HandleEvent(event);
		
		Update();
		Draw();
		
		SDL_GL_SwapWindow(window);
		
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
				
			case SDL_MOUSEBUTTONDOWN:
				if( !player->getCamera()->isMouseInScreen() ) {
					SDL_ShowCursor(SDL_DISABLE);
					player->getCamera()->setMouseInScreen(true);
				}
					
				break;
		}
		
	}
	
}

void Scratch::Update() {
	player->Update();
}

void Scratch::Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	player->Draw(window);
	
	int size = 10;
	glTranslatef(0, 0, -10);
	glBegin(GL_QUADS);
                //front face
                //glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);
                glNormal3f(0.0,0.0,1.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);
 
                //left face
                glNormal3f(-1.0,0.0,0.0);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(-size/2,-size/2,size/2);
 
                //back face
                glNormal3f(0.0,0.0,-1.0);
                glVertex3f(size/2,size/2,-size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);
 
                //right face
                glNormal3f(1.0,0.0,0.0);
                glVertex3f(size/2,size/2,-size/2);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,-size/2);
 
                //top face
                glNormal3f(0.0,1.0,0.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(size/2,size/2,-size/2);
 
                //bottom face
                glNormal3f(0.0,-1.0,0.0);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
}

SDL_Window* Scratch::getWindow() {
	return window;
}

int Scratch::getScreenWidth() {
	int width;
	SDL_GetWindowSize(window, &width, NULL);
	
	return width;
}

int Scratch::getScreenHeight() {
	int height;
	SDL_GetWindowSize(window, NULL, &height);
	
	return height;
}
 
void Scratch::Log(const char* str) {
	printf("Log: %s\n", str);
}

void Scratch::SDLError(const char *str) {
	printf("SDL Error(%d): %s\n", SDL_GetError(), str);
}