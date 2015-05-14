#include "background.h"

Background::Background(uint width, uint height) {
	texture = Texture::loadFromFile("res/background.png");
	
	mList = glGenLists(1);
	glNewList(mList, GL_COMPILE);
	
		if( texture != NULL )
			texture->Bind();
				
		glBegin(GL_QUADS);
		
			glTexCoord2i(0, 1);
			glVertex2f(0, 0);
			
			glTexCoord2i(0, 0);
			glVertex2f(0, height);
			
			glTexCoord2i(1, 0);
			glVertex2f(width, height);
			
			glTexCoord2i(1, 1);
			glVertex2f(width, 0);
		
		glEnd();
		
	glEndList();
}

Background::~Background() {
	glDeleteLists(mList, 1);
}

void Background::Draw() {
	glCallList(mList);
}