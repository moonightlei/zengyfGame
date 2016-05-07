#pragma once
#ifndef __MAININTERFACE_SCENE_H__
#define __MAININTERFACE_SCENE_H__

#include "cocos2d.h"
#include "ui\UIButton.h"

using namespace cocos2d;
using namespace ui;

class MainInterface : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(MainInterface);

	void OnClick(Ref* pender,TouchEventType type);
	void readArrayJson();
};

#endif // __MAININTERFACE_SCENE_H__
