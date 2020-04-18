#ifndef __SCENE_H__
#define __SCENE_H__

//Draw / Input 헤더(h) Include
#include "Draw.h"
#include "Input.h"
//장면선택 렌더링 함수
bool SceneRender(float timeDelta);

//현재 보여지는 장면번호
enum {
	INGAME, GAMESET, GAMECLEAR
};

//extern을 사용해서 Scene.cpp의 변수를 공유
extern int SceneNumber;

//게임에 사용되는 모든 장면 헤더(h)파일
#include "Scene_Ingame.h"
#include "Scene_Gameclear.h"
#include "Scene_Gameset.h"

#endif
