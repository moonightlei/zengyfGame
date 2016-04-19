#pragma once
#ifndef __MAININTERFACE_SCENE_H__
#define __MAININTERFACE_SCENE_H__

#include "cocos2d.h"

class MainInterface : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(MainInterface);
};

#endif // __MAININTERFACE_SCENE_H__
