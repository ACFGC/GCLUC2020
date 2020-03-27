#ifndef CDUMMYENEMY_H
#define CDUMMYENEMY_H
//敵基本クラスのインクルード
#include"CEnemy.h"
//四角形クラスのインクルード
#include"CRectangle.h"
#include"CPlayer.h"
/*
ダミーエネミークラス
ダミーの機能を定義する
*/

class CDummyEnemy : public CEnemy {
public:
	//状態の種類
	enum EStatus{
		EIDLE,   //待機状態
		EBURNATTACK, //火の玉攻撃状態
		EDUMMY,//ダミー攻撃状態
		
	};
	static CDummyEnemy*mpDummyEnemy;

	EStatus mStatus;
	CTexture mDummyIdle;
	CTexture mDummyBurnAttack;
	CTexture mDummyDummy;
	CTexture mDummyPlayer;

	int mFireCount; //火の玉発射間隔
	int mHitPoint; //体力
	int mDamage;  //被ダメージ
	int mUltDamagePlus; //必殺技被ダメージ係数

	int mACount;//アニメーションのカウント
	int mACountB;//アニメーションのカウント火の玉
	int mACountD;//アニメーションのカウントダミー
	int mACountDP;//アニメーションのカウントダミー変身後
	int mFps;   //アニメーション持続時間

	bool mSearch; //サーチ
	bool mEnabled; //生き死に

	CDummyEnemy(int Priority);

	void Update();
	bool Collision(const CRectangle &r);
	void Render();


	void CDummyEnemy::Collision(CTask*task);
};
#endif