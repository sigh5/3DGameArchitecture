#include <stdio.h>

#include "Object.h"
#include "Renderer.h"
#include "RenderingObject.h"
#include "Sphere.h"
#include "NonRenderingObject.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "InputKey.h"



void Renderer::addRenderObject(RenderingObject* obj)
{
	renderObjList.push_back(obj);
}

void Renderer::addNonRenderObject(NonRenderingObject* obj)
{
	nonrenderObjList.push_back(obj);
}


int Renderer::init()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "1", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true;

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);



	// depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	for (std::vector<RenderingObject*>::iterator it = renderObjList.begin(); it != renderObjList.end(); it++)
	{
		(*it)->init();
	}

	for (std::vector<NonRenderingObject*>::iterator it = nonrenderObjList.begin(); it != nonrenderObjList.end(); it++)
	{
		(*it)->init();
	}

}

void Renderer::setXYZ(float x, float y, float z)
{
	
}



void Renderer::Update()
{
	for (std::vector<RenderingObject*>::iterator it = renderObjList.begin(); it != renderObjList.end(); it++)
	{
		(*it)->Update();
	}

	for (std::vector<NonRenderingObject*>::iterator it = nonrenderObjList.begin(); it != nonrenderObjList.end(); it++)
	{
		(*it)->Update();
	}
}



void Renderer::render()
{
	for (std::vector<RenderingObject*>::iterator it = renderObjList.begin(); it != renderObjList.end(); it++)
	{
		(*it)->render();
	}

	for (std::vector<NonRenderingObject*>::iterator it = nonrenderObjList.begin(); it != nonrenderObjList.end(); it++)
	{
		(*it)->render();
	}
	
}

void Renderer::shutDown()
{
	for (std::vector<RenderingObject*>::iterator it = renderObjList.begin(); it != renderObjList.end(); it++)
	{
		(*it)->shutDown();
	}

	for (std::vector<NonRenderingObject*>::iterator it = nonrenderObjList.begin(); it != nonrenderObjList.end(); it++)
	{
		(*it)->shutDown();
	}
	
	glfwTerminate();
}

void Renderer::renderup()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::renderdown()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

