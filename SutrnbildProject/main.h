//#pragma once


//�萔
//-----------------------------------
#define SCREEN_SIZE_X 800		//��ʃT�C�Y��
#define SCREEN_SIZE_Y 600		//��ʃT�C�Y�c
#define BG_SIZE_X     800
#define BG_SIZE_Y	  600


//�񋓌^
//-----------------------------------
enum SCENE
{
	SCENE_INIT,					//�Q�[���������V�[��
	SCENE_TITLE,				//�^�C�g���V�[��
	SCENE_GAME,					//�Q�[���V�[��
	SCENE_GAMEOVER,				//�Q�[���I�[�o�[�V�[��
	SCENE_MAX
};

enum MOVE_DIR {
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};
//�\����
//------------------------
//���W�i�[�p
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
	MOVE_DIR moveDir;	//�����Ă������
	XY pos;			//�L�����N�^�̈ʒu�i���S�j
	XY size;		//�L�����N�^�摜�̃T�C�Y
	XY sizeOffset;		//�L�����N�^��������̍���ʒu
	XY hitPosS;		//�����蔻��p�̍���
	XY hitPosE;		//�����蔻��p�̉E��
	bool runFlag;		//�L�����N�^�̏�ԁi�����Ă��邩�H�j
	bool jumpFlag;		//�L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	bool shotFlag;		//�L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	bool damageFlag;	//�L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	int moveSpeed;		//�L�����N�^�̈ړ���
	int life;		//�L�����N�^�̗̑�
	int lifeMax;		//�L�����N�^�̗͍̑ő�
	int animCnt;		//�L�����N�^�̃A�j���[�V�����p�J�E���^
	int imgLockCnt;		//�L�����N�^�̃C���[�W�Œ�p�J�E���^
} ;
//�v���g�^�C�v�錾
//-----------------------------------
bool SystemInit(void);			//�V�X�e���̏�����
void InitScene(void);			//�������p�V�[��
void TitleScene(void);			//�Z���N�g�V�[��
void TitleDraw(void);			//�Z���N�g�V�[���`��
void GameScene(void);			//�Q�[���V�[��
void GameDraw(void);			//�Q�[���V�[���`��
void GameOverScene(void);		//�Q�[���I�[�o�[�V�[��
void GameOverDraw(void);		//�Q�[���I�[�o�[�V�[���`��