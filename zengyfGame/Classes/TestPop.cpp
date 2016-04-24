#include "TestPop.h"


TestPop * TestPop::createDailog()
{
	auto popdailog = TestPop::create();
	return popdailog;
}


bool TestPop::init()
{
	if (!PopDailog::init())
	{
		return false;
	}
	auto visibleSize = getContentSize();

	auto sprite = Sprite::create("res/poptest.png");
	sprite->setPosition(visibleSize/2.0);
	this->addChild(sprite);

	return true;
}