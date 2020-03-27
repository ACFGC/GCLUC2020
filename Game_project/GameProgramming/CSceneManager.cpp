#include "CSceneManager.h"
#include "CSceneGame.h"
#include "CSceneTitle.h"
#include "CSceneOpening.h"

CScene::EScene mScene;//�V�[���̎���

//�R���X�g���N�^
CSceneManager::CSceneManager()
: mpScene(0)
{}
//�f�X�g���N�^�i�폜�����Ƃ��Ɏ��s����܂��j
CSceneManager::~CSceneManager() {
	//�V�[��������΍폜
	if (mpScene)
		//�V�[���̍폜
		delete mpScene;
	mpScene = 0;
}
//����������
void CSceneManager::Init() {
	//�V�[���̎��ʂ�ݒ肷��
	mScene = CScene::ETITLE;
	//�V�[���𐶐����A�|�C���^��ݒ肷��
	mpScene = new CSceneTitle();
	//���������N���X�̃��\�b�h���Ă΂��
	mpScene->Init();
}
//�X�V����
void CSceneManager::Update() {
	//�|�C���^��Update���Ă�
	mpScene->Update();
	//���̃V�[�����擾���قȂ邩����
	if (mScene != mpScene->GetNextScene()){
		mScene = mpScene->GetNextScene();
		delete mpScene;//���̃V�[���폜
		//�Y������V�[���𐶐�
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
