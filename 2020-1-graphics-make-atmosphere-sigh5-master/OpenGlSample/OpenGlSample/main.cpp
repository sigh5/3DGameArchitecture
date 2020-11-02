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

int main(void)
{
	FileManager *filemgr = FileManager::instance();
	Renderer *renderer = Renderer::instance();
	renderer->init();
	
	Obj*cube = new Obj();
	filemgr->loadObj(
	cube,
	"cube.obj",
	"star.bmp",
	"20161677_황현욱_vs.shader",
	"20161677_황현욱_fs.shader"
);
	cube->setXYZ(10.0f,0.0f,0.0f); //모델의 위치이동
	renderer->addObject(cube);  
	
	Sphere *sphere = new Sphere();
	sphere->setXYZ(5.0f, 0.0f, 0.0f); //모델 좌표이동
	renderer->addObject(sphere);

	Obj* human = new Obj();

	filemgr->loadObj(
		human,
		"human_2.obj",
		"star.bmp",
		"20161677_황현욱_vs.shader",
		"20161677_황현욱_fs.shader"
	);
	
	human->setXYZ(6.0f, 0.0f, 0.0f);
	renderer->addObject(human);

	Obj* Background = new Obj();

	Background->setXYZ(20.0f, -11.0f, 10.0f);
	filemgr->loadObj(
		Background,
		"Back.obj",
		"moon.bmp",
		"20161677_황현욱_vs.shader",
		"20161677_황현욱_fs.shader"
	);
	renderer->addObject(Background);

	NonRenderingObject *non_render_obj = new NonRenderingObject();


	while (glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->window) == 0)
	{
		renderer->renderup();

		if (Time::GetInstance()->IsFixedRendering())
		{
			renderer->Update(non_render_obj);
			renderer->Update(cube);
		}

		renderer->draw();


		renderer->renderdown();
	}

		
	renderer->shutDown();
	
	delete sphere;
	delete cube;
	delete human;
	delete non_render_obj;

	return 0;
}
