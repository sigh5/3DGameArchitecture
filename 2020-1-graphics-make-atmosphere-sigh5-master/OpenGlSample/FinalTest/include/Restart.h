#pragma once
#include "RenderingObject.h"

class Restart :public RenderingObject
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

	bool getGameOver();
	void setGameOver(bool _IsGame);

private:
	bool IsGame;
};
