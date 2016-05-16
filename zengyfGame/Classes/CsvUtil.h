#pragma once
#ifndef  _CSVUTIL_H_
#define  _CSVUTIL_H_

#include"cocos2d.h"
#include"CsvData.h"

using namespace cocos2d;

class CsvUtil :public Ref 
{
public:
	static CsvUtil* getInstance();
	virtual bool init();

	void loadFile(const char* sPath);//加载配置文件

	Value getValue(int iRow, int iCol, const char* csvFilePath);	//获取某行某列的值
	const std::string get(int iRow, int iCol, const char* csvFilePath); //获取值并转化为字符串
	const int getInt(int iRow, int iCol, const char* csvFilePath);	//获取值并转换为整形
	const Size getFileRowColNum(const char* csvFilePath);		//获取文件的行和列数量

	/*根据某个列值，查找该值所在的行*/
	const int findValueInWithLine(const char * chValue, int iValueCol, const char* csvFilePath);
private:
	static CsvUtil* m_CsvUtil;
	Map<std::string, CsvData*> m_CsvMap;	//存放文件数据的map

};


#endif