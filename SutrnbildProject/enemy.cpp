#include "DxLib.h"
#include "main.h"
#include "enemy.h"

#define ENEMY_SIZE_X 64		//敵のサイズ（横）
#define ENEMY_SIZE_Y 64		//敵のサイズ（縦）

int enemyImage;				//敵の画像
int enemyPosX;				//
int enemyPosY;				//
int enemySpeed;				//敵の速度
int enemyFlag;				//敵のON：OFF

//敵のシステムの初期化
void EnemySystemInit(void)
{
	//敵
	enemyPosX = (SCREEN_SIZE_X/2) - (ENEMY_SIZE_X/2);
	enemyPosY = 0;
	enemySpeed = 4;
	enemyImage = LoadGraph("enemy.png");

}
//初期化用
void EnemyInit(void)
{

}
//操作用
void EnemyControl(void)
{
	
	//左移動
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (enemyPosX >= enemySpeed)
		{
			enemyPosX = enemyPosX - enemySpeed;
		}
	}
	//右移動
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (enemyPosX + enemySpeed <= SCREEN_SIZE_X - ENEMY_SIZE_X)
		{
			enemyPosX = enemyPosX + enemySpeed;
		}
	}
	//上移動
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		if (enemyPosY >= enemySpeed)
		{
			enemyPosY = enemyPosY - enemySpeed;
		}
	}
	//下移動
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		if (enemyPosY + enemySpeed <= SCREEN_SIZE_Y - ENEMY_SIZE_Y)
		{
			enemyPosY = enemyPosY + enemySpeed;
		}
	}
	

}
//敵の描画
void EnemyDraw(void)
{
	//敵の表示
	DrawGraph(enemyPosX, enemyPosY, enemyImage, true);
	DrawBox(enemyPosX, enemyPosY, enemyPosX + ENEMY_SIZE_X, enemyPosY + ENEMY_SIZE_Y, 0xFFFFFF, false);

}
