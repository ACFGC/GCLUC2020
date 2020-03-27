#include"CMistress.h"
#include "CTexture.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
CMistress *CMistress::mpMistress = 0;

CMistress::CMistress(int Priority)
:mFx(0.0f), mFy(0.0f), mFireCount(120), mHitPoint(700), mSearch(true), mDamage(100),
mSlowMove(1), mMove(2), mQuickMove(3), mUltDamagePlus(7), CEnemy(Priority), mEnabled(true), mWarpTime(300)
, mACount(0), mACountW(0), mACountM(0), mACountD(0), mACountB(0), mFps(300.0), mWx(300), mWy(100)
{
	mTag = EMISTRESS;
	mStatus = EIDLE;
	mpMistress = this;
	w = 128;
	h = 128;
	mMistressIdle.Load("image\\enemy\\forest\\Forest Boss_1.tga");
	mMistressMove.Load("image\\enemy\\forest\\Forest Boss_1.tga");
	mMistressBurnAttack.Load("image\\enemy\\forest\\Forest Boss_1.tga");
	mMistressWarp.Load("image\\enemy\\forest\\Forest Boss_2.tga");
	mMistressMist.Load("image\\enemy\\forest\\Forest Boss_2.tga");
	mMistressDeath.Load("image\\enemy\\forest\\Forest Boss_2.tga");
}

void CMistress::Update(){
	CEnemy::Update();
	if (mHitPoint <= 0){
		mStatus == EDEATH;
	}

	/*if (mHitPoint < 350){
		mTag == EMISTRESSES;
	}*/

	if (0 < mWarpTime){
		mWarpTime--;
	}
	if(mWarpTime <= 0){
		mStatus = EWARPFIRST;
		mWarpTime = 300;
	}

	if (mEnabled && mStatus == EWARPFIRST){
		mStatus = ESHADOWMIST;
	}

	if (rand() % 100 < 50){
		if (mEnabled && mStatus == ESHADOWMIST){
			if (rand() % 100 < 50){
				x += mWx;
			}
			else {
				x -= mWx;
			}
			mStatus = EIDLE;
		}
		else{
			if (mEnabled && mStatus == ESHADOWMIST){
				if (rand() % 100 < 50){
					y += mWy;
				}
				else {
					y -= mWy;
				}
				mStatus = EIDLE;
			}
		}
	
	}

	z = y;
}

void CMistress::Render() {
	int frame = 0;

	if (mEnabled && mStatus == EIDLE) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 12){
			frame = 0;
		}
		else if (mACount < 24){
			frame = 1;
		}
		else if (mACount < 36){
			frame = 2;
		}
		else if (mACount < 48){
			frame = 3;
		}
		else if (mACount < 60){
			frame = 4;
		}
		else if (mACount >= 60){
			mACount = 0;
		}
		frame = 256 + frame * 512;
		frame += 130;
		CRectangle::Render(mMistressIdle, frame - 256, frame + 256, 1170, 658);
	}

	if (mEnabled && mStatus == EBOSSMOVE) {
		if (mACountM < mFps){
			mACountM++;
		}
		if (mACountM < 6){
			frame = 0;
		}
		else if (mACountM < 12){
			frame = 1;
		}
		else if (mACountM < 18){
			frame = 2;
		}
		else if (mACountM < 24){
			frame = 3;
		}
		else if (mACountM < 30){
			frame = 4;
		}
		else if (mACountM >= 30){
			mACountM = 0;
		}
		frame = 256 + frame * 512;
		frame += 130;
		CRectangle::Render(mMistressMove, frame - 256, frame + 256, 1170, 658);
	}
	
	if (mEnabled && mStatus == EBURNATTACK) {
		if (mACountB < mFps){
			mACountB++;
		}
		if (mACountB < 30){
			frame = 0;
		}
		else if (mACountB < 60){
			frame = 1;
		}
		else if (mACountB < 90){
			frame = 2;
		}
		else if (mACountB < 120){
			frame = 1;
		}
		else if (mACountB >= 120){
			mACountB = 0;
		}
		frame = 256 + frame * 512;
		frame += 130;
		CRectangle::Render(mMistressBurnAttack, frame - 256, frame + 256, 1908, 1396);
	}

	if (mEnabled && mStatus == EWARPFIRST) {
		if (mACountW < mFps){
			mACountW++;
		}
		if (mACountW < 30){
			frame = 0;
		}
		else if (mACountW < 60){
			frame = 1;
		}
		else if (mACountW < 90){
			frame = 2;
		}
		else if (mACountW < 120){
			frame = 3;
		}
		else if (mACountW >= 120){
			mACountW = 0;
		}
		frame = 256 + frame * 512;
		frame + 134;
		CRectangle::Render(mMistressWarp, frame - 250, frame + 250, 794, 282);
	}

	if (mEnabled && mStatus == ESHADOWMIST) {
		if (mACountSM < mFps){
			mACountSM++;
		}
		if (mACountSM < 15){
			frame = 0;
		}
		else if (mACountSM < 30){
			frame = 1;
		}
		else if (mACountSM < 45){
			frame = 2;
		}
		else if (mACountSM < 60){
			frame = 3;
		}
		else if (mACountSM >= 60){
			mACountSM = 0;
		}
		frame = 256 + frame * 512;
		frame + 134;
		CRectangle::Render(mMistressMist, frame - 250, frame + 250, 1566, 1054);
	}
	
	if (mEnabled && mStatus == EDEATH) {
		if (mACountD < mFps){
			mACountD++;
		}
		if (mACountD < 30){
			frame = 1;
		}
		else if (mACountD < 60){
			frame = 0;
		}
		else if (mACountD < 90){
			frame = 1;
		}
		else if (mACountD < 120){
			frame = 0;
		}
		else if (mACountD < 150){
			frame = 1;
		}
		else if (mACountD < 180){
			frame = 2;
		}
		else if (mACountD < 210){
			frame = 1;
		}
		else if (mACountD < 240){
			frame = 2;
		}
		else if (mACountD < 270){
			frame = 3;
		}
		else if (mACountD < 300){
			frame = 2;
		}
		else if (mACountD < 330){
			frame = 3;
		}
		else if (mACountD < 360){
			frame = 4;
		}
		else if (mACountD < 390){
			frame = 3;
		}
		else if (mACountD >= 450){
			mACountD = 4;
		}
		frame = 256 + frame * 512;
		frame + 134;
		CRectangle::Render(mMistressDeath, frame - 250, frame + 250, 2338, 1826);
	}

}

void CMistress::Collision(CTask*task){
	CEnemy::Collision(task);
	CRectangle*rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EATTACK:
			mHitPoint -= 100;
			//mEnabled = false;
			break;

		}
	}
}