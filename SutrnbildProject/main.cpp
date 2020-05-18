//--------------------------------------------------------
//
//					main.cpp
//
//--------------------------------------------------------

#include "DxLib.h"					//DxLibײ���؂��g�p����
#include "main.h"
#include "KeyCheck.h"
#include "effect.h"
#include "player.h"
#include "enemy.h"

//�ϐ��̒�`
//--------------------------------------------------------
//�V�[���Ǘ��p
SCENE sceneID;						//���݂̃V�[��
SCENE preSceneID;					//�ЂƂO�̃V�[��
int sceneCounter;					//�J�E���^�[

int titleImage;




int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SystemInit();

	SetDrawScreen(DX_SCREEN_BACK);									//�ЂƂ܂��ޯ��ޯ̧�ɕ`��

	//�ް�ٰ��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		ClsDrawScreen();				//��ʏ���

		//�V�[���J�E���^�̏�����
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
		DxLib_End();			//DXײ���؂̏I������
		return 0;				//������۸��т̏I��
}

//�V�X�e���̏�����
bool SystemInit(void)
{

	bool retFlag = true;  //�֐��̖߂�l

	//----------���я���
	SetWindowText("1916030_�����p��");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);					//800*320�ޯ�65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);											// true:window false:�ٽ�ذ�
	if (DxLib_Init() == -1)
		return false;												//DXײ���؏���������

	EffectInit();
	KeyCheck();
	PlayerSystemInit();
	EnemySystemInit();

	//�O���t�B�b�N�̓o�^
	titleImage = LoadGraph("bs1.jpg");
	//---------------------

	//�ϐ��̏�����
	sceneCounter = 0;
	preSceneID = SCENE_MAX;
	sceneID = SCENE_TITLE;



	return retFlag;

}
//�������V�[��
void InitScene(void)
{
	
}
//�^�C�g���V�[��
void TitleScene(void)
{
	TitleDraw();
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}
}
//�^�C�g���`��
void TitleDraw(void)
{

	DrawFormatString(0, 0, 0xffffff, "Count:%d", sceneCounter);
	DrawBox(100, 100, SCREEN_SIZE_X - 100, SCREEN_SIZE_Y - 100, 0x00ffff, 1);
	DrawFormatString(350, 300, 0x000000, "GAME START");
	
}
//�Q�[���V�[��
void GameScene(void)
{
	PlayerControl();
	EnemyControl();

	if (keyDownTrigger[KEY_ID_P])
	{
		pauseFlag = !pauseFlag;
	}
	//Pause��
	if (pauseFlag)
	{
		SetDrawBright(128, 128, 128);
	}
	//�ʏ퓮�쎞
	else
	{
		aaaa++;
	}
	//��ʕ`��
	GameDraw();
	//Pause���b�Z�[�W��`��
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
//�Q�[���V�[���`��
void GameDraw(void)
{
	PlayerDraw();
	EnemyDraw();
	DrawGraph(50,50,titleImage,true);
	DrawFormatString(50, 50, 0xffff00, "%d", aaaa); 
	DrawFormatString(0, 0, 0xffffff, "Count:%d", sceneCounter);
}
//�Q�[���I�[�o�[�V�[��
void GameOverScene(void)
{
	GameOverDraw();
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}
}
//�Q�[���I�[�o�[�V�[���`��
void GameOverDraw(void)
{
	DrawFormatString(0, 0, 0xffffff, "Count:%d", sceneCounter);
	DrawBox(100,100,SCREEN_SIZE_X-100,SCREEN_SIZE_Y-100,0xff00ff,1);
	DrawFormatString(350,300,0xffffff,"GAME OVER");
}
