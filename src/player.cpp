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

void Player::Draw(SDL_Window* window) {
	camera.Control(window);
	camera.Update();
}

Camera* Player::getCamera() {
	return &camera;
}