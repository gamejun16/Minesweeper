// �ʿ� ��� ���� ����
#include "Scene.h"
#include "Ingame_Func.h"
#include "Field.h"

//�ʵ� ��ü
Field field[80];
//Init()�Լ��� �ѹ��� �θ��� ����
bool Init_Once = true;

// ����¿� ���� �ڵ��� ����.
HANDLE hIn, hOut;
INPUT_RECORD rec;
DWORD dw;

//�ΰ��� ��(Scene Ingame) �ʱ�ȭ �Լ�
void Scene_Ingame_Init()
{
	//�ܼ�â ����
	for (int i = 2; i <= 13; i++) {
		Draw(4, i, RED, "������������������������������������������������������������������������");
	}
	//UI���� �׷���.
	Draw_UI();
	//��� ���� ���� �� ����� �����ϰ� state�� 0���� ����(���� ����)
	for (int i = 0; i < 80; i++) {
		field[i].closeBlock();
		field[i].Flag_off();
		field[i].setState(0);
	}
	//ã�� ������ ������ 0���� �ʱ�ȭ
	field->setFindmines();
	//���� ��ġ
	set_Blocks(field);

	//���� �߽߰� true�Ǵ� static bool�� bomb������ false�� ����
	Field::setBomb(false);

	// ����¿� ���� �ڵ��� ������.
	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

//�ΰ��� ��(Scene Ingame) ������ �Լ�
bool Scene_Ingame_Render(float timeDelta)
{
	//Init()�Լ��� �ѹ��� ��ġ�� �ϱ� ���� �۾�
	if (Init_Once) {
		Scene_Ingame_Init();
		Init_Once = false;
	}

	// ���콺 ��� �Ͼ �� ��쿡�� ReadConsoleInput()�Լ��� ��ħ.
	PeekConsoleInput(hIn, &rec, 1, &dw);
	if (dw > 0) {
		//���콺 Ŭ�� �� �ش� ���� ����.
		Game_Playing(field, hIn, rec, dw);
	}
	Draw_Field(field);

	return true;
}
