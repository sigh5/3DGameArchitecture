#pragma once
#include <vector>

#include "glm/glm.hpp"
#include "include/GL/glew.h"

#include "ICleanUp.h"
#include "ISetPosition.h"


class Object :public ICleanUp, public ISetPosition
{
public:

	virtual ~Object(){ }
};