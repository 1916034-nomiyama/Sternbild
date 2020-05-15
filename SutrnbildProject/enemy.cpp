#include "DxLib.h"
#include "main.h"
#include "enemy.h"

#define ENEMY_SIZE_X 64
#define ENEMY_SIZE_Y 64

int enemyImage;
int enemyPosX;
int enemyPosY;
int enemySpeed;


void EnemySystemInit(void)
{
	//“G
	enemyPosX = (SCREEN_SIZE_X/2) - (ENEMY_SIZE_X/2);
	enemyPosY = 0;
	enemySpeed = 4;
	enemyImage = LoadGraph("enemy.png");		

}
void EnemyInit(void)
{

}
void EnemyControl(void)
{
	/*
	//¶ˆÚ“®
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (enemyPosX >= enemySpeed)
		{
			enemyPosX = enemyPosX - enemySpeed;
		}
	}
	//‰EˆÚ“®
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (enemyPosX + enemySpeed <= SCREEN_SIZE_X - ENEMY_SIZE_X)
		{
			enemyPosX = enemyPosX + enemySpeed;
		}
	}
	//ãˆÚ“®
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		if (enemyPosY >= enemySpeed)
		{
			enemyPosY = enemyPosY - enemySpeed;
		}
	}
	//‰ºˆÚ“®
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		if (enemyPosY + enemySpeed <= SCREEN_SIZE_Y - ENEMY_SIZE_Y)
		{
			enemyPosY = enemyPosY + enemySpeed;
		}
	}
	*/

}
void EnemyDraw(void)
{
	//“G‚Ì•\Ž¦
	DrawGraph(enemyPosX, enemyPosY, enemyImage, true);
	DrawBox(enemyPosX, enemyPosY, enemyPosX + ENEMY_SIZE_X, enemyPosY + ENEMY_SIZE_Y, 0xFFFFFF, false);

}
