#ifndef CBOSSDEATHBLOW_H
#define CBOSSDEATHBLOW_H

#include "CRectangle.h"

/*
必殺技クラス
CRectangleクラスを継承する
親：CRectangleクラス
子：CBossDeathBlowクラス
*/
class CBossDeathBlow : public CRectangle {
public:
	int mFx, mFy;	//移動量
	int mFireCount; //持続時間

	static	CTexture mBossDeathBlow;
	//デフォルトコンストラクタ
	CBossDeathBlow(int Priority);
	//更新処理
	void Update();

	//描画処理
	void Render();

	
	void Collision(CTask*task);//当たり判定
};

#endif