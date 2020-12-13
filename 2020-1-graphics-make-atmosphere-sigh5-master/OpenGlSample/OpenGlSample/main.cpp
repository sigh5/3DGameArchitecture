#define _CRT_SECURE_NO_WARNING

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"

#include "RenderingObject.h"
#include "Sphere.h"
#include "Obj.h"
#include "NonRenderingObject.h"
#include "Time.h"
#include "SampleNonRenderingObj.h"
#include "CompositeObj.h"

int main(void)
{
	FileManager *filemgr = FileManager::instance();
	Renderer *renderer = Renderer::instance();
	Obj* cube = new Obj();
	//SampleNonRenderingObj *nonObj = new SampleNonRenderingObj();
	Obj* cube2 = new Obj();
	
	renderer->init();

	cube->add(cube2);
	cube->setScale(0.5f, 0.5f, 0.5f);
	cube->setRot(1, 0, 0, 1);
	cube2->setPos(5, 0, 0);
	cube2->setRot(1, 0, 0, 1);
	cube2->setScale(0.5f, 0.5f, 0.5f);



	while (glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->window) == 0)
	{
		renderer->renderup();
		if (Time::GetInstance()->IsFixedRendering())
		{
			renderer->Update();
		}
		renderer->render();
		renderer->renderdown();
	}
	renderer->shutDown();
	
	
	delete cube;
	delete cube2;

	return 0;
}
