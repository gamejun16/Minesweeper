// 필요 헤더 파일 포함
#include "Scene.h"
#include "Ingame_Func.h"
#include "Field.h"

//필드 객체
Field field[80];
//Init()함수를 한번만 부르기 위함
bool Init_Once = true;

// 입출력에 사용될 핸들을 생성.
HANDLE hIn, hOut;
INPUT_RECORD rec;
DWORD dw;

//인게임 씬(Scene Ingame) 초기화 함수
void Scene_Ingame_Init()
{
	//콘솔창 정리
	for (int i = 2; i <= 13; i++) {
		Draw(4, i, RED, "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	}
	//UI탭을 그려냄.
	Draw_UI();
	//모든 블럭을 가린 후 깃발을 제거하고 state를 0으로 설정(지뢰 제거)
	for (int i = 0; i < 80; i++) {
		field[i].closeBlock();
		field[i].Flag_off();
		field[i].setState(0);
	}
	//찾은 지뢰의 갯수를 0개로 초기화
	field->setFindmines();
	//지뢰 설치
	set_Blocks(field);

	//지뢰 발견시 true되는 static bool형 bomb변수를 false로 설정
	Field::setBomb(false);

	// 입출력에 사용될 핸들을 가져옴.
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

//인게임 씬(Scene Ingame) 렌더링 함수
bool Scene_Ingame_Render(float timeDelta)
{
	//Init()함수를 한번만 거치게 하기 위한 작업
	if (Init_Once) {
		Scene_Ingame_Init();
		Init_Once = false;
	}

	// 마우스 제어가 일어났 을 경우에만 ReadConsoleInput()함수를 거침.
	PeekConsoleInput(hIn, &rec, 1, &dw);
	if (dw > 0) {
		//마우스 클릭 시 해당 블럭을 오픈.
		Game_Playing(field, hIn, rec, dw);
	}
	Draw_Field(field);

	return true;
}
