#ifndef CSCENETITLE_H
#define CSCENETITLE_H
#include "CScene.h"
#include "CKey.h"
#include <Windows.h>
#include "CRectangle.h"

#include "CHPBar.h"
/*
ゲームのシーン
*/
class CSceneTitle : public CScene{
public:
	//画面投影範囲の変数
	int mLeft, mRight, mBottom, mTop;

	//タイトル画面の背景
	static CTexture mTitleBackGround;
	//タイトル画面のロゴ
	static CTexture mTitleLogo;
	//タイトル画面のスタートボタン
	static CTexture mTitleStartButton;
	//タイトル画面の操作説明ボタン
	static CTexture mTitleInstButton;
	//タイトル画面のカーソル
	static CTexture mTitleCarsol;
	//タイトル画面の操作説明画面
	static CTexture mJunbi;

	
	//次のシーンの取得
	EScene GetNextScene();

	CRectangle mRectTBG;//背景
	CRectangle mRectTL; //タイトルロゴ
	CRectangle mRectTSB;//Startボタン
	CRectangle mRectTIB;//操作説明ボタン
	CRectangle mRectTC; //カーソル

	//カーソルの目的地(Y座標)
	int mGetYforTC;
	//カーソルが移動中のみ有効になる
	bool mIsMoveCarsol;

	//カーソルのちょっとした動きの変化量
	float mArrowLittleMove;
	//ちょっとした動きの上昇・下降のフラグ
	bool mArrowUpFlag;
	bool mArrowDownFlag;
	//ちょっとした動きの頂点に留っている時間
	int mArrowLittleMoveWaitTime;

	//画面暗転用
	CRectangle mFadeOut;
	//暗転させる程度を決める変数
	float mFadeValue;

	//説明画面の描画用
	CRectangle mSetsumeiScreen;

	//タイトル画面のカーソルの位置に関する変数
	int mCarsol;
	//操作説明画面が開いているかどうかを決める変数
	bool mSetsumei;
	//初回かどうか判定する変数
	static bool mIsFirst;
	//スタートボタンを押すと有効になる
	bool mStartFlag;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//描画処理のオーバーライド
	void Render();
};

#endif
