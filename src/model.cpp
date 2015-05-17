#include "model.h"

Model::Model() {
	vertexCount = 0;
}

void Model::addVertex(const Coordinate *vertex) {
	Coordinate * tmp = (Coordinate*) malloc(sizeof(Coordinate) * (vertexCount + 1) );
	
	if( tmp == NULL ) {
		printf("Failed to allocate memory for a new vertex!\n");
		return;
	}
	
	memmove((void*)tmp, (void*)this->vertex, sizeof(Coordinate) * vertexCount);
	memmove((void*)(tmp + (sizeof(Coordinate) * vertexCount)), (void*)vertex, sizeof(Coordinate));
	
	vertexCount++;
}

Model* Model::loadFromFile(const char* path) {
	FILE *f;
	f = fopen(path, "r");
	
	if( f == NULL ) {
		printf("Failed to open model: %s! No such file or cannot open!\n", path);
		return NULL;
	}
	
	Model model;
	
	while( true ) {
		int c = fgetc(f);
		
		if( c == EOF )
			break;
		else if( c == '#' ) {
			
			while( true ) {
				if( fgetc(f) == '\n' )
					break;
			}
			
		}
		else if( c == 'v' ) {
			int a = fgetc(f);
			
			if( a == ' ' ) {
				
			} 
			else if( a == 'n' ) {
				
			}
		}
		
	}
	
	fclose(f);
}