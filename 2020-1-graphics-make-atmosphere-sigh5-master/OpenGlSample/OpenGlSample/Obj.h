
#pragma once
#include "RenderingObject.h"

class Obj :public RenderingObject
{
public:
	virtual void shutDown() override;
	virtual void setXYZ(float x, float y, float z)override;
};

