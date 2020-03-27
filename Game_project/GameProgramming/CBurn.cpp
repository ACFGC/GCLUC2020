#include "CBurn.h"
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
CTexture CBurn::mBurnTexture;
//�f�t�H���g�R���X�g���N�^
CBurn::CBurn(int Priority)
: mFx(0), mFy(0), mFireCount(300), CRectangle(Priority), mACount(0), mFps(300)
{
	mTag = EBURN;
	mEnabled = false;
	w = 50;	//���ݒ�
	h = 20;	//�����ݒ�
	
}

//�X�V����
void CBurn::Update() {
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
void CBurn::Render() {
	int frame = 0;
	if (mEnabled) {
		if (mACount < mFps){
			mACount++;
		}
		if (mACount < 50){
			frame = 0;
		}
		else if (mACount < 100){
			frame = 1;
		}
		else if (mACount < 150){
			frame = 2;
		}
		else if (mACount < 200){
			frame = 3;
		}
		else if (mACount < 250){
			frame = 4;
		}
		else if (mACount < 300){
			frame = 5;
		}
		else if (mACount == 300){
			mACount = 0;
		}
		frame = 128 + frame * 256;
		CRectangle::Render(mBurnTexture, frame - 78, frame + 78, 754, 526);
	}
}

void CBurn::Collision(CTask*task){

	CRectangle*rect = (CRectangle*)task;
	if (CRectangle::Collision(*rect)){
		switch (rect->mTag){
		case EPLAYER:
			mEnabled = false;
			break;


		}

	}

}

//36
//void CBurn::Collision(CRectangle *i, CRectangle *y) {
//	if (i->mEnabled && y->mEnabled) {
//
//		//�v���C���[�ɓ���������
//		if (i->mTag == EBURN && y->mTag == EPLAYER) {
//			if (i->Collision(*y)) {
//				mEnabled = false;
//				return;
//			}
//
//		}
//		//�G�ɓ���������
//		if (i->mTag == EBURN && y->mTag == ESLIMEENEMY) {
//			if (i->Collision(*y)) {
//				mEnabled = false;
//				return;
//			}
//
//		}
//		if (i->mTag == EBURN && y->mTag == ECATENEMY) {
//			if (i->Collision(*y)) {
//				mEnabled = false;
//				return;
//			}
//
//		}
//		if (i->mTag == EBURN && y->mTag == EMISTRESS) {
//			if (i->Collision(*y)) {
//				mEnabled = false;
//				return;
//			}
//
//		}
//	}
//}