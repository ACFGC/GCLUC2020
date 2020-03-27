#ifndef CGAMEOVER_H
#define CGAMEOVER_H

#include "CRectangle.h"
#include "CPlayer.h"

class CGameOver :public CRectangle{
public:
	static CGameOver *mpInstance;

	//���񂩂ǂ������肷��ϐ�
	static bool mIsFirst;
	//�Q�[���I�[�o�[���̃e�N�X�`��
	static CTexture mTextureGameOverBackGround;
	static CTexture mTextureGameOverReplay;
	static CTexture mTextureGameOverGiveUp;
	/*static CTexture mTextureGameOverText;
	static CTexture mTextureGameOverDeadSlime;*/
	//�Q�[���I�[�o�[��ʂ�`�悷��}�`
	CRectangle mRectGameOverBackGround;
	CRectangle mRectGameOverReplay;
	CRectangle mRectGameOverGiveUp;
	/*CRectangle mRectGameOverText;
	CRectangle mRectGameOverDeadSlime;
	CRectangle mRectCarsol;*/
	
	bool mIsGameOver;
	int mCarsol;// 0:������x(�R���e�B�j���[)�A1:������߂�(�^�C�g����ʂ�)
	int mTitleBackTime;

	CGameOver(int Priority);
	void Update();
	void Render();
};
#endif