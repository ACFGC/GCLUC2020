#ifndef CMISTRESS_H
#define CMISTRESS_H
//�G��{�N���X�̃C���N���[�h
#include"CEnemy.h"
//�l�p�`�N���X�̃C���N���[�h
#include"CRectangle.h"
/*
�X�̃{�X�N���X
�X�̃{�X�̋@�\���`����
*/

class CMistress : public CEnemy {
public:
	//��Ԃ̎��
	enum EStatus{
		EIDLE,   //�ҋ@���
		EMOVE,   //�ړ����
		EBURNATTACK, //�΂̋ʍU�����
		EDAMAGE, //��e���
		EDEATH,  //���ŏ��
		ESHADOWMIST, //���[�v���
		EWARPFIRST,  //���[�v����
	};
	static CMistress *mpMistress;

	EStatus mStatus;
	CTexture mMistressIdle;
	CTexture mMistressMove;
	CTexture mMistressWarp;
	CTexture mMistressMist;
	CTexture mMistressDeath;
	CTexture mMistressBurnAttack;

	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	int mFireCount; //�΂̋ʔ��ˊԊu
	int mHitPoint; //�̗�
	int mSlowMove; //�ړ��ʒ�
	int mMove;     //�ړ��ʕ�
	int mQuickMove; //�ړ��ʍ�
	int mDamage;  //��_���[�W
	int mUltDamagePlus; //�K�E�Z��_���[�W�W��
	int mACount;  //�A�j���[�V����
	int mACountM; //�A�j���[�V�������[�u
	int mACountW; //�A�j���[�V�������[�v
	int mACountSM; //�A�j���[�V�����~�X�g
	int mACountD; //�A�j���[�V������
	int mACountB;  //�A�j���[�V�����΂̋�

	int mFps;   //�A�j���[�V������������
	int mWarpTime; //���[�v�Ԋu
	int mWx;  //���[�v���W
	int mWy;  //���[�v���W

	bool mSearch; //�T�[�`
	bool mEnabled;  //��������

	CMistress(int Priority);

	void Update();
	
	void Render();

	//�����ƓG�̓����蔻��

	void Collision(CTask*task);
};
#endif