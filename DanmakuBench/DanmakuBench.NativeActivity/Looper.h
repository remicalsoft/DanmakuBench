#pragma once
#include "Define.h"
#include "Scene.h"
#include "Fps.h"
#include "ISceneChangedListener.h"
#include <list>
#include <memory>

class Looper : public ISceneChangedListener{
	std::list<Scene*> _scene;
	Fps _fps;

public:
	Looper();
	~Looper();
	void onSceneChanged(eScene,bool,ScenePrmBase*) ;
	bool main();
};

