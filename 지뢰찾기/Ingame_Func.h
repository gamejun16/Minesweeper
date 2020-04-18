#ifndef __INGAME_FUNC__
#define __INGAME_FUNC__
#include "Scene.h"
#include "Field.h"

//UI탭을 그림
void Draw_UI(void);

//블럭 설정 (지뢰 설치 및 번호 부여)
void set_Blocks(Field *f);
//블럭 주변 지뢰 검사 후 갯수 반환
int Find_Mines(Field *f, int i);
//주변 state가 0인 블럭을 찾아 오픈
void Find_Safes(Field *f, int i);
//필드를 계속해서 그려냄
void Draw_Field(Field *f);
//마우스 입력을 받아 필드에 변화를 가하는 함수
void Game_Playing(Field *f, HANDLE hIn,INPUT_RECORD rec, DWORD dw);

#endif