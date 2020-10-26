#pragma once
#include "RenderingObject.h"

class RenderingObject;
class FileManager;

class Sphere :public RenderingObject {


private:
	
public:
	Sphere();
	

public:
	virtual void shutDown() override;
	virtual void setXYZ(float x, float y, float z)override;
	
};