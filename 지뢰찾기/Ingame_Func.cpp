#include "Ingame_Func.h"
#include "Scene.h"
#include "Field.h"

#include <ctime>
#include <stdlib.h>

// ���� ����
#define BOMB_COUNT 15

//UI���� �׸�
void Draw_UI(void)
{
	// UI ���� �ʱ�ȭ
	Draw(38, 4, WHITE, "��������������������");
	Draw(38, 6, WHITE, "������������������");


	/*
	EASY ���̵�
	Draw(4, 2, BG_GRAY, "��������������");
	Draw(4, 3, BG_GRAY, "��������������");
	Draw(4, 4, BG_GRAY, "��������������");
	Draw(4, 5, BG_GRAY, "��"); Draw(16, 5, BG_GRAY, "��");
	Draw(4, 6, BG_GRAY, "��"); Draw(16, 6, BG_GRAY, "��");
	Draw(4, 7, BG_GRAY, "��"); Draw(16, 7, BG_GRAY, "��");
	Draw(4, 8, BG_GRAY, "��"); Draw(16, 8, BG_GRAY, "��");
	Draw(4, 9, BG_GRAY, "��"); Draw(16, 9, BG_GRAY, "��");
	Draw(4, 10, BG_GRAY, "��������������");
	*/


	Draw(4, 2, BG_GRAY, "������������������������");
	Draw(4, 3, BG_GRAY, "���������� "); Draw(15, 3, RED | BG_GRAY, ":^l"); Draw(18, 3, BG_GRAY, " �������� ");
	Draw(4, 4, BG_GRAY, "������������������������");
	Draw(4, 5, BG_GRAY, "��"); Draw(26, 5, BG_GRAY, "��");
	Draw(4, 6, BG_GRAY, "��"); Draw(26, 6, BG_GRAY, "��");
	Draw(4, 7, BG_GRAY, "��"); Draw(26, 7, BG_GRAY, "��");
	Draw(4, 8, BG_GRAY, "��"); Draw(26, 8, BG_GRAY, "��");
	Draw(4, 9, BG_GRAY, "��"); Draw(26, 9, BG_GRAY, "��");
	Draw(4, 10, BG_GRAY, "��"); Draw(26, 10, BG_GRAY, "��");
	Draw(4, 11, BG_GRAY, "��"); Draw(26, 11, BG_GRAY, "��");
	Draw(4, 12, BG_GRAY, "��"); Draw(26, 12, BG_GRAY, "��");
	Draw(4, 13, BG_GRAY, "������������������������");

	// ���� ���� //
	Draw(32, 4, WHITE, "��Ŭ�� : �� �ı�");
	Draw(32, 5, WHITE, "��Ŭ�� : ��� �ȱ�");
	Draw(32, 6, RED|BG_GRAY, ":^l");
	Draw(36,6,WHITE,": �����");
}

//�� ���� (���� ��ġ �� ��ȣ �ο�)
void set_Blocks(Field *f) {
	//BOMB_COUNT ���� ���� ��ġ
	for (int i = 0; i < BOMB_COUNT; i++) {
		int r = rand() % 80;
		// �̹� ���ڶ�� �� ���� �� ����
		if(f[r].getState() == 9)
			i--;
		// ���ڰ� �ƴ϶�� ���� ��ġ
		else if (f[r].getState() != 9)
			f[r].setState(9);	
	}

	//��ȣ �ο�
	for (int i = 0; i < 80; i++) {
		//�̹� ���ڶ�� �н�
		if (f[i].getState() == 9) continue;

		//���ڰ� �ƴ�. �ֺ� ���ڰ˻� �� ��ȣ �ο�
		else {
			//state�� ���ڰ��� �ο�
			f[i].setState(Find_Mines(f, i));
		}
	}
}

//�ֺ� ���ڸ� ã�� ������ ��ȯ. ���� ���� ����
int Find_Mines(Field *f, int i) {
	//���� ���� (��ȯ�� ��)
	int mines = 0;


	//2���� ��ķ� ���� ��. �˻��� ����� �Ǵ� ���� �������� ������ 3�� �˻�
	if (i % 10 != 0) {
		//�������
		if (f[i - 11].getState() == 9) mines++;
		//����
		if (f[i - 1].getState() == 9) mines++;
		//�����ϴ�
		if (f[i + 9].getState() == 9) mines++;
	}

	//�� �Ʒ� 2���� �˻�
	if (f[i - 10].getState() == 9) mines++;
	if (f[i + 10].getState() == 9) mines++;


	//������ 3�� �˻�
	if (i % 10 != 9) {
		//�������
		if (f[i - 9].getState() == 9) mines++;
		//����
		if (f[i + 1].getState() == 9) mines++;
		//�����ϴ�
		if (f[i + 11].getState() == 9) mines++;
	}


	//�ֺ� ���� ���� ��ȯ
	return mines;
}

//�ֺ� state�� 0�� ��(�ֺ��� �ƹ� ���ڵ� ���� ������ ��)�� ã�� ���������� ����.
void Find_Safes(Field *f, int i) {

	//2���� ��ķ� ���� ��. �˻��� ����� �Ǵ� ���� �������� ������ 3�� �˻�
	if (i % 10 != 0) {
		/*
		//�������. ���ڰ��ֺ��� �����鼭 �̹� ���µ� ���� �ƴ϶��
		if (f[i - 11].getState() == 0 && f[i - 11].getBlock()==true) {
			f[i - 11].openBlock();
			Find_Safes(f, i - 11);
		}
		*/
		//����
		if (f[i - 1].getState() == 0 && f[i-1].getBlock() == true) {
			f[i - 1].openBlock();
			Find_Safes(f, i - 1);
		}
		/*
		//�����ϴ�
		if (f[i + 9].getState() == 0&&f[i+9].getBlock() == true) {
			f[i + 9].openBlock();
			Find_Safes(f, i + 9);
		}
		*/
	}

	//�� �Ʒ� 2���� �˻�
	if (f[i - 10].getState() == 0 && f[i-10].getBlock() == true) {
		f[i - 10].openBlock();
		Find_Safes(f,i - 10);
	}
	if (f[i + 10].getState() == 0 && f[i+10].getBlock() == true) {
		f[i + 10].openBlock();
		Find_Safes(f, i + 10);
	}


	//������ 3�� �˻�
	if (i % 10 != 9) {
		/*
		//�������
		if (f[i - 9].getState() == 0 && f[i-9].getBlock() == true) {
			f[i - 9].openBlock();
			Find_Safes(f, i - 9);
		}
		*/
		//����
		if (f[i + 1].getState() == 0 && f[i+1].getBlock() == true) {
			f[i + 1].openBlock();
			Find_Safes(f, i + 1);
		}
		//�����ϴ�
		/*
		if (f[i + 11].getState() == 0 && f[i+11].getBlock() == true) {
			f[i + 11].openBlock();
			Find_Safes(f, i + 11);
		}
		*/
	}
}

//���� ���� Ȯ�� �Լ�
/*
Draw_Field() �Լ����� ���ڸ� �׷����� ������ �˻�.
���ڸ� ���� ��� �����κ��� Ű �Է��� �ް� ���� ������ �ѱ�
*/
//���ڸ� ��Ұų�(GameOver), ��� ���ڸ� ã�� ���(GameClear)
void OverCheck(Field *f) {
	//���ڸ� ��Ҵٸ�(Game over)
	if (Field::getBomb() == true) {
		Scene_Gameset_Init();
		SceneNumber = GAMESET;
	}
	//BOME_COUNT ���� ���ڸ� ��� ã�Ҵٸ�(Game Clear)
	if (f->getFindmines() == BOMB_COUNT) {
		Scene_Gameclear_Init();
		SceneNumber = GAMECLEAR;
	}

}

//�ʵ带 ����ؼ� �׷���
void Draw_Field(Field *f) {
	//�ε��� ��ȣ
	int index = 0;
	//y��
	for (int y = 5; y < 13; y++) {
		//x��
		for (int x = 6; x < 26; x += 2, index++) {
			//���µ��� �ʾҰ� ����� ���ٸ�
			if(f[index].getBlock() == true &&f[index].getFlag() == false)
				Draw(x, y, DGRAY, "��");
			//���µ��� �ʾҰ� ����� �ִٸ�
			else if (f[index].getBlock() == true && f[index].getFlag() == true)
				Draw(x, y, GREEN, "��");
			//���µǾ��ٸ�
			else if (f[index].getBlock() == false) {
				switch (f[index].getState()) {
					//����
				case 9:
					Draw(x, y, RED, "��");
					break;
				case 0:
					Draw(x, y, BLUE | BG_DGRAY, "��");
					break;
				case 1:
					Draw(x, y, BLUE | BG_DGRAY, "��");
					break;
				case 2:
					Draw(x, y, BLUE | BG_DGRAY, "��");
					break;
				case 3:
					Draw(x, y, BLUE | BG_DGRAY, "��");
					break;
				case 4:
					Draw(x, y, BLUE | BG_DGRAY, "��");
					break;
				case 5:
					Draw(x, y, BLUE | BG_DGRAY, "��");
					break;
				case 6:
					Draw(x, y, BLUE | BG_DGRAY, "��");
					break;
				case 7:
					Draw(x, y, BLUE | BG_DGRAY, "��");
					break;
				case 8:
					Draw(x, y, BLUE | BG_DGRAY, "��");
					break;
				}
			}
		}
	}

	// UI�� ���
	Draw(32, 8, WHITE, "�� ���� �� : %d" , BOMB_COUNT);
	//Draw(40, 6, WHITE, "ã�� ���� �� : %d", f->getFindmines());

	// ���� ���� �Ǻ� (���ڸ� ��Ұų� ��� ã�Ұų�)
	OverCheck(f);
}

//���콺 �Է��� �޾� �ʵ忡 ��ȭ�� ���ϴ� �Լ�
/*
	���콺 Ŭ�� ��ǩ�� -> �迭 �ε��� �� ���� ����
	f[((y-5)*10)+((x-6)/2)]

*/
void Game_Playing(Field *f, HANDLE hIn, INPUT_RECORD rec, DWORD dw) {
	COORD pos = rec.Event.MouseEvent.dwMousePosition;

	//�Էµ� ���� ����
	ReadConsoleInput(hIn, &rec, 1, &dw);
	//��Ŭ���̶��
	if (rec.Event.MouseEvent.dwButtonState &FROM_LEFT_1ST_BUTTON_PRESSED) {
		//Ŭ���� �ʵ� ���� ������ �Ͼ�ٸ�
		if ((pos.X >= 6 && pos.X <= 25) && (pos.Y >= 5 && pos.Y <= 12)) {
			//�ش� ���� ������ �ʾҰ� ����� ���� ���¶��
			if (f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getBlock() == true && f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getFlag() == false) {
				//����
				f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].openBlock();
				Find_Safes(f, ((pos.Y - 5) * 10) + ((pos.X - 6) / 2));

				//���µ� ����� ���ڿ��ٸ�, -> ���ڸ� ��Ҵٸ�
				if (f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getState() == 9) {
					Field::setBomb(true); // ���ڹ���. �� ��������
				}
			}
		}
		//���� ������ Ŭ����
		else if ((pos.X >= 15 && pos.X <= 16) && pos.Y == 3)
			Scene_Ingame_Init();
	}
	
	//��Ŭ���̶��
	else if (rec.Event.MouseEvent.dwButtonState &RIGHTMOST_BUTTON_PRESSED) {
		//Ŭ���� �ʵ� ���� ������ �Ͼ�ٸ�
		if ((pos.X >= 6 && pos.X <= 25) && (pos.Y >= 5 && pos.Y <= 12)) {
			//�ش� ���� ���µ��� �ʾ����� ����� ���� ���� �ʴٸ�
			if (f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getBlock() == true && f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getFlag() == false) {
				//��� ��
				f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].Flag_on();
				//���� ���ڿ��ٸ�? bomb�� true�� -> ���� ���� ���� �Ǻ��� ����
				//if (f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getState() == 9)
				//	Field::setBomb(true); // < ���ڸ� �����.
			}
			//�ش� ���� ���µ��� �ʾ����� ����� ���� �ִٸ�
			else if(f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getBlock() == true && f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].getFlag() == true)
				//��� ��
				f[((pos.Y - 5) * 10) + ((pos.X - 6) / 2)].Flag_off();
		}
	}
}

