#ifndef CCHARACTER_H
#define CCHARACTER_H

#include "CVector.h"

#include"CTaskManager.h"


class CCharacter :public CTask{
public:


	~CCharacter();

	CCharacter(int Priority);

	//XVˆ—
	void Update();

	//•`‰æˆ—
	void Render();
};
#endif