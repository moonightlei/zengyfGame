#include "MainInterface.h"
#include "TestPop.h"


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

	//背景图片
	auto spriteBackgound = Sprite::create("res/MainInterface.png");
	//spriteBackgound->setAnchorPoint(Vec2(0.5,0.5));
	spriteBackgound->setPosition(visibleSize/2.0);
	this->addChild(spriteBackgound);

	//按钮
	auto button = Button::create("CloseNormal.png");
	button->setPosition(origin + Vec2(visibleSize) - Vec2(button->getContentSize() / 2.0));
	button->addTouchEventListener(this,toucheventselector(MainInterface::OnClick));
	this->addChild(button);

	//加载json文件

	


	return true;
}


void MainInterface::OnClick(Ref* pender, TouchEventType type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		auto popdailog = TestPop::createDailog();
		this->addChild(popdailog);
	}
}
