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

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//��ʼ�������������
	__backgroundSprite = Sprite::create();
	__backgroundSprite->setPosition(Vec2(origin) + Vec2(visibleSize / 2.0));
	this->addChild(__backgroundSprite);

	//��ʼ���Ի���
	auto dailogSprite = Sprite::create("res/dailog.png");
	dailogSprite->setPosition(Vec2(origin) + Vec2(visibleSize.width / 2.0,0)
		+ Vec2(0,dailogSprite->getContentSize().height/2.0)
		);
	dailogSprite->setScaleX(visibleSize.width / dailogSprite->getContentSize().width);
	this->addChild(dailogSprite);


	//�Ի�������
	Size dailogSize(dailogSprite->getContentSize().width * dailogSprite->getScaleX(),
		dailogSprite->getContentSize().height * dailogSprite->getScaleY());
	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 20,Size(420,140));
	label->setPosition(dailogSprite->getPosition());
	this->addChild(label, 1);

	//ȷ����ť
	auto nextButton = Button::create("res/enter.png");
	nextButton->setPosition(origin + Vec2(visibleSize.width,0) 
		+ Vec2(- nextButton->getContentSize().width/2.0,nextButton->getContentSize().height / 2.0)
		+ Vec2(- 15.0,10.0)
		);
	nextButton->addTouchEventListener(this, toucheventselector(GameInterface::OnClick));
	this->addChild(nextButton, 10);

	//��ȡjson����
	readJsonData();

	//ָ������
	__iter = __command.begin();

	//��������
	__doCommand();


	return true;
}

void GameInterface::readJsonData()
//��ȡJson�ļ��е�����
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("json/data.json");
	if (reader.parse(data, root, false) == true) {
		log("reader.parse");
		int iNum = root.size();
		for (int i = 0; i < iNum; ++i) {
			CommandItem commanditem;
			commanditem.strBackGround_pngName = root[i]["png"].asString();
			__command.push_back(commanditem);
		}
	}	
}

void GameInterface::__doCommand()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	__backgroundSprite->setTexture(__iter->strBackGround_pngName);
	__backgroundSprite->setScaleX(visibleSize.width / __backgroundSprite->getContentSize().width);
	__backgroundSprite->setScaleY(visibleSize.height / __backgroundSprite->getContentSize().height);



	__iter++;
}

void GameInterface::OnClick(Ref* pender, TouchEventType type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		if (__iter != __command.end()) {
			__doCommand();
		}
	}
}
