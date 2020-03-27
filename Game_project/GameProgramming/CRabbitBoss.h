#ifndef CRABBITBOSS_H
#define CRABBITBOSS_H
//�G��{�N���X�̃C���N���[�h
#include"CEnemy.h"
//�l�p�`�N���X�̃C���N���[�h
#include"CRectangle.h"
/*
�e�{�X�N���X
�e�{�X�̋@�\���`����
*/

class CRabbitBoss : public CEnemy {
public:
	//��Ԃ̎��
	enum EStatus{
		EIDLE,   //�ҋ@���
		EMOVE,   //�ړ����
		EBURNATTACK, //�΂̋ʍU�����
		EDEATH,  //���ŏ��
		EVENOM,  //�ł��΂��A����������
	};
	EStatus mStatus;
	CTexture mRabbitIdle;
	CTexture mRabbitMove;
	CTexture mRabbitBurnAttack;
	CTexture mRabbitVenom;
	CTexture mRabbitDeath;

	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	int mFireCount; //�΂̋ʔ��ˊԊu
	int mHitPoint; //�̗�
	int mSlowMove; //�ړ��ʒ�
	int mMove;     //�ړ��ʕ�
	int mQuickMove; //�ړ��ʍ�
	int mDamage;  //��_���[�W
	int mUltDamagePlus; //�K�E�Z��_���[�W�W��
	int mACount;  //�A�j���[�V�����ҋ@
	int mACountM;  //�A�j���[�V�������[�u
	int mACountB;  //�A�j���[�V�����΂̋�
	int mACountD;  //�A�j���[�V������
	int mACountV;  //�A�j���[�V�����ōU��
	int mFps;   //�A�j���[�V������������

	bool mSearch; //�T�[�`
	bool mEnabled; //��������


	CRabbitBoss(int Priority);

	void Update();

	void Render();

	//�����ƓG�̓����蔻��
	void Collision(CTask*task);
};
#endif