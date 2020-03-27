#ifndef CDUMMYENEMY_H
#define CDUMMYENEMY_H
//�G��{�N���X�̃C���N���[�h
#include"CEnemy.h"
//�l�p�`�N���X�̃C���N���[�h
#include"CRectangle.h"
#include"CPlayer.h"
/*
�_�~�[�G�l�~�[�N���X
�_�~�[�̋@�\���`����
*/

class CDummyEnemy : public CEnemy {
public:
	//��Ԃ̎��
	enum EStatus{
		EIDLE,   //�ҋ@���
		EBURNATTACK, //�΂̋ʍU�����
		EDUMMY,//�_�~�[�U�����
		
	};
	static CDummyEnemy*mpDummyEnemy;

	EStatus mStatus;
	CTexture mDummyIdle;
	CTexture mDummyBurnAttack;
	CTexture mDummyDummy;
	CTexture mDummyPlayer;

	int mFireCount; //�΂̋ʔ��ˊԊu
	int mHitPoint; //�̗�
	int mDamage;  //��_���[�W
	int mUltDamagePlus; //�K�E�Z��_���[�W�W��

	int mACount;//�A�j���[�V�����̃J�E���g
	int mACountB;//�A�j���[�V�����̃J�E���g�΂̋�
	int mACountD;//�A�j���[�V�����̃J�E���g�_�~�[
	int mACountDP;//�A�j���[�V�����̃J�E���g�_�~�[�ϐg��
	int mFps;   //�A�j���[�V������������

	bool mSearch; //�T�[�`
	bool mEnabled; //��������

	CDummyEnemy(int Priority);

	void Update();
	bool Collision(const CRectangle &r);
	void Render();


	void CDummyEnemy::Collision(CTask*task);
};
#endif