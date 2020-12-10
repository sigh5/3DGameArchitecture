#pragma once

#include "Object.h"
#include <vector>
#include "FileManager.h"

using namespace std;

class CompositeObj :public Object
{
public:
	CompositeObj();
	~CompositeObj();
	virtual void init() override {};
	virtual void render() override {};
	virtual void Update() override {};
	virtual void shutDown() override {};

	//∫ª¿Œ∞≈
	virtual void add(Object* addObj);
	
	//Object≤® 
	virtual void RotMatrix(glm::mat4 _rot)  override;
	virtual void PosMatrix(glm::mat4 _pos)  override;
	virtual void ScaleMatrix(glm::mat4 _scale) override;


protected:
	vector<Object*>* _Table;
	glm::mat4 CompositRot;
	glm::mat4 ComPositPos;
	glm::mat4 ComPositScale;
};