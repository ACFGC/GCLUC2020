#ifndef CHPBAR_H
#define CHPBAR_H

#include "CRectangle.h"

class CHPBar : public CRectangle{
public:
	//enum EType{
	//	EPLAYERHP,//プレイヤーのHP
	//	EPLAYERSP,//プレイヤーのSP
	//	/*EENEMYHP,
	//	EBOSSHP,*/
	//};
	//EType mType;

	static CHPBar *mpInstance;

	//プレイヤーのHPバー、SPバー
	CTexture mHPBackTexture;
	CTexture mHPFrontTexture;
	/*CTexture mSPBackTexture;
	CTexture mSPFrontTexture;*/
	//ボス敵のHPバー
	CTexture mBossHPBackTexture;
	CTexture mForestBossHPFrontTexture;

	CRectangle mHPBarBack;
	CRectangle mHPBarFront;
	/*CRectangle mSPBarBack;
	CRectangle mSPBarFront;*/
	CRectangle mBossHPBarBack;
	CRectangle mForestBossHPBarFront;

	float mHPPercent;
	int mMaxHP;
	int mHP;

	CHPBar(int Priority);

	void Update();
	void Render();
};

#endif