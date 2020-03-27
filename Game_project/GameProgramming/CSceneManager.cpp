#include "CSceneManager.h"
#include "CSceneGame.h"
#include "CSceneTitle.h"
#include "CSceneOpening.h"

CScene::EScene mScene;//シーンの識別

//コンストラクタ
CSceneManager::CSceneManager()
: mpScene(0)
{}
//デストラクタ（削除されるときに実行されます）
CSceneManager::~CSceneManager() {
	//シーンがあれば削除
	if (mpScene)
		//シーンの削除
		delete mpScene;
	mpScene = 0;
}
//初期化処理
void CSceneManager::Init() {
	//シーンの識別を設定する
	mScene = CScene::ETITLE;
	//シーンを生成し、ポインタを設定する
	mpScene = new CSceneTitle();
	//生成したクラスのメソッドが呼ばれる
	mpScene->Init();
}
//更新処理
void CSceneManager::Update() {
	//ポインタのUpdateを呼ぶ
	mpScene->Update();
	//次のシーンを取得し異なるか判定
	if (mScene != mpScene->GetNextScene()){
		mScene = mpScene->GetNextScene();
		delete mpScene;//今のシーン削除
		//該当するシーンを生成
		switch (mScene){
		case CScene::EFOREST:
			mpScene = new CSceneGame();
			mpScene->Init();
			break;
		case CScene::ETITLE:
			mpScene = new CSceneTitle();
			mpScene->Init();
			break;
		case CScene::EOPENING:
			mpScene = new CSceneOpening();
			mpScene->Init();
			break;
		case CScene::EMANSION:
			mpScene = new CSceneGame_Mansion();
			mpScene->Init();
			break;
		case CScene::EMANSIONF2:
			mpScene = new CSceneGame_MansionF2();
			mpScene->Init();
			break;
		case CScene::EMANSIONLAST:
			mpScene = new CSceneGame_Mansion_Last();
			mpScene->Init();
			break;

		}
	}
}
