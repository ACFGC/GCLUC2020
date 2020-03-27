#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include"CPlayer.h"
#include "CSlimeEnemy.h"
#include"CCatEnemy.h"
#include "CObject.h"
#include "CRabbitBoss.h"
#include "CMistress.h"
#include "CHPBar.h"
#include "CGameOver.h"
#include "CLastMyF.h"
#include"CShadow.h"
/*
ゲームのシーン
*/
class CSceneGame : public CScene {
public:
	CTexture mforest1;
	CTexture mforest2;
	CTexture mforest3;
	CTexture mforest4;

	CTexture mMansion1;
	CTexture mMansionsky;
	CTexture mCandle;

	CTexture mfrontdoor1;
	CTexture mfrontdoor2;
	CTexture mPillar1;
	CTexture mPillar2;

	static CSceneGame*mpCSceGame;

	CTexture TEST;

	int mCameramove;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	//次のシーンの取得
	CScene::EScene CSceneGame::GetNextScene(){
		return mScene;
	}
};

class CSceneGame_Mansion : public CScene {
public:

	//画面投影範囲の変数
	//int mLeft, mRight, mBottom, mTop;


	CTexture mMansion1;
	CTexture mMansionsky;
	CTexture mCandle;
	CTexture mMansion2;


	CTexture TEST;

	int mCameramove;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	//次のシーンの取得
	CScene::EScene CSceneGame_Mansion::GetNextScene(){
		return mScene;
	}
};

class CSceneGame_MansionF2 :public CScene{
public:

	CTexture mMansion1;
	CTexture mMansionsky;
	CTexture mCandle;
	CTexture mMansion3;

	int mCameramove;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	//次のシーンの取得
	CScene::EScene CSceneGame_MansionF2::GetNextScene(){
		return mScene;


	}
};

class CSceneGame_Mansion_Last :public CScene{
public:

	CTexture mMansion1;
	CTexture mMansionsky;
	CTexture mCandle;

	int mCameramove;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	//次のシーンの取得
	CScene::EScene CSceneGame_Mansion_Last::GetNextScene(){
		return mScene;


	}
};


#endif
