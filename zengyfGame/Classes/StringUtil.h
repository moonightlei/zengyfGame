#pragma once
#ifndef  _STRINGUTIL_H_
#define  _STRINGUTIL_H_

#include"cocos2d.h"

using namespace cocos2d;

class StringUtil:public Ref
{
public:
	static StringUtil* getInstance();//获取实例对象
	virtual bool init();

	//用分隔符sSep分割字符串，结果存放到一个列表中，列表中的对象为Value
	ValueVector split(const char* srcStr, const char* sSep);
private:
	static StringUtil* m_StringUtil;

};
#endif //end StringUtil