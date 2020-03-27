#ifndef CPLAYER_H
#define CPLAYER_H

#include"CRectangle.h"
#include"Cvector.h"
#include "CScene.h"



class CPlayer:public CRectangle{
public:

	enum EState{
		
		
		EMOVE,//移動
		EIDLE,//待機
		ESTRIKE,//攻撃
		EJUMP,//ジャンプ
		EULT,//必殺技
		EDEATH//死ね

	};
	EState mState;

	enum EMode{
		ENORMAL,//通常状態
		ESTRONG,//攻撃状態
		EHEAL,//回復状態
		
	};
	EMode mMode;
	static CPlayer*mpPlayer;
	static CTexture mcharaatk;
	static CTexture mcharahear;
	static CTexture mcharanormal;
	static CTexture mModeAttack;
	static CTexture mModeHeal;
	static CTexture mModeNormal;

	CRectangle mRectMode;
	
	CPlayer(int Priority);
	int mACount;//アニメーションのカウント
	int mACountA;//アニメーションのカウントの攻撃
	int mACountD;//アニメーションのカウントの死
	int mACountU;//アニメーションのカウントの必殺技
	int mPhp;//プレイヤーのHP
	int mPHPM;//プレイヤーのさいだいHP
	int mSpecialGauge;//必殺技のゲージ
	int mSpecialGaugeMax;//必殺技のゲージ最大値
	int mDamage;//ダメージ
	int mHealNumber;//回復値
	int mmove;   //移動量
	int mSpeed;  //速度
	int mAttackCount;//攻撃のカウント
	int mHealCount;  //回復のカウント
	int mCount;//カウント
	float my_prev;//前のy
	bool jflag = false; //ジャンプフラグ
	bool aflag = false;//攻撃フラグ
	bool mflag = true;//動フラグ
	bool uflag = false;//必殺技フラグ
	int mJumpPower; //ジャンプパワー
    float mFPS ;  //1フレーム
	float mGRAVITY; //重力
	
	int mFx, mFy;//向き

	
	float mDistantTime;
	void Update();

	void Render();

	void Collision(CTask*task);//当たり判定

	
};
#endif