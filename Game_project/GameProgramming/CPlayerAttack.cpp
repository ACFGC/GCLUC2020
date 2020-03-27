#include"CPlayerAttack.h"
#include"CPlayer.h"


CPlayerAttack::CPlayerAttack(int Priority)
:CRectangle(Priority), mFPS(60), mACountA(0)
, mFx(0), mFy(0)
{

	w = 128;
	h = 128;
	d = 30;
	
}

void CPlayerAttack::Update(){
	//—LŒø‚ÈŽž
	/*if (mEnabled){
		if (CPlayer::mpPlayer->mState == CPlayer::EIDLE || CPlayer::mpPlayer->mState == CPlayer::EMOVE)
			mEnabled = false;
	}*/
}
void CPlayerAttack::Render(){
	//int frame = 0;
	////—LŒø‚ÈŽž
	//if (mEnabled){
	//	if (CPlayer::mpPlayer->mMode == CPlayer::ENORMAL){
	//		if (mACountA < mFPS){
	//			mACountA++;
	//		}
	//		if (mACountA < 20){
	//			frame = 0;
	//		}
	//		else if (mACountA < 40){
	//			frame = 1;
	//		}
	//		else if (mACountA < 60){
	//			frame = 2;
	//		}
	//		else if (mACountA == 60){
	//			mACountA = 0;
	//			CPlayer::mpPlayer->mflag = true;
	//			mEnabled = false;
	//		}
	//		if (CPlayer::mpPlayer->mFx > 0){
	//			frame = 128 + frame * 256;
	//		CRectangle::Render(CPlayer::mcharanormal, frame - 128, frame + 128, 515, 266);
	//		}
	//		else if (CPlayer::mpPlayer->mFx < 0){
	//			frame = 128 + frame * 256;
	//			CRectangle::Render(CPlayer::mcharanormal, frame + 128, frame - 128, 515, 266);
	//		}
	//	}
	//	else if (CPlayer::mpPlayer->mMode == CPlayer::ESTRONG){
	//		if (mACountA < mFPS){
	//			mACountA++;
	//		}
	//		if (mACountA < 20){
	//			frame = 0;
	//		}
	//		else if (mACountA < 40){
	//			frame = 1;
	//		}
	//		else if (mACountA < 60){
	//			frame = 2;

	//		}
	//		else if (mACountA == 60){
	//			mACountA = 0;
	//			CPlayer::mpPlayer->mflag = true;
	//			mEnabled = false;
	//		}
	//		if (CPlayer::mpPlayer->mFx > 0){
	//			frame = 128 + frame * 256;
	//			CRectangle::Render(CPlayer::mcharaatk, frame - 128, frame + 128, 515, 266);
	//		}
	//		else if (CPlayer::mpPlayer->mFx < 0){
	//			frame = 128 + frame * 256;
	//			CRectangle::Render(CPlayer::mcharaatk, frame + 128, frame - 128, 515, 266);
	//		}
	//	}
	//	
	//}
}





void CPlayerAttack::Collision(CTask*task){
	CRectangle*rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case ESLIMEENEMY:
		case EMISTRESS:	
		case ECATENEMY:
		case ERABBITBOSS:	
		case EDUMMYENEMY:
		case ELASTMYF:
			mEnabled = false;
			break;
		}
	}

}