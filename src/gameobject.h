#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vector.h"
#include "texture.h"

class GameObject {
	
	private:
		Vector mPosition;
		Vector mSize;
		
		float mRotate;
		
		Texture mTexture;
		
	public:
		GameObject();
		~GameObject();

		GameObject setPosition(const Vector &position);
		Vector *getPosition();
		
		GameObject setSize(const Vector &size);
		Vector getSize();

		GameObject setRotate(const float angle);
		float getRotate();
		
		void Update();
		void Draw();
};

#endif