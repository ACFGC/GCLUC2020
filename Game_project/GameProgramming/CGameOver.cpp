#include "CGameOver.h"
#include "CScene.h"
#include "CKey.h"

bool CGameOver::mIsFirst = true;

CTexture CGameOver::mTextureGameOverBackGround;
CTexture CGameOver::mTextureGameOverReplay;
CTexture CGameOver::mTextureGameOverGiveUp;
//CTexture CGameOver::mTextureGameOverText;
//CTexture CGameOver::mTextureGameOverDeadSlime;


CGameOver *CGameOver::mpInstance = 0;
CGameOver::CGameOver(int Priority)
:CRectangle(Priority), mIsGameOver(false), mCarsol(1), mTitleBackTime(200)
{
	mpInstance = this;
	
	if (mIsFirst){
		mTextureGameOverBackGround.Load("image\\UI\\gameover　clear\\gemeover haikei.tga");
		mTextureGameOverReplay.Load("image\\UI\\gameover　clear\\retry.tga");
		mTextureGameOverGiveUp.Load("image\\UI\\gameover　clear\\giveup.tga");
		/*mTextureGameOverText.Load("image\\UI\\gameover　clear\\gemeover.tga");
		mTextureGameOverDeadSlime.Load("image\\UI\\gameover　clear\\gemeover chara.tga");*/
		mIsFirst = false;
	}
	//CRectangle mRectGameOverBackGround;
	//CRectangle mRectGameOverText;
	//CRectangle mRectGameOverReplay;
	//CRectangle mRectGameOverGiveUp;
	//CRectangle mRectGameOverDeadSlime;

	mRectGameOverBackGround.w = 640, mRectGameOverBackGround.h = 360;

	mRectGameOverReplay.w = 256, mRectGameOverReplay.h = 128;
	mRectGameOverGiveUp.w = 256, mRectGameOverGiveUp.h = 128;
	/*mRectGameOverText.w = 600, mRectGameOverText.h = 140;
	mRectGameOverDeadSlime.w = 256, mRectGameOverDeadSlime.h = 256;
	mRectCarsol.w = 25, mRectCarsol.h = 30;*/
}
void CGameOver::Update(){
	

	mRectGameOverBackGround.x = x;
	mRectGameOverBackGround.y = y;
	mRectGameOverReplay.x = x - 300;
	mRectGameOverReplay.y = y - 30;
	mRectGameOverGiveUp.x = x;
	mRectGameOverGiveUp.y = y;
	/*mRectGameOverText.x = x;
	mRectGameOverText.y = y + 220;
	mRectGameOverDeadSlime.x = x;
	mRectGameOverDeadSlime.y = y - 120;
	mRectCarsol.x = x - 200 + mCarsol * 390;
	mRectCarsol.y = y - 30;*/

	if (mIsGameOver){
		/*if (mDisapTime > 0){
			mDisapTime--;
		}
		if (CKey::Once('A') || CKey::Once('D')){
			if (mCarsol == 0){
				mCarsol++;
			}
			else if (mCarsol == 1){
				mCarsol--;
			}
			mDisapTime = 1;
		}*/
		
		if (mTitleBackTime > 0){
			mTitleBackTime--;
		}
	}

	//画面投影範囲の中心を求める
	x = CScene::mpInstance->mLeft + (CScene::mpInstance->mRight - CScene::mpInstance->mLeft) / 2;
	y = CScene::mpInstance->mBottom + (CScene::mpInstance->mTop - CScene::mpInstance->mBottom) / 2;

	/*if (CPlayer::mpPlayer->mEnabled == false){
		mIsGameOver = true;
	}*/
	
	/*if (CKey::Once('G')){
		if (mIsGameOver){
			mIsGameOver = false;
		}
		else{
			mIsGameOver = true;
		}
	}*/
	
}
void CGameOver::Render(){
	if (mIsGameOver){
		mRectGameOverBackGround.Render(mTextureGameOverBackGround, 0, 1280, 720, 0);

		////アルファブレンドを有効
		//glEnable(GL_BLEND);
		////ブレンド方法を指定
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//float c[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		//if (mCarsol == 1){
		//	c[3] = 0.2f;
		//}
		//glColor4fv(c);
		////mRectGameOverReplay.Render(mTextureGameOverReplay, 0, 512, 256, 0);
		//c[3] = 1.0f;
		//if (mCarsol == 0){
		//	c[3] = 0.2f;
		//}
		//glColor4fv(c);
		//mRectGameOverGiveUp.Render(mTextureGameOverGiveUp, 0, 512, 256, 0);
		////最後に白色に戻す
		//c[0] = c[1] = c[2] = c[3] = 1.0f;
		//glColor4fv(c);
		////アルファブレンドを無効
		//glDisable(GL_BLEND);

		/*mRectGameOverDeadSlime.Render(mTextureGameOverDeadSlime, 0, 512, 512, 0);
		mRectGameOverText.Render(mTextureGameOverText, 0, 1092, 256, 0);*/
		
		/*if (mDisapTime <= 0){
			if (mCarsol == 0){
				mRectCarsol.Render(mTextureGameOverReplay, 315, 365, 130, 70);
			}
			else if (mCarsol == 1){
				mRectCarsol.Render(mTextureGameOverGiveUp, 90, 140, 160, 100);
			}
		}*/
	}
}

