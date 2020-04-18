#include "Ingame_Func.h"
#include "Scene.h"
#include "Field.h"

#include <ctime>
#include <stdlib.h>

// 지뢰 갯수
#define BOMB_COUNT 15

//UI탭을 그림
void Draw_UI(void)
{
	// UI 정보 초기화
	Draw(38, 4, WHITE, "　　　　　　　　　　");
	Draw(38, 6, WHITE, "　　　　　　　　　");


	/*
	EASY 난이도
	Draw(4, 2, BG_GRAY, "　　　　　　　");
	Draw(4, 3, BG_GRAY, "　　　　　　　");
	Draw(4, 4, BG_GRAY, "　　　　　　　");
	Draw(4, 5, BG_GRAY, "　"); Draw(16, 5, BG_GRAY, "　");
	Draw(4, 6, BG_GRAY, "　"); Draw(16, 6, BG_GRAY, "　");
	Draw(4, 7, BG_GRAY, "　"); Draw(16, 7, BG_GRAY, "　");
	Draw(4, 8, BG_GRAY, "　"); Draw(16, 8, BG_GRAY, "　");
	Draw(4, 9, BG_GRAY, "　"); Draw(16, 9, BG_GRAY, "　");
	Draw(4, 10, BG_GRAY, "　　　　　　　");
	*/


	Draw(4, 2, BG_GRAY, "　　　　　　　　　　　　");
	Draw(4, 3, BG_GRAY, "　　　　　 "); Draw(15, 3, RED | BG_GRAY, ":^l"); Draw(18, 3, BG_GRAY, " 　　　　 ");
	Draw(4, 4, BG_GRAY, "　　　　　　　　　　　　");
	Draw(4, 5, BG_GRAY, "　"); Draw(26, 5, BG_GRAY, "　");
	Draw(4, 6, BG_GRAY, "　"); Draw(26, 6, BG_GRAY, "　");
	Draw(4, 7, BG_GRAY, "　"); Draw(26, 7, BG_GRAY, "　");
	Draw(4, 8, BG_GRAY, "　"); Draw(26, 8, BG_GRAY, "　");
	Draw(4, 9, BG_GRAY, "　"); Draw(26, 9, BG_GRAY, "　");
	Draw(4, 10, BG_GRAY, "　"); Draw(26, 10, BG_GRAY, "　");
	Draw(4, 11, BG_GRAY, "　"); Draw(26, 11, BG_GRAY, "　");
	Draw(4, 12, BG_GRAY, "　"); Draw(26, 12, BG_GRAY, "　");
	Draw(4, 13, BG_GRAY, "　　　　　　　　　　　　");

	// 게임 설명 //
	Draw(32, 4, WHITE, "좌클릭 : 땅 파기");
	Draw(32, 5, WHITE, "우클릭 : 깃발 꽂기");
	Draw(32, 6, RED|BG_GRAY, ":^l");
	Draw(36,6,WHITE,": 재시작");
}

//블럭 설정 (지뢰 설치 및 번호 부여)
void set_Blocks(Field *f) {
	//BOMB_COUNT 개의 지뢰 설치
	for (int i = 0; i < BOMB_COUNT; i++) {
		int r = rand() % 80;
		// 이미 지뢰라면 한 바퀴 더 돌림
		if(f[r].getState() == 9)
			i--;
		// 지뢰가 아니라면 지뢰 설치
		else if (f[r].getState() != 9)
			f[r].setState(9);	
	}

	//번호 부여
	for (int i = 0; i < 80; i++) {
		//이미 지뢰라면 패스
		if (f[i].getState() == 9) continue;

		//지뢰가 아님. 주변 지뢰검사 후 번호 부여
		else {
			//state에 지뢰갯수 부여
			f[i].setState(Find_Mines(f, i));
		}
	}
}

//주변 지뢰를 찾아 갯수를 반환. 블럭의 숫자 결정
int Find_Mines(Field *f, int i) {
	//지뢰 갯수 (반환될 값)
	int mines = 0;


	//2차원 행렬로 봤을 때. 검사의 대상이 되는 블럭을 기준으로 왼쪽의 3블럭 검사
	if (i % 10 != 0) {
		//좌측상단
		if (f[i - 11].getState() == 9) mines++;
		//좌측
		if (f[i - 1].getState() == 9) mines++;
		//좌측하단
		if (f[i + 9].getState() == 9) mines++;
	}

	//위 아래 2블럭을 검사
	if (f[i - 10].getState() == 9) mines++;
	if (f[i + 10].getState() == 9) mines++;


	//오른쪽 3블럭 검사
	if (i % 10 != 9) {
		//우측상단
		if (f[i - 9].getState() == 9) mines++;
		//우측
		if (f[i + 1].getState() == 9) mines++;
		//우측하단
		if (f[i + 11].getState() == 9) mines++;
	}


	//주변 지뢰 갯수 반환
	return mines;
}

//주변 state가 0인 블럭(주변에 아무 지뢰도 없는 안전한 블럭)을 찾아 연쇄적으로 오픈.
void Find_Safes(Field *f, int i) {

	//2차원 행렬로 봤을 때. 검사의 대상이 되는 블럭을 기준으로 왼쪽의 3블럭 검사
	if (i % 10 != 0) {
		/*
		//좌측상단. 지뢰가주변에 없으면서 이미 오픈된 블럭이 아니라면
		if (f[i - 11].getState() == 0 && f[i - 11].getBlock()==true) {
			f[i - 11].openBlock();
			Find_Safes(f, i - 11);
		}
		*/
		//좌측
		if (f[i - 1].getState() == 0 && f[i-1].getBlock() == true) {
			f[i - 1].openBlock();
			Find_Safes(f, i - 1);
		}
		/*
		//좌측하단
		if (f[i + 9].getState() == 0&&f[i+9].getBlock() == true) {
			f[i + 9].openBlock();
			Find_Safes(f, i + 9);
		}
		*/
	}

	//위 아래 2블럭을 검사
	if (f[i - 10].getState() == 0 && f[i-10].getBlock() == true) {
		f[i - 10].openBlock();
		Find_Safes(f,i - 10);
	}
	if (f[i + 10].getState() == 0 && f[i+10].getBlock() == true) {
		f[i + 10].openBlock();
		Find_Safes(f, i + 10);
	}


	//오른쪽 3블럭 검사
	if (i % 10 != 9) {
		/*
		//우측상단
		if (f[i - 9].getState() == 0 && f[i-9].getBlock() == true) {
			f[i - 9].openBlock();
			Find_Safes(f, i - 9);
		}
		*/
		//우측
		if (f[i + 1].getState() == 0 && f[i+1].getBlock() == true) {
			f[i + 1].openBlock();
			Find_Safes(f, i + 1);
		}
		//우측하단
		/*
		if (f[i + 11].getState() == 0 && f[i+11].getBlock() == true) {
			f[i + 11].openBlock();
			Find_Safes(f, i + 11);
		}
		*/
	}
}

//게임 종료 확인 함수
/*
Draw_Field() 함수에서 지뢰를 그려내는 시점에 검사.
지뢰를 밟을 경우 유저로부터 키 입력을 받고 엔딩 씬으로 넘김
*/
//지뢰를 밟았거나(GameOver), 모든 지뢰를 찾은 경우(GameClear)
void OverCheck(Field *f) {
	//지뢰를 밟았다면(Game over)
	if (Field::getBomb() == true) {
		Scene_Gameset_Init();
		SceneNumber = GAMESET;
	}
	//BOME_COUNT 개의 지뢰를 모두 찾았다면(Game Clear)
	if (f->getFindmines() == BOMB_COUNT) {
		Scene_Gameclear_Init();
		SceneNumber = GAMECLEAR;
	}

}

//필드를 계속해서 그려냄
void Draw_Field(Field *f) {
	//인덱스 번호
	int index = 0;
	//y축
	for (int y = 5; y < 13; y++) {
		//x축
		for (int x = 6; x < 26; x += 2, index++) {
			//오픈되지 않았고 깃발이 없다면
			if(f[index].getBlock() == true &&f[index].getFlag() == false)
				Draw(x, y, DGRAY, "■");
			//오픈되지 않았고 깃발이 있다면
			else if (f[index].getBlock() == true && f[index].getFlag() == true)
				Draw(x, y, GREEN, "▶");
			//오픈되었다면
			else if (f[index].getBlock() == false) {
				switch (f[index].getState()) {
					//지뢰
				case 9:
					Draw(x, y, RED, "■");
					break;
				case 0:
					Draw(x, y, BLUE | BG_DGRAY, "０");
					break;
				case 1:
					Draw(x, y, BLUE | BG_DGRAY, "１");
					break;
				case 2:
					Draw(x, y, BLUE | BG_DGRAY, "２");
					break;
				case 3:
					Draw(x, y, BLUE | BG_DGRAY, "３");
					break;
				case 4:
					Draw(x, y, BLUE | BG_DGRAY, "４");
					break;
				case 5:
					Draw(x, y, BLUE | BG_DGRAY, "５");
					break;
				case 6:
					Draw(x, y, BLUE | BG_DGRAY, "６");
					break;
				case 7:
					Draw(x, y, BLUE | BG_DGRAY, "７");
					break;
				case 8:
					Draw(x, y, BLUE | BG_DGRAY, "８");
					break;
				}
			}
		}
	}

	// UI탭 출력
	Draw(32, 8, WHITE, "총 지뢰 수 : %d" , BOMB_COUNT);
	//Draw(40, 6, WHITE, "찾은 지뢰 수 : %d", f->getFindmines());

	// 게임 종료 판별 (지뢰를 밟았거나 모두 찾았거나)
	OverCheck(f);
}

//마우스 입력을 받아 필드에 변화를 가하는 함수
/*
	마우스 클릭 좌푯값 -> 배열 인덱스 값 직행 공식
	f[((y-5)*10)+((x-6)/2)]

*/
void Game_Playing(Field *f, HANDLE hIn, INPUT_RECORD rec, DWORD dw) {
	COORD pos = rec.Event.MouseEvent.dwMousePosition;

	//입력된 값을 읽음
	ReadConsoleInput(hIn, &rec, 1, &dw);
	//좌클릭이라면
	if (rec.Event.MouseEvent.dwButtonState &FROM_LEFT_1ST_BUTTON_PRESSED) {
		//클릭이 필드 범위 내에서 일어났다면
		if ((pos.X >= 6 && pos.X <= 25) && (pos.Y >= 5 && pos.Y <= 12)) {
			//해당 블럭이 눌리지 않았고 깃발이 없는 상태라면
			if (f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getBlock() == true && f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getFlag() == false) {
				//오픈
				f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].openBlock();
				Find_Safes(f, ((pos.Y - 5) * 10) + ((pos.X - 6) / 2));

				//오픈된 블록이 지뢰였다면, -> 지뢰를 밟았다면
				if (f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getState() == 9) {
					Field::setBomb(true); // 지뢰밟음. 즉 게임종료
				}
			}
		}
		//리겜 아이콘 클릭시
		else if ((pos.X >= 15 && pos.X <= 16) && pos.Y == 3)
			Scene_Ingame_Init();
	}
	
	//우클릭이라면
	else if (rec.Event.MouseEvent.dwButtonState &RIGHTMOST_BUTTON_PRESSED) {
		//클릭이 필드 범위 내에서 일어났다면
		if ((pos.X >= 6 && pos.X <= 25) && (pos.Y >= 5 && pos.Y <= 12)) {
			//해당 블럭이 오픈되지 않았으며 깃발이 꼽혀 있지 않다면
			if (f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getBlock() == true && f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getFlag() == false) {
				//깃발 꼽
				f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].Flag_on();
				//만약 지뢰였다면? bomb를 true로 -> 게임 종료 여부 판별에 쓰임
				//if (f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getState() == 9)
				//	Field::setBomb(true); // < 지뢰를 밟았음.
			}
			//해당 블럭이 오픈되지 않았으며 깃발이 꼽혀 있다면
			else if(f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getBlock() == true && f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getFlag() == true)
				//깃발 뽑
				f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].Flag_off();
		}
	}
}

