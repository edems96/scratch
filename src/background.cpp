#include "background.h"

Background::Background(uint width, uint height) {
	texture = Texture::loadFromFile("res/background.png");
	
	mList = glGenLists(1);
	glNewList(mList, GL_COMPILE);
	
		glBegin(GL_QUADS);
		
			glVertex2f(0, 0);
			glVertex2f(0, height);
			glVertex2f(width, height);
			glVertex2f(width, 0);
		
			
		glEnd();
	glEndList();
}

Background::~Background() {

}

void Background::Draw() {
	glCallList(mList);
}