#pragma once



//-----�萔�̒�`
#define SCREEN_SIZE_X 800		//��ʂ̉�����
#define SCREEN_SIZE_Y 600		//��ʂ̏c����
#define PLAYER_SIZE_X 32		//��ڲ԰�̉�����
#define PLAYER_SIZE_Y 32		//��ڲ԰�̏c����

enum SCENE
{
	SCENE_INIT,					//�Q�[���������V�[��
	SCENE_TITLE,				//�^�C�g���V�[��
	SCENE_GAME,					//�Q�[���V�[��
	SCENE_GAMEOVER,				//�Q�[���I�[�o�[�V�[��
	SCENE_MAX
};


bool SystemInit(void);
void InitScene(void);
void TitleScene(void);
void TitleDraw(void);
void GameScene(void);
void GameDraw(void);
void GameOverScene(void);
void GameOverDraw(void);



