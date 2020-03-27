#ifndef CSHADOW_H
#define CSHADOW_H
#include"CRectangle.h"

class CShadow :public CRectangle{
public:
	CShadow(int Priority);
	CTexture mShadow;
	static CShadow *mpInstanceS;
	int my_prev;//前のy
	int mPlayercenter;//プレイヤーの中心
	void Update();

	void Render();

};
#endif