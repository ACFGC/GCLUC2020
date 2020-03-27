#include "CSceneTitle.h"
//OpenGL
#include "glut.h"
#include"Cvector.h"
#include "CKey.h"
#include "CRectangle.h"

#include "CTexture.h"



#define ARROWLITTLEMOVE_SPEED 0.17f
#define ARROWLITTLEMOVE_MOUNTAIN 6.0f//���_(�R)
#define ARROWLITTLEMOVE_VALLEY 0.0f  //���_(�J)
#define ARROWLITTLEMOVE_WAITTIME_MOUNTAIN 2
#define ARROWLITTLEMOVE_WAITTIME_VALLEY 9

#define CARSOL_MOVESPEED 20

#define FADEOUT_SPEED 0.02f


bool CSceneTitle::mIsFirst = true;

CTexture CSceneTitle::mTitleBackGround;
CTexture CSceneTitle::mTitleLogo;
CTexture CSceneTitle::mTitleStartButton;
CTexture CSceneTitle::mTitleInstButton;
CTexture CSceneTitle::mTitleCarsol;
CTexture CSceneTitle::mJunbi;

void CSceneTitle::Init() {
	//�V�[���̐ݒ�
	mScene = ETITLE;
	//�Q�[���N�����A�u���񂾂��v�^�C�g���f�ނ̓ǂݍ���
	if (mIsFirst){
		mTitleBackGround.Load("image\\UI\\game_title\\game_title_background.tga");
		mTitleLogo.Load("image\\UI\\game_title\\game_title.tga");
		mTitleStartButton.Load("image\\UI\\game_title\\GAME_START.tga");
		mTitleInstButton.Load("image\\UI\\game_title\\Method of operation.tga");
		mTitleCarsol.Load("image\\UI\\game_title\\Arrow.tga");
		mJunbi.Load("image\\UI\\game_title\\Methodofoperation_01.tga");
		mIsFirst = false;
	}
	mCarsol = 0;
	mSetsumei = false;

	//��ʓ��e�͈͂̐��l
	mLeft = 0; mRight = 1280;
	mTop = 720; mBottom = 0;

	//�^�C�g����ʂŕ`�悷�郍�S��{�^�����̏����ʒu�A�T�C�Y��ݒ肷��
	//����������̉��
	mSetsumeiScreen.x = 640; mSetsumeiScreen.y = 360;
	mSetsumeiScreen.w = 512; mSetsumeiScreen.h = 288;
	//�^�C�g����ʂ̔w�i
	mRectTBG.x = 640; mRectTBG.y = 360;
	mRectTBG.w = 640; mRectTBG.h = 360;
	//�^�C�g����ʂ̃��S
	mRectTL.x = 400; mRectTL.y = 535;
	mRectTL.w = 450; mRectTL.h = 225;
	//�^�C�g����ʂ̃X�^�[�g�{�^��
	mRectTSB.x = 400; mRectTSB.y = 300;
	mRectTSB.w = 256; mRectTSB.h = 64;
	//�^�C�g����ʂ̑�������{�^��
	mRectTIB.x = 400; mRectTIB.y = 150;
	mRectTIB.w = 256; mRectTIB.h = 64;
	//�^�C�g����ʂ̃J�[�\��
	mRectTC.x = 675; mRectTC.y = 375;
	mRectTC.w = 64; mRectTC.h = 64;
	//�t�F�[�h�A�E�g�p
	mFadeOut.x = 640; mFadeOut.y = 360;
	mFadeOut.w = 640; mFadeOut.h = 360;
	mFadeValue = 0.0f;

	mStartFlag = false;

	mArrowLittleMove = 0.0f;

	mArrowUpFlag = false;
	mArrowDownFlag = false;
	mArrowLittleMoveWaitTime = 5;

	mGetYforTC = 0;
	mIsMoveCarsol = false;
}

void CSceneTitle::Update() {
	//��ʓ��e�͈͕ύX
	//�s����v���W�F�N�V�������[�h�ύX
	glMatrixMode(GL_PROJECTION);

	//�s���������
	glLoadIdentity();

	//2D�̉�ʓ��e�͈͐ݒ�
	gluOrtho2D(mLeft, mRight, mBottom, mTop);

	//�s������f���r���[���[�h�֕ύX
	glMatrixMode(GL_MODELVIEW);

	//�s���������
	glLoadIdentity();


	if (mIsMoveCarsol == false){

		if (mArrowUpFlag){
			mArrowLittleMove += ARROWLITTLEMOVE_SPEED;
		}
		if (mArrowDownFlag){
			mArrowLittleMove -= ARROWLITTLEMOVE_SPEED;
		}
	}
	if (mArrowLittleMove <= ARROWLITTLEMOVE_VALLEY){
		mArrowDownFlag = false;
		if (mArrowLittleMoveWaitTime > 0){
			mArrowLittleMoveWaitTime--;
		}
		else{
			mArrowUpFlag = true;
			mArrowLittleMoveWaitTime = ARROWLITTLEMOVE_WAITTIME_VALLEY;
		}
	}
	else if (mArrowLittleMove >= ARROWLITTLEMOVE_MOUNTAIN){
		mArrowUpFlag = false;
		if (mArrowLittleMoveWaitTime > 0){
			mArrowLittleMoveWaitTime--;
		}
		else{
			mArrowDownFlag = true;
			mArrowLittleMoveWaitTime = ARROWLITTLEMOVE_WAITTIME_MOUNTAIN;
		}
	}


	//�X�^�[�g�������ꂽ��
	if (mStartFlag){
		//���S�ɈÓ]������
		if (mFadeValue > 1.0f){
			//���̃V�[���̓I�[�v�j���O
			mScene = EOPENING;
		}
		else{
			mFadeValue += FADEOUT_SPEED;
		}
	}

	//��ԏ�̍���(START�{�^��)
	if (mCarsol == 0){
		//Enter�L�[�����ŃI�[�v�j���O���n�܂�(�I�[�v�j���O��ʂɈڍs)
		if (CKey::Once(VK_RETURN)){
			mStartFlag = true;
		}
	}
	//�ォ���Ԗڂ̍���(�������)
	else if (mCarsol == 1){
		//Enter�L�[�����ő��������ʂ��J��
		if (CKey::Once(VK_RETURN)){
			//���������ʂ����ɊJ���Ă��鎞�͕���
			if (mSetsumei){
				mSetsumei = false;
			}
			//���������ʂ��J��
			else{
				mSetsumei = true;
			}
		}
	}

	if (CKey::Once(('W')) || CKey::Once('S')){
		//����������\�����̓J�[�\���ړ������ɐ�����ʂ����
		if (mSetsumei){
			mSetsumei = false;
		}
		else if (mCarsol == 0){
			mCarsol = 1;
		}
		else if (mCarsol == 1){
			mCarsol = 0;
		}
	}
	
	//�w�i�E���S�E�{�^��2�̕`��
	mRectTBG.Render(mTitleBackGround, 0, 1280, 720, 0);
	mRectTL.Render(mTitleLogo, 0, 1024, 512, 0);
	mRectTSB.Render(mTitleStartButton, 0, 512, 128, 0);
	mRectTIB.Render(mTitleInstButton, 0, 512, 128, 0);
	
	//�J�[�\���ړ����A���̒n�_�֊��炩�Ɉړ������鏈��
	if (mRectTC.y != mGetYforTC){
		mIsMoveCarsol = true;
		if (mRectTC.y > mGetYforTC){
			if (mRectTC.y - mGetYforTC >= CARSOL_MOVESPEED){
				mRectTC.y -= CARSOL_MOVESPEED;
			}
			//������
			else{
				if (mRectTC.y - mGetYforTC >= CARSOL_MOVESPEED / 6){
					mRectTC.y -= CARSOL_MOVESPEED / 6;
				}
				else{
					mRectTC.y--;
				}
			}
		}
		else{
			if (mGetYforTC - mRectTC.y >= CARSOL_MOVESPEED){
				mRectTC.y += CARSOL_MOVESPEED;
			}
			//������
			else{
				if (mGetYforTC - mRectTC.y >= CARSOL_MOVESPEED / 6){
					mRectTC.y += CARSOL_MOVESPEED / 6;
				}
				else{
					mRectTC.y++;
				}
			}
		}
	}
	else{
		mIsMoveCarsol = false;
	}
	//�J�[�\���̎��̒n�_��ݒ肷��
	mGetYforTC = 357 - mCarsol * 150 + mArrowLittleMove;
	//�J�[�\���̕`��
	mRectTC.Render(mTitleCarsol, 0, 128, 128, 0);
	
	

	//����������\�������
	if (mSetsumei){
		/*if (mSetsumeiScreen.w < 512){
			mSetsumeiScreen.w += 64;
		}
		if (mSetsumeiScreen.h < 288){
			mSetsumeiScreen.h += 36;
		}*/
		
		//������ʂ̕`��
		mSetsumeiScreen.Render(mJunbi, 0, 1280, 720, 0);
	}
	//else{
	//	if (mSetsumeiScreen.w > 0){
	//		mSetsumeiScreen.w -= 64;
	//	}
	//	if (mSetsumeiScreen.h > 0){
	//		mSetsumeiScreen.h -= 36;
	//	}
	//}
	////������ʂ̕`��
	//mSetsumeiScreen.Render(mJunbi, 0, 1280, 720, 0);
	
	//�A���t�@�u�����h��L��
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float c[] = { 0.0f, 0.0f, 0.0f, mFadeValue };
	glColor4fv(c);

	mFadeOut.Render();
	//�Ō�ɔ��F�ɖ߂�
	c[0] = c[1] = c[2] = c[3] = 1.0f;
	glColor4fv(c);

	//�A���t�@�u�����h�𖳌�
	glDisable(GL_BLEND);
}

void CSceneTitle::Render() {
	
}

//���̃V�[���̎擾
CScene::EScene CSceneTitle::GetNextScene(){
	return mScene;
}