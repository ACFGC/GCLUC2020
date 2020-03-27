#include "CSceneGame.h"
#include "CKey.h"
//OpenGL
#include "glut.h"
#include"Cvector.h"
#include "CTaskManager.h"
#include "CRectangle.h"

//��ʉ���1280
//��ʏc��720
//CPlayer*mpPlayer;
void CSceneGame::Init() {

	mpInstance = this;

	mLeft = 0;
	mRight = 1280;
	mTop = 720;
	mBottom = 0;

	mCameramove = 3;
	mScene = EFOREST;

	CBurn::mBurnTexture.Load("image\\effect\\fire.tga");
	mforest1.Load("image\\bg_forest\\bg_forest_01.tga");
	mforest2.Load("image\\bg_forest\\bg_forest_02.tga");
	mforest3.Load("image\\bg_forest\\bg_forest_03.tga");
	mforest4.Load("image\\bg_forest\\bg_forest_sky.tga");


	mfrontdoor1.Load("image\\bg_forest\\mansion_02.tga");
	mfrontdoor2.Load("image\\bg_forest\\mansion_01.tga");

	mPillar1.Load("image\\bg_forest\\gate_01.tga");//��O
	mPillar2.Load("image\\bg_forest\\gate_02.tga");//����
	CPlayer*mPlayer = new CPlayer(3);

	mPlayer->x = 256;
	mPlayer->y = 256;
	mPlayer->z = mPlayer->y;


	mPlayer->mEnabled = true;


	CSlimeEnemy*mSlimeEnemy = new CSlimeEnemy(3);

	mSlimeEnemy->x = 400;
	mSlimeEnemy->y = 300;
	mSlimeEnemy->z = mSlimeEnemy->y;

	mSlimeEnemy->mEnabled = true;


	mSlimeEnemy = new CSlimeEnemy(3);

	mSlimeEnemy->x = 500;
	mSlimeEnemy->y = 400;
	mSlimeEnemy->z = mSlimeEnemy->y;

	mSlimeEnemy->mEnabled = true;


	mSlimeEnemy = new CSlimeEnemy(3);

	mSlimeEnemy->x = 800;
	mSlimeEnemy->y = 400;
	mSlimeEnemy->z = mSlimeEnemy->y;

	mSlimeEnemy->mEnabled = true;


	mSlimeEnemy = new CSlimeEnemy(3);

	mSlimeEnemy->x = 900;
	mSlimeEnemy->y = 300;
	mSlimeEnemy->z = mSlimeEnemy->y;

	mSlimeEnemy->mEnabled = true;


	CObject1 * mObjectF = new CObject1(2);  //�v���C���[���O

	mObjectF->x = 3690;
	mObjectF->y = 280;
	mObjectF->h = 300;
	mObjectF->w = 205;
	
	mObjectF->mEnabled = true;

	

	CObject2 * mObjectP = new CObject2(2);  //�v���C���[���O

	mObjectP->x = 3470;
	mObjectP->y = 100;
	mObjectP->h = 100;
	mObjectP->w = 45;

	mObjectP->mEnabled = true;

	
	
	CThroughObject1 * mThroughObjenameF = new CThroughObject1(4);  //�v���C���[����

	mThroughObjenameF->x =3645;
	mThroughObjenameF->y = 290;
	mThroughObjenameF->h = 280;
	mThroughObjenameF->w = 190;

	mThroughObjenameF->mEnabled = true;

	
	
	CThroughObject2 * mThroughObjenameP = new CThroughObject2(4);  //�v���C���[����

	mThroughObjenameP->x = 3405;
	mThroughObjenameP->y = 225;
	mThroughObjenameP->h = 80;
	mThroughObjenameP->w = 30;

	mThroughObjenameP->mEnabled = true;

		
	CMistress*mpMistress = new CMistress(3);

	mpMistress->x = 3700;
	mpMistress->y = 400;
	mpMistress->z = mpMistress->y;


	CHPBar *HPBar = new CHPBar(1);
	HPBar->x = 300 + mLeft, HPBar->y = 660 + mBottom;


	CGameOver *GameOver = new CGameOver(-1);
	GameOver->mEnabled = true;
}

void CSceneGame::Update() {


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

	if (CMistress::mpMistress->mHitPoint==700){
		if (CMistress::mpMistress->mHitPoint==350){

	//	mLeft = CMistress::mpMistress->x - 500;
	//	mRight = CMistress::mpMistress->x + 500;

	//	if (CMistress::mpMistress->x > 3860){

	//		mLeft = CPlayer::mpPlayer->x - 200;
	//		mRight = CPlayer::mpPlayer->x + 1080;

		}


	}

	
	
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

	//���_�̐ݒ�
	//gluLookAt(���_X, ���_Y, ���_Z, ���SX, ���SY, ���SZ, ���X, ���Y, ���Z�j
	//gluLookAt(1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	


	//�e�N�X�`���g�p�\
	glEnable(GL_TEXTURE_2D);

	//�e�N�X�`�����o�C���h
	glBindTexture(GL_TEXTURE_2D, mforest4.mId);
	//�A���t�@�u�����h��L��

	glEnable(GL_BLEND);

	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//�`��J�n
	glBegin(GL_QUADS);

	//��
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f, 750.0f, 0.0f);
	v1.Set(0.0f, 750.0f, 0.0f);
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

	//��񖇖�
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f + 1280.0, 750.0f, 0.0f);
	v1.Set(1280.0f, 750.0f, 0.0f);
	v2.Set(1280.0f, 0.0f, 0.0f);
	v3.Set(1280.0f + 1280.0, 0.0f, 0.0f);

	//�l�p�`�̕`��
	glTexCoord2f(0.1f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(0.1f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);


	//�`��I��
	glEnd();


	//�`��J�n
	glBegin(GL_QUADS);

	//��O����
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f+1280.0+1280.0, 750.0f, 0.0f);
	v1.Set(1280.0f+1280.0, 750.0f, 0.0f);
	v2.Set(1280.0f+1280.0, 0.0f, 0.0f);
	v3.Set(1280.0f+1280.0+1280.0, 0.0f, 0.0f);

	//�l�p�`�̕`��
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.1, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.1f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//�`��I��
	glEnd();


	//�e�N�X�`���̃o�C���h������
	glBindTexture(GL_TEXTURE_2D, 0);


	//�e�N�X�`�����o�C���h
	glBindTexture(GL_TEXTURE_2D, mforest3.mId);


	//�`��J�n
	glBegin(GL_QUADS);

	//�w�i�F���̐X
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280+mRight/1.07, mBottom-100, 0.0f);
	v1.Set(1280+mRight/1.07, mTop+100, 0.0f);
	v2.Set(mLeft/1.02, mTop+100, 0.0f);
	v3.Set(mLeft/1.02, mBottom-100, 0.0f);

	glTexCoord2f(1.0, 0.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);


	//�`��I��
	glEnd();

	//�e�N�X�`���̃o�C���h������
	glBindTexture(GL_TEXTURE_2D, 0);


	//�e�N�X�`�����o�C���h
	glBindTexture(GL_TEXTURE_2D, mforest2.mId);


	//�`��J�n
	glBegin(GL_QUADS);

	//�w�i�F�����̐X
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280+mRight/1.1, mBottom-100, 0.0f);
	v1.Set(1280+mRight/1.1, mTop+100, 0.0f);
	v2.Set(mLeft/1.07, mTop+100, 0.0f);
	v3.Set(mLeft/1.07, mBottom-100, 0.0f);


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


	//�e�N�X�`���̃o�C���h������
	glBindTexture(GL_TEXTURE_2D, 0);


	//�e�N�X�`�����o�C���h
	glBindTexture(GL_TEXTURE_2D, mforest1.mId);


	//�`��J�n
	glBegin(GL_QUADS);

	//��O�̐X�A�n��1
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f, -160.0f, 0.0f);
	v1.Set(1280.0f, 720.0f, 0.0f);
	v2.Set(0.0f, 720.0f, 0.0f);
	v3.Set(0.0f, -160, 0.0f);

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


	//�`��J�n
	glBegin(GL_QUADS);

	//��O�̐X�A�n��2
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f+1280.0, -160.0f, 0.0f);
	v1.Set(1280.0f + 1280.0, 720.0f, 0.0f);
	v2.Set(0.0f+1280.0, 720.0f, 0.0f);
	v3.Set(0.0f+1280.0, -160.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//�`��I��
	glEnd();

	//�`��J�n
	glBegin(GL_QUADS);

	//��O�̐X�A�n��3
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f + 1280.0 + 1280.0, -160.0f, 0.0f);
	v1.Set(1280.0f + 1280.0 + 1280.0, 720.0f, 0.0f);
	v2.Set(0.0f + 1280.0 + 1280.0, 720.0f, 0.0f);
	v3.Set(0.0f + 1280.0 + 1280.0, -160.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(1.0f, 1.0f);
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


	if (CPlayer::mpPlayer->x >3740){
		TaskManager.AllDisable();
	    CPlayer::mpPlayer->mEnabled = true;
		CHPBar::mpInstance->mEnabled = true;
		CGameOver::mpInstance->mEnabled = true;
		CShadow::mpInstanceS->mEnabled=true;
		mScene = EMANSION;
		
	}

	if (CPlayer::mpPlayer->mEnabled == false){

		mScene = ETITLE;

	}



	TaskManager.Update();
	TaskManager.Collision();
	TaskManager.Delete();
	TaskManager.Render();

	if (CGameOver::mpInstance->mIsGameOver){
		if (CKey::Once(VK_RETURN)){
			//���g���C
			if (CGameOver::mpInstance->mCarsol == 0){
				mScene = EFOREST;
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
