#include "CCharacter.h"
#include"CTaskManager.h"

CCharacter::~CCharacter(){

	//タスク消去
	TaskManager.Remove(this);
}
CCharacter::CCharacter(int Priority){
	mPriority = Priority;
	//タスクリストに追加
	TaskManager.Add(this);
}

void CCharacter::Update(){

}

void CCharacter::Render(){

}