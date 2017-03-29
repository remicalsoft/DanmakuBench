#pragma once

#include "Scene.h"
#include <list>
#include "Define.h"
#include "ISceneChangedListener.h"
#include "ScenePrmBase.h"
#include "Bullet.h"
#include "IFpsGettable.h"

class GameScene : public Scene {

	int _font, _img, _color;
	std::list<Bullet*> _list;
	IFpsGettable* _fpsGettable;
	int _bulletN;
	int _counter;
	int _outCounter;

	void increase();
	void registerBullet();
	void judgeGameover();

public:
	GameScene(ISceneChangedListener* impl, ScenePrmBase* prm, IFpsGettable *fpsGettable);
	~GameScene();
	bool update() ;
	void draw() ;
};

