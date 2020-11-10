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
private:
	

};

