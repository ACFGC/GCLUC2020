#include"CDummyEnemy.h"
#include "CTexture.h"
#include"CRectangle.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
CDummyEnemy *CDummyEnemy::mpDummyEnemy = 0;

CDummyEnemy::CDummyEnemy(int Priority)
:mFireCount(120), mHitPoint(400), mSearch(true), mDamage(300),
mUltDamagePlus(7), CEnemy(Priority), mEnabled(true), mFps(120), mACount(0), mACountB(0), mACountD(0)
{
	mTag = EDUMMYENEMY;
	mStatus = EIDLE;
	mpDummyEnemy = this;
	w = 64;
	h = 64;
	mDummyIdle.Load("image\\enemy\\Last\\Normal enemy_Dummy.tga");
	mDummyBurnAttack.Load("image\\enemy\\Last\\Normal enemy_Dummy.tga");
	mDummyDummy.Load("image\\enemy\\Last\\Normal enemy_Dummy.tga");
	mDummyPlayer.Load("image\\chara\\chara nomal.tga");
}

void CDummyEnemy::Update(){
	CEnemy::Update();
	if (mHitPoint <= 150){
		mStatus = EDUMMY;
	}
	if (mStatus = EDUMMY){
		mFx = 0;
		mFy = 0;
		mTag = EDUMMYPLAYER;
		EBURN == false;
	}
}

void CDummyEnemy::Render() {
	int frame = 0;
	if (mEnabled && mStatus == EIDLE) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 15){
			frame = 1;

		}
		else if (mACount < 30){
			frame = 0;
		}
		else if (mACount < 45){
			frame = 1;
		}
		else if (mACount < 60){
			frame = 2;
		}
		else if (mACount < 45){
			frame = 1;
		}
		else if (mACount < 60){
			frame = 0;
		}
		else if (mACount == 60){
			mACount = 0;
		}
		frame = 128 + frame * 256;
		frame += 134;
		CRectangle::Render(mDummyIdle, frame - 120, frame + 120, 576, 320);
	}

	if (mEnabled && mStatus == EBURNATTACK) {
		if (mACountB < mFps){
			mACountB++;
		}
		if (mACountB < 12){
			frame = 0;

		}
		else if (mACountB < 24){
			frame = 1;
		}
		else if (mACountB < 36){
			frame = 2;
		}
		else if (mACountB < 48){
			frame = 1;
		}
		else if (mACountB < 60){
			frame = 0;
		}
		else if (mACountB == 60){
			mACountB = 0;
		}
		frame = 128 + frame * 256;
		frame += 134;
		CRectangle::Render(mDummyBurnAttack, frame - 120, frame + 120, 980, 724);
	}

	if (mEnabled && mStatus == EDUMMY) {
		if (mACountD < mFps){
			mACountD++;
		}
		if (mACountD < 15){
			frame = 0;

		}
		else if (mACountD < 30){
			frame = 1;
		}
		else if (mACountD < 45){
			frame = 0;
		}
		else if (mACountD < 60){
			frame = 1;
		}
		else if (mACountD < 75){
			frame = 2;
		}
		else if (mACountD < 90){
			frame = 1;
		}
		else if (mACountD < 105){
			frame = 2;
		}
		else if (mACountD >= 105){
			mACountD = 0;
		}
		frame = 128 + frame * 256;
		frame += 1090;
		CRectangle::Render(mDummyDummy, frame - 120, frame + 120, 576, 320);
	}
	
	if (mTag = EDUMMYPLAYER){

		if (mACountDP < mFps){
			mACount++;
		}
		if (mACountDP < 15){
			frame = 0;
		}
		else if (mACountDP < 30){
			frame = 1;
		}
		else if (mACountDP < 45){
			frame = 2;
		}
		else if (mACountDP < 60){
			frame = 3;
		}
		else if (mACountDP == 60){
			mACountDP = 0;
		}
		if (mFx > 0){
			frame = 128 + frame * 256;
			CRectangle::Render(CPlayer::mcharanormal, frame - 64, frame + 64, 1024, 768);
		}
		else if (mFx < 0){
			frame = 128 + frame * 256;
			CRectangle::Render(CPlayer::mcharanormal, frame + 64, frame - 64, 1024, 768);
		}
	}
}

void CDummyEnemy::Collision(CTask*task){
	CRectangle *rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EATTACK:
			mHitPoint -= mDamage;
			break;
	
		}
	}
}