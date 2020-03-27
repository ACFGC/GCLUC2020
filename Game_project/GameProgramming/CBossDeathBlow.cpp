#include "CBossDeathBlow.h"
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
CTexture CBossDeathBlow::mBossDeathBlow;
//�f�t�H���g�R���X�g���N�^
CBossDeathBlow::CBossDeathBlow(int Priority)
: mFx(1), mFy(1), mFireCount(300), CRectangle(Priority)
{
	mTag = EBOSSDEATHBLOW;
	mEnabled = false;
	w = 50;	//���ݒ�
	h = 20;	//�����ݒ�
	mBossDeathBlow.Load("image\\effect\\Range attack_2.tga");
}

//�X�V����
void CBossDeathBlow::Update() {
	//�L���Ȏ�
	if (mEnabled) {
		//�ړ�
		x += mFx;
		y += mFy;
		//��������
		if (mFireCount > 0) {
			mFireCount--;
		}
		if (mFireCount <= 0)
			mEnabled = false;
	}
	}

//�`�揈��
void CBossDeathBlow::Render() {
	//�L���Ȏ�
	if (mEnabled) {
		CRectangle::Render(mBossDeathBlow, 630, 1273, 507, 109);
	}
}

void CBossDeathBlow::Collision(CTask*task){

	CRectangle*rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EPLAYER:
			mEnabled = false;
			break;
		}
	}
}