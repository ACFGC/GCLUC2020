#ifndef CCATENEMY_H
#define CCATENEMY_H
//�G��{�N���X�̃C���N���[�h
#include"CEnemy.h"
//�l�p�`�N���X�̃C���N���[�h
#include"CRectangle.h"
/*
�L���b�g�G�l�~�[�N���X
�L���b�g�̋@�\���`����
*/

class CCatEnemy : public CEnemy {
public:
	//��Ԃ̎��
	enum EStatus{
		EIDLE,   //�ҋ@���
		EMOVE,   //�ړ����
		EBURNATTACK, //�΂̋ʍU�����
		EDAMAGE, //��e���
		EDEATH,  //���ŏ��
		EJUNP,   //�W�����v���
		EBIND,   //�S���U����ԁA�L
	};
	static CCatEnemy*mpCatEnemy;

	EStatus mStatus;
	CTexture mCatIdle;
	CTexture mCatBind;

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
	int mFps;   //�A�j���[�V������������

	bool mSearch; //�T�[�`
	bool mEnabled; //��������


	CCatEnemy(int Priority);

	void Update();
	
	void Render();

	//�����ƓG�̓����蔻��
	
	void Collision(CTask*task);
};
#endif