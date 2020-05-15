//#pragma once

//列挙型
//-----------------------------------
enum KEY_ID
{
	KEY_ID_SPACE,				//スペースキー
	KEY_ID_MOUSE_LEFT,			//マウス左ボタン
	KEY_ID_MOUSE_MIDDLE,		//マウスホイールボタン
	KEY_ID_MOUSE_RIGHT,			//マウス右ボタン
	KEY_ID_P,
	KEY_ID_MAX
};

extern bool keyOld[KEY_ID_MAX];			//1フレーム前の入力状態
extern bool keyNew[KEY_ID_MAX];			//現在の入力状態
extern bool keyDownTrigger[KEY_ID_MAX];	//ダウン時のトリガー
extern bool keyUpTrigger[KEY_ID_MAX];		//アップ時のトリガー
extern int mouseButton;					//マウスのボタン状態
extern int mouseButtonOld;					//マウスのボタン状態


//構造体
//------------------------
//プロトタイプ宣言
//-----------------------------------
void KeyInit(void);				//入力情報の初期化
void KeyCheck(void);			//入力情報の確認