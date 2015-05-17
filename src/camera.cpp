#include "camera.h"

Camera::Camera() {
	pitch = 0;
	yaw = 0;
	
	moveVelocity = 0;
	mouseVelocity = 0;
	
	mouseInScreen = false;
}

void Camera::lock() {
	if( pitch > 90 )
		pitch = 90;
	
	if( pitch < -90 )
		pitch = -90;
	
	if( yaw < 0 )
		yaw += 360;
	
	if( yaw > 360 )
		yaw -= 360;
}

void Camera::move(float direction) {
	float radian = (yaw + direction) * M_PI / 180.0f;
	
	position.x -= sin(radian) * moveVelocity;
	position.z -= cos(radian) * moveVelocity;
	printf("position: %f %f %f\n", position.x, position.y, position.z);
	printf("pitch: %f yaw: %f\n", pitch, yaw);
}

void Camera::moveUp(float direction) {
	float radian = (pitch + direction) * M_PI / 180.0f;
	
	position.y += sin(radian) * moveVelocity;
	printf("moveUp\n");
}

void Camera::Control(SDL_Window *window) {
	
	if( mouseInScreen ) {
		int midX, midY;
		
		SDL_GetWindowSize(window, &midX, &midY);
		
		midX /= 2;
		midY /= 2;
	
		int x, y;
		SDL_GetMouseState(&x, &y);
		
		pitch += mouseVelocity * (midY - y);
		yaw += mouseVelocity * (midX - x);
		
		printf("mv: %f\n", mouseVelocity);
		
		lock();
		
		SDL_WarpMouseInWindow(window, midX, midY);
		
		const Uint8 *state = SDL_GetKeyboardState(NULL);
		
		if( state[SDL_SCANCODE_W] ) {
			if( pitch != 90 && pitch != -90 )
				move(0);
			
			moveUp(0);
		}
		else if( state[SDL_SCANCODE_S] ) {
			if( pitch != 90 && pitch != -90 )
				move(180);
			
			moveUp(180);
		}
		
		if( state[SDL_SCANCODE_A] )
			move(90);
		else if( state[SDL_SCANCODE_D] )
			move(270);
	}
	
	glRotatef(-pitch, 1.0f, 0.0f, 0.0f);
	glRotatef(-yaw, 0.0f, 1.0f, 0.0f);
}

void Camera::Update() {
	glTranslatef(-position.x, -position.y, -position.z);
}

Camera* Camera::setPosition(const Vector &vector) {
	position.set(vector); return this;
}

Vector Camera::getPosition() {
	return position;
}
		
Camera* Camera::setPitch(const float pitch) {
	this->pitch = pitch; return this;
}

float Camera::getPitch() {
	return pitch;
}
		
Camera* Camera::setYaw(const float yaw) {
	this->yaw = yaw; return this;
}

float Camera::getYaw() {
	return yaw;
}
		
Camera* Camera::setMoveVelocity(const float velocity) {
	moveVelocity = velocity; return this;
}

float Camera::getMoveVelocity() {
	return moveVelocity;
}
		
Camera* Camera::setMouseVelocity(const float velocity) {
	mouseVelocity = velocity; return this;
}

float Camera::getMouseVelocity() {
	return mouseVelocity;
}
		
Camera* Camera::setMouseInScreen(bool mouseInScreen) {
	this->mouseInScreen = mouseInScreen; return this;
}
bool Camera::isMouseInScreen() {
	return mouseInScreen;
}