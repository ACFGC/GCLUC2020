#include "CBossDeathBlow.h"
#include "CTexture.h"
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
CTexture CBossDeathBlow::mBossDeathBlow;
//デフォルトコンストラクタ
CBossDeathBlow::CBossDeathBlow(int Priority)
: mFx(1), mFy(1), mFireCount(300), CRectangle(Priority)
{
	mTag = EBOSSDEATHBLOW;
	mEnabled = false;
	w = 50;	//幅設定
	h = 20;	//高さ設定
	mBossDeathBlow.Load("image\\effect\\Range attack_2.tga");
}

//更新処理
void CBossDeathBlow::Update() {
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
void CBossDeathBlow::Render() {
	//有効な時
	if (mEnabled) {
		CRectangle::Render(mBossDeathBlow, 630, 1273, 507, 109);
	}
}

void CBossDeathBlow::Collision(CTask*task){

	CRectangle*rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EPLAYER:
			mEnabled = false;
			break;
		}
	}
}