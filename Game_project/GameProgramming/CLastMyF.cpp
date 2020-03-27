#include"CLastMyF.h"
#include "CTexture.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

CLastMyF::CLastMyF(int Priority)
:mFx(0.0f), mFy(0.0f), mFireCount(120), mHitPoint(700), mSearch(true), mDamage(100),
mSlowMove(1), mMove(2), mQuickMove(3), mUltDamagePlus(7), CEnemy(Priority), mEnabled(true)
, mACount(0), mACountM(0), mACountB(0), mACountK(0), mFps(120.0)
{
	mTag = ELASTMYF;
	mStatus = EIDLE;
	w = 256;
	h = 256;
	mLastBossIdle.Load("image\\enemy\\Last\\Last boss_1.tga");
	mLastBossMove.Load("image\\enemy\\Last\\Last boss_1.tga");
	mLastBossBurnAttack.Load("image\\enemy\\Last\\Last boss_2.tga");
	mLastBossDeathBlow.Load("image\\enemy\\Last\\Last boss_2.tga");
	mLastBossDeath.Load("image\\enemy\\Last\\Last boss_2.tga");
}

void CLastMyF::Update(){
	CEnemy::Update();
	mFy = 0;
	mFx = 0;

	if (mHitPoint < 700){
		//有効な時
		if (mEnabled) {
			CBossDeathBlow *BossDeathBlow = new CBossDeathBlow(2);
			//移動
			y += mFy;
			//持続時間
			if (mFireCount > 0) {
				mFireCount--;
			}
			if (mFireCount <= 0)
				mEnabled = false;
		}
		
		//有効な時
		if (mEnabled) {
			CBossDeathBlow *BossDeathBlow = new CBossDeathBlow(4);
			//移動
			y -= mFy;
			//持続時間
			if (mFireCount > 0) {
				mFireCount--;
			}
			if (mFireCount <= 0)
				mEnabled = false;
		}
		
		//有効な時
		if (mEnabled) {
			CBossDeathBlow *BossDeathBlow = new CBossDeathBlow(3);
			//移動
			x += mFx;
			//持続時間
			if (mFireCount > 0) {
				mFireCount--;
			}
			if (mFireCount <= 0)
				mEnabled = false;
		}
		//有効な時
		if (mEnabled) {
			CBossDeathBlow *BossDeathBlow = new CBossDeathBlow(3);
			//移動
			x -= mFx;
			//持続時間
			if (mFireCount > 0) {
				mFireCount--;
			}
			if (mFireCount <= 0)
				mEnabled = false;
		}
	}
	if (mHitPoint <= 0){
		mEnabled = false;
	}
	z = y;
}

void CLastMyF::Render() {
	if (mEnabled && mStatus == EIDLE) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 15){
			CRectangle::Render(mLastBossIdle, 151, 151 + 512, 641 + 512, 641);
			//151641
		}
		else if (mACount < 30){
			CRectangle::Render(mLastBossIdle, 151 + 512, 151 + 1024, 641 + 512, 641);
		}
		else if (mACount < 45){
			CRectangle::Render(mLastBossIdle, 151 + 1024, 151 + 1536, 641 + 512, 641);
		}
		else if (mACount < 60){
			CRectangle::Render(mLastBossIdle, 151 + 512, 151 + 1024, 641 + 512, 641);
			mACount = 0;
		}
		/*if (mACount < 15){
			CRectangle::Render(mLastBossIdle, 138, 632, 1155, 642);
		}
		else if (mACount < 30){
			CRectangle::Render(mLastBossIdle, 831, 1217, 1250, 789);
		}
		else if (mACount < 45){
			CRectangle::Render(mLastBossIdle, 321, 708, 1250, 789);
		}
		else if (mACount < 60){
			CRectangle::Render(mLastBossIdle, 831, 1217, 1250, 789);
		}
		else if (mACount < 75){
			CRectangle::Render(mLastBossIdle, 1362, 1716, 1250, 789);
		}
		else if (mACount < 90){
			CRectangle::Render(mLastBossIdle, 1861, 2236, 1250, 789);
		}
		else if (mACount < 105){
			CRectangle::Render(mLastBossIdle, 2381, 2751, 1250, 789);
		}
		else if (mACount < 120){
			CRectangle::Render(mLastBossIdle, 1362, 1716, 1250, 789);
			mACount = 0;
		}*/
	}
	
	if (mEnabled && mStatus == EBURNATTACK) {
		if (mACountB < mFps){
			mACountB++;
		}
		if (mACountB < 20){
			CRectangle::Render(mLastBossBurnAttack, 333, 677, 460, 540);
		}
		else if (mACountB < 40){
			CRectangle::Render(mLastBossBurnAttack, 850, 1191, 460, 540);
		}
		else if (mACountB < 60){
			CRectangle::Render(mLastBossBurnAttack, 1335, 1750, 460, 540);
			mACountB = 0;
		}
	}
	if (mEnabled && mStatus == EBOSSDEATHBLOW) {
		if (mACountK < mFps){
			mACountK++;
		}
		if (mACountK < 24){
			CRectangle::Render(mLastBossDeathBlow, 195, 545, 1140, 674);
		}
		else if (mACountK < 48){
			CRectangle::Render(mLastBossDeathBlow, 637, 1127, 1140, 674);
		}
		else if (mACountK < 72){
			CRectangle::Render(mLastBossDeathBlow, 1240, 1620, 1140, 674);
		}
		else if (mACountK < 96){
			CRectangle::Render(mLastBossDeathBlow, 1690, 2170, 1140, 674);
		}
		else if (mACountK < 120){
			CRectangle::Render(mLastBossDeathBlow, 2230, 2665, 1140, 674);
			mACountK = 0;
		}
	}
	if (mEnabled && mStatus == EDEATH) {
		if (mACountD < mFps){
			mACountD++;
		}
		if (mACountD < 10){
			CRectangle::Render(mLastBossDeath, 205, 572, 1910, 1405);
		}
		else if (mACountD < 20){
			CRectangle::Render(mLastBossDeath, 682, 1107, 1250, 789);
		}
		else if (mACountD < 30){
			CRectangle::Render(mLastBossDeath, 205, 572, 1910, 1405);
		}
		else if (mACountD < 40){
			CRectangle::Render(mLastBossDeath, 682, 1107, 1250, 789);
		}
		else if (mACountD < 50){
			CRectangle::Render(mLastBossDeath, 1164, 1642, 1250, 789);
		}
		else if (mACountD < 60){
			CRectangle::Render(mLastBossDeath, 682, 1107, 1250, 789);
		}
		else if (mACountD < 70){
			CRectangle::Render(mLastBossDeath , 1164, 1642, 1250, 789);
		}
		else if (mACountD < 80){
			CRectangle::Render(mLastBossDeath, 1675, 2160, 1250, 789);
		}
		else if (mACountD < 90){
			CRectangle::Render(mLastBossDeath, 1164, 1642, 1250, 789);
		}
		else if (mACountD < 100){
			CRectangle::Render(mLastBossDeath, 1675, 2160, 1250, 789);
		}
		else if (mACountD < 120){
			CRectangle::Render(mLastBossDeath, 2208, 2693, 1250, 789);
			mACountD = 0;
			mEnabled = false;
		}
	}
}

/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
void CLastMyF::Collision(CTask*task){
	CEnemy::Collision(task);
	CRectangle*rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EATTACK:
			mHitPoint -= 50;
			break;

		}
	}
}