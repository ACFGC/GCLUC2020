#ifndef CPLAYERATTACK_H
#define CPLAYERATTACK_H

#include "CRectangle.h"

class CPlayerAttack :public CRectangle{
public:

	CPlayerAttack(int Priority);

	
	int mFx, mFy;
	int mACountA;
	int mFPS;
	void Update();

	void Render();

	void Collision(CTask*task);//“–‚½‚è”»’è

};
#endif