#pragma once
#include "Object.h"
#include "CompositeObj.h"

class NonRenderingObject :public CompositeObj
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


