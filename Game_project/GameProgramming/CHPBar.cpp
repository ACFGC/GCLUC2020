#include "CHPBar.h"
#include "CTexture.h"
#include"CRectangle.h"
#include "CSceneGame.h"
#include "CPlayer.h"
#include "CKey.h"

CHPBar *CHPBar::mpInstance = 0;
CHPBar::CHPBar(int Priority)
:CRectangle(Priority), mHP(3)
{
	//1280x720
	mpInstance = this;

	w = 256, h = 64;

	mHPBarBack.w = 256, mHPBarBack.h = 64;
	mHPBarFront.w = 256, mHPBarFront.h = 64;
	/*mSPBarBack.w = 256, mSPBarBack.h = 32;
	mSPBarFront.w = 212, mSPBarFront.h = 32;*/

	mBossHPBarBack.w = mForestBossHPBarFront.w = 410;
	mBossHPBarBack.h = mForestBossHPBarFront.h = 20;

	mHPBackTexture.Load("image\\UI\\player_HP\\player_HP_01.tga");
	mHPFrontTexture.Load("image\\UI\\player_HP\\player_HP_02.tga");
	/*mSPBackTexture.Load("image\\UI\\•KŽE‹ZƒQ[ƒW\\specialskill_01.tga");
	mSPFrontTexture.Load("image\\UI\\•KŽE‹ZƒQ[ƒW\\specialskill_02.tga");*/
	mBossHPBackTexture.Load("image\\ŽG‹›Aƒ{ƒX‚Ì‘Ì—ÍƒQ[ƒW\\boss_HP_01.tga");
	mForestBossHPFrontTexture.Load("image\\ŽG‹›Aƒ{ƒX‚Ì‘Ì—ÍƒQ[ƒW\\boss_forest_HP_01.tga");

	mHP = CPlayer::mpPlayer->mPhp;
	mMaxHP = CPlayer::mpPlayer->mPHPM;
	/*mSP = CPlayer::mpPlayer->mSpecialGauge;
	mMaxSP = CPlayer::mpPlayer->mSpecialGaugeMax;*/
}

void CHPBar::Update(){
	mHPBarFront.w = 220 * mHP / mMaxHP;
	/*mSPBarFront.w = 212 * CPlayer::mpPlayer->mSpecialGauge / CPlayer::mpPlayer->mSpecialGaugeMax;*/
	/*mSPBarFront.w = 212 * mSP / mMaxSP;)*/

	mHPBarBack.x = x + 123;
	mHPBarFront.x = x - 95 + mHPBarFront.w;
	mHPBarBack.y = mHPBarFront.y = y;
	/*mSPBarBack.x = x + 115;
	mSPBarFront.x = mSPBarBack.x - 214 + mSPBarFront.w;
	mSPBarBack.y = mSPBarFront.y = y - 60;*/

	mBossHPBarBack.x = x + 340;
	mBossHPBarBack.y = mForestBossHPBarFront.y = y - 600;
	mForestBossHPBarFront.x = x + 340;
	mForestBossHPBarFront.w = 408;

	if (CKey::Once('X')){
		if (CPlayer::mpPlayer->mSpecialGauge >= CPlayer::mpPlayer->mSpecialGaugeMax){
			CPlayer::mpPlayer->mSpecialGauge -= CPlayer::mpPlayer->mSpecialGaugeMax;
		}		
	}
	
	x = CScene::mpInstance->mLeft + 300;
	y = CScene::mpInstance->mBottom + 660;
	

	if (mHP > 0){
		mHP = CPlayer::mpPlayer->mPhp;
	}
	else if(mHP < 0){
		mHP = 0;
	}	
	/*if (CPlayer::mpPlayer->mSpecialGauge < mMaxSP){
		mSP++;
	}*/
}

void CHPBar::Render(){
	mHPBarBack.Render(mHPBackTexture, 0, 512, 128, 0);
	mHPBarFront.Render(mHPFrontTexture, 43, 469, 128, 0);
	/*mSPBarBack.Render(mSPBackTexture, 0, 512, 64, 0);
	mSPBarFront.Render(mSPFrontTexture, 46, 464, 64, 0);*/

	mBossHPBarBack.Render(mBossHPBackTexture, 4, 404, 30, 0);
	mForestBossHPBarFront.Render(mForestBossHPFrontTexture, 16, 394, 20, 0);

	/*if (mType == EPLAYERHP){
		mHPBack.Render(mHPBackGauge, 0, 512, 128, 0);
		mHPFront.Render(mHPBackGauge, 0, 512, 128, 0);
	}
	else if (mType == EPLAYERSP){
		mSPBack.Render(mSPBackGauge, 0, 512, 64, 0);
		mSPFront.Render(mSPBackGauge, 0, 512, 64, 0);
	}*/
}