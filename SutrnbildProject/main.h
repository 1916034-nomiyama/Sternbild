#pragma once



//-----定数の定義
#define SCREEN_SIZE_X 800		//画面の横ｻｲｽﾞ
#define SCREEN_SIZE_Y 600		//画面の縦ｻｲｽﾞ
#define PLAYER_SIZE_X 32		//ﾌﾟﾚｲﾔｰの横ｻｲｽﾞ
#define PLAYER_SIZE_Y 32		//ﾌﾟﾚｲﾔｰの縦ｻｲｽﾞ

enum SCENE
{
	SCENE_INIT,					//ゲーム初期化シーン
	SCENE_TITLE,				//タイトルシーン
	SCENE_GAME,					//ゲームシーン
	SCENE_GAMEOVER,				//ゲームオーバーシーン
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



