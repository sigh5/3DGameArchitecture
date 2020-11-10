#define _CRT_SECURE_NO_WARNING

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"

#include "RenderingObject.h"
#include "Sphere.h"
#include "Obj.h"
#include "NonRenderingObject.h"
#include "Time.h"
#include "SampleNonRenderingObj.h"

int main(void)
{
	FileManager *filemgr = FileManager::instance();
	Renderer *renderer = Renderer::instance();
	Obj* cube = new Obj();
	SampleNonRenderingObj *nonObj = new SampleNonRenderingObj();

	renderer->init();


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
	
	delete nonObj;
	delete cube;

	

	return 0;
}
