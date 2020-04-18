#include "Scene.h"

//���� �������� ��� ��ȣ
int SceneNumber = INGAME;

//��鼱�� ������ �Լ�
bool SceneRender(float timeDelta)
{
	//��� ��ȣ�� ���� Render ȣ�� ����
	if (SceneNumber == INGAME) return Scene_Ingame_Render(timeDelta);
	else if (SceneNumber == GAMECLEAR) return Scene_Gameclear_Render(timeDelta);
	else if (SceneNumber == GAMESET) return Scene_Gameset_Render(timeDelta);
	return true;
}
