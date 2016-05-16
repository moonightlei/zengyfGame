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

	void addLineData(ValueVector lineData);//向Data中加入一条数据
	ValueVector getSingleLineData(int iLine);//按行号获取数据
	Size getRowColNum();//获取data的二维表格大小
private:
	ValueVector m_allLineVec;
};

#endif //end CsvData