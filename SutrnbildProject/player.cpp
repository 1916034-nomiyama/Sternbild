
#include "Dxlib.h"				//DxLibײ���؂��g�p����
#include "main.h"
#include "player.h"

//���@
int playerImage;				//��ڲ԰�̲Ұ��
int playerPosX;					//��ڲ԰��X���W
int playerPosY;					//��ڲ԰��Y���W
int playerSpeed;				//��ڲ԰�̈ړ���


//���@�̼��я����̏�����
void PlayerSystemInit(void)
{
	//���@
	playerPosX = (SCREEN_SIZE_X) / 2 - (PLAYER_SIZE_X) / 2;
	playerPosY = SCREEN_SIZE_Y - PLAYER_SIZE_Y;
	playerSpeed = 8;

}
//���@�̏�����
void PlayerInit(void)
{
	playerImage = LoadGraph("Image/player.png");		//Image�̒��ɂ���Ƃ����Ӗ��� / ���� \ ��t����

}
//���@�̑���
void PlayerControl(void)
{
	//------��ڲ԰�̷�����
//���ړ�
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		if (playerPosX >= playerSpeed)
		{
			playerPosX = playerPosX - playerSpeed;
		}
	}
	//�E�ړ�
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		if (playerPosX + playerSpeed <= SCREEN_SIZE_X - PLAYER_SIZE_X)
		{
			playerPosX = playerPosX + playerSpeed;
		}
	}
	//��ړ�
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		if (playerPosY >= playerSpeed)
		{
			playerPosY = playerPosY - playerSpeed;
		}
	}
	//���ړ�
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		if (playerPosY + playerSpeed <= SCREEN_SIZE_Y - PLAYER_SIZE_Y)
		{
			playerPosY = playerPosY + playerSpeed;
		}
	}

}
//���@�̕`��
void PlayerDraw(void)
{
	//�v���C���[�̕\��
	DrawGraph(playerPosX, playerPosY, playerImage, true);
	DrawBox(playerPosX, playerPosY, playerPosX + PLAYER_SIZE_X, playerPosY + PLAYER_SIZE_Y, 0xFFFFFF, false);

}
