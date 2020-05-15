//--------------------------------------------------------
//
//					KeyCheck.cpp
//
//--------------------------------------------------------

#include "DxLib.h"
#include "main.h"
#include "keyCheck.h"


bool keyOld[KEY_ID_MAX];			//1フレーム前の入力状態
bool keyNew[KEY_ID_MAX];			//現在の入力状態
bool keyDownTrigger[KEY_ID_MAX];	//ダウン時のトリガー
bool keyUpTrigger[KEY_ID_MAX];		//アップ時のトリガー
//int mouseButton;					//マウスのボタン状態
//int mouseButtonOld;					//マウスのボタン状態



									//入力情報の初期化
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
//入力情報の確認
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

	//トリガーの算出
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
		//ダウントリガー
		if (!keyOld[keyID] && keyNew[keyID])
		{
			keyDownTrigger[keyID] = true;
		}
		//アップトリガー
		if (keyOld[keyID] && !keyNew[keyID])
		{
			keyUpTrigger[keyID] = true;
		}
	}
}