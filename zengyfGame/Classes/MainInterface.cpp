#include "MainInterface.h"
#include "TestPop.h"
#include "json\json.h"
#include "GameInterface.h"
#include"CsvUtil.h"


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


	//背景图片
	auto spriteBackgound = Sprite::create("res/MainInterface.png");
	//spriteBackgound->setAnchorPoint(Vec2(0.5,0.5));
	spriteBackgound->setPosition(Vec2(origin) + Vec2(visibleSize/2.0));

	spriteBackgound->setScaleX(visibleSize.width / spriteBackgound->getContentSize().width);
	spriteBackgound->setScaleY(visibleSize.height / spriteBackgound->getContentSize().height);

	this->addChild(spriteBackgound);

	//按钮
	/*auto button = Button::create("CloseNormal.png");
	button->setPosition(origin + Vec2(visibleSize) - Vec2(button->getContentSize() / 2.0));
	button->addTouchEventListener(this,toucheventselector(MainInterface::OnClick));
	this->addChild(button);*/

	//进入关卡按钮
	auto startButton = Button::create("res/startgame.png");
	startButton->setPosition(origin + Vec2(visibleSize / 2.0));
	startButton->addTouchEventListener(this, toucheventselector(MainInterface::OnClick));
	this->addChild(startButton);

	//加载json文件
	//readArrayJson();


	//test代码
	//const char *sPath = "json/test.csv";
	//CsvUtil::getInstance()->loadFile(sPath);
	//auto size = CsvUtil::getInstance()->getFileRowColNum(sPath);

	//for (int i = 2; i < size.width; ++i){
	//	//log("id = %d", CsvUtil::getInstance()->getValue(i, 0, sPath).asInt());
	//	//log("name = %s", CsvUtil::getInstance()->getValue(i, 1, sPath).asString().c_str());
	//	//log("level = %d", CsvUtil::getInstance()->getValue(i, 2, sPath).asInt());

	//	auto label = Label::createWithTTF(CsvUtil::getInstance()->getValue(i, 1, sPath).asString(), "Arial", 24);
	//	label->setPosition(Vec2(i*50, 200));
	//	this->addChild(label, 1);
	//}
	
	auto strings = CCDictionary::createWithContentsOfFile("json/dailog.xml");
	auto daiog = static_cast<String*>(strings->objectForKey("1"));

	log("%s", daiog);
	auto label = Label::createWithTTF(daiog->_string,"fonts/msyh.ttf",24);
	label->setPosition(Vec2(200,100));
	this->addChild(label, 1);



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

	std::string data = FileUtils::getInstance()->getStringFromFile("json/dailog.json");
	log("readArrayJson");
	if (reader.parse(data,root,false) == true) {
		log("reader.parse");
		log("key:袁成鹏%s",root[0]["dailog"].asString().c_str());

		auto label = Label::createWithTTF("test","fonts/msyh.ttf",24);
		label->setPosition(Vec2(300,200));
		this->addChild(label, 1);
	}
}
