#include "model.h"

Model::Model() {
	model = 0;
}

Model::Model(GLuint model) {
	this->model = model;
}

Model *Model::loadFromFile(const char* path) {
	FILE *f;
	f = fopen(path, "r");
	
	if( f == NULL ) {
		printf("Failed to open model: %s! No such file or cannot open!\n", path);
		return NULL;
	}
	
	char *HEADER = (char*) malloc(5);
	
	fread(HEADER, 5, 1, f);
	
	if( strcmp(HEADER, "MODEL") != 0 ) {
		printf("Bad file format! Use .model!\n");
		return NULL;
	}
	
	ushort version;
	fread(&version, sizeof(ushort), 1, f);
	
	uint c_vertex, c_textureCoordinate, c_normal, c_face, c_material;
	
	fread(&c_vertex, sizeof(uint), 1, f);
	fread(&c_textureCoordinate, sizeof(uint), 1, f);
	fread(&c_normal, sizeof(uint), 1, f);
	fread(&c_face, sizeof(uint), 1, f);
	fread(&c_material, sizeof(uint), 1, f);
	
	printf("Vertex count: %d\n", c_vertex);
	printf("Texture coordinate count: %d\n", c_textureCoordinate);
	printf("Normal count: %d\n", c_normal);
	printf("Face count: %d\n", c_face);
	printf("Material count: %d\n", c_material);
	
	Vertex* vertexes = (Vertex*) malloc(sizeof(Vertex) * c_vertex);
	TextureCoordinate* textureCoordinates = (TextureCoordinate*) malloc(sizeof(TextureCoordinate) * c_textureCoordinate);
	Normal* normals = (Normal*) malloc(sizeof(Normal) * c_normal);
	Face* faces = (Face*) malloc(sizeof(Face) * c_face);
	Material* materials = (Material*) malloc(sizeof(Material) * c_material);
	
	if( fread(vertexes, sizeof(Vertex), c_vertex, f) != c_vertex ) {
		printf("Failed to read vertexes from .model file: %s\n", path);
		return NULL;
	}
	
	if( fread(textureCoordinates, sizeof(TextureCoordinate), c_textureCoordinate, f) != c_textureCoordinate ) {
		printf("Failed to read texture coordinates from .model file: %s\n", path);
		return NULL;
	}
	
	if( fread(normals, sizeof(Normal), c_normal, f) != c_normal ) {
		printf("Failed to read normals from .model file: %s\n", path);
		return NULL;
	}
	
	if( fread(faces, sizeof(Face), c_face, f) != c_face ) {
		printf("Failed to read faces from .model file: %s\n", path);
		return NULL;
	}
	
	if( fread(materials, sizeof(Material), c_material, f) != c_material ) {
		printf("Failed to read materials from .model file: %s\n", path);
		return NULL;
	}

	fclose(f);
	
	vector<Texture*> textures;
	vector<char*> textureNames;
	
	for(uint i = 0; i < c_material; i++) {
		string path = "res/";
		path += materials[i].map_Kd;
		
		textures.push_back(Texture::loadFromFile(path.c_str()));
		textureNames.push_back(materials[i].map_Kd);
	}
	
	GLuint num;
	num = glGenLists(1);

	glNewList(num, GL_COMPILE);

	for(uint i = 0; i < c_face; i++) {
		
		if( faces[i].material != 0 ) {
			float diffuse[] = { materials[faces[i].material - 1].Kd[0], materials[faces[i].material - 1].Kd[1], materials[faces[i].material - 1].Kd[2], 1.0 };
			float ambient[] = { materials[faces[i].material - 1].Ka[0], materials[faces[i].material - 1].Ka[1], materials[faces[i].material - 1].Ka[2], 1.0 };
			float specular[] = { materials[faces[i].material - 1].Ks[0], materials[faces[i].material - 1].Ks[1], materials[faces[i].material - 1].Ks[2], 1.0 };
			
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
			glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
			
			glMaterialf(GL_FRONT, GL_SHININESS, materials[faces[i].material - 1].Ns);
			
			glColor3f(materials[faces[i].material - 1].Kd[0], materials[faces[i].material - 1].Kd[1], materials[faces[i].material - 1].Kd[2]);
		
			if( strlen(materials[faces[i].material - 1].map_Kd) ) {
				glEnable(GL_TEXTURE_2D);
				
				for(uint j = 0; j < textures.size(); j++) {
					if( strcmp(materials[faces[i].material - 1].map_Kd, textureNames[j]) )
						textures[j]->Bind();
				}
				
			}
		}
		
		if( faces[i].quad ) {
			glBegin(GL_QUADS);
				
				for(uint j = 0; j < 4; j++) {
					
					if( faces[i].hasTextureCoordinate )
						glTexCoord2f(textureCoordinates[faces[i].texture[j] - 1].u, textureCoordinates[faces[i].texture[j] - 1].v);
					
					if( faces[i].hasNormal )
						glNormal3f(normals[faces[i].normal[j] - 1].x, normals[faces[i].normal[j] - 1].y, normals[faces[i].normal[j] - 1].z);
					
					glVertex3f(vertexes[faces[i].vertex[j] - 1].x, vertexes[faces[i].vertex[j] - 1].y, vertexes[faces[i].vertex[j] - 1].z);
				}
				
			glEnd();
		} else {
			glBegin(GL_TRIANGLES);
			
				for(uint j = 0; j < 3; j++) {
					
					if( faces[i].hasTextureCoordinate )
						glTexCoord2f(textureCoordinates[faces[i].texture[j] - 1].u, textureCoordinates[faces[i].texture[j] - 1].v);
					
					if( faces[i].hasNormal )
						glNormal3f(normals[faces[i].normal[j] - 1].x, normals[faces[i].normal[j] - 1].y, normals[faces[i].normal[j] - 1].z);
					
					glVertex3f(vertexes[faces[i].vertex[j] - 1].x, vertexes[faces[i].vertex[j] - 1].y, vertexes[faces[i].vertex[j] - 1].z);
				}
				
			glEnd();
		}
		
		glDisable(GL_TEXTURE_2D);
	}
	
	glEndList();
	
	return new Model(num);
}

void Model::Draw() {
	glCallList(model);
}