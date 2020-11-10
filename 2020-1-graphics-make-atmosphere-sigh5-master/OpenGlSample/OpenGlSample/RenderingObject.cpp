#include "RenderingObject.h"
#include "Renderer.h"

RenderingObject::RenderingObject()
{
	Renderer *renderer = Renderer::instance();
	renderer->addRenderObject(this);
	
}

