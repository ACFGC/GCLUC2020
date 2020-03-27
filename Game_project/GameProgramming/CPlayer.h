#ifndef CPLAYER_H
#define CPLAYER_H

#include"CRectangle.h"
#include"Cvector.h"
#include "CScene.h"



class CPlayer:public CRectangle{
public:

	enum EState{
		
		
		EMOVE,//�ړ�
		EIDLE,//�ҋ@
		ESTRIKE,//�U��
		EJUMP,//�W�����v
		EULT,//�K�E�Z
		EDEATH//����

	};
	EState mState;

	enum EMode{
		ENORMAL,//�ʏ���
		ESTRONG,//�U�����
		EHEAL,//�񕜏��
		
	};
	EMode mMode;
	static CPlayer*mpPlayer;
	static CTexture mcharaatk;
	static CTexture mcharahear;
	static CTexture mcharanormal;
	static CTexture mModeAttack;
	static CTexture mModeHeal;
	static CTexture mModeNormal;

	CRectangle mRectMode;
	
	CPlayer(int Priority);
	int mACount;//�A�j���[�V�����̃J�E���g
	int mACountA;//�A�j���[�V�����̃J�E���g�̍U��
	int mACountD;//�A�j���[�V�����̃J�E���g�̎�
	int mACountU;//�A�j���[�V�����̃J�E���g�̕K�E�Z
	int mPhp;//�v���C���[��HP
	int mPHPM;//�v���C���[�̂�������HP
	int mSpecialGauge;//�K�E�Z�̃Q�[�W
	int mSpecialGaugeMax;//�K�E�Z�̃Q�[�W�ő�l
	int mDamage;//�_���[�W
	int mHealNumber;//�񕜒l
	int mmove;   //�ړ���
	int mSpeed;  //���x
	int mAttackCount;//�U���̃J�E���g
	int mHealCount;  //�񕜂̃J�E���g
	int mCount;//�J�E���g
	float my_prev;//�O��y
	bool jflag = false; //�W�����v�t���O
	bool aflag = false;//�U���t���O
	bool mflag = true;//���t���O
	bool uflag = false;//�K�E�Z�t���O
	int mJumpPower; //�W�����v�p���[
    float mFPS ;  //1�t���[��
	float mGRAVITY; //�d��
	
	int mFx, mFy;//����

	
	float mDistantTime;
	void Update();

	void Render();

	void Collision(CTask*task);//�����蔻��

	
};
#endif