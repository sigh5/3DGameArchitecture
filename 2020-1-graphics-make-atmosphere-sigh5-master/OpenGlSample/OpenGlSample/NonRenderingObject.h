#pragma once
#include "Object.h"
#include "IUpdate.h"

class NonRenderingObject :public Object, public IUpdate
{

public:
	virtual void Update(IUpdate *iupdate)override;
	virtual void setXYZ(float x, float y, float z)override;
	virtual void shutDown()override;

};


