#include "CEnemy.h"
#include "CTexture.h"
#include"CPlayer.h"
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

CEnemy::CEnemy(int Priority)
: mFx(0.0f), mFy(0.0f), mFireCount(180), mHitPoint(0), mSearch(true), mDamage(100),
mSlowMove(1), mMove(2), mQuickMove(3), mUltDamagePlus(7), CRectangle(Priority), mBurnSpeed(2), mBurnSpeedB(4),
mEnabled(true)
{

	d = 30;

}

void CEnemy::Update() {

	if (mTag == ESLIMEENEMY||mTag == ECATENEMY ||mTag == EDUMMYENEMY){
			if (y > 199){
				mFy = -mSlowMove;
				y += mFy;
				z = y;
				mStatus = EMOVE;
			}
			if (y < 69){
				mFy = +mSlowMove;
				y += mFy;
				z = y;
				mStatus = EMOVE;
			}
	}
	if (rand() % 100 < 10){
		mSearch == true;
	}
	if (rand() % 100 < 90){
		mSearch == false;
	}
	//プレイヤージャンプ時
	if (CPlayer::mpPlayer->jflag == true){
		mFy = 0;
	}
	if (mTag == EMISTRESS || mTag == ERABBITBOSS || mTag == ELASTMYF){
		//プレイヤーをサーチして動く
		if (mSearch == true && CPlayer::mpPlayer->jflag == false){
			if (rand() % 100 < 50){
				if (x - CPlayer::mpPlayer->x > 300){
					mFx = -mSlowMove;
					mStatus = EBOSSMOVE;
				}
				else if (x - CPlayer::mpPlayer->x < 300){
					mFx = +mSlowMove;
					mStatus = EBOSSMOVE;
				}
			/*	else if (x - CPlayer::mpPlayer->x == 300){
					mFx = 0;
					mStatus = EIDLE;
				}*/
				else{
					if (x - CPlayer::mpPlayer->x > 400){
						mFx = -mSlowMove;
						mStatus = EBOSSMOVE;
					}
					else if (x - CPlayer::mpPlayer->x < 400){
						mFx = +mSlowMove;
						mStatus = EBOSSMOVE;
					}
				/*	else if (x - CPlayer::mpPlayer->x == 400){
						mFx = 0;
						mStatus = EIDLE;
					}*/
				}
			}
			if (rand() % 100 < 50){
				if (x - CPlayer::mpPlayer->x > -300){
					mFx = -mSlowMove;
					mStatus = EBOSSMOVE;
				}
				else if (x - CPlayer::mpPlayer->x < -300){
					mFx = +mSlowMove;
					mStatus = EBOSSMOVE;
				}
				/*else if (x - CPlayer::mpPlayer->x == -300){
					mFx = 0;
					mStatus = EIDLE;
				}*/
				else{
					if (x - CPlayer::mpPlayer->x > -400){
						mFx = -mSlowMove;
						mStatus = EBOSSMOVE;
					}
					else if (x - CPlayer::mpPlayer->x < -400){
						mFx = +mSlowMove;
						mStatus = EBOSSMOVE;
					}
					/*else if (x - CPlayer::mpPlayer->x == -400){
						mFx = 0;
						mStatus = EIDLE;
					}*/
				}
			}

			if (mSearch == true ){
				if (y - CPlayer::mpPlayer->y > 0){
					mFy = -mSlowMove;
					mStatus = EBOSSMOVE;
				}
				if (y - CPlayer::mpPlayer->y < 0){
					mFy = +mSlowMove;
					mStatus = EBOSSMOVE;
				}
				else if (y - CPlayer::mpPlayer->y == 0){
					mFy = 0;
					mStatus = EIDLE;
				}
			}
		}
	}

	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	//120フレームに1回発射
	if (mFireCount > 0) {
		mFireCount--;
	}
	else if (mTag == EMISTRESS || mTag == ERABBITBOSS || mTag == ELASTMYF) {
		
		//弾を1発一方へ発射する
		for (int i = 0; i < 1; i++) {
			mStatus = EBURNATTACK;

		

			CBurn *EBurn = new CBurn(3);
			//プレイヤーが左側の時
			if (x >= CPlayer::mpPlayer->x){
				//座標設定
				EBurn->x = x;
				EBurn->y = EBurn->z = y;
				//移動量設定
				EBurn->mFx = -mBurnSpeedB;
				//EBurn->mFy = (i - 1) % 2 * 2;
				mStatus = EBURNATTACK;
			}
			//プレイヤーが右側の時
			else if (x <= CPlayer::mpPlayer->x){
				//座標設定
				EBurn->x = x;
				EBurn->y = EBurn->z = y;
				//移動量設定
				EBurn->mFx = +mBurnSpeedB;
				//EBurn->mFy = (i - 1) % 2 * 2;
				mStatus = EBURNATTACK;
			}
			//有効にする
			EBurn->mEnabled = true;
			EBurn->mTag = EBURN;
		}
		mFireCount = 180;
		mStatus = EIDLE;
	}
	else {
		//弾を1発一方へ発射する
		for (int i = 0; i < 1; i++) {
			mStatus = EBURNATTACK;



			CBurn *EBurn = new CBurn(3);
			//プレイヤーが左側の時
			if (x >= CPlayer::mpPlayer->x){
				//座標設定
				EBurn->x = x;
				EBurn->y = EBurn->z = y;
				//移動量設定
				EBurn->mFx = -mBurnSpeed;
				//EBurn->mFy = (i - 1) % 2 * 2;
				mStatus = EBURNATTACK;
			}
			//プレイヤーが右側の時
			else if (x <= CPlayer::mpPlayer->x){
				//座標設定
				EBurn->x = x;
				EBurn->y = EBurn->z = y;
				//移動量設定
				EBurn->mFx = +mBurnSpeed;
				//EBurn->mFy = (i - 1) % 2 * 2;
				mStatus = EBURNATTACK;
			}
			//有効にする
			EBurn->mEnabled = true;
			EBurn->mTag = EBURN;
		}
		mFireCount = 180;
		//mStatus = EIDLE;
	}
	x += mFx;
	y += mFy;

	if (mTag == EDEATH){
		mEnabled = false;
	}

	if (mHitPoint <= 0){
		mTag == EDEATH;
	}
	/*if (mTag == EMISTRESS && mHitPoint == 350){
		mTag = EMISTRESSES;
	}
	if (mTag == EMISTRESSES){
			mFx = +mQuickMove;
			x += mFx;
	}*/
}

void CEnemy::Render() {
}

/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
void CEnemy::Collision(CTask*task){
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