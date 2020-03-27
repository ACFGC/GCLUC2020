#include "CSceneGame.h"
#include "CKey.h"
//OpenGL
#include "glut.h"
#include"Cvector.h"
#include "CTaskManager.h"
#include "CRectangle.h"

//画面横＝1280
//画面縦＝720
//CPlayer*mpPlayer;
void CSceneGame::Init() {

	mpInstance = this;

	mLeft = 0;
	mRight = 1280;
	mTop = 720;
	mBottom = 0;

	mCameramove = 3;
	mScene = EFOREST;

	CBurn::mBurnTexture.Load("image\\effect\\fire.tga");
	mforest1.Load("image\\bg_forest\\bg_forest_01.tga");
	mforest2.Load("image\\bg_forest\\bg_forest_02.tga");
	mforest3.Load("image\\bg_forest\\bg_forest_03.tga");
	mforest4.Load("image\\bg_forest\\bg_forest_sky.tga");


	mfrontdoor1.Load("image\\bg_forest\\mansion_02.tga");
	mfrontdoor2.Load("image\\bg_forest\\mansion_01.tga");

	mPillar1.Load("image\\bg_forest\\gate_01.tga");//手前
	mPillar2.Load("image\\bg_forest\\gate_02.tga");//奥手
	CPlayer*mPlayer = new CPlayer(3);

	mPlayer->x = 256;
	mPlayer->y = 256;
	mPlayer->z = mPlayer->y;


	mPlayer->mEnabled = true;


	CSlimeEnemy*mSlimeEnemy = new CSlimeEnemy(3);

	mSlimeEnemy->x = 400;
	mSlimeEnemy->y = 300;
	mSlimeEnemy->z = mSlimeEnemy->y;

	mSlimeEnemy->mEnabled = true;


	mSlimeEnemy = new CSlimeEnemy(3);

	mSlimeEnemy->x = 500;
	mSlimeEnemy->y = 400;
	mSlimeEnemy->z = mSlimeEnemy->y;

	mSlimeEnemy->mEnabled = true;


	mSlimeEnemy = new CSlimeEnemy(3);

	mSlimeEnemy->x = 800;
	mSlimeEnemy->y = 400;
	mSlimeEnemy->z = mSlimeEnemy->y;

	mSlimeEnemy->mEnabled = true;


	mSlimeEnemy = new CSlimeEnemy(3);

	mSlimeEnemy->x = 900;
	mSlimeEnemy->y = 300;
	mSlimeEnemy->z = mSlimeEnemy->y;

	mSlimeEnemy->mEnabled = true;


	CObject1 * mObjectF = new CObject1(2);  //プレイヤーより前

	mObjectF->x = 3690;
	mObjectF->y = 280;
	mObjectF->h = 300;
	mObjectF->w = 205;
	
	mObjectF->mEnabled = true;

	

	CObject2 * mObjectP = new CObject2(2);  //プレイヤーより前

	mObjectP->x = 3470;
	mObjectP->y = 100;
	mObjectP->h = 100;
	mObjectP->w = 45;

	mObjectP->mEnabled = true;

	
	
	CThroughObject1 * mThroughObjenameF = new CThroughObject1(4);  //プレイヤーより後

	mThroughObjenameF->x =3645;
	mThroughObjenameF->y = 290;
	mThroughObjenameF->h = 280;
	mThroughObjenameF->w = 190;

	mThroughObjenameF->mEnabled = true;

	
	
	CThroughObject2 * mThroughObjenameP = new CThroughObject2(4);  //プレイヤーより後

	mThroughObjenameP->x = 3405;
	mThroughObjenameP->y = 225;
	mThroughObjenameP->h = 80;
	mThroughObjenameP->w = 30;

	mThroughObjenameP->mEnabled = true;

		
	CMistress*mpMistress = new CMistress(3);

	mpMistress->x = 3700;
	mpMistress->y = 400;
	mpMistress->z = mpMistress->y;


	CHPBar *HPBar = new CHPBar(1);
	HPBar->x = 300 + mLeft, HPBar->y = 660 + mBottom;


	CGameOver *GameOver = new CGameOver(-1);
	GameOver->mEnabled = true;
}

void CSceneGame::Update() {


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

	if (CMistress::mpMistress->mHitPoint==700){
		if (CMistress::mpMistress->mHitPoint==350){

	//	mLeft = CMistress::mpMistress->x - 500;
	//	mRight = CMistress::mpMistress->x + 500;

	//	if (CMistress::mpMistress->x > 3860){

	//		mLeft = CPlayer::mpPlayer->x - 200;
	//		mRight = CPlayer::mpPlayer->x + 1080;

		}


	}

	
	
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

	//視点の設定
	//gluLookAt(視点X, 視点Y, 視点Z, 中心X, 中心Y, 中心Z, 上向X, 上向Y, 上向Z）
	//gluLookAt(1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	


	//テクスチャ使用可能
	glEnable(GL_TEXTURE_2D);

	//テクスチャをバインド
	glBindTexture(GL_TEXTURE_2D, mforest4.mId);
	//アルファブレンドを有効

	glEnable(GL_BLEND);

	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//描画開始
	glBegin(GL_QUADS);

	//空
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f, 750.0f, 0.0f);
	v1.Set(0.0f, 750.0f, 0.0f);
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

	//空二枚目
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f + 1280.0, 750.0f, 0.0f);
	v1.Set(1280.0f, 750.0f, 0.0f);
	v2.Set(1280.0f, 0.0f, 0.0f);
	v3.Set(1280.0f + 1280.0, 0.0f, 0.0f);

	//四角形の描画
	glTexCoord2f(0.1f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(0.1f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);


	//描画終了
	glEnd();


	//描画開始
	glBegin(GL_QUADS);

	//空三枚目
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f+1280.0+1280.0, 750.0f, 0.0f);
	v1.Set(1280.0f+1280.0, 750.0f, 0.0f);
	v2.Set(1280.0f+1280.0, 0.0f, 0.0f);
	v3.Set(1280.0f+1280.0+1280.0, 0.0f, 0.0f);

	//四角形の描画
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.1, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.1f, 0.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//描画終了
	glEnd();


	//テクスチャのバインドを解く
	glBindTexture(GL_TEXTURE_2D, 0);


	//テクスチャをバインド
	glBindTexture(GL_TEXTURE_2D, mforest3.mId);


	//描画開始
	glBegin(GL_QUADS);

	//背景：奥の森
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280+mRight/1.07, mBottom-100, 0.0f);
	v1.Set(1280+mRight/1.07, mTop+100, 0.0f);
	v2.Set(mLeft/1.02, mTop+100, 0.0f);
	v3.Set(mLeft/1.02, mBottom-100, 0.0f);

	glTexCoord2f(1.0, 0.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);


	//描画終了
	glEnd();

	//テクスチャのバインドを解く
	glBindTexture(GL_TEXTURE_2D, 0);


	//テクスチャをバインド
	glBindTexture(GL_TEXTURE_2D, mforest2.mId);


	//描画開始
	glBegin(GL_QUADS);

	//背景：中央の森
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280+mRight/1.1, mBottom-100, 0.0f);
	v1.Set(1280+mRight/1.1, mTop+100, 0.0f);
	v2.Set(mLeft/1.07, mTop+100, 0.0f);
	v3.Set(mLeft/1.07, mBottom-100, 0.0f);


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


	//テクスチャのバインドを解く
	glBindTexture(GL_TEXTURE_2D, 0);


	//テクスチャをバインド
	glBindTexture(GL_TEXTURE_2D, mforest1.mId);


	//描画開始
	glBegin(GL_QUADS);

	//手前の森、地面1
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f, -160.0f, 0.0f);
	v1.Set(1280.0f, 720.0f, 0.0f);
	v2.Set(0.0f, 720.0f, 0.0f);
	v3.Set(0.0f, -160, 0.0f);

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


	//描画開始
	glBegin(GL_QUADS);

	//手前の森、地面2
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f+1280.0, -160.0f, 0.0f);
	v1.Set(1280.0f + 1280.0, 720.0f, 0.0f);
	v2.Set(0.0f+1280.0, 720.0f, 0.0f);
	v3.Set(0.0f+1280.0, -160.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(v3.mX, v3.mY, v3.mZ);

	//描画終了
	glEnd();

	//描画開始
	glBegin(GL_QUADS);

	//手前の森、地面3
	n.Set(0.0f, 0.0f, 0.0f);
	v0.Set(1280.0f + 1280.0 + 1280.0, -160.0f, 0.0f);
	v1.Set(1280.0f + 1280.0 + 1280.0, 720.0f, 0.0f);
	v2.Set(0.0f + 1280.0 + 1280.0, 720.0f, 0.0f);
	v3.Set(0.0f + 1280.0 + 1280.0, -160.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(v0.mX, v0.mY, v0.mZ);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(v1.mX, v1.mY, v1.mZ);

	glTexCoord2f(1.0f, 1.0f);
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


	if (CPlayer::mpPlayer->x >3740){
		TaskManager.AllDisable();
	    CPlayer::mpPlayer->mEnabled = true;
		CHPBar::mpInstance->mEnabled = true;
		CGameOver::mpInstance->mEnabled = true;
		CShadow::mpInstanceS->mEnabled=true;
		mScene = EMANSION;
		
	}

	if (CPlayer::mpPlayer->mEnabled == false){

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
				mScene = EFOREST;
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
