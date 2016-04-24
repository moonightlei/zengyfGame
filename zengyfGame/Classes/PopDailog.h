#pragma once
#ifndef __POPDAILOG_H__
#define __POPDAILOG_H__

#include "cocos2d.h"

USING_NS_CC;

class PopDailog : public LayerColor
{
public:
	static PopDailog * createDailog();
	CREATE_FUNC(PopDailog);

	virtual bool init();
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

	virtual void onEnter();
	void closeDailog();

private:
	void close();

	
};

#endif // __POPDAILOG_H__
