#ifndef CVECTOR_H
#define CVECTOR_H
/*
ベクトルクラス
ベクトルデータの扱い
*/
class CVector{
public:
	//3D各軸での値設定
	float mX, mY, mZ;
	//各軸での値の設定
	//Set(X座標, Y座標, Z座標)
	void Set(float x, float y, float z);
	void Set(float x, float y);
};
#endif