//--------------------------------------------------------
//
//					effect.cpp
//
//--------------------------------------------------------
#include"DxLib.h"

//�ϐ��̒�`
//--------------------------------------------------------

int aaaa;
int fadeCnt;
bool fadeIn, fadeOut;
bool pauseFlag;

//
void EffectInit(void)
{
	fadeIn = true;
	fadeOut = false;
	pauseFlag = false;
	fadeCnt = 0;
	aaaa = 0;
}
//�t�F�[�h�C������
bool FadeInScreen(int fadeStep)
{
	fadeCnt += fadeStep;
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		return true;
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeCnt = 0;
		fadeIn = false;
		return false;
	}
}
//�t�F�[�h�A�E�g����
bool FadeOutScreen(int fadeStep)
{
	fadeCnt += fadeStep;
	if (fadeCnt <= 255)
	{
		SetDrawBright(255 - fadeCnt, 255 - fadeCnt, 255 - fadeCnt);
		return true;
	}
	else
	{
		SetDrawBright(0, 0, 0);
		fadeCnt = 0;
		fadeOut = false;
		return false;
	}
}