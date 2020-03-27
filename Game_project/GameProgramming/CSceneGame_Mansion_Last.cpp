#include "CSceneGame.h"
#include "CKey.h"
//OpenGL
#include "glut.h"
#include"Cvector.h"
#include "CTaskManager.h"
#include "CRectangle.h"


void CSceneGame_Mansion_Last::Init() {

	mpInstance = this;
	mpInstanceS = this;

	mLeft = 0;
	mRight = 1280;
	mTop = 720;
	mBottom = 0;

	mCameramove = 3;
	mScene = EMANSIONLAST;
	CBurn::mBurnTexture.Load("image\\effect\\fire.tga");

	mMansion1.Load("image\\bg_mansion\\bg_mansion_.tga");


	mMansionsky.Load("image\\bg_mansion\\bg_mansion_sky.tga");

	//CPlayer*mPlayer = new CPlayer(3);

	CPlayer::mpPlayer->x = 256;
	CPlayer::mpPlayer->y = 256;
	CPlayer::mpPlayer->z = CPlayer::mpPlayer->y;


	CCandle*mCandle = new CCandle(5);

	mCandle->x = 410;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;

	CCandleL*mCandleL = new CCandleL(4);

	mCandleL->x = 410;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;

	mCandle = new CCandle(5);

	mCandle->x = 820;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;


	mCandleL = new CCandleL(4);

	mCandleL->x = 820;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;


	mCandle = new CCandle(5);

	mCandle->x = 1200;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;


	mCandleL = new CCandleL(4);

	mCandleL->x = 1200;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;


	mCandle = new CCandle(5);

	mCandle->x = 1700;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;

	mCandleL = new CCandleL(4);

	mCandleL->x = 1700;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;

	mCandle = new CCandle(5);

	mCandle->x = 2100;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;


	mCandleL = new CCandleL(4);

	mCandleL->x = 2100;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;

	mCandle = new CCandle(5);

	mCandle->x = 2480;
	mCandle->y = 550;
	mCandle->h = 40;
	mCandle->w = 20;

	mCandle->mEnabled = true;

	mCandleL = new CCandleL(4);

	mCandleL->x = 2480;
	mCandleL->y = 540;
	mCandleL->h = 40;
	mCandleL->w = 40;

	mCandleL->mEnabled = true;


	CLastMyF*mLastMyF = new CLastMyF(4);

	mLastMyF->x = 3500;
	mLastMyF->y = 400;
	mLastMyF->z = mLastMyF->y;



}

void CSceneGame_Mansion_Last::Update(){

	//画面投影範囲変更
	//行列をプロジェクションモード変更
	glMatrixMode(GL_PROJECTION);

	//行列を初期化
	glLoadIdentity();

	//2Dの画面投影範囲設定
	gluOrtho2D(mLeft, mRight, mBottom, mTop);

	//行列をモデルビューモードへ変更
	glMatrixMode(GL_MODELVIEW);

	//行列を初期化
	glLoadIdentity();

	mLeft = CPlayer::mpPlayer->x - 200;
	mRight = CPlayer::mpPlayer->x + 1080;
	if (mLeft < 0){

		mLeft = 0;
		mRight = 1280;

	}

	if (mRight>3840){

		mLeft = 2560;
		mRight = 3840;

	}



	CVector v0, v1, v2, v3, n;


	//テクスチャ使用可能
	glEnable(GL_TEXTURE_2D);

	//テクスチャをバインド
	glBindTexture(GL_TEXTURE_2D, mMansionsky.mId);

	//アルファブレンドを有効
	glEnable(GL_BLEND);

	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//描画開始
	glBegin(GL_QUADS);

	//窓の景色
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(mRight, mBottom, 0.0f);
	v1.Set(mRight, mTop, 0.0f);
	v2.Set(mLeft, mTop, 0.0f);
	v3.Set(mLeft, mBottom, 0.0f);

	//四角形の描画
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//描画終了
	glEnd();

	//アルファブレンド無効
	glDisable(GL_BLEND);

	//テクスチャのバインドを解く
	glBindTexture(GL_TEXTURE_2D, 0);


	//テクスチャをバインド
	glBindTexture(GL_TEXTURE_2D, mMansion1.mId);

	//アルファブレンドを有効

	glEnable(GL_BLEND);

	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//描画開始
	glBegin(GL_QUADS);

	//マンションF1：1枚目
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f, 720.0f, 0.0f);
	v1.Set(0.0f, 720.0f, 0.0f);
	v2.Set(0.0f, 0.0f, 0.0f);
	v3.Set(1280.0f, 00.0f, 0.0f);

	//四角形の描画
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);


	//描画終了
	glEnd();


	//描画開始
	glBegin(GL_QUADS);

	//マンションF1：2枚目
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f + 1280, 720.0f, 0.0f);
	v1.Set(1280.0f, 720.0f, 0.0f);
	v2.Set(1280.0f, 0.0f, 0.0f);
	v3.Set(1280.0f + 1280, 00.0f, 0.0f);

	//四角形の描画
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//描画終了
	glEnd();


	//描画開始
	glBegin(GL_QUADS);

	//マンションF1：3枚目、階段
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f + 1280 + 1280, 720.0f, 0.0f);
	v1.Set(1280.0f + 1280, 720.0f, 0.0f);
	v2.Set(1280.0f + 1280, 0.0f, 0.0f);
	v3.Set(1280.0f + 1280 + 1280, 00.0f, 0.0f);

	//四角形の描画
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//描画終了
	glEnd();

	//アルファブレンド無効
	glDisable(GL_BLEND);
	//テクスチャのバインドを解く
	glBindTexture(GL_TEXTURE_2D, 0);
	//テクスチャを無効
	glDisable(GL_TEXTURE_2D);


	if (CPlayer::mpPlayer->x >3700){
		TaskManager.AllDisable();
		CPlayer::mpPlayer->mEnabled = true;
		
		mScene = ETITLE;
	}


	TaskManager.Update();
	TaskManager.Collision();
	TaskManager.Delete();
	TaskManager.Render();

	if (CGameOver::mpInstance->mIsGameOver){
		if (CKey::Once(VK_RETURN)){
			//リトライ
			if (CGameOver::mpInstance->mCarsol == 0){

			}
			//タイトル画面へ
			else if (CGameOver::mpInstance->mCarsol == 1){
				mScene = ETITLE;
			}
		}
		if (CGameOver::mpInstance->mTitleBackTime <= 0){
			mScene = ETITLE;
		}
	}

}