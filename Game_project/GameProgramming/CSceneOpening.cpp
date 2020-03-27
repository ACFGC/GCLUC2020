#include "CSceneOpening.h"
//OpenGL
#include "glut.h"
#include"Cvector.h"
#include "CKey.h"
#include "CRectangle.h"

#include "CTexture.h"

#define TOTALPAGE 5
#define READTIME1P 240
#define READTIME2P 320
#define READTIME3P 510
#define READTIME4P 310
#define READTIME5P 560
#define FADE_PER_FRAME 0.017f

void CSceneOpening::Init() {
	//シーンの設定
	mScene = EOPENING;
	//OP画面・背景・字幕のテクスチャ読み込み
	mOPBackGround.Load("image\\UI\\story\\story haikei.tga");
	mOPStory1.Load("image\\UI\\story\\story_01.tga");
	mOPStory2.Load("image\\UI\\story\\story_02.tga");
	mOPStory3.Load("image\\UI\\story\\story_03.tga");
	mOPStory4.Load("image\\UI\\story\\story_04.tga");
	mOPStory5.Load("image\\UI\\story\\story_05.tga");

	mCurrentPage = 0;
	mTimeCount = 1;

	mRecOPBackGround.x = 640; mRecOPBackGround.y = 360;
	mRecOPBackGround.w = 640; mRecOPBackGround.h = 360;
	
	mRecOPStory.x = 640; mRecOPStory.y = 360;
	mRecOPStory.w = 512; mRecOPStory.h = 64;

	mRectFade.x = 640; mRectFade.y = 360;
	mRectFade.w = 640; mRectFade.h = 360;
	mScreenFadeValue = 1.0f;
	mScreenFadeIn = true;
	mScreenFadeOut = false;
	mStoryFadeIn = false;
	mStoryFadeOut = false;
	mStoryFadeValue = 0.0f;

	mStoryReadTime = 0;
	
	mStoryShowing = false;
}

void CSceneOpening::Update() {
	//画面のフェードインの処理
	if (mScreenFadeIn){
		//まだ完全に表示されてない時
		if (mScreenFadeValue > 0.0f){
			mScreenFadeValue -= FADE_PER_FRAME;
		}
		else{
			mScreenFadeIn = false;
		}
	}
	//画面のフェードアウトの処理
	if (mScreenFadeOut){
		//完全に暗転した時
		if (mScreenFadeValue > 1.0f){
			//次のシーンでゲーム画面に入る
			mScene = EFOREST;
		}
		//徐々に暗くなる
		else{
			mScreenFadeValue += FADE_PER_FRAME;
		}
	}
	//字幕のフェードインの処理
	if (mStoryFadeIn){
		if (mStoryFadeValue < 1.0f){
			mStoryFadeValue += FADE_PER_FRAME;
		}
		else{
			mStoryFadeIn = false;
			if (mCurrentPage != TOTALPAGE){
				mStoryShowing = true;
			}
		}
	}
	//字幕のフェードアウトの処理
	if (mStoryFadeOut){
		if (mStoryFadeValue > 0.0f){
			mStoryFadeValue -= FADE_PER_FRAME;
		}
		else{
			mStoryFadeOut = false;
			mTimeCount = 9;
		}
	}

	if (mTimeCount > 0){
		if (mScreenFadeIn == false){
			mTimeCount--;
		}
	}
	else{
		//mStoryFadeOut = true;
	}


	if (mStoryShowing){
		if (mStoryReadTime <= 0){
			mStoryFadeOut = true;
			mStoryShowing = false;
		}
		else{
			mStoryReadTime--;
		}
	}


	
	mRecOPBackGround.Render(mOPBackGround, 0, 1280, 720, 0);
		
	
	//EnterキーでOPをスキップ
	if (CKey::Once(VK_RETURN)){
		mStoryFadeIn = false;
		mScreenFadeIn = false;
		mScreenFadeOut = true;
	}

	if (mTimeCount <= 0){
		//最後のページの後、フェードアウトが始まる
		if (mCurrentPage == TOTALPAGE){
			mScreenFadeOut = true;
		}
		//そうじゃない時は次のページへ
		else{
			mCurrentPage++;
			//↓？？？？？
			mTimeCount = 999;
			mStoryFadeIn = true;
			
			//次の字幕を表示する時間を設定する
			if (mCurrentPage == 1){
				mStoryReadTime = READTIME1P;
			}
			else if (mCurrentPage == 2){
				mStoryReadTime = READTIME2P;
			}
			else if (mCurrentPage == 3){
				mStoryReadTime = READTIME3P;
			}
			else if (mCurrentPage == 4){
				mStoryReadTime = READTIME4P;
			}
			else if (mCurrentPage == TOTALPAGE){
				mTimeCount = READTIME5P;
			}
		}
	}

	//アルファブレンドを有効
	glEnable(GL_BLEND);
	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float c[] = { 1.0f, 1.0f, 1.0f, mStoryFadeValue };
	glColor4fv(c);

	if (mCurrentPage == 1){
		mRecOPStory.Render(mOPStory1, 0, 1024, 128, 0);
	}
	else if (mCurrentPage == 2){
		mRecOPStory.Render(mOPStory2, 0, 1024, 128, 0);
	}
	else if (mCurrentPage == 3){
		mRecOPStory.Render(mOPStory3, 0, 1024, 128, 0);
	}
	else if (mCurrentPage == 4){
		mRecOPStory.Render(mOPStory4, 0, 1024, 128, 0);
	}
	else if (mCurrentPage == 5){
		mRecOPStory.Render(mOPStory5, 0, 1024, 128, 0);
	}
	
	//最後に白色に戻す
	c[0] = c[1] = c[2] = c[3] = 1.0f;
	glColor4fv(c);

	//アルファブレンドを無効
	glDisable(GL_BLEND);



	//アルファブレンドを有効
	glEnable(GL_BLEND);
	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float cf[] = { 0.0f, 0.0f, 0.0f, mScreenFadeValue };
	glColor4fv(cf);

	mRectFade.Render();
	//最後に白色に戻す
	cf[0] = cf[1] = cf[2] = cf[3] = 1.0f;
	glColor4fv(cf);

	//アルファブレンドを無効
	glDisable(GL_BLEND);
	
}

//次のシーンの取得
CScene::EScene CSceneOpening::GetNextScene(){
	return mScene;
}