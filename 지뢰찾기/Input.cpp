#include "Input.h"

//키 버퍼 - 입력된 키보드 값 보관
int key = NULL;

//키보드 입력 - 업데이트 함수
void InputUpdate()
{
	if (_kbhit())
	{
		key = getch();
	}
}

//키보드 입력 - 후 업데이트 함수
void InputLateUpdate()
{
	key = NULL;
}

//키보드 입력 확인 함수
bool KeyDown(int keyCode)
{
	if (key == keyCode) return true;
	else return false;
}

