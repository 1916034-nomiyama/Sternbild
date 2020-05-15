#include "DxLib.h"
#include "main.h"
#include "player.h"

#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32

int playerImage;
int playerPosX;
int playerPosY;
int playerSpeed;


void PlayerSystemInit(void)
{
	//自機
	playerPosX = (SCREEN_SIZE_X) / 2 - (PLAYER_SIZE_X) / 2;
	playerPosY = SCREEN_SIZE_Y - PLAYER_SIZE_Y;
	playerSpeed = 8;
	playerImage = LoadGraph("player.png");		//Imageの中にあるという意味で / 又は \ を付ける

}
void PlayerInit(void)
{

}
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
void PlayerDraw(void)
{
	//プレイヤーの表示
	DrawGraph(playerPosX, playerPosY, playerImage, true);
	DrawBox(playerPosX, playerPosY, playerPosX + PLAYER_SIZE_X, playerPosY + PLAYER_SIZE_Y, 0xFFFFFF, false);

}
