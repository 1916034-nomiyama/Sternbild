//#pragma once

extern int aaaa;
extern int fadeCnt;
extern bool fadeIn, fadeOut;
extern bool pauseFlag;

//�v���g�^�C�v�錾
void EffectInit(void);
bool FadeInScreen(int fadeStep);
bool FadeOutScreen(int fadeStep);