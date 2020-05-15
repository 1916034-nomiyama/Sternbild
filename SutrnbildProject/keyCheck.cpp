//--------------------------------------------------------
//
//					KeyCheck.cpp
//
//--------------------------------------------------------

#include "DxLib.h"
#include "main.h"
#include "keyCheck.h"


bool keyOld[KEY_ID_MAX];			//1�t���[���O�̓��͏��
bool keyNew[KEY_ID_MAX];			//���݂̓��͏��
bool keyDownTrigger[KEY_ID_MAX];	//�_�E�����̃g���K�[
bool keyUpTrigger[KEY_ID_MAX];		//�A�b�v���̃g���K�[
//int mouseButton;					//�}�E�X�̃{�^�����
//int mouseButtonOld;					//�}�E�X�̃{�^�����



									//���͏��̏�����
void KeyInit(void)
{
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = false;
		keyNew[keyID] = false;
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
	}
}
//���͏��̊m�F
void KeyCheck(void)
{


	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = keyNew[keyID];
	}

	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);
	keyNew[KEY_ID_MOUSE_LEFT] = mouseButton & MOUSE_INPUT_LEFT;
	keyNew[KEY_ID_MOUSE_MIDDLE] = mouseButton & MOUSE_INPUT_MIDDLE;
	keyNew[KEY_ID_MOUSE_RIGHT] = mouseButton & MOUSE_INPUT_RIGHT;
	keyNew[KEY_ID_P] = CheckHitKey(KEY_INPUT_P);

	//�g���K�[�̎Z�o
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
		//�_�E���g���K�[
		if (!keyOld[keyID] && keyNew[keyID])
		{
			keyDownTrigger[keyID] = true;
		}
		//�A�b�v�g���K�[
		if (keyOld[keyID] && !keyNew[keyID])
		{
			keyUpTrigger[keyID] = true;
		}
	}
}