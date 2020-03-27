#ifndef CSLIMEENEMY_H
#define CSLIMEENEMY_H
//�G��{�N���X�̃C���N���[�h
#include"CEnemy.h"
//�l�p�`�N���X�̃C���N���[�h
//#include"CRectangle.h"
/*
�X���C���G�l�~�[�N���X
�X���C���̋@�\���`����
*/

class CSlimeEnemy : public CEnemy {
public:
	//��Ԃ̎��
	enum EStatus{
		EIDLE,   //�ҋ@���
		EMOVE,   //�ړ����
		EBURNATTACK, //�΂̋ʍU�����
		EDAMAGE, //��e���
		EDEATH,  //���ŏ��
	};
	static CSlimeEnemy*mpSlimeEnemy;

	EStatus mStatus;
	CTexture mSlime;

	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	int mFireCount; //�΂̋ʔ��ˊԊu
	int mHitPoint; //�̗�
	int mSlowMove; //�ړ��ʒ�
	int mMove;     //�ړ��ʕ�
	int mQuickMove; //�ړ��ʍ�
	int mDamage;  //��_���[�W
	int mUltDamagePlus; //�K�E�Z��_���[�W�W��

	int mACount;//�A�j���[�V�����̃J�E���g
	int mACountM;  //�A�j���[�V�������[�u
	int mACountB;  //�A�j���[�V�����΂̋�
	int mFps;   //�A�j���[�V������������

	bool mSearch; //�T�[�`
	bool mEnabled; //��������

	CSlimeEnemy(int Priority);

	void Update();
	bool Collision(const CRectangle &r);
	void Render();

	//�����ƓG�̓����蔻��
	void Collision(CRectangle *i, CRectangle *y);

	void CSlimeEnemy::Collision(CTask*task);
};
#endif