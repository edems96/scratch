#include "player.h"

Player::Player(const Vector &position) {
	setPosition(position);
	
	camera.setMoveVelocity(0.2f)->setMouseVelocity(0.2);
	
	health = 0;
	speed = 0;
}

Player::~Player() {
	
}

Player Player::setPosition(const Vector &position) {
	camera.setPosition(position); return *this;
}

Vector Player::getPosition() {
	return camera.getPosition();
}

Player Player::setHealth(const int health) {
	this->health = health; return *this;
}

int Player::getHealth() {
	return health;
}

Player Player::setSpeed(const float speed) {
	this->speed = speed; return *this;
}

float Player::getSpeed() {
	return speed;
}

void Player::Update() {
	
}

bool rayPlane(Vector start, Vector direction, Plane plane, float &distance) {
	if( Collision::rayTriangle(start, direction, plane.getVertex(0), plane.getVertex(1), plane.getVertex(2), &distance) ) 
		return true;

	if( Collision::rayTriangle(start, direction, plane.getVertex(0), plane.getVertex(2), plane.getVertex(3), &distance) ) 
		return true;

	return false;
}

void Player::Draw(SDL_Window* window, Plane *planes, uint c) {
	Vector pos(camera.getPosition());
	camera.Control(window);
	
	Vector dir = (camera.getPosition() - pos);

	for(uint i = 0; i < c; i++) {
		float distance = 0.0f;
		
		glBegin(GL_LINE_LOOP);
		glColor3f(0.f, 1.f, 0.f);
		for(uint j = 0; j < 4; j++) {
			glVertex3f(planes[i].getVertex(j).x, planes[i].getVertex(j).y, planes[i].getVertex(j).z);
		}
		glEnd();
		
		/* if( rayPlane(pos, dir, planes[i], distance) ) {
			if( distance < 10.0f ) {
				printf("#COOLL dist: %f %f\n", distance, (10.0f - distance));
				Vector end(pos + dir * distance);
				
				
				
				camera.setPosition(end);
				break;
			}
		} */
		
	}
	
	camera.Update();
}

Camera* Player::getCamera() {
	return &camera;
}