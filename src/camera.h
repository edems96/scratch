#ifndef CAMERA_H
#define CAMERA_H

#include <cstdio>
#include <cmath>

#include <SDL2/SDL.h>

#include <GL/gl.h>

#include "vector.h"

typedef unsigned int uint;

class Camera {
	
	private:
		Vector position;

		float pitch, yaw;
		float moveVelocity, mouseVelocity;
		bool mouseInScreen;
		
		void lock();
		void move(float direction);
		void moveUp(float direction);
		
	public:
		Camera();
		
		void Control(SDL_Window *window);
		void Update();
		
		Camera* setPosition(const Vector &vector);
		Vector getPosition();
		
		Camera* setPitch(const float pitch);
		float getPitch();
		
		Camera* setYaw(const float yaw);
		float getYaw();
		
		Camera* setMoveVelocity(const float velocity);
		float getMoveVelocity();
		
		Camera* setMouseVelocity(const float velocity);
		float getMouseVelocity();
		
		Camera* setMouseInScreen(bool mouseInScreen);
		bool isMouseInScreen();
		bool toggleMouseInScreen();
};

#endif