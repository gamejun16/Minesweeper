#include "Scene.h"
#include "Scene_Gameset.h"

//예제장면(Scene Gameset) 초기화 함수
void Scene_Gameset_Init()
{
	//for (int i = 2; i <= 13; i++) {
	//	Draw(4, i, RED, "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	//}
}

//예제장면(Scene Gameset) 렌더링 함수
bool Scene_Gameset_Render(float timeDelta)
{
	Draw(15, 3, RED | BG_GRAY, ":^(");

	Draw(32, 10, WHITE | BG_BLUE, "게임오버.. ENTER눌러서 다시시작");

	if (KeyDown(KEY_ENTER)) {
		SceneNumber = INGAME;
		Scene_Ingame_Init();
	}

	return true;
}