#ifndef CBURN_H
#define CBURN_H

#include "CRectangle.h"

/*
CBurn
火の玉クラス
CRectangleクラスを継承する
親：CRectangleクラス
子：CBurnクラス
*/
class CBurn : public CRectangle {
public:
	int mFx, mFy;	//移動量
	int mFireCount; //持続時間
	int mACount;   //アニメーション
	int mFps;

static	CTexture mBurnTexture;
	//デフォルトコンストラクタ
	CBurn(int Priority);
	//更新処理
	void Update();

	//描画処理
	void Render();

	//36
	//void Collision(CRectangle *i, CRectangle *y);
	void Collision(CTask*task);//当たり判定
};

#endif