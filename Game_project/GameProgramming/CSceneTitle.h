#ifndef CSCENETITLE_H
#define CSCENETITLE_H
#include "CScene.h"
#include "CKey.h"
#include <Windows.h>
#include "CRectangle.h"

#include "CHPBar.h"
/*
�Q�[���̃V�[��
*/
class CSceneTitle : public CScene{
public:
	//��ʓ��e�͈͂̕ϐ�
	int mLeft, mRight, mBottom, mTop;

	//�^�C�g����ʂ̔w�i
	static CTexture mTitleBackGround;
	//�^�C�g����ʂ̃��S
	static CTexture mTitleLogo;
	//�^�C�g����ʂ̃X�^�[�g�{�^��
	static CTexture mTitleStartButton;
	//�^�C�g����ʂ̑�������{�^��
	static CTexture mTitleInstButton;
	//�^�C�g����ʂ̃J�[�\��
	static CTexture mTitleCarsol;
	//�^�C�g����ʂ̑���������
	static CTexture mJunbi;

	
	//���̃V�[���̎擾
	EScene GetNextScene();

	CRectangle mRectTBG;//�w�i
	CRectangle mRectTL; //�^�C�g�����S
	CRectangle mRectTSB;//Start�{�^��
	CRectangle mRectTIB;//��������{�^��
	CRectangle mRectTC; //�J�[�\��

	//�J�[�\���̖ړI�n(Y���W)
	int mGetYforTC;
	//�J�[�\�����ړ����̂ݗL���ɂȂ�
	bool mIsMoveCarsol;

	//�J�[�\���̂�����Ƃ��������̕ω���
	float mArrowLittleMove;
	//������Ƃ��������̏㏸�E���~�̃t���O
	bool mArrowUpFlag;
	bool mArrowDownFlag;
	//������Ƃ��������̒��_�ɗ����Ă��鎞��
	int mArrowLittleMoveWaitTime;

	//��ʈÓ]�p
	CRectangle mFadeOut;
	//�Ó]��������x�����߂�ϐ�
	float mFadeValue;

	//������ʂ̕`��p
	CRectangle mSetsumeiScreen;

	//�^�C�g����ʂ̃J�[�\���̈ʒu�Ɋւ���ϐ�
	int mCarsol;
	//���������ʂ��J���Ă��邩�ǂ��������߂�ϐ�
	bool mSetsumei;
	//���񂩂ǂ������肷��ϐ�
	static bool mIsFirst;
	//�X�^�[�g�{�^���������ƗL���ɂȂ�
	bool mStartFlag;

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//�`�揈���̃I�[�o�[���C�h
	void Render();
};

#endif
