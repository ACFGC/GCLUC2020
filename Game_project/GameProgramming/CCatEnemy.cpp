#include"CCatEnemy.h"
#include "CTexture.h"
#include"CRectangle.h"
#include"CPlayer.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

CCatEnemy::CCatEnemy(int Priority)
:mFx(0.0f), mFy(0.0f), mFireCount(120), mHitPoint(200), mSearch(true), mDamage(100),
mSlowMove(1), mMove(2), mQuickMove(3), mUltDamagePlus(7), CEnemy(Priority), mEnabled(true)
, mACount(0), mFps(60.0)
{
	mTag = ECATENEMY;
	mStatus = EIDLE;
	w = 128;
	h = 128;
	mCatIdle.Load("image\\enemy\\3F\\Cat.tga");
	mCatBind.Load("image\\enemy\\3F\\Cat.tga");
}

void CCatEnemy::Update(){
	CEnemy::Update();

	if (x - CPlayer::mpPlayer->x < 10){
		mStatus = EBIND;
	};
}

void CCatEnemy::Render() {
	if (mEnabled && mStatus == EIDLE){
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 15){
			CRectangle::Render(mCatIdle, 380, 640, 570, 320);
		}
		else if (mACount < 30){
			CRectangle::Render(mCatIdle, 130, 380, 570, 320);
		}
		else if (mACount < 45){
			CRectangle::Render(mCatIdle, 380, 640, 570, 320);
		}
		else if (mACount < 60){
			CRectangle::Render(mCatIdle, 640, 890, 570, 320);
			mACount = 0;
		}
	}

	if (mEnabled && mStatus == EMOVE) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 15){
			CRectangle::Render(mCatIdle, 380, 640, 570, 320);
		}
		else if (mACount < 30){
			CRectangle::Render(mCatIdle, 130, 380, 570, 320);
		}
		else if (mACount < 45){
			CRectangle::Render(mCatIdle, 380, 640, 570, 320);
		}
		else if (mACount < 60){
			CRectangle::Render(mCatIdle, 640, 890, 570, 320);
			mACount = 0;
		}
	}

	if (mEnabled && mStatus == EBURNATTACK) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 20){
			CRectangle::Render(mCatIdle, 130, 380, 957, 710);
		}
		else if (mACount < 40){
			CRectangle::Render(mCatIdle, 385, 635, 957, 710);
		}
		else if (mACount < 60){
			CRectangle::Render(mCatIdle, 640, 890, 957, 710);
			mACount = 0;
		}
	}

	if (mEnabled && mStatus == EBIND) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 20){
			CRectangle::Render(mCatBind, 1090, 1341, 572, 323);
		}
		else if (mACount < 40){
			CRectangle::Render(mCatBind, 1345, 1595, 572, 323);
		}
		else if (mACount < 60){
			CRectangle::Render(mCatBind, 1600, 1850, 572, 323);
			mACount = 0;
		}
		
	}

	if (mEnabled && mStatus == EDAMAGE) {
		CRectangle::Render(mCatIdle, 0, 256, 256, 0);
	}
	if (mEnabled && mStatus == EDEATH) {
		CRectangle::Render(mCatIdle, 0, 256, 256, 0);
	}
}


void CCatEnemy::Collision(CTask*task){
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