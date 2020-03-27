#ifndef CSCENEOPENING_H
#define CSCENEOPENING_H
#include "CScene.h"
#include "CKey.h"
#include <Windows.h>
#include "CRectangle.h"
/*
ゲームのシーン
*/
class CSceneOpening : public CScene{
public:
	//OP画面の背景
	CTexture mOPBackGround;
	//OPのストーリー
	CTexture mOPStory1;
	CTexture mOPStory2;
	CTexture mOPStory3;
	CTexture mOPStory4;
	CTexture mOPStory5;

	//画面暗転用
	CRectangle mRectFade;
	//画面を暗転させる程度を決める変数
	float mScreenFadeValue;
	//画面のフェードイン・アウト用のフラグ
	bool mScreenFadeIn;
	bool mScreenFadeOut;

	//字幕の透明度を決める変数
	float mStoryFadeValue;
	//字幕のフェードイン・アウト用のフラグ
	bool mStoryFadeIn;
	bool mStoryFadeOut;
	//字幕をプレイヤーに読ませる時間
	int mStoryReadTime;
	//字幕が完全に表示中だけ有効になるフラグ
	bool mStoryShowing;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//次のシーンの取得
	EScene GetNextScene();

	//OP画面の背景
	CRectangle mRecOPBackGround;
	//OP画面の字幕
	CRectangle mRecOPStory;


	//現在のページ
	int mCurrentPage;
	//次のページに行くまでの時間
	int mTimeCount;

};

#endif
