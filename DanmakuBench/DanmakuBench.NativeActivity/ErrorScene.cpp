#include "ErrorScene.h"
#include "DxLib.h"
#include "Define.h"

ErrorScene::ErrorScene(ISceneChangedListener* impl, ScenePrmBase* prm) : Scene(impl){
	_font = CreateFontToHandle(FONT_NAME, 20, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
}

ErrorScene::~ErrorScene(){
	DeleteFontToHandle(_font);
}

bool ErrorScene::update() {
	return true;
}

void ErrorScene::draw() {
	DrawFormatStringToHandle(10,  10, GetColor(255, 255, 255), _font, "画面のリフレッシュレートが55以下の端末はサポートしていません");
}
