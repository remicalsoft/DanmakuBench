#pragma once

//GameSceneからFPSを取得可能にする
class IFpsGettable {
public:
	virtual float getFps() = 0;
};