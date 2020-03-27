#ifndef CENEMY_H
#define CENEMY_H
//�l�p�`�N���X�̃C���N���[�h
#include"CRectangle.h"
//�^�X�N�N���X�̃C���N���[�h
#include"CTask.h"
//�o�[���̃N���X�̃C���N���[�h
#include"CBurn.h"
/*
�G�l�~�[�N���X
�G�̊�{�I�ȋ@�\���`����
*/


class CEnemy : public CRectangle {
public:
	//��Ԃ̎��
	enum EStatus{
		EIDLE,   //�ҋ@���
		EMOVE,   //�ړ����
		EBOSSMOVE,  //�{�X�ړ����
		EBURNATTACK, //�΂̋ʍU�����
		EDAMAGE, //��e���
		EDEATH,  //���ŏ��
		EJUNP,   //�W�����v���
		EBIND,   //�S���U����ԁA�L
		EPLAYINGDEAD,  //���񂾂ӂ��ԁA�}���I�l�b�g
		EMEEXPLOSION,  //������ԁA�˂�������
		EDUMMY,  //�v���C���[�̌����ڂɂȂ�A������
		ESHADOWMIST,   //���A�e����o�Ă���A�X�̃{�X
		EVENOM,  //�ł��΂��A����������
		EBOSSDEATHBLOW,//���͈͍U��,  �΂�����ɔ�юU��A���X�{�X
	};
	EStatus mStatus;

	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	int mFireCount; //�΂̋ʔ��ˊԊu
	int mHitPoint; //�̗�
	int mSlowMove; //�ړ��ʒ�
	int mMove;     //�ړ��ʕ�
	int mQuickMove; //�ړ��ʍ�
	int mDamage;  //��_���[�W
	int mUltDamagePlus; //�K�E�Z�W��
	int mBurnSpeed; //�΂̋ʑ��x
	int mBurnSpeedB; //�΂̋ʑ��x

	bool mSearch; //�T�[�`
	bool mEnabled; //��������

	CEnemy(int Priority);

	void Update();
	bool Collision(const CRectangle &r);
	void Render();

	//�����ƓG�̓����蔻��
	void Collision(CRectangle *i, CRectangle *y);
	void Collision(CTask*task);
};
#endif