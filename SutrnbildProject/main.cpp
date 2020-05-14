///////////////////////////////////////////////////////////////
//////////////////Sutrnbild～星座の動物たち～//////////////////
///////////////////////////////////////////////////////////////
//          <2020/05/14開始>～<2020/06/05終了予定>

#include "Dxlib.h"				//DxLibﾗｲﾌﾞﾗﾘを使用する

//-----定数の定義
#define SCREEN_SIZE_X 800		//画面の横ｻｲｽﾞ
#define SCREEN_SIZE_Y 600		//画面の縦ｻｲｽﾞ
#define PLAYER_SIZE_X 32		//ﾌﾟﾚｲﾔｰの横ｻｲｽﾞ
#define PLAYER_SIZE_Y 32		//ﾌﾟﾚｲﾔｰの縦ｻｲｽﾞ



//-----変数の定義
//自機
int playerImage;				//ﾌﾟﾚｲﾔｰのｲﾒｰｼﾞ
int playerPosX;					//ﾌﾟﾚｲﾔｰのX座標
int playerPosY;					//ﾌﾟﾚｲﾔｰのY座標
int playerSpeed;				//ﾌﾟﾚｲﾔｰの移動量



//==========WinMain
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//----------ｼｽﾃﾑ処理
	SetWindowText("Nakahara Yoshiharu");
	//ｼｽﾃﾑ処理
	SetGraphMode(SCREEN_SIZE_X,SCREEN_SIZE_Y, 16);		//640 * 480ﾄﾞｯﾄ65536色ﾓｰﾄﾞに設定
		ChangeWindowMode(true);				//true:window  false:ﾌﾙｽｸﾘｰﾝ
	if (DxLib_Init() == -1) return -1;		//DXﾗｲﾌﾞﾗﾘ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);			//ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画

	//----------グラフィックの登録----------
	playerImage = LoadGraph("Image/player.png");		//Imageの中にあるという意味で / 又は \ を付ける

	//----------変数の初期化----------
	//自機
	playerPosX = (SCREEN_SIZE_X) / 2 - (PLAYER_SIZE_X) / 2;
	playerPosY = SCREEN_SIZE_Y - PLAYER_SIZE_Y;
	playerSpeed = 8;

	//----------ｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
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

						//画面描画処理
		ClsDrawScreen();//描画の消去
						//背景の表示

		//プレイヤーの表示
		DrawGraph(playerPosX, playerPosY, playerImage, true);
		DrawBox(playerPosX, playerPosY, playerPosX + PLAYER_SIZE_X, playerPosY + PLAYER_SIZE_Y, 0xFFFFFF, false);



		ScreenFlip(); //裏画面を表画面に瞬間ｺﾋﾟｰ
	}
	DxLib_End();	//DXﾗｲﾌﾞﾗﾘの終了処理
	return 0;		//このﾌﾟﾛｸﾞﾗﾑの終了
}