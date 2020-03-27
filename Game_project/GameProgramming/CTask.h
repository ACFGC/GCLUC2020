#ifndef CTASK_H
#define CTASK_H

class CTask
{
public:
	CTask*mpMine;//自分のポインタ	

	CTask*mpNext; //次ポインタ
	
	CTask*mpPrev; //前ポインタ

	int mPriority;//優先度

	bool mEnabled;//優効度

	bool mSurvivalConfirmation;//生存確認(true=生、false=死)

	//デフォルトコンストラクタ
	CTask()
		:mpNext(0), mpPrev(0), mPriority(0), mEnabled(true), mSurvivalConfirmation(true){}
	//デストラクタ　virtualにしないと子クラスのデストラクタが呼ばれない
	virtual~CTask(){}

	virtual void Update(){}
	
	virtual void Render(){}

	virtual void Collision(CTask*task){}

};
#endif

