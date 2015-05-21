#ifndef PLAYER_H
#define PLAYER_H

#include <cstdio>

#include <SDL2/SDL.h>

#include <GL/GL.h>

#include "camera.h"
#include "texture.h"
#include "vector.h"
#include "plane.h"
#include "collision.h"

class Player {
	
	private:
		Camera camera;
		Texture texture;
		
		int health;
		float speed;
		
	public:
		Player(const Vector &position);
		~Player();
		
		Player setPosition(const Vector &position);
		Vector getPosition();
		
		Player setHealth(const int health);
		int getHealth();
		
		Player setSpeed(const float speed);
		float getSpeed();
		
		void Update();
		void Draw(SDL_Window* window, Plane *planes, uint c);
		
		Camera* getCamera();
};

#endif