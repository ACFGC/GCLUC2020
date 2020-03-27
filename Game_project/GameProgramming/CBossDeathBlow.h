#ifndef CBOSSDEATHBLOW_H
#define CBOSSDEATHBLOW_H

#include "CRectangle.h"

/*
�K�E�Z�N���X
CRectangle�N���X���p������
�e�FCRectangle�N���X
�q�FCBossDeathBlow�N���X
*/
class CBossDeathBlow : public CRectangle {
public:
	int mFx, mFy;	//�ړ���
	int mFireCount; //��������

	static	CTexture mBossDeathBlow;
	//�f�t�H���g�R���X�g���N�^
	CBossDeathBlow(int Priority);
	//�X�V����
	void Update();

	//�`�揈��
	void Render();

	
	void Collision(CTask*task);//�����蔻��
};

#endif