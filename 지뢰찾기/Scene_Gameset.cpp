#include "Scene.h"
#include "Scene_Gameset.h"

//�������(Scene Gameset) �ʱ�ȭ �Լ�
void Scene_Gameset_Init()
{
	//for (int i = 2; i <= 13; i++) {
	//	Draw(4, i, RED, "������������������������������������������������������������������������");
	//}
}

//�������(Scene Gameset) ������ �Լ�
bool Scene_Gameset_Render(float timeDelta)
{
	Draw(15, 3, RED | BG_GRAY, ":^(");

	Draw(32, 10, WHITE | BG_BLUE, "���ӿ���.. ENTER������ �ٽý���");

	if (KeyDown(KEY_ENTER)) {
		SceneNumber = INGAME;
		Scene_Ingame_Init();
	}

	return true;
}