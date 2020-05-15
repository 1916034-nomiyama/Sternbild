
#include "Dxlib.h"				//DxLibﾗｲﾌﾞﾗﾘを使用する
#include "main.h"
#include "player.h"

//自機
int playerImage;				//ﾌﾟﾚｲﾔｰのｲﾒｰｼﾞ
int playerPosX;					//ﾌﾟﾚｲﾔｰのX座標
int playerPosY;					//ﾌﾟﾚｲﾔｰのY座標
int playerSpeed;				//ﾌﾟﾚｲﾔｰの移動量


//自機のｼｽﾃﾑ処理の初期化
void PlayerSystemInit(void)
{
	//自機
	playerPosX = (SCREEN_SIZE_X) / 2 - (PLAYER_SIZE_X) / 2;
	playerPosY = SCREEN_SIZE_Y - PLAYER_SIZE_Y;
	playerSpeed = 8;

}
//自機の初期化
void PlayerInit(void)
{
	playerImage = LoadGraph("Image/player.png");		//Imageの中にあるという意味で / 又は \ を付ける

}
//自機の操作
void PlayerControl(void)
{
	//------ﾌﾟﾚｲﾔｰのｷｰ操作
//左移動
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		if (playerPosX >= playerSpeed)
		{
			playerPosX = playerPosX - playerSpeed;
		}
	}
	//右移動
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		if (playerPosX + playerSpeed <= SCREEN_SIZE_X - PLAYER_SIZE_X)
		{
			playerPosX = playerPosX + playerSpeed;
		}
	}
	//上移動
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		if (playerPosY >= playerSpeed)
		{
			playerPosY = playerPosY - playerSpeed;
		}
	}
	//下移動
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		if (playerPosY + playerSpeed <= SCREEN_SIZE_Y - PLAYER_SIZE_Y)
		{
			playerPosY = playerPosY + playerSpeed;
		}
	}

}
//自機の描画
void PlayerDraw(void)
{
	//プレイヤーの表示
	DrawGraph(playerPosX, playerPosY, playerImage, true);
	DrawBox(playerPosX, playerPosY, playerPosX + PLAYER_SIZE_X, playerPosY + PLAYER_SIZE_Y, 0xFFFFFF, false);

}
