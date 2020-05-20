#include "DxLib.h"
#include "main.h"
#include "enemy.h"

#define ENEMY_SIZE_X 64		//�G�̃T�C�Y�i���j
#define ENEMY_SIZE_Y 64		//�G�̃T�C�Y�i�c�j

int enemyImage;				//�G�̉摜
int enemyPosX;				//
int enemyPosY;				//
int enemySpeed;				//�G�̑��x
int enemyFlag;				//�G��ON�FOFF

//�G�̃V�X�e���̏�����
void EnemySystemInit(void)
{
	//�G
	enemyPosX = (SCREEN_SIZE_X/2) - (ENEMY_SIZE_X/2);
	enemyPosY = 0;
	enemySpeed = 4;
	enemyImage = LoadGraph("enemy.png");

}
//�������p
void EnemyInit(void)
{

}
//����p
void EnemyControl(void)
{
	
	//���ړ�
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (enemyPosX >= enemySpeed)
		{
			enemyPosX = enemyPosX - enemySpeed;
		}
	}
	//�E�ړ�
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (enemyPosX + enemySpeed <= SCREEN_SIZE_X - ENEMY_SIZE_X)
		{
			enemyPosX = enemyPosX + enemySpeed;
		}
	}
	//��ړ�
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		if (enemyPosY >= enemySpeed)
		{
			enemyPosY = enemyPosY - enemySpeed;
		}
	}
	//���ړ�
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		if (enemyPosY + enemySpeed <= SCREEN_SIZE_Y - ENEMY_SIZE_Y)
		{
			enemyPosY = enemyPosY + enemySpeed;
		}
	}
	

}
//�G�̕`��
void EnemyDraw(void)
{
	//�G�̕\��
	DrawGraph(enemyPosX, enemyPosY, enemyImage, true);
	DrawBox(enemyPosX, enemyPosY, enemyPosX + ENEMY_SIZE_X, enemyPosY + ENEMY_SIZE_Y, 0xFFFFFF, false);

}
