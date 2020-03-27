#ifndef CTASK_H
#define CTASK_H

class CTask
{
public:
	CTask*mpMine;//�����̃|�C���^	

	CTask*mpNext; //���|�C���^
	
	CTask*mpPrev; //�O�|�C���^

	int mPriority;//�D��x

	bool mEnabled;//�D���x

	bool mSurvivalConfirmation;//�����m�F(true=���Afalse=��)

	//�f�t�H���g�R���X�g���N�^
	CTask()
		:mpNext(0), mpPrev(0), mPriority(0), mEnabled(true), mSurvivalConfirmation(true){}
	//�f�X�g���N�^�@virtual�ɂ��Ȃ��Ǝq�N���X�̃f�X�g���N�^���Ă΂�Ȃ�
	virtual~CTask(){}

	virtual void Update(){}
	
	virtual void Render(){}

	virtual void Collision(CTask*task){}

};
#endif

