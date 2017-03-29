#pragma once

#include "Scene.h"
#include "ISceneChangedListener.h"
#include "ScenePrmBase.h"

class ErrorScene : public Scene {

	int _font;

public:
	ErrorScene(ISceneChangedListener* impl, ScenePrmBase* prm);
	~ErrorScene();
	bool update();
	void draw();

};

