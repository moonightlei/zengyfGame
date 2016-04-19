#include "MainInterface.h"

USING_NS_CC;

Scene* MainInterface::createScene()
{
	auto scene = Scene::create();
	auto layer = MainInterface::create();
	scene->addChild(layer);
	return scene;
}


bool MainInterface::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto spriteBackgound = Sprite::create("res/MainInterface.png");
	spriteBackgound->setAnchorPoint(Vec2(0.5,0.5));
	//log("%f,%f", visibleSize.width, visibleSize.height);
	//log("%f,%f", spriteBackgound->getContentSize().width,spriteBackgound->getContentSize().height);
	spriteBackgound->setPosition(visibleSize/2.0);
	//log("%f,%f", spriteBackgound->getPosition().x, spriteBackgound->getPosition().y);
	this->addChild(spriteBackgound);

	return true;
}
