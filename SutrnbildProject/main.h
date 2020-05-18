//#pragma once


//定数
//-----------------------------------
#define SCREEN_SIZE_X 800		//画面サイズ横
#define SCREEN_SIZE_Y 600		//画面サイズ縦
#define BG_SIZE_X     800
#define BG_SIZE_Y	  600


//列挙型
//-----------------------------------
enum SCENE
{
	SCENE_INIT,					//ゲーム初期化シーン
	SCENE_TITLE,				//タイトルシーン
	SCENE_GAME,					//ゲームシーン
	SCENE_GAMEOVER,				//ゲームオーバーシーン
	SCENE_MAX
};

enum MOVE_DIR {
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};
//構造体
//------------------------
//座標格納用
struct POS
{
	int x, y;
};

struct XY
{
	int x;
	int y;
};

struct CHARACTERS {
	MOVE_DIR moveDir;	//向いている方向
	XY pos;			//キャラクタの位置（中心）
	XY size;		//キャラクタ画像のサイズ
	XY sizeOffset;		//キャラクタ中央からの左上位置
	XY hitPosS;		//当たり判定用の左上
	XY hitPosE;		//当たり判定用の右下
	bool runFlag;		//キャラクタの状態（走っているか？）
	bool jumpFlag;		//キャラクタの状態（ジャンプしているか？）
	bool shotFlag;		//キャラクタの状態（弾撃っているか？）
	bool damageFlag;	//キャラクタの状態（ダメージ受けているか？）
	int moveSpeed;		//キャラクタの移動量
	int life;		//キャラクタの体力
	int lifeMax;		//キャラクタの体力最大
	int animCnt;		//キャラクタのアニメーション用カウンタ
	int imgLockCnt;		//キャラクタのイメージ固定用カウンタ
} ;
//プロトタイプ宣言
//-----------------------------------
bool SystemInit(void);			//システムの初期化
void InitScene(void);			//初期化用シーン
void TitleScene(void);			//セレクトシーン
void TitleDraw(void);			//セレクトシーン描画
void GameScene(void);			//ゲームシーン
void GameDraw(void);			//ゲームシーン描画
void GameOverScene(void);		//ゲームオーバーシーン
void GameOverDraw(void);		//ゲームオーバーシーン描画