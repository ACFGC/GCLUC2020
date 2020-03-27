#include"CPlayer.h"
#include"CKey.h"
#include"CPlayerAttack.h"
#include"CShadow.h"
#include"CGameOver.h"
#define VELOCITY0 40;

CPlayer *CPlayer::mpPlayer = 0;
CTexture CPlayer::mcharanormal;
CTexture CPlayer::mcharahear;
CTexture CPlayer::mcharaatk;
CTexture CPlayer::mModeNormal;
CTexture CPlayer::mModeHeal;
CTexture CPlayer::mModeAttack;
CPlayer::CPlayer(int Priority)
:CRectangle(Priority), mJumpPower(20), mmove(3)
, mAttackCount(0), mHealCount(0), mSpeed(0), mCount(0)
, mPhp(10), mPHPM(10), mHealNumber(1), mDistantTime(0), mACount(0), mACountA(0)
, mACountD(0), mFx(1), mFy(0), mSpecialGauge(0), mSpecialGaugeMax(600)
, mGRAVITY(2.0f), mFPS(60.0f)
{
	h = 128;
	w = 64;
	d = 30;
	mTag = EPLAYER;
	mpPlayer = this;
	mState = EIDLE;
	mMode = ENORMAL;
	mcharanormal.Load("image\\chara\\chara nomal.tga");
	mcharahear.Load("image\\chara\\chara heal.tga");
	mcharaatk.Load("image\\chara\\chara atk.tga");
	mModeAttack.Load("image\\UI\\���[�h�ؑ�\\mode.tga");
	mModeHeal.Load("image\\UI\\���[�h�ؑ�\\mode_2.tga");
	mModeNormal.Load("image\\UI\\���[�h�ؑ�\\mode_3.tga");
	CShadow*Shadow = new CShadow(3);

	mRectMode.x = CScene::mpInstance->mLeft + 110;
	mRectMode.y = CScene::mpInstance->mBottom + 610;
	mRectMode.w = 100;
	mRectMode.h = 100;
}


void CPlayer::Update(){
	
		//��
		if (CKey::Push('A')&&mflag==true&&w==64){
			x -= mmove;
			mFx = -1;
			mFy = 0;
			if (CPlayer::mpPlayer->x <78){
				x += mmove;
			}

			if (CPlayer::mpPlayer->y>100 &&CPlayer::mpPlayer->x > 3250 && CScene::mpInstance->mScene == CScene::EMANSION && CScene::mpInstance->mScene == CScene::EMANSIONF2)
				{

				x += mmove;

			}

			mState = EMOVE;
			
		}
		//�E
		else if (CKey::Push('D') && mflag == true && w == 64){
			x += mmove;
			mFx = 1;
			mFy = 0;
			if (CPlayer::mpPlayer->x>3750){
				x -= mmove;
			}
			mState = EMOVE;
			
		}
		else if(mState==EMOVE){
			mState = EIDLE;

		}

		//��
		if (CKey::Push('W') && mflag == true && w == 64){
			y += mmove;
		
			if (CScene::mpInstance->mScene == CScene::EFOREST){
				if(CPlayer::mpPlayer->y > 300)
				y -= mmove;
			}

			if (CScene::mpInstance->mScene == CScene::EMANSIONLAST){
				if (CPlayer::mpPlayer->y > 300)
					y -= mmove;
			}

			if (CScene::mpInstance->mScene == CScene::EMANSION || CScene::mpInstance->mScene == CScene::EMANSIONF2){

				if (CPlayer::mpPlayer->x > 2950 && CPlayer::mpPlayer->y > 500){
					
						y -= mmove;

				}
				else if (CPlayer::mpPlayer->x < 3500 && CPlayer::mpPlayer->y > 300){

						y -= mmove;

				}
			}
			z = y;
		}
		

		 if (CKey::Push('S') && mflag == true && w == 64){
			y -= mmove;
			
			if (CPlayer::mpPlayer->y < 170){
				y += mmove;
			}
			z = y;
		}
		
	
	//�W�����v
	if (jflag == true){
		mState = EJUMP;
		mSpeed -= mGRAVITY;
		y += mSpeed;
		if (my_prev>y){
			y = my_prev;
			mState = EIDLE;
			jflag = false;
		}
	}
	else if (CKey::Once('J') && aflag == false && uflag == false && w == 64){
		if (jflag == false){
			my_prev = y;
			mSpeed = VELOCITY0;
			y += mSpeed;
			jflag = true;
		}
		
	}

	//�m�[�}�����
	if (mMode == ENORMAL){
		if (mAttackCount < mFPS){
			mAttackCount++;
		}
		//�G�ɍU��
		else if (CKey::Once(' ') && jflag == false && uflag == false){
			mACountA = 0;
			aflag = true;
			mflag = false;
			w = 128;
			mState = ESTRIKE;
			CPlayerAttack*PlayerAttack = new CPlayerAttack(2);
			//�ʒu�̐ݒ�
			PlayerAttack->x = x;
			PlayerAttack->y = PlayerAttack->z = y;
			
			PlayerAttack->mEnabled = true;
			PlayerAttack->mTag = CRectangle::EATTACK;
			mAttackCount = 0;
		}
		else if (mState == ESTRIKE){
			w = 64;
			mState = EIDLE;
		}


		//if (mSpecialGauge<mSpecialGaugeMax&&uflag==false){
		//	mSpecialGauge++;
		//}
		////�K�E�Z�S�̍U��
		//else  if (CKey::Once('U') && jflag == false && aflag == false && uflag == false){
		//	mACountU = 0;
		//	uflag = true;
		//	mflag = false;
		//	mState = EULT;
		//	mSpecialGauge = 0;
		//}
		//���[�h�`�F���W
		if (CKey::Once('M')){
			mMode = ESTRONG;
		}
	}
	//�������
	else if (mMode == ESTRONG){
		if (mAttackCount < mFPS){
			mAttackCount++;
		}
		//�G�ɍU��
		else if (CKey::Once(' ') && jflag == false && uflag == false){
			mACountA = 0;
			aflag = true;
			mflag = false;
			w = 128;
			mState = ESTRIKE;
			CPlayerAttack*PlayerAttack = new CPlayerAttack(2);
			//�ʒu�̐ݒ�
			PlayerAttack->x = x;
			PlayerAttack->y = PlayerAttack->z = y;
			//����
			PlayerAttack->mFx = mFx;
			PlayerAttack->mFy = mFy;

			PlayerAttack->mEnabled = true;
			PlayerAttack->mTag = CRectangle::EATTACK;
			mAttackCount = 0;
		}
		else if (mState == ESTRIKE){
			w = 64;
			mState = EIDLE;
		}
		//���[�h�`�F���W
		if (CKey::Once('M')){
			mMode = EHEAL;
		}
	}
	//�񕜏��
	else if (mMode == EHEAL){
		if (mHealCount < mFPS){
			mHealCount++;
		}
		else if (mPhp<mPHPM){
			mPhp = mPhp + mHealNumber;
			mHealCount = 0;
		}
		//���[�h�`�F���W
		if (CKey::Once('M')){
			mMode = ENORMAL;
		}
	}
	if (mPhp <= 0){
		mflag = false;
		mState = EDEATH;
	}

	mRectMode.x = CScene::mpInstance->mLeft + 110;
	mRectMode.y = CScene::mpInstance->mBottom + 610;
}
void CPlayer::Collision(CTask*task){
	CRectangle*rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EBURN:
			mPhp--;
			break;
		}
	}
}

void CPlayer::Render(){
	int frame = 0;
	if (mEnabled) {
		//�������
		if (mMode == ESTRONG){
			//�U��
		 if (mState == ESTRIKE){
			if (mACountA < mFPS){
				mACountA++;
			}
			if (mACountA < 20){
				frame = 0;
			}
			else if (mACountA < 40){
				frame = 1;
			}
			else if (mACountA < 60){
				frame = 2;

			}
			else if (mACountA == 60){
				mACountA = 0;
				mflag = true;
				aflag = false;
			}
			if (mFx > 0){
				frame = 128 + frame * 256;
				CRectangle::Render(mcharaatk, frame - 128, frame + 128, 512, 256);
			}
			else if (mFx < 0){
				frame = 128 + frame * 256;
				CRectangle::Render(mcharaatk, frame + 128, frame - 128, 512, 256);
			}

		}
			//�W�����v
			else  if (mState == EJUMP){
				if (mACount < mFPS){
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
				else if (mACount == 60){
					mACount = 0;
				}
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharaatk, frame - 64, frame + 64, 256, 0);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharaatk, frame + 64, frame - 64, 256, 0);
				}
			}

			//�ړ�
			else  if (mState == EMOVE){
				if (mACount < mFPS){
					mACount++;
				}
				if (mACount < 10){
					frame = 0;
				}
				else if (mACount < 20){
					frame = 1;

				}
				else if (mACount < 30){
					frame = 2;

				}
				else if (mACount < 40){
					frame = 3;

				}
				else if (mACount < 50){
					frame = 4;

				}
				else if (mACount < 60)
				{
					frame = 5;

				}
				else if (mACount == 60){
					mACount = 0;
				}
				//�E
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharaatk, frame - 64, frame + 64, 768, 512);
				}
				//��
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharaatk, frame + 64, frame - 64, 768, 512);
				}
			}
			//�ҋ@
			else if (mState == EIDLE){

				if (mACount < mFPS){
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
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharaatk, frame - 64, frame + 64, 1024, 768);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharaatk, frame + 64, frame - 64, 1024, 768);
				}
			}
			//���S
			else if (mState == EDEATH){
				if (mACountD < mFPS){
					mACountD++;
				}
				if (mACountD < 20){
					frame = 0;
				}
				else if (mACountD < 40){
					frame = 1;
				}
				else if (mACountD < 60){
					frame = 2;
				}
				else if (mACountD == 60){
					CGameOver::mpInstance->mIsGameOver = true;
					//mEnabled = false;
					mflag == true;
				}
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame - 64, frame + 64, 1280, 1024);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame + 64, frame - 64, 1280, 1024);
				}
			}

		}
		//�񕜏��
		else if (mMode == EHEAL){

			//�W�����v
			if (mState == EJUMP){
				if (mACount < mFPS){
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
				else if (mACount == 60){
					mACount = 0;
				}
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharahear, frame - 64, frame + 64, 256, 0);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharahear, frame + 64, frame - 64, 256, 0);
				}
			}

			//�ړ�
			else  if (mState == EMOVE){
				if (mACount < mFPS){
					mACount++;
				}
				if (mACount < 10){
					frame = 0;
				}
				else if (mACount < 20){
					frame = 1;

				}
				else if (mACount < 30){
					frame = 2;

				}
				else if (mACount < 40){
					frame = 3;

				}
				else if (mACount < 50){
					frame = 4;

				}
				else if (mACount < 60)
				{
					frame = 5;

				}
				else if (mACount == 60){
					mACount = 0;
				}
				//�E
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharahear, frame - 64, frame + 64, 768, 512);
				}
				//��
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharahear, frame + 64, frame - 64, 768, 512);
				}
			}
			//�ҋ@
			else if (mState == EIDLE){

				if (mACount < mFPS){
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
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharahear, frame - 64, frame + 64, 1024, 768);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharahear, frame + 64, frame - 64, 1024, 768);
				}
			}
			//���S
			else if (mState == EDEATH){
				if (mACountD < mFPS){
					mACountD++;
				}
				if (mACountD < 20){
					frame = 0;
				}
				else if (mACountD < 40){
					frame = 1;
				}
				else if (mACountD < 60){
					frame = 2;
				}
				else if (mACountD == 60){
					CGameOver::mpInstance->mIsGameOver = true;
					//mEnabled = false;
					mflag == true;
				}
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharahear, frame - 64, frame + 64, 1280, 1024);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharahear, frame + 64, frame - 64, 1280, 1024);
				}

			}
		}

		//�ʏ���
		else{
			//�ҋ@
			if (mState == EIDLE){

				if (mACount < mFPS){
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
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame - 64, frame + 64, 1024, 768);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame + 64, frame - 64, 1024, 768);
				}
			}
			//�U��
			 else if (mState == ESTRIKE){
				 
				if (mACountA < mFPS){
					mACountA++;
				}
				if (mACountA < 20){
					frame = 0;
				}
				else if (mACountA < 40){
					frame = 1;
				}
				else if (mACountA < 60){
					frame = 2;

				}
				else if (mACountA == 60){
					
					mflag = true;
					aflag = false;
					
				}
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame - 128, frame + 128, 512, 256);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame + 128, frame - 128, 512, 256);
				}

			}
			//�W�����v
			else  if (mState == EJUMP){
				if (mACount < mFPS){
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
				else if (mACount == 60){
					mACount = 0;
				}
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame - 64, frame + 64, 256, 0);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame + 64, frame - 64, 256, 0);
				}
			}

			//�ړ�
			else  if (mState == EMOVE){
				if (mACount < mFPS){
					mACount++;
				}
				if (mACount < 10){
					frame = 0;
				}
				else if (mACount < 20){
					frame = 1;

				}
				else if (mACount < 30){
					frame = 2;

				}
				else if (mACount < 40){
					frame = 3;

				}
				else if (mACount < 50){
					frame = 4;

				}
				else if (mACount < 60)
				{
					frame = 5;

				}
				else if (mACount == 60){
					mACount = 0;
				}
				//�E
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame - 64, frame + 64, 768, 512);
				}
				//��
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame + 64, frame - 64, 768, 512);
				}
			}
			
			//���S
			else if (mState == EDEATH){
				w = 64;
				if (mACountD < mFPS){
					mACountD++;
				}
				if (mACountD < 20){
					frame = 0;
				}
				else if (mACountD < 40){
					frame = 1;
				}
				else if (mACountD < 60){
					frame = 2;
				}
				else if (mACountD == 60){
					CGameOver::mpInstance->mIsGameOver = true;
		//			mEnabled = false;
					mflag == true;
				}
				if (mFx > 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame - 64, frame + 64, 1280, 1024);
				}
				else if (mFx < 0){
					frame = 128 + frame * 256;
					CRectangle::Render(mcharanormal, frame + 64, frame - 64, 1280, 1024);
				}
			}
			////�K�E�Z
			//else if (mState==EULT){
			//	
			//	if (mACountU < mFPS){
			//		mACountU++;
			//	}
			//	if (mACountU < 20){
			//		frame = 0;
			//	}
			//	else if (mACountU < 40){
			//		frame = 1;
			//	}
			//	else if (mACountU < 60){
			//		frame = 2;
			//	}
			//	else if (mACountU == 60){
			//		uflag = false;
			//		mflag = true;
			//		mState = EIDLE;
			//	}
			//	if (mFx > 0){
			//		frame = 128 + frame * 256;
			//		CRectangle::Render(mcharanormal, frame - 64, frame + 64, 1536, 1280);
			//	}
			//	else if (mFx < 0){
			//		frame = 128 + frame * 256;
			//		CRectangle::Render(mcharanormal, frame + 64, frame - 64, 1536, 1280);
			//	}
			//}

		}
	}
	if (mMode == ESTRONG){
		mRectMode.Render(mModeAttack, 0, 256, 256, 0);
	}
	else if (mMode == EHEAL){
		mRectMode.Render(mModeHeal, 0, 256, 256, 0);
	}
	else if (mMode == ENORMAL){
		mRectMode.Render(mModeNormal, 0, 256, 256, 0);
	}
}


	



