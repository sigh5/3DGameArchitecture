#pragma once
#include "Object.h"


class NonRenderingObject :public Object
{

public:
	virtual void Update(IUpdate *iupdate)override;
	virtual void setXYZ(float x, float y, float z)override;
	virtual void shutDown()override;

};


