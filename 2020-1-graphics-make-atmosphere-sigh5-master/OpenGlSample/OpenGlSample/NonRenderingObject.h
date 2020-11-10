#pragma once
#include "Object.h"


class NonRenderingObject :public Object
{
public:
	NonRenderingObject();

public:
	virtual void Update()override;
	virtual void setXYZ(float x, float y, float z)override;
	virtual void shutDown()override;
	virtual void render()override;
	virtual void init() override;


};


