#include "Bullet.h"
#include "Utils.h"
#include "Define.h"
#include <math.h>

static const int W = 16;//弾画像のサイズ
static const int H = 16;

Bullet::Bullet(int img) {
	_img = img;					//弾画像ハンドル
	_x = WINDOW_W / 2;			//弾の初期位置
	_y = WINDOW_H / 2;			//弾の初期位置
	_speed = 5+Utils::randf(3);	//5±3のスピード値に設定
	_angle = Utils::randf(PI);	//360°ばらつかせる
}

bool Bullet::update() {
	_x += cos(_angle)*_speed;	//弾を移動させる
	_y += sin(_angle)*_speed;
	//画面外に出たら消す
	if (isOutside()) {
		return false;
	}
	return true;
}

void Bullet::draw() {
	DrawRotaGraphF(_x,_y,1.0,0,_img,TRUE);//弾を描画
}

//弾が画面外に出たか。
//true:外に出た、false:まだ内側
bool Bullet::isOutside() {
	return _x < -W / 2 || WINDOW_W + W / 2 < _x || _y < -H / 2 || WINDOW_H + H / 2 < _y;
}