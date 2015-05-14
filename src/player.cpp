#include "player.h"

Player::Player() {
	
}

Player::~Player() {
	
}

Player Player::setHealth(const int health) {
	mHealth = health; return *this;
}

int Player::getHealth() {
	return mHealth;
}

Player Player::setSpeed(const float speed) {
	mSpeed = speed; return *this;
}

float Player::getSpeed() {
	return mSpeed;
}