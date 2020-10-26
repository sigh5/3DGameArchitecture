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
	cube->setXYZ(10.0f,5.0f,0.0f); //모델의 위치이동
	renderer->addObject(cube);  
	
	Sphere *sphere = new Sphere();
	sphere->setXYZ(10.0f, 3.0f, 0.0f); //모델 좌표이동
	renderer->addObject(sphere);

	Obj* human = new Obj();

	filemgr->loadObj(
		human,
		"human_2.obj",
		"star.bmp",
		"20161677_황현욱_vs.shader",
		"20161677_황현욱_fs.shader"
	);
	
	human->setXYZ(10.0f, 1.0f, 0.0f);
	renderer->addObject(human);


	NonRenderingObject *non_render_obj = new NonRenderingObject();


	while (true)
		{	
		renderer->renderup();
		renderer->draw();
		renderer->Update(non_render_obj);
		renderer->renderdown();
		
		}
		
	renderer->shutDown();
	
	delete sphere;
	delete cube;
	delete human;
	return 0;
}
