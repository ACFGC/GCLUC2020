#include "CCharacter.h"
#include"CTaskManager.h"

CCharacter::~CCharacter(){

	//�^�X�N����
	TaskManager.Remove(this);
}
CCharacter::CCharacter(int Priority){
	mPriority = Priority;
	//�^�X�N���X�g�ɒǉ�
	TaskManager.Add(this);
}

void CCharacter::Update(){

}

void CCharacter::Render(){

}