#pragma once
#include "RenderingObject.h"


class Obj :public RenderingObject
{

public:
	virtual void shutDown() override;
	virtual void setXYZ(float x, float y, float z)override;
	virtual void Update()override;
	virtual void init() override;
	virtual void render() override;
	
	glm::mat4 getMatrixTranslatePosition(glm::mat4 Model, RenderingObject *obj);

	virtual void setPos(float x, float y, float z) override;
	virtual void setRot(float speed, float x, float y, float z)override;
	virtual void setScale(float x, float y, float z)override;
	virtual void setCameraPos(float x, float y, float z) override;
	virtual void add(Object* addObj)override;
	virtual void RotMatrix(glm::mat4 _rot)  override;
	virtual void PosMatrix(glm::mat4 _pos)  override;
	virtual void ScaleMatrix(glm::mat4 _scale) override;

};

