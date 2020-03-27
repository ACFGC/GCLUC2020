#ifndef CRECTANGLE_H
/*
#ifndef CRECTANGLE_H
もしCRECTANGLE_Hのdefineがなければ#endifまで有効
*/
#define CRECTANGLE_H //CRECTANGLE_Hを定義する

//#include "glut.h"
#include "CTexture.h"
#include"CTaskManager.h"

/*
CRectangleクラス
四角形に関するクラス
*/
class CRectangle :public CTask {
public:
	//列挙型の定義
	enum ETag {
		EBLOCK,	//ブロック
		EPLAYER,//プレイヤー
		EATTACK,//攻撃中
		ENHANCEDATTACK,//強化攻撃
		EBURN,//敵の火の玉
		EDEATHBLOW,//必殺技
		EBOSSDEATHBLOW,//ボス必殺技
		ESLIMEENEMY,//スライム型の雑魚敵
		EMISTRESS,//森のボス
		ECATENEMY,//猫型の雑魚敵
		ERABBITBOSS,//兎型のボス
		EDUMMYENEMY,//ダミーの雑魚敵
		EDUMMYPLAYER,//ダミーの雑魚プレイヤーに変身状態
		ELASTMYF,//ラスボス
		EENEMY,  //敵の基本動作
		EMISTRESSES,//森ボス逃げ
	};
	ETag mTag;	//列挙型の変数
	//デフォルトコンストラクタ
	CRectangle(int priority);
	CRectangle();
	~CRectangle();

	//bool mEnabled;	// true : Update Collision Render

	enum EStatus {
		EENABLED,	//
		EDISABLED,	// mEnabled true -> false
		EDELETE,	// delete list
	};
	EStatus mStatus;

	float x;		//中心のX座標
	float y, w, h, z, d;	//中心のY座標,幅,高さ,奥行き



	/*
	DrawTriangle
	三角形を描画する関数
	*/
	void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2);
	/*
	DrawRectangle
	四角形を描画する関数
	x0,y0:右上
	x1,y1:左上
	x2,y2:左下
	x3,y3:右下
	*/
	void DrawRectangle(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);

	/*
	Draw
	　四角形を描画する関数
	 */
	virtual void Render();
	/*
	Collision
	四角形rと衝突していればtrueを
	していなければfalseを返します。
	*/
    bool Collision(const CRectangle &r);
	/*
	Collision
	引数*prの四角形と衝突しているか検出し、
	衝突していればtrueを、していなければfalseを返す。
	また、衝突していた場合、*pxにX軸方向に重なった量を、
	*pyにY軸方向へ重なった量を設定する。
	*/
	bool Collision(CRectangle *pr, int *px, int *py);
	/*
	テクスチャの描画
	t:テクスチャのポインタ left:テクスチャの左X座標 right:テクスチャの右X座標
	bottom:テクスチャの下Y座標 top:テクスチャの上Y座標
	*/
	virtual void Render(CTexture &t, int left, int right
		, int bottom, int top) {
		t.DrawImage(x - w, x + w, y - h, y + h
			, left, right, bottom, top);
	}

	virtual void Update() {};

	//36
	
};

#include <vector>
//可変長配列の定義
extern std::vector<CRectangle*> VectorRect;

#endif //#ifndefの終わり