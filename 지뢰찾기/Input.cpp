#include "Input.h"

//Ű ���� - �Էµ� Ű���� �� ����
int key = NULL;

//Ű���� �Է� - ������Ʈ �Լ�
void InputUpdate()
{
	if (_kbhit())
	{
		key = getch();
	}
}

//Ű���� �Է� - �� ������Ʈ �Լ�
void InputLateUpdate()
{
	key = NULL;
}

//Ű���� �Է� Ȯ�� �Լ�
bool KeyDown(int keyCode)
{
	if (key == keyCode) return true;
	else return false;
}

