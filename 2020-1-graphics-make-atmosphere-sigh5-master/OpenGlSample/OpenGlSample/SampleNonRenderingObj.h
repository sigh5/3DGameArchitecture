#pragma once
#include "NonRenderingObject.h"


class SampleNonRenderingObj :public NonRenderingObject 
{
public:
	virtual void Update()override;
	virtual void setXYZ(float x, float y, float z) override;
	virtual void shutDown()override;
	virtual void render()override;
	virtual void init() override;


};