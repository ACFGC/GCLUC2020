#ifndef CSLIMEENEMY_H
#define CSLIMEENEMY_H
//敵基本クラスのインクルード
#include"CEnemy.h"
//四角形クラスのインクルード
//#include"CRectangle.h"
/*
スライムエネミークラス
スライムの機能を定義する
*/

class CSlimeEnemy : public CEnemy {
public:
	//状態の種類
	enum EStatus{
		EIDLE,   //待機状態
		EMOVE,   //移動状態
		EBURNATTACK, //火の玉攻撃状態
		EDAMAGE, //被弾状態
		EDEATH,  //消滅状態
	};
	static CSlimeEnemy*mpSlimeEnemy;

	EStatus mStatus;
	CTexture mSlime;

	int mFx; //X軸方向の移動 -1:左 0:移動しない 1:右へ移動
	int mFy; //Y軸方向の移動 -1:下 0:移動しない 1:上へ移動
	int mFireCount; //火の玉発射間隔
	int mHitPoint; //体力
	int mSlowMove; //移動量低
	int mMove;     //移動量並
	int mQuickMove; //移動量高
	int mDamage;  //被ダメージ
	int mUltDamagePlus; //必殺技被ダメージ係数

	int mACount;//アニメーションのカウント
	int mACountM;  //アニメーションムーブ
	int mACountB;  //アニメーション火の玉
	int mFps;   //アニメーション持続時間

	bool mSearch; //サーチ
	bool mEnabled; //生き死に

	CSlimeEnemy(int Priority);

	void Update();
	bool Collision(const CRectangle &r);
	void Render();

	//自分と敵の当たり判定
	void Collision(CRectangle *i, CRectangle *y);

	void CSlimeEnemy::Collision(CTask*task);
};
#endif