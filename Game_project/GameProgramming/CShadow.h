#ifndef CSHADOW_H
#define CSHADOW_H
#include"CRectangle.h"

class CShadow :public CRectangle{
public:
	CShadow(int Priority);
	CTexture mShadow;
	static CShadow *mpInstanceS;
	int my_prev;//�O��y
	int mPlayercenter;//�v���C���[�̒��S
	void Update();

	void Render();

};
#endif