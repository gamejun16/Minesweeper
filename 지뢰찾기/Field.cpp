#include "Field.h"

//��� �Ŵ� �Լ�
void Field::Flag_on() {
	flag = true;
	//���ڿ� ����� �žҴٸ�. find_mines�� +1. 20�� �Ǹ� ��������
	if (state == 9) find_mines++;
}

//��� ���� �Լ�
void Field::Flag_off() {
	flag = false;
	//���ڿ��µ� ����� �̾Ҵٸ�. find_mines�� -1.
	if (state == 9) find_mines--;
}

//ã�� ���� ����. ó���� 0���� ����
int Field::find_mines = 0;
//���ڸ� ��Ҵ���(Gave over) ����. �⺻ false, ������ true
bool Field::bomb = false;

