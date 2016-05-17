#include "GameInterface.h"


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

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//初始化背景精灵对象
	__backgroundSprite = Sprite::create();
	__backgroundSprite->setPosition(Vec2(origin) + Vec2(visibleSize / 2.0));
	this->addChild(__backgroundSprite);

	//初始化对话框
	auto dailogSprite = Sprite::create("res/dailog.png");
	dailogSprite->setPosition(Vec2(origin) + Vec2(visibleSize.width / 2.0, 0)
		+ Vec2(0, dailogSprite->getContentSize().height / 2.0*0.7)
		);
	dailogSprite->setScaleX(visibleSize.width / dailogSprite->getContentSize().width);
	dailogSprite->setScaleY(0.7);
	this->addChild(dailogSprite);


	//对话框文字
	Size dailogSize(dailogSprite->getContentSize().width * dailogSprite->getScaleX(),
		dailogSprite->getContentSize().height * dailogSprite->getScaleY());
	__dailogLabel = Label::createWithTTF("Hello World", "fonts/msyh.ttf", 18, Size(420, 110));
	__dailogLabel->setPosition(dailogSprite->getPosition());
	this->addChild(__dailogLabel, 1);

	//确定按钮
	auto nextButton = Button::create("res/enter.png");
	nextButton->setPosition(origin + Vec2(visibleSize.width, 0)
		+ Vec2(-nextButton->getContentSize().width / 2.0, nextButton->getContentSize().height / 2.0)
		+ Vec2(-15.0, 10.0)
		);
	nextButton->addTouchEventListener(this, toucheventselector(GameInterface::OnClick));
	this->addChild(nextButton, 10);

	//读取json数据
	readJsonData();

	//指令设置
	//__iter = __command.begin();
	__iCommandItem = 0;
	//运行命令
	__doCommand();


	return true;
}

void GameInterface::readJsonData()
//读取Json文件中的数据
{
	Json::Reader reader;
	//Json::Value root;

	/*std::string data = FileUtils::getInstance()->getStringFromFile("json/data.json");
	if (reader.parse(data, root, false) == true) {
		log("reader.parse");
		int iNum = root.size();
		for (int i = 0; i < iNum; ++i) {
			CommandItem commanditem;
			commanditem.strBackGround_pngName = root[i]["png"].asString();
			__command.push_back(commanditem);
		}
	}*/
	std::string data = FileUtils::getInstance()->getStringFromFile("json/dailog.json");
	if (reader.parse(data, __root, false) == true) {
		log("read success!!!");
		log("Command Size:%d", __root.size());
	}
}

void GameInterface::__doCommand()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	int size = __root[__iCommandItem]["data"].size();
	Json::Value data = __root[__iCommandItem]["data"];
	for (int i = 0; i < size; ++i) {
		//log("%s", data[i]["command"].asCString());
		if (data[i]["command"] == "updatedailog") {
			//更新对话
			auto strings = CCDictionary::createWithContentsOfFile("json/dailog.xml");
			std::stringstream ss;
			ss << data[i]["dailog"].asInt();
			auto dailog = static_cast<String*>(strings->objectForKey(ss.str()));
			__dailogLabel->setString(dailog->_string);
		}
		else if (data[i]["command"] == "updatebackground") {
			//切换场景;
			__backgroundSprite->setTexture(data[i]["background"].asString());
			__backgroundSprite->setScaleX(visibleSize.width / __backgroundSprite->getContentSize().width);
			__backgroundSprite->setScaleY(visibleSize.height / __backgroundSprite->getContentSize().height);
			for (auto sprite : m_FigureSprite) {
				sprite.second->removeFromParent();
			}
			m_FigureSprite.clear();
		}
		else if (data[i]["command"] == "addfigure") {
			//添加人物
			auto sprite = Sprite::create(data[i]["res"].asString());
			sprite->setScale(0.8);
			this->addChild(sprite);
			m_FigureSprite.insert(data[i]["res"].asString(),sprite);
			__updateFigurePos();
		}
	}
	
	
	
	
	
	//log("dailog:%s", __root[__iCommandItem]["dailog"].asCString());

	//__iter++;
	__iCommandItem++;
}

void GameInterface::OnClick(Ref* pender, TouchEventType type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		if (__iCommandItem != __root.size()){
		//if (__iter != __command.end()) {
			__doCommand();
		}
	}
}

void GameInterface::__updateFigurePos()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	int size = m_FigureSprite.size();
	int n = 1;
	for (auto sprite : m_FigureSprite) {
		sprite.second->setPosition(origin + Vec2(visibleSize.width/ (size + 1)*n,225));
		++n;
	}

}
