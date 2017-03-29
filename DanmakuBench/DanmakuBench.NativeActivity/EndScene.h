#pragma once

#include "Scene.h"
#include "ISceneChangedListener.h"
#include "ScenePrmBase.h"

class EndScene : public Scene {

	int _score;
	int _font;

	void callShowDialog();
	bool isClicked(int x, int y);

public:
	EndScene(ISceneChangedListener* impl, ScenePrmBase* prm);
	~EndScene();
	bool update();
	void draw();

};

