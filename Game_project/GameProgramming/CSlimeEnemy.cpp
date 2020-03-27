#include"CSlimeEnemy.h"
#include "CTexture.h"
#include"CRectangle.h"
#include"CPlayer.h"
#include "CObject.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
CSlimeEnemy *CSlimeEnemy::mpSlimeEnemy = 0;

CSlimeEnemy::CSlimeEnemy(int Priority)
:mFx(0.0f), mFy(0.0f), mFireCount(120), mHitPoint(200), mSearch(true), mDamage(100),
mSlowMove(1), mMove(2), mQuickMove(3), mUltDamagePlus(7), CEnemy(Priority), mEnabled(true)
{
	mTag = ESLIMEENEMY;
	mStatus = EIDLE;
	mpSlimeEnemy = this;
	w = 128;
	h = 128;
	mSlime.Load("image\\enemy\\forest\\Normal enemy_forest.tga");
	
}

void CSlimeEnemy::Update(){
	CEnemy::Update();
	if (rand() % 100 < 50){
		if (y > 299){
			mFy = -mSlowMove;
			mStatus = EMOVE;
		}
		if (y < 169){
			mFy = +mSlowMove;
			mStatus = EMOVE;
		}
		else{
			mFy = 0;
			mStatus = EIDLE;
		}
	}
	z = y;

	if (mHitPoint <= 0){
		mEnabled = false;
	}
}

void CSlimeEnemy::Render() {
	int frame = 0;
	if (mEnabled && mStatus == EIDLE) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 15){
			frame = 0;
		}
		else if (mACount < 30){
			frame = 1;
		}
		else if (mACount < 45){
			frame = 2;
		}
		else if (mACount < 60){
			frame = 3;
		}
		else if (mACount == 60){
			mACount = 0;
		}
		frame = 0 + frame * 256;
		frame += 192;
		CRectangle::Render(mSlime, frame - 126, frame + 126, 878, 622);
	}
	if (mEnabled && mStatus == EMOVE) {
		if (mACountM < mFps){
			mACountM++;
		}
		if (mACountM < 15){
			frame = 0;
		}
		else if (mACountM < 30){
			frame = 1;
		}
		else if (mACountM < 45){
			frame = 2;
		}
		else if (mACountM < 60){
			frame = 3;
		}
		else if (mACountM == 60){
			mACountM = 0;

		}
		frame = 0 + frame * 256;
		frame += 192;
		CRectangle::Render(mSlime, frame - 126, frame + 126, 878, 622);

	}

	if (mEnabled && mStatus == EBURNATTACK) {
		if (mACountB < mFps){
			mACountB++;
		}
		if (mACountB < 15){
			frame = 0;
		}
		else if (mACountB < 30){
			frame = 1;
		}
		else if (mACountB < 45){
			frame = 2;
		}
		else if (mACountB < 60){
			frame = 1;
		}
		else if (mACountB == 60){
			mACountB = 0;

		}
		frame = 0 + frame * 256;
		frame += 192;
		CRectangle::Render(mSlime, frame - 126, frame + 126, 712, 968);
	}

}
void CSlimeEnemy::Collision(CTask*task){
	CEnemy::Collision(task);
	CRectangle *rect = (CRectangle*)task;
	CEffect *mEffect;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EATTACK:
			//mEnabled = false;
			mHitPoint -= mDamage;

			//mEffect = new CEffect(2);

			//mEffect->w = 64;
			//mEffect->h = 64;
			//
			//if (CPlayer::mpPlayer->x < CSlimeEnemy::mpSlimeEnemy->x){

			//	mEffect->x= x - 40;
			//	mEffect->y= y + 20;
			//}
			//
			//if (CPlayer::mpPlayer->x > CSlimeEnemy::mpSlimeEnemy->x){

			//	mEffect->x= x + 40;
			//	mEffect->y = y + 20;
			//}

			mEnabled = false;
			//mHitPoint -= mDamage;

			mHitPoint -= mDamage;
			break;

		case EDEATHBLOW:
			mEnabled = false;
			break;
		}
	}
}