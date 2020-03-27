#include "CBurn.h"
#include "CTexture.h"
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
CTexture CBurn::mBurnTexture;
//デフォルトコンストラクタ
CBurn::CBurn(int Priority)
: mFx(0), mFy(0), mFireCount(300), CRectangle(Priority), mACount(0), mFps(300)
{
	mTag = EBURN;
	mEnabled = false;
	w = 50;	//幅設定
	h = 20;	//高さ設定
	
}

//更新処理
void CBurn::Update() {
	//有効な時
	if (mEnabled) {
		//移動
		x += mFx;
		y += mFy;
		//持続時間
		if (mFireCount > 0) {
			mFireCount--;
		}
		if (mFireCount <= 0)
			mEnabled = false;
	}
}

//描画処理
void CBurn::Render() {
	int frame = 0;
	if (mEnabled) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 50){
			frame = 0;
		}
		else if (mACount < 100){
			frame = 1;
		}
		else if (mACount < 150){
			frame = 2;
		}
		else if (mACount < 200){
			frame = 3;
		}
		else if (mACount < 250){
			frame = 4;
		}
		else if (mACount < 300){
			frame = 5;
		}
		else if (mACount == 300){
			mACount = 0;
		}
		frame = 128 + frame * 256;
		CRectangle::Render(mBurnTexture, frame - 78, frame + 78, 754, 526);
	}
}

void CBurn::Collision(CTask*task){

	CRectangle*rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EPLAYER:
			mEnabled = false;
			break;


		}

	}

}

//36
//void CBurn::Collision(CRectangle *i, CRectangle *y) {
//	if (i->mEnabled && y->mEnabled) {
//
//		//プレイヤーに当たった時
//		if (i->mTag == EBURN && y->mTag == EPLAYER) {
//			if (i->Collision(*y)) {
//				mEnabled = false;
//				return;
//			}
//
//		}
//		//敵に当たった時
//		if (i->mTag == EBURN && y->mTag == ESLIMEENEMY) {
//			if (i->Collision(*y)) {
//				mEnabled = false;
//				return;
//			}
//
//		}
//		if (i->mTag == EBURN && y->mTag == ECATENEMY) {
//			if (i->Collision(*y)) {
//				mEnabled = false;
//				return;
//			}
//
//		}
//		if (i->mTag == EBURN && y->mTag == EMISTRESS) {
//			if (i->Collision(*y)) {
//				mEnabled = false;
//				return;
//			}
//
//		}
//	}
//}