#include "PopDailog.h"


PopDailog * PopDailog::createDailog()
{
	auto layerColor = PopDailog::create();
	return layerColor;
}

bool PopDailog::init()
{
	if (!LayerColor::init())
	{
		return false;
	}

	this->initWithColor(Color4B(0,0,0,120));//ÉèÖÃÕÚÕÖ²ãÑÕÉ«
	//ÉèÖÃ´¥ÃþÊÂ¼þ
	this->setTouchEnabled(true);
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(PopDailog::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(PopDailog::onTouchEnded,this);
	listener->onTouchMoved = CC_CALLBACK_2(PopDailog::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	
	return true;
}

bool PopDailog::onTouchBegan(Touch *touch, Event *unused_event)
{
	//log("onTouchBegan");
	return true;
}

void PopDailog::onTouchMoved(Touch *touch, Event *unused_event)
{
	//log("onTouchMoved");
}

void PopDailog::onTouchEnded(Touch *touch, Event *unused_event)
{
	//log("onTouchEnded");
	//this->removeFromParentAndCleanup(true);
	closeDailog();
}

void PopDailog::onEnter()
{
	LayerColor::onEnter();
	CCAction* enterAction = CCSequence::create(
		CCScaleTo::create(0.0, 0.0),
		CCScaleTo::create(0.1, 1.05),
		CCScaleTo::create(0.08, 0.95),
		CCScaleTo::create(0.08, 1.0), 
		NULL);
	this->runAction(enterAction);
}

void PopDailog::closeDailog()
{
	CCAction* exitAction = CCSequence::create(
		CCScaleTo::create(0.08, 0.0), 
		CCCallFunc::create(this, callfunc_selector(PopDailog::close)),
		NULL);

	this->runAction(exitAction);
}

void PopDailog::close()
{
	this->removeFromParentAndCleanup(true);
}
