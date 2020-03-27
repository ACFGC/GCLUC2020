#include "CSceneGame.h"
#include "CKey.h"
//OpenGL
#include "glut.h"
#include"Cvector.h"
#include "CTaskManager.h"
#include "CRectangle.h"


void CSceneGame_Mansion::Init() {

	mpInstance = this;
	mpInstanceS = this;

	mLeft = 0;
	mRight = 1280;
	mTop = 720;
	mBottom = 0;

	mCameramove = 3;
	mScene = EMANSION;
	CBurn::mBurnTexture.Load("image\\effect\\fire.tga");

	mMansion1.Load("image\\bg_mansion\\bg_mansion_.tga");

	mMansion2.Load("image\\bg_mansion\\bg_mansion_02.tga");

	mMansionsky.Load("image\\bg_mansion\\bg_mansion_sky.tga");


	//CPlayer*mPlayer = new CPlayer(3);

	CPlayer::mpPlayer->x = 256;
	CPlayer::mpPlayer->y = 256;
	CPlayer::mpPlayer->z = CPlayer::mpPlayer->y;

	CCandle*mCandle = new CCandle(5);

	mCandle->x = 410;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;

	CCandleL*mCandleL = new CCandleL(4);

	mCandleL->x = 410;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;

	mCandle = new CCandle(5);

	mCandle->x = 820;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;


	mCandleL = new CCandleL(4);

	mCandleL->x = 820;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;


	mCandle = new CCandle(5);

	mCandle->x = 1200;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;


	mCandleL = new CCandleL(4);

	mCandleL->x = 1200;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;


	mCandle = new CCandle(5);

	mCandle->x = 1700;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;

	mCandleL = new CCandleL(4);

	mCandleL->x = 1700;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;

	mCandle = new CCandle(5);

	mCandle->x = 2100;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;


	mCandleL = new CCandleL(4);

	mCandleL->x = 2100;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;

	mCandle = new CCandle(5);

	mCandle->x = 2480;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;

	mCandleL = new CCandleL(4);

	mCandleL->x = 2480;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;

	CSlimeEnemy*mSlimeEnemy = new CSlimeEnemy(3);

	mSlimeEnemy->x = 400;
	mSlimeEnemy->y = 300;
	mSlimeEnemy->z = mSlimeEnemy->y;

	mSlimeEnemy->mEnabled = true;


	CCatEnemy*mCatEnemy = new CCatEnemy(3);

	mCatEnemy->x = 600;
	mCatEnemy->y = 300;
	mCatEnemy->z = mCatEnemy->y;
	mCatEnemy->mEnabled = true;


	CMistress::mpMistress->x = 3700;
	CMistress::mpMistress->y = 400;
	CMistress::mpMistress->h = 192;
	CMistress::mpMistress->w = 192;
	CMistress::mpMistress->z = CMistress::mpMistress->y;

	
}

void CSceneGame_Mansion::Update(){

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

	mLeft = CPlayer::mpPlayer->x - 200;
	mRight = CPlayer::mpPlayer->x + 1080;
	if (mLeft < 0){

		mLeft = 0;
		mRight = 1280;

	}

	if (mRight>3840){

		mLeft = 2560;
		mRight = 3840;

	}



	CVector v0, v1, v2, v3, n;


	//�e�N�X�`���g�p�\
	glEnable(GL_TEXTURE_2D);

	//�e�N�X�`�����o�C���h
	glBindTexture(GL_TEXTURE_2D, mMansionsky.mId);

	//�A���t�@�u�����h��L��
	glEnable(GL_BLEND);

	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//�`��J�n
	glBegin(GL_QUADS);

	//���̌i�F
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280+mRight/1.07, mBottom, 0.0f);
	v1.Set(1280+mRight/1.07, mTop, 0.0f);
	v2.Set(mLeft/1.02,mTop, 0.0f);
	v3.Set(mLeft/1.02, mBottom, 0.0f);

	//�l�p�`�̕`��
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//�`��I��
	glEnd();

	//�A���t�@�u�����h����
	glDisable(GL_BLEND);

	//�e�N�X�`���̃o�C���h������
	glBindTexture(GL_TEXTURE_2D, 0);



	//�e�N�X�`�����o�C���h
	glBindTexture(GL_TEXTURE_2D, mMansion1.mId);

	//�A���t�@�u�����h��L��
	glEnable(GL_BLEND);

	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//�`��J�n
	glBegin(GL_QUADS);

	//�}���V����F1�F1����
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f, 720.0f, 0.0f);
	v1.Set(0.0f, 720.0f, 0.0f);
	v2.Set(0.0f, 0.0f, 0.0f);
	v3.Set(1280.0f, 00.0f, 0.0f);

	//�l�p�`�̕`��
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//�`��I��
	glEnd();


	//�`��J�n
	glBegin(GL_QUADS);

	//�}���V����F1�F2����
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f+1280, 720.0f, 0.0f);
	v1.Set(1280.0f, 720.0f, 0.0f);
	v2.Set(1280.0f, 0.0f, 0.0f);
	v3.Set(1280.0f+1280, 00.0f, 0.0f);

	//�l�p�`�̕`��
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);


	//�`��I��
	glEnd();

	//�A���t�@�u�����h����
	glDisable(GL_BLEND);

	//�e�N�X�`���̃o�C���h������
	glBindTexture(GL_TEXTURE_2D, 0);



	//�e�N�X�`�����o�C���h
	glBindTexture(GL_TEXTURE_2D, mMansion2.mId);

	//�A���t�@�u�����h��L��
	glEnable(GL_BLEND);

	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//�`��J�n
	glBegin(GL_QUADS);

	//�}���V����F1�F3����
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f+1280+1280, 720.0f, 0.0f);
	v1.Set(1280.0f+1280, 720.0f, 0.0f);
	v2.Set(1280.0f+1280, 0.0f, 0.0f);
	v3.Set(1280.0f+1280+1280, 00.0f, 0.0f);

	//�l�p�`�̕`��
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//�`��I��
	glEnd();

	//�A���t�@�u�����h����
	glDisable(GL_BLEND);
	//�e�N�X�`���̃o�C���h������
	glBindTexture(GL_TEXTURE_2D, 0);
	//�e�N�X�`���𖳌�
	glDisable(GL_TEXTURE_2D);


	if (CPlayer::mpPlayer->x >3500&&CPlayer::mpPlayer->y>200){
		TaskManager.AllDisable();
		CPlayer::mpPlayer->mEnabled = true;
		CHPBar::mpInstance->mEnabled = true;
		CGameOver::mpInstance->mEnabled = true;
		CShadow::mpInstanceS->mEnabled = true;
		mScene = EMANSIONF2;

	}


	TaskManager.Update();
	TaskManager.Collision();
	TaskManager.Delete();
	TaskManager.Render();

	if (CGameOver::mpInstance->mIsGameOver){
		if (CKey::Once(VK_RETURN)){
			//���g���C
			if (CGameOver::mpInstance->mCarsol == 0){

			}
			//�^�C�g����ʂ�
			else if (CGameOver::mpInstance->mCarsol == 1){
				mScene = ETITLE;
			}
		}
		if (CGameOver::mpInstance->mTitleBackTime <= 0){
			mScene = ETITLE;
		}
	}


}