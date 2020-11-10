#pragma once

#include "ISetPosition.h"
#include "FileManager.h"
#include "ICleanUp.h"
#include "IUpdate.h"
#include <vector>

class RenderingObject;
class NonRenderingObject;

class Renderer :public ICleanUp, public ISetPosition,public IUpdate
{
private:
	std::vector< RenderingObject*> renderObjList;
	std::vector< NonRenderingObject*> nonrenderObjList;

public:
	static Renderer* instance() {

		static Renderer instance;

		return &instance;
	}
	
public:
	int init();	
	void render();
	void renderup();
	void renderdown();
	void addRenderObject(RenderingObject* _obj);
	void addNonRenderObject(NonRenderingObject* _obj);

public:
	GLFWwindow* window;

public:
	virtual void shutDown()override;
	virtual void setXYZ(float x, float y, float z)override; 
	virtual void Update()override;

};