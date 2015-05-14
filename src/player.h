#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"

class Player : GameObject {
	
	private:
		int mHealth;
		float mSpeed;
		
	public:
		Player();
		~Player();
		
		Player setHealth(const int health);
		int getHealth();
		
		Player setSpeed(const float speed);
		float getSpeed();
};

#endif