#ifndef CCHARACTER_H
#define CCHARACTER_H

#include "CVector.h"

#include"CTaskManager.h"


class CCharacter :public CTask{
public:


	~CCharacter();

	CCharacter(int Priority);

	//�X�V����
	void Update();

	//�`�揈��
	void Render();
};
#endif