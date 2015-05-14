#include "gameobject.h"

GameObject::GameObject() {
	rotate = 0;
}

GameObject::~GameObject() {

}

GameObject GameObject::setPosition(const Vector &position) {
	mPosition.set(position); return *this;
}

Vector GameObject::getPosition() {
	return Vector(mPosition);
}

GameObject GameObject::setSize(const Vector &size) {
	mSize.set(size); return *this;
} 

Vector GameObject::getSize() {
	return Vector(mSize);
}

GameObject GameObject::setRotate(const float angle) {
	mAngle = angle; return *this;
}

float GameObject::getRotate() {
	return mAngle;
}

void GameObject::Update() {
}

void GameObject::Draw() {
	
}