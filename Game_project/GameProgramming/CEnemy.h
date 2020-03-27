#ifndef CENEMY_H
#define CENEMY_H
//四角形クラスのインクルード
#include"CRectangle.h"
//タスククラスのインクルード
#include"CTask.h"
//バーンのクラスのインクルード
#include"CBurn.h"
/*
エネミークラス
敵の基本的な機能を定義する
*/


class CEnemy : public CRectangle {
public:
	//状態の種類
	enum EStatus{
		EIDLE,   //待機状態
		EMOVE,   //移動状態
		EBOSSMOVE,  //ボス移動状態
		EBURNATTACK, //火の玉攻撃状態
		EDAMAGE, //被弾状態
		EDEATH,  //消滅状態
		EJUNP,   //ジャンプ状態
		EBIND,   //拘束攻撃状態、猫
		EPLAYINGDEAD,  //死んだふり状態、マリオネット
		EMEEXPLOSION,  //自爆状態、ねこうもり
		EDUMMY,  //プレイヤーの見た目になる、かかし
		ESHADOWMIST,   //霧、影から出てくる、森のボス
		EVENOM,  //毒を飛ばす、うさぎさん
		EBOSSDEATHBLOW,//超範囲攻撃,  火が周りに飛び散る、ラスボス
	};
	EStatus mStatus;

	int mFx; //X軸方向の移動 -1:左 0:移動しない 1:右へ移動
	int mFy; //Y軸方向の移動 -1:下 0:移動しない 1:上へ移動
	int mFireCount; //火の玉発射間隔
	int mHitPoint; //体力
	int mSlowMove; //移動量低
	int mMove;     //移動量並
	int mQuickMove; //移動量高
	int mDamage;  //被ダメージ
	int mUltDamagePlus; //必殺技係数
	int mBurnSpeed; //火の玉速度
	int mBurnSpeedB; //火の玉速度

	bool mSearch; //サーチ
	bool mEnabled; //生き死に

	CEnemy(int Priority);

	void Update();
	bool Collision(const CRectangle &r);
	void Render();

	//自分と敵の当たり判定
	void Collision(CRectangle *i, CRectangle *y);
	void Collision(CTask*task);
};
#endif