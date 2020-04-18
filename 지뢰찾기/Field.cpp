#include "Field.h"

//깃발 꼽는 함수
void Field::Flag_on() {
	flag = true;
	//지뢰에 깃발을 꼽았다면. find_mines에 +1. 20이 되면 게임종료
	if (state == 9) find_mines++;
}

//깃발 뽑은 함수
void Field::Flag_off() {
	flag = false;
	//지뢰였는데 깃발을 뽑았다면. find_mines에 -1.
	if (state == 9) find_mines--;
}

//찾은 지뢰 갯수. 처음엔 0으로 설정
int Field::find_mines = 0;
//지뢰를 밟았는지(Gave over) 여부. 기본 false, 밟으면 true
bool Field::bomb = false;

