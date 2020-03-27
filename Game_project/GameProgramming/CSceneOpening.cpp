#include "CSceneOpening.h"
//OpenGL
#include "glut.h"
#include"Cvector.h"
#include "CKey.h"
#include "CRectangle.h"

#include "CTexture.h"

#define TOTALPAGE 5
#define READTIME1P 240
#define READTIME2P 320
#define READTIME3P 510
#define READTIME4P 310
#define READTIME5P 560
#define FADE_PER_FRAME 0.017f

void CSceneOpening::Init() {
	//�V�[���̐ݒ�
	mScene = EOPENING;
	//OP��ʁE�w�i�E�����̃e�N�X�`���ǂݍ���
	mOPBackGround.Load("image\\UI\\story\\story haikei.tga");
	mOPStory1.Load("image\\UI\\story\\story_01.tga");
	mOPStory2.Load("image\\UI\\story\\story_02.tga");
	mOPStory3.Load("image\\UI\\story\\story_03.tga");
	mOPStory4.Load("image\\UI\\story\\story_04.tga");
	mOPStory5.Load("image\\UI\\story\\story_05.tga");

	mCurrentPage = 0;
	mTimeCount = 1;

	mRecOPBackGround.x = 640; mRecOPBackGround.y = 360;
	mRecOPBackGround.w = 640; mRecOPBackGround.h = 360;
	
	mRecOPStory.x = 640; mRecOPStory.y = 360;
	mRecOPStory.w = 512; mRecOPStory.h = 64;

	mRectFade.x = 640; mRectFade.y = 360;
	mRectFade.w = 640; mRectFade.h = 360;
	mScreenFadeValue = 1.0f;
	mScreenFadeIn = true;
	mScreenFadeOut = false;
	mStoryFadeIn = false;
	mStoryFadeOut = false;
	mStoryFadeValue = 0.0f;

	mStoryReadTime = 0;
	
	mStoryShowing = false;
}

void CSceneOpening::Update() {
	//��ʂ̃t�F�[�h�C���̏���
	if (mScreenFadeIn){
		//�܂����S�ɕ\������ĂȂ���
		if (mScreenFadeValue > 0.0f){
			mScreenFadeValue -= FADE_PER_FRAME;
		}
		else{
			mScreenFadeIn = false;
		}
	}
	//��ʂ̃t�F�[�h�A�E�g�̏���
	if (mScreenFadeOut){
		//���S�ɈÓ]������
		if (mScreenFadeValue > 1.0f){
			//���̃V�[���ŃQ�[����ʂɓ���
			mScene = EFOREST;
		}
		//���X�ɈÂ��Ȃ�
		else{
			mScreenFadeValue += FADE_PER_FRAME;
		}
	}
	//�����̃t�F�[�h�C���̏���
	if (mStoryFadeIn){
		if (mStoryFadeValue < 1.0f){
			mStoryFadeValue += FADE_PER_FRAME;
		}
		else{
			mStoryFadeIn = false;
			if (mCurrentPage != TOTALPAGE){
				mStoryShowing = true;
			}
		}
	}
	//�����̃t�F�[�h�A�E�g�̏���
	if (mStoryFadeOut){
		if (mStoryFadeValue > 0.0f){
			mStoryFadeValue -= FADE_PER_FRAME;
		}
		else{
			mStoryFadeOut = false;
			mTimeCount = 9;
		}
	}

	if (mTimeCount > 0){
		if (mScreenFadeIn == false){
			mTimeCount--;
		}
	}
	else{
		//mStoryFadeOut = true;
	}


	if (mStoryShowing){
		if (mStoryReadTime <= 0){
			mStoryFadeOut = true;
			mStoryShowing = false;
		}
		else{
			mStoryReadTime--;
		}
	}


	
	mRecOPBackGround.Render(mOPBackGround, 0, 1280, 720, 0);
		
	
	//Enter�L�[��OP���X�L�b�v
	if (CKey::Once(VK_RETURN)){
		mStoryFadeIn = false;
		mScreenFadeIn = false;
		mScreenFadeOut = true;
	}

	if (mTimeCount <= 0){
		//�Ō�̃y�[�W�̌�A�t�F�[�h�A�E�g���n�܂�
		if (mCurrentPage == TOTALPAGE){
			mScreenFadeOut = true;
		}
		//��������Ȃ����͎��̃y�[�W��
		else{
			mCurrentPage++;
			//���H�H�H�H�H
			mTimeCount = 999;
			mStoryFadeIn = true;
			
			//���̎�����\�����鎞�Ԃ�ݒ肷��
			if (mCurrentPage == 1){
				mStoryReadTime = READTIME1P;
			}
			else if (mCurrentPage == 2){
				mStoryReadTime = READTIME2P;
			}
			else if (mCurrentPage == 3){
				mStoryReadTime = READTIME3P;
			}
			else if (mCurrentPage == 4){
				mStoryReadTime = READTIME4P;
			}
			else if (mCurrentPage == TOTALPAGE){
				mTimeCount = READTIME5P;
			}
		}
	}

	//�A���t�@�u�����h��L��
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float c[] = { 1.0f, 1.0f, 1.0f, mStoryFadeValue };
	glColor4fv(c);

	if (mCurrentPage == 1){
		mRecOPStory.Render(mOPStory1, 0, 1024, 128, 0);
	}
	else if (mCurrentPage == 2){
		mRecOPStory.Render(mOPStory2, 0, 1024, 128, 0);
	}
	else if (mCurrentPage == 3){
		mRecOPStory.Render(mOPStory3, 0, 1024, 128, 0);
	}
	else if (mCurrentPage == 4){
		mRecOPStory.Render(mOPStory4, 0, 1024, 128, 0);
	}
	else if (mCurrentPage == 5){
		mRecOPStory.Render(mOPStory5, 0, 1024, 128, 0);
	}
	
	//�Ō�ɔ��F�ɖ߂�
	c[0] = c[1] = c[2] = c[3] = 1.0f;
	glColor4fv(c);

	//�A���t�@�u�����h�𖳌�
	glDisable(GL_BLEND);



	//�A���t�@�u�����h��L��
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float cf[] = { 0.0f, 0.0f, 0.0f, mScreenFadeValue };
	glColor4fv(cf);

	mRectFade.Render();
	//�Ō�ɔ��F�ɖ߂�
	cf[0] = cf[1] = cf[2] = cf[3] = 1.0f;
	glColor4fv(cf);

	//�A���t�@�u�����h�𖳌�
	glDisable(GL_BLEND);
	
}

//���̃V�[���̎擾
CScene::EScene CSceneOpening::GetNextScene(){
	return mScene;
}