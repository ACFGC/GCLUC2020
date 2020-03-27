#ifndef CSCENEOPENING_H
#define CSCENEOPENING_H
#include "CScene.h"
#include "CKey.h"
#include <Windows.h>
#include "CRectangle.h"
/*
�Q�[���̃V�[��
*/
class CSceneOpening : public CScene{
public:
	//OP��ʂ̔w�i
	CTexture mOPBackGround;
	//OP�̃X�g�[���[
	CTexture mOPStory1;
	CTexture mOPStory2;
	CTexture mOPStory3;
	CTexture mOPStory4;
	CTexture mOPStory5;

	//��ʈÓ]�p
	CRectangle mRectFade;
	//��ʂ��Ó]��������x�����߂�ϐ�
	float mScreenFadeValue;
	//��ʂ̃t�F�[�h�C���E�A�E�g�p�̃t���O
	bool mScreenFadeIn;
	bool mScreenFadeOut;

	//�����̓����x�����߂�ϐ�
	float mStoryFadeValue;
	//�����̃t�F�[�h�C���E�A�E�g�p�̃t���O
	bool mStoryFadeIn;
	bool mStoryFadeOut;
	//�������v���C���[�ɓǂ܂��鎞��
	int mStoryReadTime;
	//���������S�ɕ\���������L���ɂȂ�t���O
	bool mStoryShowing;

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//���̃V�[���̎擾
	EScene GetNextScene();

	//OP��ʂ̔w�i
	CRectangle mRecOPBackGround;
	//OP��ʂ̎���
	CRectangle mRecOPStory;


	//���݂̃y�[�W
	int mCurrentPage;
	//���̃y�[�W�ɍs���܂ł̎���
	int mTimeCount;

};

#endif
