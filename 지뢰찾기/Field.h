#ifndef __FIELD_CLASS__
#define __FIELD_CLASS__

class Field {
	// 정상적으로 찾은지뢰의 갯수
	static int find_mines;
	// 지뢰를 밟았는지 여부(Gave over)
	static bool bomb;

	//해당 블럭의 스크린 상태 여부. 유저가 클릭하면 보임. true=가림. false=열림(보임)
	bool block;
	//깃발 꽂힘 여부. false=안꽂힘. true-꽂힘. 지뢰에 깃발을 다 꼽으면 승리
	bool flag;
	//해당 블럭의 상태를 나타냄
	//0~8 주변지뢰 갯수. 9 지뢰. 10 깃발.
	int state;
public:
	//지뢰 밟음여부의 설정 및 접근자.(bomb는 static형 멤버변수)
	static void setBomb(bool b) { bomb = b; }
	static bool getBomb() { return bomb; }

	//생성자
	Field(int s = 0) :state(s) { block = true; flag = false; }

	//state 설정자 및 접근자
	void setState(int s) { state = s; }
	int getState() { return state; }
	//block 해제.설정 함수 및 접근자
	void openBlock() { block = false; }
	void closeBlock() { block = true; }
	bool getBlock() { return block; }
	//flag 접근자 및 깃발 꽂/뽑는 함수. find_mines에 변화 -> 게임종료 판별
	bool getFlag() { return flag; } // 깃발이 꽂혔는지(true) 안꽂혔는지(false)를 판별
	void Flag_on();
	void Flag_off();
	//찾은 지뢰 갯수 반환 -> 20개가 되면 게임 종료
	int getFindmines() { return find_mines; }
	//Init() 게임의 초기화시 사용. 찾은 지뢰의 갯수를 0으로 초기화
	void setFindmines() { find_mines = 0; }
};


#endif