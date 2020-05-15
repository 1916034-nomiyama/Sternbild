///////////////////////////////////////////////////////////////
//////////////////Sutrnbild～星座の動物たち～//////////////////
///////////////////////////////////////////////////////////////
//          <2020/05/14開始>～<2020/06/05終了予定>

#include "Dxlib.h"				//DxLibﾗｲﾌﾞﾗﾘを使用する
#include "main.h"
#include "effect.h"
#include "keyCheck.h"
#include "player.h"



//-----変数の定義
SCENE sceneID;						//現在のシーン
SCENE preSceneID;					//ひとつ前のシーン
int sceneCounter;					//カウンター

int titleImage;
int gameoverImage;
int hitstartkeyImage;


//==========WinMain
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SystemInit();
	//----------ｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
	

						//画面描画処理
		ClsDrawScreen();//描画の消去
						//背景の表示
				//シーンカウンタの初期化
		if (sceneID != preSceneID)
		{
			preSceneID = sceneID;
			sceneCounter = 0;
		}

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
			else if (fadeOut)
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

		//敵の表示


		//ScreenFlip(); //裏画面を表画面に瞬間ｺﾋﾟｰ
	}
	DxLib_End();	//DXﾗｲﾌﾞﾗﾘの終了処理
	return 0;		//このﾌﾟﾛｸﾞﾗﾑの終了
}

bool SystemInit(void)
{
	bool retFlag = true;  //関数の戻り値

	//----------ｼｽﾃﾑ処理
	SetWindowText("Nakahara Yoshiharu");
	//ｼｽﾃﾑ処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);		//640 * 480ﾄﾞｯﾄ65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);				//true:window  false:ﾌﾙｽｸﾘｰﾝ
	if (DxLib_Init() == -1) return -1;		//DXﾗｲﾌﾞﾗﾘ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);			//ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画

	//----------グラフィックの登録----------


	//----------変数の初期化----------
	sceneCounter = 0;
	preSceneID = SCENE_MAX;
	sceneID = SCENE_TITLE;

	//敵

	return false;
}
//初期化のシーン
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
//タイトルの描画
void TitleDraw(void)
{
	DrawGraph(0, 0, titleImage, true);
	DrawFormatString(0, 0, 0xffffff, "Count:%d", sceneCounter);

}
//ゲームシーン
void GameScene(void)
{
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
//ゲーム画面の描画
void GameDraw(void)
{
	DrawFormatString(50, 50, 0xffff00, "%d", aaaa); ;
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
//ゲームオーバーの描画
void GameOverDraw(void)
{
	DrawFormatString(0, 0, 0xffffff, "Count:%d", sceneCounter);

}

