#ifndef CBURN_H
#define CBURN_H

#include "CRectangle.h"

/*
CBurn
�΂̋ʃN���X
CRectangle�N���X���p������
�e�FCRectangle�N���X
�q�FCBurn�N���X
*/
class CBurn : public CRectangle {
public:
	int mFx, mFy;	//�ړ���
	int mFireCount; //��������
	int mACount;   //�A�j���[�V����
	int mFps;

static	CTexture mBurnTexture;
	//�f�t�H���g�R���X�g���N�^
	CBurn(int Priority);
	//�X�V����
	void Update();

	//�`�揈��
	void Render();

	//36
	//void Collision(CRectangle *i, CRectangle *y);
	void Collision(CTask*task);//�����蔻��
};

#endif