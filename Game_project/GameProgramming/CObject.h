#ifndef COBJECT_H
#define COBJECT_H

#include"CRectangle.h"
#include"Cvector.h"
#include "CSlimeEnemy.h"

class CObject1 :public CRectangle{
public:	
	
	CObject1(int Priority);

	static CTexture mfrontdoor2;
	

	void Updete();

	void Render();

};


class CObject2 :public CRectangle{
public:

	CObject2(int Priority);

	static CTexture mPillar1;

	void Updete();

	void Render();

};


class CThroughObject1 :public CRectangle{
public:

	CThroughObject1(int Priority);

	static CTexture mfrontdoor1;

	void Updete();

	void Render();

};


class CThroughObject2 :public CRectangle{
public:

	CThroughObject2(int Priority);

	static CTexture mPillar2;

	void Updete();

	void Render();

};

class CCandle :public CRectangle{
public:


	CCandle(int Priority);

	static CTexture mCandle;

	int mCandleCount;

	int mFPS;
	
	void Render();

};

class CCandleL :public CRectangle{
public:

	CCandleL(int Priority);

	static CTexture mCandleL;

	int mCandleCount;

	int mFPS;

	void Render();

};

class CEffect :public CRectangle{
public:

	CEffect(int Priority);

	static CTexture mEffect;

	int mEffectCount;

	int mEFPS;

	void Render();
};
#endif