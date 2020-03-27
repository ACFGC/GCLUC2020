#ifndef CSCENE_H
#define CSCENE_H

/*
�V�[���̊��N���X
*/
class CScene {
public:
	static CScene *mpInstance;
	static CScene *mpInstanceS;
	//��ʓ��e�͈͂̕ϐ�
	int mLeft, mRight, mBottom, mTop;

	//virtual ���z�֐�
	//�|�����[�t�B�Y���̎���
	//=0 �������z�֐��̐ݒ�
	virtual void Init() = 0;	//�������z�֐� ����������
	virtual void Update() = 0; //�������z�֐� �X�V����

	//�V�[���̎��ʎq
	enum EScene {
		EFOREST,  //�X
		EMANSION,//�}���V�����V�[��
		EMANSIONF2,//�}���V�����V�[��F2
		EMANSIONLAST,//���X�{�X�X�e�[�W
		ETITLE, //�^�C�g��
		EOPENING,//�I�[�v�j���O
	};
	//���̃V�[���̎擾
	EScene mScene;


	virtual EScene GetNextScene() = 0;
	virtual ~CScene() {}	//�f�X�g���N�^�̒�`
};


#endif
