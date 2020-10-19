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
	
	renderer->setXYZ(20.0f,2.0f,7.0f); //camera ���� �̵�
	
	Obj*cube = new Obj();
	
	filemgr->loadObj(
	cube,
	"cube.obj",
	"star.bmp",
	"20161677_Ȳ����_vs.shader",
	"20161677_Ȳ����_fs.shader"
);

	cube->setXYZ(10.0f,5.0f,0.0f); //���� ��ġ�̵�
	renderer->addObject(cube);
	
	Sphere *sphere = new Sphere();
	sphere->setXYZ(0.0f, 2.0f, 1.0f); //�� ��ǥ�̵�
	renderer->addObject(sphere);

	NonRenderingObject *non_render_obj = new NonRenderingObject();
		


	while (true)
		{	
		renderer->renderup();
		renderer->draw();
		renderer->Update(non_render_obj);
		renderer->renderdown();

		}
		


	cube->shutDown();
	sphere->shutDown();
	
	renderer->shutDown();
	


	delete sphere;
	delete cube;
	return 0;
}