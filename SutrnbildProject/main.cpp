//--------------------------------------------------------
//
//					main.cpp
//
//--------------------------------------------------------

#include "DxLib.h"					//DxLibﾗｲﾌﾞﾗﾘを使用する
#include "main.h"
#include "KeyCheck.h"
#include "effect.h"
#include "player.h"
#include "enemy.h"

//変数の定義
//--------------------------------------------------------
//シーン管理用
SCENE sceneID;						//現在のシーン
SCENE preSceneID;					//ひとつ前のシーン
int sceneCounter;					//カウンター

int titleImage;




int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SystemInit();

	SetDrawScreen(DX_SCREEN_BACK);									//ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画

	//ｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		ClsDrawScreen();				//画面消去

		//シーンカウンタの初期化
		if (sceneID != preSceneID)
		{
			preSceneID = sceneID;
			sceneCounter = 0;
		}

		KeyCheck();

		switch (sceneID)
		{
		case SCENE_INIT:
			InitScene();
			sceneID = SCENE_TITLE;
			break;

		case SCENE_TITLE:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}
			}
			else if(fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					sceneID = SCENE_GAME;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}
			TitleScene();
			break;

		case SCENE_GAME:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					sceneID = SCENE_GAMEOVER;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}
			GameScene();
			break;

		case SCENE_GAMEOVER:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {}
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					sceneID = SCENE_INIT;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}
			GameOverScene();
			break;

		default:
			return -1;
			break;
		}


		sceneCounter++;

		ScreenFlip();
	}
		DxLib_End();			//DXﾗｲﾌﾞﾗﾘの終了処理
		return 0;				//このﾌﾟﾛｸﾞﾗﾑの終了
}

//システムの初期化
bool SystemInit(void)
{

	bool retFlag = true;  //関数の戻り値

	//----------ｼｽﾃﾑ処理
	SetWindowText("1916030_中原英喜");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);					//800*320ﾄﾞｯﾄ65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);											// true:window false:ﾌﾙｽｸﾘｰﾝ
	if (DxLib_Init() == -1)
		return false;												//DXﾗｲﾌﾞﾗﾘ初期化処理

	EffectInit();
	KeyCheck();
	PlayerSystemInit();
	EnemySystemInit();

	//グラフィックの登録
	titleImage = LoadGraph("bs1.jpg");
	//---------------------

	//変数の初期化
	sceneCounter = 0;
	preSceneID = SCENE_MAX;
	sceneID = SCENE_TITLE;



	return retFlag;

}
//初期化シーン
void InitScene(void)
{
	
}
//タイトルシーン
void TitleScene(void)
{
	TitleDraw();
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}
}
//タイトル描画
void TitleDraw(void)
{

	DrawFormatString(0, 0, 0xffffff, "Count:%d", sceneCounter);
	DrawBox(100, 100, SCREEN_SIZE_X - 100, SCREEN_SIZE_Y - 100, 0x00ffff, 1);
	DrawFormatString(350, 300, 0x000000, "GAME START");
	
}
//ゲームシーン
void GameScene(void)
{
	PlayerControl();
	EnemyControl();

	if (keyDownTrigger[KEY_ID_P])
	{
		pauseFlag = !pauseFlag;
	}
	//Pause時
	if (pauseFlag)
	{
		SetDrawBright(128, 128, 128);
	}
	//通常動作時
	else
	{
		aaaa++;
	}
	//画面描画
	GameDraw();
	//Pauseメッセージを描画
	if (pauseFlag)
	{
		SetDrawBright(255, 255, 255);
		DrawFormatString(400 - 36, 300 - 4, 0xffffff, "P A U S E");
	}
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}
}
//ゲームシーン描画
void GameDraw(void)
{
	PlayerDraw();
	EnemyDraw();
	DrawGraph(50,50,titleImage,true);
	DrawFormatString(50, 50, 0xffff00, "%d", aaaa); 
	DrawFormatString(0, 0, 0xffffff, "Count:%d", sceneCounter);
}
//ゲームオーバーシーン
void GameOverScene(void)
{
	GameOverDraw();
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}
}
//ゲームオーバーシーン描画
void GameOverDraw(void)
{
	DrawFormatString(0, 0, 0xffffff, "Count:%d", sceneCounter);
	DrawBox(100,100,SCREEN_SIZE_X-100,SCREEN_SIZE_Y-100,0xff00ff,1);
	DrawFormatString(350,300,0xffffff,"GAME OVER");
}
