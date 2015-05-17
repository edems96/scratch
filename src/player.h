#ifndef PLAYER_H
#define PLAYER_H

#include <cstdio>

#include <SDL2/SDL.h>

#include <GL/GL.h>

#include "gameobject.h"
#include "camera.h"

class Player : GameObject {
	
	private:
		Camera camera;
		
		int health;
		float speed;
		
	public:
		Player(const Vector &position);
		~Player();
		
		Player setHealth(const int health);
		int getHealth();
		
		Player setSpeed(const float speed);
		float getSpeed();
		
		void Update();
		void Draw(SDL_Window* window);
		
		Camera* getCamera();
};

#endif