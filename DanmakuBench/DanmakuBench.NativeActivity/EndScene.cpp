#include "EndScene.h"
#include "DxLib.h"
#include "ScorePrm.h"
#include "Define.h"

//ボタンのX,Y,W,H
const static int X = WINDOW_W / 2 - 300;
const static int Y = WINDOW_H - 300;
const static int W = 600;
const static int H = 200;

EndScene::EndScene(ISceneChangedListener* impl, ScenePrmBase* prm) : Scene(impl)
{
	ScorePrm *scorePrm = (ScorePrm*)prm;	//GameSceneから渡されたパラメータ。スコアが入っている
	_score = scorePrm->getScore();
	_font = CreateFontToHandle(FONT_NAME, 80, 3, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
}

EndScene::~EndScene()
{
	DeleteFontToHandle(_font);
}

bool EndScene::update() 
{
	//タッチ情報を計算
	for (int i = 0; i < GetTouchInputNum(); i++){//タッチしている指の数だけループ
		int x, y;
		GetTouchInput(i, &x, &y, NULL, NULL);
		if (isClicked(x, y)) {
			_implSceneChanged->onSceneChanged(GAME, false, 0);
		}
	}
	return true;
}

void EndScene::draw() 
{
	DrawFormatStringToHandle(10,  10, GetColor(255, 255, 255), _font, "あなたのスコア");
	DrawFormatStringToHandle(20, 120, GetColor(255, 255, 255), _font, "%d", _score);

	DrawBox(X,Y,X+W,Y+H, GetColor(169, 169, 169), TRUE);			//ボタン四角形の塗りつぶし
	DrawBox(X, Y, X + W, Y + H, GetColor(255, 255, 255), FALSE);	//ボタン四角形の輪郭
	DrawFormatStringToHandle(WINDOW_W/2-170,WINDOW_H-260,GetColor(0,0,0), _font, "もう一度");
}

//ボタンを押したか？
bool EndScene::isClicked(int x, int y) 
{
	return X < x && Y < y && x < X + W && y < Y + H;
}

//うまく機能しないのでコメントアウト。結果を掲示板に投稿する処理
void EndScene::callShowDialog() {
	/*
	JNIEnv *env;
	const ANativeActivity *NativeActivity;
	NativeActivity = GetNativeActivity();
	{
		// JavaVM とソフト実行用スレッドを関連付け( C++ から Java の機能を使用するために必要 )
		if (NativeActivity->vm->AttachCurrentThreadAsDaemon(&env, NULL) != JNI_OK)
		{
			return;
		}
		// Java のクラス (プロジェクト名) を取得
		jclass jclass_DanmakuBench = env->GetObjectClass(NativeActivity->clazz);
		// Java のクラス (プロジェクト名) のメンバー関数 StartInputStringDialog の ID を取得
		jmethodID jmethodID_showScoreDialog = env->GetMethodID(jclass_DanmakuBench, "showScoreDialog", "()V");
		// Java のクラス (プロジェクト名) のメンバー関数 StartInputStringDialog の呼び出し
		env->CallVoidMethod(NativeActivity->clazz, jmethodID_showScoreDialog);
		// Java のクラス (プロジェクト名) の参照を削除
		env->DeleteLocalRef(jclass_DanmakuBench);
		// JavaVM とソフト実行用スレッドの関連付け終了
		NativeActivity->vm->DetachCurrentThread();
	}
	*/
}
