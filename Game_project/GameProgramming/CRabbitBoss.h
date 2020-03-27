#ifndef CRABBITBOSS_H
#define CRABBITBOSS_H
//敵基本クラスのインクルード
#include"CEnemy.h"
//四角形クラスのインクルード
#include"CRectangle.h"
/*
兎ボスクラス
兎ボスの機能を定義する
*/

class CRabbitBoss : public CEnemy {
public:
	//状態の種類
	enum EStatus{
		EIDLE,   //待機状態
		EMOVE,   //移動状態
		EBURNATTACK, //火の玉攻撃状態
		EDEATH,  //消滅状態
		EVENOM,  //毒を飛ばす、うさぎさん
	};
	EStatus mStatus;
	CTexture mRabbitIdle;
	CTexture mRabbitMove;
	CTexture mRabbitBurnAttack;
	CTexture mRabbitVenom;
	CTexture mRabbitDeath;

	int mFx; //X軸方向の移動 -1:左 0:移動しない 1:右へ移動
	int mFy; //Y軸方向の移動 -1:下 0:移動しない 1:上へ移動
	int mFireCount; //火の玉発射間隔
	int mHitPoint; //体力
	int mSlowMove; //移動量低
	int mMove;     //移動量並
	int mQuickMove; //移動量高
	int mDamage;  //被ダメージ
	int mUltDamagePlus; //必殺技被ダメージ係数
	int mACount;  //アニメーション待機
	int mACountM;  //アニメーションムーブ
	int mACountB;  //アニメーション火の玉
	int mACountD;  //アニメーション死
	int mACountV;  //アニメーション毒攻撃
	int mFps;   //アニメーション持続時間

	bool mSearch; //サーチ
	bool mEnabled; //生き死に


	CRabbitBoss(int Priority);

	void Update();

	void Render();

	//自分と敵の当たり判定
	void Collision(CTask*task);
};
#endif