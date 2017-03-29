#pragma once
#include "eScene.h"
#include "Scene.h"
#include "ScenePrmBase.h"

class ISceneChangedListener
{
public:
	ISceneChangedListener() {}
	virtual ~ISceneChangedListener() {}
	virtual void onSceneChanged(eScene scene, bool stack, ScenePrmBase* prm) {}
};

