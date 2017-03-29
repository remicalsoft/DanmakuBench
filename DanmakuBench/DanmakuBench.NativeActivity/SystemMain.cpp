#include <DxLib.h>
#include "SystemMain.h"
#include "Define.h"
#include "Looper.h"
#include <string>

using namespace std;

SystemMain::SystemMain() : _isErr(false)
{
	SetGraphMode(WINDOW_W, WINDOW_H, COLOR_BIT);	//�𑜓x�̐ݒ�
	if (DxLib_Init()) {
		_isErr = true;
		return;
	}
	SetDrawScreen(DX_SCREEN_BACK);			//����ʏ����̐ݒ�
	SetDrawMode(DX_DRAWMODE_BILINEAR);		//�o�C���j�A���`��ԕ\���̐ݒ�
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