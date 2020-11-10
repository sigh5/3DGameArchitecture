#include "SampleNonRenderingObj.h"
#include <iostream>

void SampleNonRenderingObj::init()
{
	std::cout << "non init" << std::endl;
}

void SampleNonRenderingObj::render()
{

}

void SampleNonRenderingObj::Update()
{
	std::cout << "non update" << std::endl;
}

void SampleNonRenderingObj::shutDown()
{
	std::cout << "non shutdown" << std::endl;
}

void SampleNonRenderingObj::setXYZ(float x, float y, float z)
{

}