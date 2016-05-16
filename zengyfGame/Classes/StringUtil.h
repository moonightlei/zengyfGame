#pragma once
#ifndef  _STRINGUTIL_H_
#define  _STRINGUTIL_H_

#include"cocos2d.h"

using namespace cocos2d;

class StringUtil:public Ref
{
public:
	static StringUtil* getInstance();//��ȡʵ������
	virtual bool init();

	//�÷ָ���sSep�ָ��ַ����������ŵ�һ���б��У��б��еĶ���ΪValue
	ValueVector split(const char* srcStr, const char* sSep);
private:
	static StringUtil* m_StringUtil;

};
#endif //end StringUtil