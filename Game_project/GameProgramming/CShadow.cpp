#include "CShadow.h"
#include"CPlayer.h"
CShadow*CShadow::mpInstanceS=0;
CShadow::CShadow(int Priority)
:CRectangle(Priority), my_prev(0), mPlayercenter(115)
{
	mpInstanceS = this;
	h = 16;
	w = 64;
	mShadow.Load("image\\effect\\hole.tga");
}

void CShadow::Update(){
	my_prev = y;
	x = CPlayer::mpPlayer->x;
	y = CPlayer::mpPlayer->y - mPlayercenter;
	if (CPlayer::mpPlayer->jflag==true){
		y = CPlayer::mpPlayer->my_prev - mPlayercenter;
		if (CPlayer::mpPlayer->mSpeed>0){
			w--;
		}
		else if (CPlayer::mpPlayer->mSpeed <0){
			if (w < 64){
				w++;
			}
		}
	}
	

}
void CShadow::Render(){

CRectangle::Render(mShadow, 55, 243, 283, 210);

}