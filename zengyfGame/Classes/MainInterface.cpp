#include "MainInterface.h"
#include "TestPop.h"
#include "json\json.h"
#include "GameInterface.h"


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
	Size winSize = Director::getInstance()->getWinSize();
	

	log("visbleSize:%f,%f",visibleSize.width,visibleSize.height);
	log("origin:%f,%f",origin.x,origin.y);
	log("winSize:%f,%f",winSize.width,winSize.height);


	//����ͼƬ
	auto spriteBackgound = Sprite::create("res/MainInterface.png");
	//spriteBackgound->setAnchorPoint(Vec2(0.5,0.5));
	spriteBackgound->setPosition(Vec2(origin) + Vec2(visibleSize/2.0));

	spriteBackgound->setScaleX(visibleSize.width / spriteBackgound->getContentSize().width);
	spriteBackgound->setScaleY(visibleSize.height / spriteBackgound->getContentSize().height);

	this->addChild(spriteBackgound);

	//��ť
	/*auto button = Button::create("CloseNormal.png");
	button->setPosition(origin + Vec2(visibleSize) - Vec2(button->getContentSize() / 2.0));
	button->addTouchEventListener(this,toucheventselector(MainInterface::OnClick));
	this->addChild(button);*/

	//����ؿ���ť
	auto startButton = Button::create("res/startgame.png");
	startButton->setPosition(origin + Vec2(visibleSize / 2.0));
	startButton->addTouchEventListener(this, toucheventselector(MainInterface::OnClick));
	this->addChild(startButton);

	//����json�ļ�
	//readArrayJson();

	return true;
}


void MainInterface::OnClick(Ref* pender, TouchEventType type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		//auto popdailog = TestPop::createDailog();
		//this->addChild(popdailog);
		Director::getInstance()->replaceScene(GameInterface::createScene());
	}
}

void MainInterface::readArrayJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("json/data.json");
	if (reader.parse(data,root,false) == true) {
		log("reader.parse");
		int iNum = root.size();
		for (int i = 0; i < iNum;++i) {
			log("%d", root[i]["id"].asInt());
			log("%s", root[i]["dailog"].asCString());
		}
	}
}
