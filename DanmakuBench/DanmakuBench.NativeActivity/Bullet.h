#pragma once

#include "Task.h"

class Bullet : public Task {

	int _img;				//弾画像ハンドル
	float _x, _y;			//弾の座標
	float _speed, _angle;	//速さ、角度

	bool isOutside();	//弾が画面外か？

public:
	Bullet(int img);
	bool update();
	void draw();

};