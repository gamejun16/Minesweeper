#ifndef __SCENE_H__
#define __SCENE_H__

//Draw / Input ���(h) Include
#include "Draw.h"
#include "Input.h"
//��鼱�� ������ �Լ�
bool SceneRender(float timeDelta);

//���� �������� ����ȣ
enum {
	INGAME, GAMESET, GAMECLEAR
};

//extern�� ����ؼ� Scene.cpp�� ������ ����
extern int SceneNumber;

//���ӿ� ���Ǵ� ��� ��� ���(h)����
#include "Scene_Ingame.h"
#include "Scene_Gameclear.h"
#include "Scene_Gameset.h"

#endif
