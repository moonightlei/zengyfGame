#pragma once
#ifndef __GAMEINTERFACE_SCENE_H__
#define __GAMEINTERFACE_SCENE_H__

#include "cocos2d.h"
//#include "ui\UIButton.h"

using namespace cocos2d;
//using namespace ui;

class GameInterface : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameInterface);

	//void OnClick(Ref* pender, TouchEventType type);
	//void readArrayJson();
};

#endif // __GAMEINTERFACE_SCENE_H__
