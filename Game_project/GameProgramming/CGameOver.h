#ifndef CGAMEOVER_H
#define CGAMEOVER_H

#include "CRectangle.h"
#include "CPlayer.h"

class CGameOver :public CRectangle{
public:
	static CGameOver *mpInstance;

	//初回かどうか判定する変数
	static bool mIsFirst;
	//ゲームオーバー時のテクスチャ
	static CTexture mTextureGameOverBackGround;
	static CTexture mTextureGameOverReplay;
	static CTexture mTextureGameOverGiveUp;
	/*static CTexture mTextureGameOverText;
	static CTexture mTextureGameOverDeadSlime;*/
	//ゲームオーバー画面を描画する図形
	CRectangle mRectGameOverBackGround;
	CRectangle mRectGameOverReplay;
	CRectangle mRectGameOverGiveUp;
	/*CRectangle mRectGameOverText;
	CRectangle mRectGameOverDeadSlime;
	CRectangle mRectCarsol;*/
	
	bool mIsGameOver;
	int mCarsol;// 0:もう一度(コンティニュー)、1:あきらめる(タイトル画面へ)
	int mTitleBackTime;

	CGameOver(int Priority);
	void Update();
	void Render();
};
#endif