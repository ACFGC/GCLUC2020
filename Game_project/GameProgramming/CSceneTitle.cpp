#include "CSceneTitle.h"
//OpenGL
#include "glut.h"
#include"Cvector.h"
#include "CKey.h"
#include "CRectangle.h"

#include "CTexture.h"



#define ARROWLITTLEMOVE_SPEED 0.17f
#define ARROWLITTLEMOVE_MOUNTAIN 6.0f//頂点(山)
#define ARROWLITTLEMOVE_VALLEY 0.0f  //頂点(谷)
#define ARROWLITTLEMOVE_WAITTIME_MOUNTAIN 2
#define ARROWLITTLEMOVE_WAITTIME_VALLEY 9

#define CARSOL_MOVESPEED 20

#define FADEOUT_SPEED 0.02f


bool CSceneTitle::mIsFirst = true;

CTexture CSceneTitle::mTitleBackGround;
CTexture CSceneTitle::mTitleLogo;
CTexture CSceneTitle::mTitleStartButton;
CTexture CSceneTitle::mTitleInstButton;
CTexture CSceneTitle::mTitleCarsol;
CTexture CSceneTitle::mJunbi;

void CSceneTitle::Init() {
	//シーンの設定
	mScene = ETITLE;
	//ゲーム起動時、「初回だけ」タイトル素材の読み込み
	if (mIsFirst){
		mTitleBackGround.Load("image\\UI\\game_title\\game_title_background.tga");
		mTitleLogo.Load("image\\UI\\game_title\\game_title.tga");
		mTitleStartButton.Load("image\\UI\\game_title\\GAME_START.tga");
		mTitleInstButton.Load("image\\UI\\game_title\\Method of operation.tga");
		mTitleCarsol.Load("image\\UI\\game_title\\Arrow.tga");
		mJunbi.Load("image\\UI\\game_title\\Methodofoperation_01.tga");
		mIsFirst = false;
	}
	mCarsol = 0;
	mSetsumei = false;

	//画面投影範囲の数値
	mLeft = 0; mRight = 1280;
	mTop = 720; mBottom = 0;

	//タイトル画面で描画するロゴやボタン等の初期位置、サイズを設定する
	//操作説明中の画面
	mSetsumeiScreen.x = 640; mSetsumeiScreen.y = 360;
	mSetsumeiScreen.w = 512; mSetsumeiScreen.h = 288;
	//タイトル画面の背景
	mRectTBG.x = 640; mRectTBG.y = 360;
	mRectTBG.w = 640; mRectTBG.h = 360;
	//タイトル画面のロゴ
	mRectTL.x = 400; mRectTL.y = 535;
	mRectTL.w = 450; mRectTL.h = 225;
	//タイトル画面のスタートボタン
	mRectTSB.x = 400; mRectTSB.y = 300;
	mRectTSB.w = 256; mRectTSB.h = 64;
	//タイトル画面の操作説明ボタン
	mRectTIB.x = 400; mRectTIB.y = 150;
	mRectTIB.w = 256; mRectTIB.h = 64;
	//タイトル画面のカーソル
	mRectTC.x = 675; mRectTC.y = 375;
	mRectTC.w = 64; mRectTC.h = 64;
	//フェードアウト用
	mFadeOut.x = 640; mFadeOut.y = 360;
	mFadeOut.w = 640; mFadeOut.h = 360;
	mFadeValue = 0.0f;

	mStartFlag = false;

	mArrowLittleMove = 0.0f;

	mArrowUpFlag = false;
	mArrowDownFlag = false;
	mArrowLittleMoveWaitTime = 5;

	mGetYforTC = 0;
	mIsMoveCarsol = false;
}

void CSceneTitle::Update() {
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


	if (mIsMoveCarsol == false){

		if (mArrowUpFlag){
			mArrowLittleMove += ARROWLITTLEMOVE_SPEED;
		}
		if (mArrowDownFlag){
			mArrowLittleMove -= ARROWLITTLEMOVE_SPEED;
		}
	}
	if (mArrowLittleMove <= ARROWLITTLEMOVE_VALLEY){
		mArrowDownFlag = false;
		if (mArrowLittleMoveWaitTime > 0){
			mArrowLittleMoveWaitTime--;
		}
		else{
			mArrowUpFlag = true;
			mArrowLittleMoveWaitTime = ARROWLITTLEMOVE_WAITTIME_VALLEY;
		}
	}
	else if (mArrowLittleMove >= ARROWLITTLEMOVE_MOUNTAIN){
		mArrowUpFlag = false;
		if (mArrowLittleMoveWaitTime > 0){
			mArrowLittleMoveWaitTime--;
		}
		else{
			mArrowDownFlag = true;
			mArrowLittleMoveWaitTime = ARROWLITTLEMOVE_WAITTIME_MOUNTAIN;
		}
	}


	//スタートが押された時
	if (mStartFlag){
		//完全に暗転した時
		if (mFadeValue > 1.0f){
			//次のシーンはオープニング
			mScene = EOPENING;
		}
		else{
			mFadeValue += FADEOUT_SPEED;
		}
	}

	//一番上の項目(STARTボタン)
	if (mCarsol == 0){
		//Enterキー押下でオープニングが始まる(オープニング画面に移行)
		if (CKey::Once(VK_RETURN)){
			mStartFlag = true;
		}
	}
	//上から二番目の項目(操作説明)
	else if (mCarsol == 1){
		//Enterキー押下で操作説明画面が開く
		if (CKey::Once(VK_RETURN)){
			//操作説明画面を既に開いている時は閉じる
			if (mSetsumei){
				mSetsumei = false;
			}
			//操作説明画面を開く
			else{
				mSetsumei = true;
			}
		}
	}

	if (CKey::Once(('W')) || CKey::Once('S')){
		//操作説明が表示中はカーソル移動せずに説明画面を閉じる
		if (mSetsumei){
			mSetsumei = false;
		}
		else if (mCarsol == 0){
			mCarsol = 1;
		}
		else if (mCarsol == 1){
			mCarsol = 0;
		}
	}
	
	//背景・ロゴ・ボタン2つの描画
	mRectTBG.Render(mTitleBackGround, 0, 1280, 720, 0);
	mRectTL.Render(mTitleLogo, 0, 1024, 512, 0);
	mRectTSB.Render(mTitleStartButton, 0, 512, 128, 0);
	mRectTIB.Render(mTitleInstButton, 0, 512, 128, 0);
	
	//カーソル移動時、次の地点へ滑らかに移動させる処理
	if (mRectTC.y != mGetYforTC){
		mIsMoveCarsol = true;
		if (mRectTC.y > mGetYforTC){
			if (mRectTC.y - mGetYforTC >= CARSOL_MOVESPEED){
				mRectTC.y -= CARSOL_MOVESPEED;
			}
			//微調整
			else{
				if (mRectTC.y - mGetYforTC >= CARSOL_MOVESPEED / 6){
					mRectTC.y -= CARSOL_MOVESPEED / 6;
				}
				else{
					mRectTC.y--;
				}
			}
		}
		else{
			if (mGetYforTC - mRectTC.y >= CARSOL_MOVESPEED){
				mRectTC.y += CARSOL_MOVESPEED;
			}
			//微調整
			else{
				if (mGetYforTC - mRectTC.y >= CARSOL_MOVESPEED / 6){
					mRectTC.y += CARSOL_MOVESPEED / 6;
				}
				else{
					mRectTC.y++;
				}
			}
		}
	}
	else{
		mIsMoveCarsol = false;
	}
	//カーソルの次の地点を設定する
	mGetYforTC = 357 - mCarsol * 150 + mArrowLittleMove;
	//カーソルの描画
	mRectTC.Render(mTitleCarsol, 0, 128, 128, 0);
	
	

	//操作説明が表示される
	if (mSetsumei){
		/*if (mSetsumeiScreen.w < 512){
			mSetsumeiScreen.w += 64;
		}
		if (mSetsumeiScreen.h < 288){
			mSetsumeiScreen.h += 36;
		}*/
		
		//説明画面の描画
		mSetsumeiScreen.Render(mJunbi, 0, 1280, 720, 0);
	}
	//else{
	//	if (mSetsumeiScreen.w > 0){
	//		mSetsumeiScreen.w -= 64;
	//	}
	//	if (mSetsumeiScreen.h > 0){
	//		mSetsumeiScreen.h -= 36;
	//	}
	//}
	////説明画面の描画
	//mSetsumeiScreen.Render(mJunbi, 0, 1280, 720, 0);
	
	//アルファブレンドを有効
	glEnable(GL_BLEND);
	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float c[] = { 0.0f, 0.0f, 0.0f, mFadeValue };
	glColor4fv(c);

	mFadeOut.Render();
	//最後に白色に戻す
	c[0] = c[1] = c[2] = c[3] = 1.0f;
	glColor4fv(c);

	//アルファブレンドを無効
	glDisable(GL_BLEND);
}

void CSceneTitle::Render() {
	
}

//次のシーンの取得
CScene::EScene CSceneTitle::GetNextScene(){
	return mScene;
}