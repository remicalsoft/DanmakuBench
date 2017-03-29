#include <DxLib.h>
#include "SystemMain.h"
#include "Define.h"
#include "Looper.h"
#include <string>

using namespace std;

SystemMain::SystemMain() : _isErr(false)
{
	SetGraphMode(WINDOW_W, WINDOW_H, COLOR_BIT);	//解像度の設定
	if (DxLib_Init()) {
		_isErr = true;
		return;
	}
	SetDrawScreen(DX_SCREEN_BACK);			//裏画面処理の設定
	SetDrawMode(DX_DRAWMODE_BILINEAR);		//バイリニア線形補間表示の設定
}

SystemMain::~SystemMain()
{
	DxLib_End();
}

void SystemMain::main() {
	if (_isErr) {
		return;
	}
	Looper *looper = new Looper();
	while (!ScreenFlip()&&!ProcessMessage()&&!ClearDrawScreen()) {
		if (!looper->main()) {
			break;
		}
	}
	delete looper;
}