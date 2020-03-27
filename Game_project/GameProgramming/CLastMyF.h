#ifndef CLASTMYF_H
#define CLASTMYF_H
//敵基本クラスのインクルード
#include"CEnemy.h"
//四角形クラスのインクルード
#include"CRectangle.h"
#include"CBossDeathBlow.h" //ボス必殺インクルード
/*
ラスボスクラス
ラスボスの機能を定義する
*/

class CLastMyF : public CEnemy {
public:
	//状態の種類
	enum EStatus{
		EIDLE,   //待機状態
		EBURNATTACK, //火の玉攻撃状態
		EDEATH,  //消滅状態
		EBOSSDEATHBLOW,//超範囲攻撃,  火が周りに飛び散る、ラスボス
	};
	EStatus mStatus;
	CTexture mLastBossIdle;
	CTexture mLastBossMove;
	CTexture mLastBossBurnAttack;
	CTexture mLastBossDeathBlow;
	CTexture mLastBossDeath;

	int mFx; //X軸方向の移動 -1:左 0:移動しない 1:右へ移動
	int mFy; //Y軸方向の移動 -1:下 0:移動しない 1:上へ移動
	int mFireCount; //火の玉発射間隔
	int mDeathBlow; //必殺技発射間隔
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
	int mACountK;  //アニメーション必殺
	int mFps;   //アニメーション持続時間

	bool mSearch; //サーチ
	bool mEnabled; //生き死に


	CLastMyF(int Priority);

	void Update();

	void Render();

	//自分と敵の当たり判定
	void Collision(CTask*task);
};
#endif