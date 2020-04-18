#ifndef __FIELD_CLASS__
#define __FIELD_CLASS__

class Field {
	// ���������� ã�������� ����
	static int find_mines;
	// ���ڸ� ��Ҵ��� ����(Gave over)
	static bool bomb;

	//�ش� ���� ��ũ�� ���� ����. ������ Ŭ���ϸ� ����. true=����. false=����(����)
	bool block;
	//��� ���� ����. false=�Ȳ���. true-����. ���ڿ� ����� �� ������ �¸�
	bool flag;
	//�ش� ���� ���¸� ��Ÿ��
	//0~8 �ֺ����� ����. 9 ����. 10 ���.
	int state;
public:
	//���� ���������� ���� �� ������.(bomb�� static�� �������)
	static void setBomb(bool b) { bomb = b; }
	static bool getBomb() { return bomb; }

	//������
	Field(int s = 0) :state(s) { block = true; flag = false; }

	//state ������ �� ������
	void setState(int s) { state = s; }
	int getState() { return state; }
	//block ����.���� �Լ� �� ������
	void openBlock() { block = false; }
	void closeBlock() { block = true; }
	bool getBlock() { return block; }
	//flag ������ �� ��� ��/�̴� �Լ�. find_mines�� ��ȭ -> �������� �Ǻ�
	bool getFlag() { return flag; } // ����� ��������(true) �Ȳ�������(false)�� �Ǻ�
	void Flag_on();
	void Flag_off();
	//ã�� ���� ���� ��ȯ -> 20���� �Ǹ� ���� ����
	int getFindmines() { return find_mines; }
	//Init() ������ �ʱ�ȭ�� ���. ã�� ������ ������ 0���� �ʱ�ȭ
	void setFindmines() { find_mines = 0; }
};


#endif