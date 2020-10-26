#pragma once
#include "FileManager.h"

class InputKey
{
private:
	static InputKey* instance;
	
public:

	static InputKey* GetInstance()
	{
		if (instance == 0)
		{
			instance = new InputKey();
		}

		return instance;
	};
public:
	void KeyBoard();
	glm::mat4 getViewMatrix() {
		return ViewMatrix;
	}
	glm::mat4 getProjectionMatrix() {
		return ProjectionMatrix;
	}

	void setMousepos();
	void getExitKey();


public:
     glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;
	glm::vec3 position = glm::vec3(0, 0, 5);
	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	float initialFoV = 45.0f;
	float speed = 3.0f; // 3 units / second
	float mouseSpeed = 0.005f;
};

