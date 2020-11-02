#include "Time.h"
#include <iostream>

Time* Time::instance = 0;


Time::Time()
{
	frame = 60;
	count = 0;

	QueryPerformanceFrequency(&_frameInfo);
	QueryPerformanceCounter(&_prevFrameCounter);

	
	_perFrame = _frameInfo.QuadPart / 60; //60프레임 고정
}


bool Time::IsFixedRendering()
{
	QueryPerformanceCounter(&_nowFrameCounter);

	double time_distance = _nowFrameCounter.QuadPart - _prevFrameCounter.QuadPart;

	if (time_distance > _perFrame)
	{
		_prevFrameCounter = _nowFrameCounter;

		count++;
		if (frame == count)
		{
			std::cout << "1AE" << std::endl;
			count = 0;
		}
		return true;
	}

	std::cout << "Dis" << time_distance << "FPS" << 1 / (time_distance / (double)_frameInfo.QuadPart) << std::endl;
	return false;
}