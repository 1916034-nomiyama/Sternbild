//#pragma once

//�񋓌^
//-----------------------------------
enum KEY_ID
{
	KEY_ID_SPACE,				//�X�y�[�X�L�[
	KEY_ID_MOUSE_LEFT,			//�}�E�X���{�^��
	KEY_ID_MOUSE_MIDDLE,		//�}�E�X�z�C�[���{�^��
	KEY_ID_MOUSE_RIGHT,			//�}�E�X�E�{�^��
	KEY_ID_P,
	KEY_ID_MAX
};

extern bool keyOld[KEY_ID_MAX];			//1�t���[���O�̓��͏��
extern bool keyNew[KEY_ID_MAX];			//���݂̓��͏��
extern bool keyDownTrigger[KEY_ID_MAX];	//�_�E�����̃g���K�[
extern bool keyUpTrigger[KEY_ID_MAX];		//�A�b�v���̃g���K�[
extern int mouseButton;					//�}�E�X�̃{�^�����
extern int mouseButtonOld;					//�}�E�X�̃{�^�����


//�\����
//------------------------
//�v���g�^�C�v�錾
//-----------------------------------
void KeyInit(void);				//���͏��̏�����
void KeyCheck(void);			//���͏��̊m�F