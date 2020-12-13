#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"
#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 

#include "ISetPosition.h"
#include "ICleanUp.h"
#include "IUpdate.h"
#include "IInit.h"
#include "IRender.h"
class Object :public ICleanUp, public ISetPosition,public IUpdate,public IInit,public IRender
{
public:

	virtual ~Object() {};
	

};