#pragma once
#include "Object.h"
#include <vector>
#include "CompositeObj.h"

class RenderingObject:public CompositeObj
{

public:
	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint Texture;
	GLuint TextureID;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	
	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint LightID;
public:
	
	float _Obj1PositionX;
	float _Obj1PositionY;
	float _Obj1PositionZ;
	
public:
	RenderingObject();

public:
	virtual void shutDown() override {};
	virtual void setXYZ(float x, float y, float z)override {};
	virtual void Update()override {};
	virtual void init() override {};
	virtual void render() override {};
	
	virtual void setPos(float x, float y, float z) {};
	virtual void setRot(float speed, float x, float y, float z) {};
	virtual void setScale(float x, float y, float z) {};
	virtual void setCameraPos(float x, float y, float z) {};

	virtual void addComposite(CompositeObj* addObj)override {};


};