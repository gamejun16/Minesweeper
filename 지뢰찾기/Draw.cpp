#include "Draw.h"

void Draw(int x, int y, int color, char *text, ...)
{
	//콘솔 내 커서위치 지정
	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	//"..."을 통해 들어온 변수들을 문자열로 처리하기 위한 방법
	va_list va_ptr;
	char msg[512] = { NULL, };
	va_start(va_ptr, text);
	vsprintf(msg, text, va_ptr);
	va_end(va_ptr);
	//색상지정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//그리기
	printf("%s", msg);
	//색상 원래대로 지정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}

void removeCursor(void)//커서 깜빡임 제거
{
	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}

void ChangeConsoleSize(HANDLE hBuffer, int cx, int cy)
{
	enum EFlag
	{
		FlagNoChange,
		FlagWindowFirst,
		FlagScreenFirst
	};

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hBuffer, &csbi);
	csbi.srWindow.Right -= csbi.srWindow.Left;
	csbi.srWindow.Bottom -= csbi.srWindow.Top;
	csbi.srWindow.Left = 0;
	csbi.srWindow.Top = 0;
	SetConsoleWindowInfo(hBuffer, TRUE, &csbi.srWindow);

	COORD coordLargestSize = GetLargestConsoleWindowSize(hBuffer);
	COORD coordNewSize = { min(coordLargestSize.X, cx), min(coordLargestSize.Y, cy) };
	COORD coordWindowSize = { csbi.srWindow.Right + 1, csbi.srWindow.Bottom + 1 };
	SMALL_RECT srWindowRect = {};

	EFlag eFlag = FlagNoChange;

	if (coordWindowSize.Y > coordNewSize.Y)
	{
		if (coordWindowSize.X < coordNewSize.X)
		{
			SMALL_RECT srNewWindow = csbi.srWindow;
			srNewWindow.Bottom = coordNewSize.Y - 1;
			SetConsoleWindowInfo(hBuffer, TRUE, &srNewWindow);
			eFlag = FlagScreenFirst;
		}
		else
		{
			eFlag = FlagWindowFirst;
		}
	}
	else if (coordWindowSize.Y < coordNewSize.Y)
	{
		if (coordWindowSize.X > coordNewSize.X)
		{
			SMALL_RECT srNewWindow = csbi.srWindow;
			srNewWindow.Right = coordNewSize.X - 1;
			SetConsoleWindowInfo(hBuffer, TRUE, &srNewWindow);
		}
		eFlag = FlagScreenFirst;
	}
	else
	{
		if (coordWindowSize.X > coordNewSize.X)
		{
			eFlag = FlagWindowFirst;
		}
		else if (coordWindowSize.X < coordNewSize.X)
		{
			eFlag = FlagScreenFirst;
		}
	}


	if (eFlag != FlagNoChange)
	{
		srWindowRect.Right = coordNewSize.X - 1;
		srWindowRect.Bottom = coordNewSize.Y - 1;
		if (eFlag == FlagWindowFirst)
		{
			SetConsoleWindowInfo(hBuffer, TRUE, &srWindowRect);
			SetConsoleScreenBufferSize(hBuffer, coordNewSize);
		}
		else
		{
			SetConsoleScreenBufferSize(hBuffer, coordNewSize);
			SetConsoleWindowInfo(hBuffer, TRUE, &srWindowRect);
		}
	}
}