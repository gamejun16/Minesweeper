#include "Scene.h"
#include "Scene_Gameclear.h"

//�������(Scene Gameclear) �ʱ�ȭ �Լ�
void Scene_Gameclear_Init()
{
	//for (int i = 2; i <= 13; i++) {
	//	Draw(4, i, RED, "������������������������������������������������������������������������");
	//}
}

//�������(Scene Gameclear) ������ �Լ�
bool Scene_Gameclear_Render(float timeDelta)
{
	
	Draw(15, 3, RED | BG_GRAY, ":^)");
	
	Draw(32, 10, WHITE | BG_BLUE, "����Ŭ����! ENTER������ �ٽý���");

	if (KeyDown(KEY_ENTER)) {
		SceneNumber = INGAME;
		Scene_Ingame_Init();
	}

	return true;
}