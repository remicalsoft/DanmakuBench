#include "Scene.h"

Scene::Scene(ISceneChangedListener* impl)
{
	_implSceneChanged = impl;
}

Scene::~Scene()
{
}
