#pragma once
#ifndef  _CSVDATA_H_
#define  _CSVDATA_H_

#include"cocos2d.h"
#include"StringUtil.h"

using namespace cocos2d;

class CsvData :public Ref
{
public:
	CREATE_FUNC(CsvData);
	virtual bool init();

	void addLineData(ValueVector lineData);//��Data�м���һ������
	ValueVector getSingleLineData(int iLine);//���кŻ�ȡ����
	Size getRowColNum();//��ȡdata�Ķ�ά����С
private:
	ValueVector m_allLineVec;
};

#endif //end CsvData