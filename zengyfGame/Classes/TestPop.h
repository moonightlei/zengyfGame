#pragma once
#ifndef __TESTPOP_H__
#define __TESTPOP_H__

#include "cocos2d.h"
#include "PopDailog.h"

USING_NS_CC;

class TestPop : public PopDailog
{
public:
	static TestPop * createDailog();
	CREATE_FUNC(TestPop);

	virtual bool init();
};

#endif // __TESTPOP_H__
