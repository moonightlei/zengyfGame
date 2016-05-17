#pragma once
#ifndef __GAMEINTERFACE_SCENE_H__
#define __GAMEINTERFACE_SCENE_H__

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "json\json.h"
#include<vector>


using namespace cocos2d;
using namespace ui;

struct CommandItem
{
	std::string strBackGround_pngName;
};

class GameInterface : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameInterface);

	//void OnClick(Ref* pender, TouchEventType type);
	void readJsonData();
	void OnClick(Ref* pender, TouchEventType type);

private:
	std::vector<CommandItem> __command;
	void __doCommand();
	std::vector<CommandItem>::iterator __iter;
	Sprite *__backgroundSprite;
	Label *__dailogLabel;
	Json::Value __root;
	int __iCommandItem;
	Map<std::string, Sprite*> m_FigureSprite;//���ﾫ��
	void __updateFigurePos(); //ÿ����FigureMap�в��뾫��󣬸��¾����λ��
};

#endif // __GAMEINTERFACE_SCENE_H__
