#ifndef __INGAME_FUNC__
#define __INGAME_FUNC__
#include "Scene.h"
#include "Field.h"

//UI���� �׸�
void Draw_UI(void);

//�� ���� (���� ��ġ �� ��ȣ �ο�)
void set_Blocks(Field *f);
//�� �ֺ� ���� �˻� �� ���� ��ȯ
int Find_Mines(Field *f, int i);
//�ֺ� state�� 0�� ���� ã�� ����
void Find_Safes(Field *f, int i);
//�ʵ带 ����ؼ� �׷���
void Draw_Field(Field *f);
//���콺 �Է��� �޾� �ʵ忡 ��ȭ�� ���ϴ� �Լ�
void Game_Playing(Field *f, HANDLE hIn,INPUT_RECORD rec, DWORD dw);

#endif