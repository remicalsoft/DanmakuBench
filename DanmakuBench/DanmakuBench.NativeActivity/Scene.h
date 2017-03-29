#pragma once
#include "Task.h"
#include "ISceneChangedListener.h"
#include "eScene.h"

class Scene : public Task
{
protected:
	ISceneChangedListener* _implSceneChanged;
public:
	Scene(ISceneChangedListener *impl) {
		_implSceneChanged = impl;
	}
	virtual ~Scene() {}
};

