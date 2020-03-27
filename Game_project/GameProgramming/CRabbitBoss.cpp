#include"CRabbitBoss.h"
#include "CTexture.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

CRabbitBoss::CRabbitBoss(int Priority)
:mFx(0.0f), mFy(0.0f), mFireCount(120), mHitPoint(700), mSearch(true), mDamage(100),
mSlowMove(1), mMove(2), mQuickMove(3), mUltDamagePlus(7), CEnemy(Priority), mEnabled(true)
, mACount(0), mACountM(0), mACountB(0), mACountV(0), mFps(120.0)
{
	mTag = ERABBITBOSS;
	mStatus = EIDLE;
	w = 128;
	h = 128;
	mRabbitIdle.Load("image\\enemy\\3F\\3F_boss_1.tga");
	mRabbitMove.Load("image\\enemy\\3F\\3F_boss_1.tga");
	mRabbitBurnAttack.Load("image\\enemy\\3F\\3F_boss_1.tga");
	mRabbitVenom.Load("image\\enemy\\3F\\3F_boss_2.tga");
	mRabbitDeath.Load("image\\enemy\\3F\\3F_boss_2.tga");
}

void CRabbitBoss::Update(){
	CEnemy::Update();

	if (mHitPoint <= 0){
		mEnabled=false;
	}
}

void CRabbitBoss::Render() {
	if (mEnabled && mStatus == EIDLE) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 15){
			CRectangle::Render(mRabbitIdle, 1362, 1716, 1250, 789);
		}
		else if (mACount < 30){
			CRectangle::Render(mRabbitIdle, 831, 1217, 1250, 789);
		}
		else if (mACount < 45){
			CRectangle::Render(mRabbitIdle, 321, 708, 1250, 789);
		}
		else if (mACount < 60){
			CRectangle::Render(mRabbitIdle, 831, 1217, 1250, 789);
		}
		else if (mACount < 75){
			CRectangle::Render(mRabbitIdle, 1362, 1716, 1250, 789);
		}
		else if (mACount < 90){
			CRectangle::Render(mRabbitIdle, 1861, 2236, 1250, 789);
		}
		else if (mACount < 105){
			CRectangle::Render(mRabbitIdle, 2381, 2751, 1250, 789);
		}
		else if (mACount < 120){
			CRectangle::Render(mRabbitIdle, 1362, 1716, 1250, 789);
			mACount = 0;
		}
	}
	if (mEnabled && mStatus == EBOSSMOVE) {
		if (mACountM < mFps){
			mACountM++;
		}
		if (mACountM < 15){
			CRectangle::Render(mRabbitMove, 1362, 1716, 1250, 789);
		}
		else if (mACountM < 30){
			CRectangle::Render(mRabbitMove, 831, 1217, 1250, 789);
		}
		else if (mACountM < 45){
			CRectangle::Render(mRabbitMove, 321, 708, 1250, 789);
		}
		else if (mACountM < 60){
			CRectangle::Render(mRabbitMove, 831, 1217, 1250, 789);
		}
		else if (mACountM < 75){
			CRectangle::Render(mRabbitMove, 1362, 1716, 1250, 789);
		}
		else if (mACountM < 90){
			CRectangle::Render(mRabbitMove, 1861, 2236, 1250, 789);
		}
		else if (mACountM < 105){
			CRectangle::Render(mRabbitMove, 2381, 2751, 1250, 789);
		}
		else if (mACountM < 120){
			CRectangle::Render(mRabbitMove, 1362, 1716, 1250, 789);
			mACountM = 0;
		}
	}
	if (mEnabled && mStatus == EBURNATTACK) {
		if (mACountB < mFps){
			mACountB++;
		}
		if (mACountB < 20){
			CRectangle::Render(mRabbitBurnAttack, 333, 677, 460, 540);
		}
		else if (mACountB < 40){
			CRectangle::Render(mRabbitBurnAttack, 850, 1191, 460, 540);
		}
		else if (mACountB < 60){
			CRectangle::Render(mRabbitBurnAttack, 1335, 1750, 460, 540);
			mACountB = 0;
		}
	}
	if (mEnabled && mStatus == EVENOM) {
		if (mACountV < mFps){
			mACountV++;
		}
		if (mACountV < 24){
			CRectangle::Render(mRabbitVenom, 195, 545, 1140, 674);
		}
		else if (mACountV < 48){
			CRectangle::Render(mRabbitVenom, 637, 1127, 1140, 674);
		}
		else if (mACountV < 72){
			CRectangle::Render(mRabbitVenom, 1240, 1620, 1140, 674);
		}
		else if (mACountV < 96){
			CRectangle::Render(mRabbitVenom, 1690, 2170, 1140, 674);
		}
		else if (mACountV < 120){
			CRectangle::Render(mRabbitVenom, 2230, 2665, 1140, 674);
			mACountV = 0;
		}
	}
	if (mEnabled && mStatus == EDEATH) {
		if (mACountD < mFps){
			mACountD++;
		}
		if (mACountD < 10){
			CRectangle::Render(mRabbitDeath, 205, 572, 1910, 1405);
		}
		else if (mACountD < 20){
			CRectangle::Render(mRabbitDeath, 682, 1107, 1250, 789);
		}
		else if (mACountD < 30){
			CRectangle::Render(mRabbitDeath, 205, 572, 1910, 1405);
		}
		else if (mACountD < 40){
			CRectangle::Render(mRabbitDeath, 682, 1107, 1250, 789);
		}
		else if (mACountD < 50){
			CRectangle::Render(mRabbitDeath, 1164, 1642, 1250, 789);
		}
		else if (mACountD < 60){
			CRectangle::Render(mRabbitDeath, 682, 1107, 1250, 789);
		}
		else if (mACountD < 70){
			CRectangle::Render(mRabbitDeath, 1164, 1642, 1250, 789);
		}
		else if (mACountD < 80){
			CRectangle::Render(mRabbitDeath, 1675, 2160, 1250, 789);
		}
		else if (mACountD < 90){
			CRectangle::Render(mRabbitDeath, 1164, 1642, 1250, 789);
		}
		else if (mACountD < 100){
			CRectangle::Render(mRabbitDeath, 1675, 2160, 1250, 789);
		}
		else if (mACountD < 120){
			CRectangle::Render(mRabbitDeath, 2208, 2693, 1250, 789);
			mACountD = 0;
			mEnabled = false;
		}
	}
}

/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/

void CRabbitBoss::Collision(CTask*task){
	CEnemy::Collision(task);
	CRectangle*rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EATTACK:
			mHitPoint -= 100;
			/*mEnabled = false;*/
			break;

		}
	}
}