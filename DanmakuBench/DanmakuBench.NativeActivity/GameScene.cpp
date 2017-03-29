#include "DxLib.h"
#include "GameScene.h"
#include "eScene.h"
#include "ScorePrm.h"

using namespace std;

GameScene::GameScene(ISceneChangedListener* impl, ScenePrmBase* prm, IFpsGettable* fpsGettable) : Scene(impl)
{
	_font = CreateFontToHandle(FONT_NAME, 45, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	_img = LoadGraph("bullet01.png");
	_color = GetColor(255, 255, 255);
	_fpsGettable = fpsGettable;
	_bulletN = 2;
	_counter = 0;
	_outCounter = 0;
}

GameScene::~GameScene()
{
	DeleteFontToHandle(_font);
	DeleteGraph(_img);
}

bool GameScene::update() 
{
	_counter++;

	increase();
	registerBullet();

	for (std::list<Bullet*>::iterator i = _list.begin(); i != _list.end(); ) {
		if ((*i)->update()) {
			i++;
		} else {
			delete *(i);
			i = _list.erase(i);
		}

	}
	
	judgeGameover();

	return true;
}

void GameScene::draw()
{
	for (std::list<Bullet*>::iterator i = _list.begin(); i != _list.end(); i++) {
		(*i)->draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (_counter * 4) % 256);	//点滅処理
	DrawFormatStringToHandle(10, WINDOW_H - 120, _color, _font, "計測中");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);							//点滅処理中止
	DrawFormatStringToHandle(10, WINDOW_H-60, _color, _font, "スコア = %d", _list.size());
}

void GameScene::increase()
{
	if (_counter % 30 == 0) {//0.5秒に一度、弾の同時発射数を増やす
		_bulletN++;
	}
}

void GameScene::registerBullet()
{
	for (int i = 0; i < _bulletN; i++) {
		_list.push_back(new Bullet(_img));
	}
}

void GameScene::judgeGameover()
{
	if (_counter>180 && _fpsGettable->getFps()<50) {
		_outCounter++;
	}
	if (_outCounter > 130) {
		ScorePrm *prm = new ScorePrm(_list.size());
		_implSceneChanged->onSceneChanged(END, false, prm);
		delete prm;
	}
}
