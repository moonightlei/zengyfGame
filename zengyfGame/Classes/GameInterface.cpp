#include "GameInterface.h"
#include "json\json.h"

USING_NS_CC;

Scene* GameInterface::createScene()
{
	auto scene = Scene::create();
	auto layer = GameInterface::create();
	scene->addChild(layer);
	return scene;
}


bool GameInterface::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

