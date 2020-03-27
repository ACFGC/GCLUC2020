#ifndef CLASTMYF_H
#define CLASTMYF_H
//�G��{�N���X�̃C���N���[�h
#include"CEnemy.h"
//�l�p�`�N���X�̃C���N���[�h
#include"CRectangle.h"
#include"CBossDeathBlow.h" //�{�X�K�E�C���N���[�h
/*
���X�{�X�N���X
���X�{�X�̋@�\���`����
*/

class CLastMyF : public CEnemy {
public:
	//��Ԃ̎��
	enum EStatus{
		EIDLE,   //�ҋ@���
		EBURNATTACK, //�΂̋ʍU�����
		EDEATH,  //���ŏ��
		EBOSSDEATHBLOW,//���͈͍U��,  �΂�����ɔ�юU��A���X�{�X
	};
	EStatus mStatus;
	CTexture mLastBossIdle;
	CTexture mLastBossMove;
	CTexture mLastBossBurnAttack;
	CTexture mLastBossDeathBlow;
	CTexture mLastBossDeath;

	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	int mFireCount; //�΂̋ʔ��ˊԊu
	int mDeathBlow; //�K�E�Z���ˊԊu
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
	int mACountK;  //�A�j���[�V�����K�E
	int mFps;   //�A�j���[�V������������

	bool mSearch; //�T�[�`
	bool mEnabled; //��������


	CLastMyF(int Priority);

	void Update();

	void Render();

	//�����ƓG�̓����蔻��
	void Collision(CTask*task);
};
#endif