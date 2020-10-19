#include "Obj.h"




void Obj::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(MatrixID);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void Obj::setXYZ(float x, float y, float z) {

	_Obj1PositionX = x;
	_Obj1PositionY = y;
	_Obj1PositionZ = z;

}

