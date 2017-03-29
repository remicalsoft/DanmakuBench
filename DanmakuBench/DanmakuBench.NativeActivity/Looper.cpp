#include "Looper.h"
#include "Define.h"
#include "GameScene.h"
#include "ScenePrmBase.h"
#include "EndScene.h"
#include "ErrorScene.h"
#include "ErrorScene.h"
#include <DxLib.h>
#include "Utils.h"

using namespace std;

Looper::Looper()
{
	if (Utils::isAvailableDevide()) {	//対応端末かどうか確認
		_scene.push_back(new GameScene(this, 0, (IFpsGettable*)&_fps));
	}
	else {
		_scene.push_back(new ErrorScene(this, 0));
	}
	_scene.back()->initialize();
}

Looper::~Looper()
{
}

/*!
	@brief シーンのチェンジ
	@note 各シーンクラスからコールバックされる
	@retval stack : trueならシーンをスタックする(トップメニュー画面→のように)
	@retval stack : falseならスタックをクリアする(ゲーム画面のように下のレイヤーにシーンが無い場合)
*/
void Looper::onSceneChanged(eScene scene, bool stack, ScenePrmBase* prm){
	if (!stack) {
		for (std::list<Scene*>::iterator itr = _scene.begin(); itr != _scene.end(); itr++) {
			delete *(itr);
		}
		_scene.clear();
	}
	switch(scene){
	case GAME:
		_scene.push_back(new GameScene(this, prm, (IFpsGettable*)&_fps));
		break;
	case END:
		_scene.push_back(new EndScene(this, prm));
		break;
	case ERROR:
		_scene.push_back(new ErrorScene(this, prm));
		break;
	}
	if (_scene.back()!=0) {
		_scene.back()->initialize();
	}
}

bool Looper::main() {
	_scene.back()->update();
	if (_scene.size() == 0) {	//シーンが無くなったらアプリ終了
		return false;			//falseを返すとシステムマネージャーが終了する
	}
	_scene.back()->draw();
	_fps.draw();
	_fps.wait();
	return true;
}
