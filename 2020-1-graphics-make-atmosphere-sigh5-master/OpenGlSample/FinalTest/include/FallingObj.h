#pragma once
#include "RenderingObject.h"

class FallingObj :public RenderingObject
{
public:
	virtual void setPos(float x, float y, float z) override;
	virtual void setRot(float speed, float x, float y, float z)override;
	virtual void setScale(float x, float y, float z)override;
	virtual void setCameraPos(float x, float y, float z) override;
	virtual void init() override;
	virtual void render() override;
	virtual void Update() override;
	virtual void shutDown() override;

	virtual void addComposite(CompositeObj* addObj)override;

private:

	float speed;
};
