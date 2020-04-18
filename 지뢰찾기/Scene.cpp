#include "Scene.h"

//현재 보여지는 장면 번호
int SceneNumber = INGAME;

//장면선택 렌더링 함수
bool SceneRender(float timeDelta)
{
	//장면 번호에 따라 Render 호출 변경
	if (SceneNumber == INGAME) return Scene_Ingame_Render(timeDelta);
	else if (SceneNumber == GAMECLEAR) return Scene_Gameclear_Render(timeDelta);
	else if (SceneNumber == GAMESET) return Scene_Gameset_Render(timeDelta);
	return true;
}
