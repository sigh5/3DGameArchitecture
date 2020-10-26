#pragma once

#include "ISetPosition.h"
#include "FileManager.h"
#include "ICleanUp.h"
#include "IUpdate.h"
#include <vector>

class RenderingObject;

class Renderer :public ICleanUp, public ISetPosition,public IUpdate
{
private:
	std::vector< RenderingObject*> objects;
public:
	static Renderer* instance() {

		static Renderer instance;

		return &instance;
	}
	
public:
	void init();
	glm::mat4 getMatrixTranslatePosition(glm::mat4 Model, RenderingObject *obj);
	void addObject(RenderingObject *_object);
	void draw();
	void renderup();
	void renderdown();
	void objectShutdown(RenderingObject*_obj);

public:
	GLFWwindow* window;

public:
	virtual void shutDown()override;
	virtual void setXYZ(float x, float y, float z)override; 
	virtual void Update(IUpdate *iupdate)override;

private :
	void renderer(RenderingObject* _object);  //드로우함수에서 다쓸려고 


};