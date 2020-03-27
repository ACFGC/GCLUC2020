#include"CTaskManager.h"
//�^�X�N�}�l�[�W���̊O���ϐ�
CTaskManager TaskManager;

CTaskManager::CTaskManager()
:mpHead(0)
{}

CTaskManager::~CTaskManager(){}


//�^�X�N�ǉ�
void CTaskManager::Add(CTask*task){

	if (mpHead == 0){

		mpHead = task;

		task->mpPrev = 0;

		task->mpNext = 0;
	}
	else{

		CTask*pos = mpHead;

		while (task->mPriority < pos->mPriority){

			if (pos->mpNext != 0){

				pos = pos->mpNext;

			}

			else{

				break;

			}

		}

		if (pos->mpPrev == 0){

			task->mpNext = mpHead;

			mpHead->mpPrev = task;

			mpHead = task;

			mpHead->mpPrev = 0;

		}

		else if (pos->mpNext == 0){

			task->mpNext = 0;

			task->mpPrev = pos;

			pos->mpNext = task;

		}

		else{

			task->mpNext = pos;

			task->mpPrev = pos->mpPrev;

			pos->mpPrev = task;

			task->mpPrev->mpNext = task;

		}

	}
}

void CTaskManager::AllDisable(){
	CTask*pos = mpHead;

	while (pos)
	{
		//�X�V�����̌Ăяo��

		pos->mEnabled=false;

		//���֍s��
		pos = pos->mpNext;
	}

}
void CTaskManager::Changepriority(CTask*task, int priority){

	Remove(task);
	task->mPriority = priority;
	Add (task);
}

void CTaskManager::Remove(CTask*task){
	//1��task�����X�g����폜

	if (task->mpPrev == 0){

		mpHead = task->mpNext;
	}
	else{

		task->mpPrev->mpNext = task->mpNext;
	}
	if (task->mpNext == 0){

//		task->mpPrev->mpNext = task->mpNext;

	}
	else{

		task->mpNext->mpPrev = task->mpPrev;
	}

}

//�����m�F
void CTaskManager::DeleteCheck(){
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask*pos = mpHead;
	while (pos){
		CTask*mpMine = pos;
		//����
		pos = pos->mpNext;
		//mSurvivalConfirmation(�����m�F)��false�Ȃ�폜
		if (mpMine->mSurvivalConfirmation == false){
			delete mpMine;
		}
	}
}

void CTaskManager::Delete(){

	CTask*pos = mpHead;

	while (pos){
		CTask*del = pos;
		//����
		pos = pos->mpNext;
		//mEnabled��false�Ȃ����

		if (del->mEnabled == false){

			delete del;

		}
	}

}


void CTaskManager::Update(){

	CTask*pos = mpHead;

	while (pos)
	{
		//�X�V�����̌Ăяo��

		pos->Update();

		//���֍s��
		pos = pos->mpNext;
	}

}
void CTaskManager::Collision(){
	//���݈ʒu��擪�ɂ���
	CTask*pos = (CTask*)mpHead;
	//�Ō�܂łł�����I������
	while (pos ->mpNext!=0 ){
		//���݈ʒu�̎������߂�
		CTask*next = (CTask*)pos->mpNext;
		//����0�ɂȂ�����I��
		while (next){
			//�e�̏Փˏ������Ăяo��
			//�����̏Փˏ���
			pos->Collision( next);
			//����̏Փˏ���
			next->Collision(pos);
			//�������߂�
			next = next->mpNext;
		}
		//���݈ʒu�����ɂ���
		pos = pos->mpNext;
	}
}

void CTaskManager::Render(){

	CTask*pos = mpHead;

	while (pos)
	{
		//�`�揈���̌Ăяo��

		pos->Render();

		//���֍s��
		pos = pos->mpNext;
	}

}

//void CTaskManager::AllDelete(){
//
//	CTask*pos = mpHead;
//
//	while (pos){
//		CTask*del = pos;
//		//����
//		pos = pos->mpNext;
//		//mEnabled��false�Ȃ����
//
//			delete del;
//
//	}
//
//}