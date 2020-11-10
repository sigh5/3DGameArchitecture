#include "NonRenderingObject.h"
#include "Renderer.h"

NonRenderingObject::NonRenderingObject()
{
	Renderer *renderer = Renderer::instance();
	renderer->addNonRenderObject(this);
}

void NonRenderingObject::init()
{

}

void NonRenderingObject::render()
{

}

void NonRenderingObject::Update()
{

}

void NonRenderingObject::shutDown()
{

}

void NonRenderingObject::setXYZ(float x, float y, float z)
{

}