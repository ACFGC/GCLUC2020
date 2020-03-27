#ifndef CHPBAR_H
#define CHPBAR_H

#include "CRectangle.h"

class CHPBar : public CRectangle{
public:
	//enum EType{
	//	EPLAYERHP,//�v���C���[��HP
	//	EPLAYERSP,//�v���C���[��SP
	//	/*EENEMYHP,
	//	EBOSSHP,*/
	//};
	//EType mType;

	static CHPBar *mpInstance;

	//�v���C���[��HP�o�[�ASP�o�[
	CTexture mHPBackTexture;
	CTexture mHPFrontTexture;
	/*CTexture mSPBackTexture;
	CTexture mSPFrontTexture;*/
	//�{�X�G��HP�o�[
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