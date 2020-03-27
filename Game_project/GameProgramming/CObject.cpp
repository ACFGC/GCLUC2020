#include "CObject.h"
#include "CTexture.h"

extern CTexture Texture;
CTexture CObject1::mfrontdoor2;
CTexture CObject2::mPillar1;
CTexture CThroughObject1::mfrontdoor1;
CTexture CThroughObject2::mPillar2;
CTexture CCandle::mCandle;
CTexture CCandleL::mCandleL;
//CTexture CEffect::mEffect;


CObject1::CObject1(int Priority)  //プレイヤーより優先度の高い屋根オブジェクト
:CRectangle(Priority){
	if (mEnabled){
		mfrontdoor2.Load("image\\bg_forest\\mansion_01.tga");//手前

	}
}


CObject2::CObject2(int Priority)  //プレイヤーより優先度の高い柱オブジェクト
:CRectangle(Priority){
	if (mEnabled){
		mPillar1.Load("image\\bg_forest\\gate_01.tga");//手前
	}
}


CThroughObject1::CThroughObject1(int Priority)   //プレイヤーより優先度の低い屋根オブジェクト
:CRectangle(Priority){
	if (mEnabled){
		mfrontdoor1.Load("image\\bg_forest\\mansion_02.tga");  //手奥　　EFRONTDOOR1
	}
}


CThroughObject2::CThroughObject2(int Priority)   //プレイヤーより優先度の低い柱オブジェクト
:CRectangle(Priority){
	if (mEnabled){
		mPillar2.Load("image\\bg_forest\\gate_02.tga");//奥手
	}
}


CCandle::CCandle(int Priority)	//ろうそくの描画
:CRectangle(Priority), mCandleCount(0), mFPS(20)

{
	if (mEnabled){

		mCandle.Load("image\\bg_mansion\\Candle_Description.tga");

	}

}

CCandleL::CCandleL(int Priority)	//ろうそくの灯描画
:CRectangle(Priority), mCandleCount(0), mFPS(20)

{
	if (mEnabled){

		mCandleL.Load("image\\bg_mansion\\Candle_Description.tga");

	}

}

//CEffect::CEffect(int Priority) //ダメージエフェクト
//:CRectangle(Priority), mEffectCount(0), mEFPS(20)
//{
//
//	if (mEnabled){
//
//		mEffect.Load("image\\effect\\explosion.tga");
//
//	}
//
//}

void CObject1::Render(){
	if (mEnabled){
		CRectangle::Render(mfrontdoor2, 1, 516, 970, 119);
	}
}

void CObject2::Render(){

	if (mEnabled){

		CRectangle::Render(mPillar1, 156, 356, 462, 48);

	}

}


void CThroughObject1::Render(){
	if (mEnabled){

		CRectangle::Render(mfrontdoor1, 299, 846, 922, 84);

	}

}

void CThroughObject2::Render(){

	if (mEnabled){

		CRectangle::Render(mPillar2, 156, 356, 462, 48);

	}

}

void CCandle::Render(){	//キャンドルの描画

	if (mEnabled){

		if (mCandleCount < mFPS){
			mCandleCount++;
		}
		if (mCandleCount < 10){

			CRectangle::Render(mCandle, 282, 349, 250, 130);

		}

		else if (mCandleCount < 20){

			CRectangle::Render(mCandle, 169, 239, 546, 436);

		}

		else if (mCandleCount == 20){
			CRectangle::Render(mCandle, 282, 349, 250, 130);
			mCandleCount = 0;
		}

	}

}

void CCandleL::Render(){

	if (mEnabled){

		if (mCandleCount < mFPS){
			mCandleCount++;
		}
		if (mCandleCount < 10){

			CRectangle::Render(mCandleL, 315, 555, 595, 370);

		}

		else if (mCandleCount < 20){

			CRectangle::Render(mCandleL, 315, 555, 595, 370);

		}

		else if (mCandleCount == 20){
			CRectangle::Render(mCandleL, 315, 555, 595, 370);
			mCandleCount = 0;

		}
	}
}

//void CEffect::Render(){
//
//	if (CSlimeEnemy::mpSlimeEnemy->mHitPoint--){
//		if (mEffectCount < mEFPS){
//			mEffectCount++;
//		}
//	
//		if (mEffectCount < 10){
//	
//			CRectangle::Render(mEffect, 192, 477, 383, 128);
//	
//		}
//	
//		else if (mEffectCount < 20){
//	
//			CRectangle::Render(mEffect, 511, 796, 383, 128);
//	
//		}
//	
//		else if (mEffectCount < 30){
//	
//			CRectangle::Render(mEffect, 830, 1115, 383, 128);
//	
//		}
//	}
//	
//}
