#include "Obj.h"
#include "FileManager.h"
#include "InputKey.h"


void Obj::setPos(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
}


void Obj::setRot(float speed, float x, float y, float z)
{
	rotSpeed = speed;
	rotVec = glm::vec3(x, y, z);
}

void Obj::setScale(float x, float y, float z)
{
	scaleVec = glm::vec3(x, y, z);
	if (scaleVec.x != 0.0f || scaleVec.y != 0.0f || scaleVec.z != 0.0f)
	{
		Scale = glm::scale(Scale, scaleVec);
	}
}

void Obj::setCameraPos(float x, float y, float z)
{
	cameraPos = glm::vec3(-x, -y, -z);
}


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
void Obj::Update()
{

}

void Obj::init()
{
	FileManager *filemgr = FileManager::instance();
	filemgr->loadObj(this, "cube.obj", "star.bmp",
		"20161677_황현욱_vs.shader",
		"20161677_황현욱_fs.shader");
	this->setPos(0, 0, 0);
	this->setCameraPos(0, 0, 0);
	this->setScale(0, 0, 0);
	

}

glm::mat4 Obj::getMatrixTranslatePosition(glm::mat4 Model, RenderingObject *obj)
{
	float a, b, c = 0;

	a = obj->_Obj1PositionX;
	b = obj->_Obj1PositionY;
	c = obj->_Obj1PositionZ;

	Model = glm::translate(Model, glm::vec3(a, b, c));
	return Model;
}


void Obj::render()
{
	glUseProgram(this->programID);

	InputKey::GetInstance()->KeyBoard();
	InputKey::GetInstance()->setMousepos();

	glm::mat4 ProjectionMatrix = InputKey::GetInstance()->getProjectionMatrix();
	glm::mat4 ViewMatrix = InputKey::GetInstance()->getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);

	//ModelMatrix = getMatrixTranslatePosition(ModelMatrix, this);
	//glm::mat4 MVP = ProjectionMatrix * ViewMatrix*ModelMatrix;

	//glUniformMatrix4fv(this->MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->Texture);
	glUniform1i(this->TextureID, 0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	glBindBuffer(GL_ARRAY_BUFFER, this->uvbuffer);
	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
	glBindBuffer(GL_ARRAY_BUFFER, this->normalbuffer);
	glVertexAttribPointer(
		2,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glm::mat4 movePos = glm::mat4(1.0f);
	movePos = glm::translate(movePos, this->position);

	glm::mat4 moveCameraPos = glm::mat4(1.0f);
	moveCameraPos = glm::translate(moveCameraPos, this->cameraPos);

	glm::mat4 MVP;

	if (rotSpeed > 0.0f)
	{
		Rot = glm::rotate(Rot, glm::radians(rotSpeed), rotVec);
	}

	MVP = ProjectionMatrix * moveCameraPos * ViewMatrix*ComPositScale*ComPositPos *CompositRot * Scale* movePos *Rot * ModelMatrix;


	glUniformMatrix4fv(this->MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	for (
		vector<Object*>::const_iterator it = _Table->begin();
		it != _Table->end();
		++it
		)
	{
		(*it)->RotMatrix(Rot);
		(*it)->PosMatrix(movePos);
		(*it)->PosMatrix(Scale);
	}
}

void Obj::add(Object* addObj)
{
	_Table->push_back(addObj);
}


void Obj::RotMatrix(glm::mat4 _rot)
{
	CompositRot = _rot;
}

void Obj::PosMatrix(glm::mat4 _pos)
{
	ComPositPos = _pos;
}

void Obj::ScaleMatrix(glm::mat4 _scale)
{
	ComPositScale = _scale;
}