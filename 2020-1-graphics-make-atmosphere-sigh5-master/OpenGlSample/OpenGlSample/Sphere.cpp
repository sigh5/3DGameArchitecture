#include "Sphere.h"
#include "FileManager.h"

void Sphere::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}


void Sphere::setXYZ(float x, float y, float z) 
{
	_Obj1PositionX = x;
	_Obj1PositionY = y;
	_Obj1PositionZ = z;
}



Sphere::Sphere()
{
	programID= _loadData->LoadShaders("20161677_황현욱_vs.shader", "20161677_황현욱_fs.shader");
	MatrixID = glGetUniformLocation(programID, "MVP");
	Texture = _loadData->loadBMP("star.bmp");
	TextureID = glGetUniformLocation(programID, "myTextureSampler");
	bool res = _loadData->loadOBJ("sphere.obj", vertices, uvs, normals);


	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

}


