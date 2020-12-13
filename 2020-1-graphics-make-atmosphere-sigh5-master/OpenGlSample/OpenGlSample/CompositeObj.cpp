#include "CompositeObj.h"
#include <iostream>

CompositeObj::CompositeObj()
{
	composite = new vector<CompositeObj*>();
	Parent = nullptr;
}

CompositeObj::~CompositeObj()
{
	for (
		vector<CompositeObj*>::const_iterator it = composite->begin();
		it != composite->end();
		++it
		)
	{
		delete (*it);
	}

	composite->clear();

	delete composite;
}


void CompositeObj::addComposite(CompositeObj* addObj)
{
	composite->push_back(addObj);

	addObj->Parent = this;
}

void CompositeObj::Update()
{
	if (Parent)
	{
		WorldTransform = Parent->WorldTransform * Transform;
	}
	else
	{
		WorldTransform = Transform;
	}
}
