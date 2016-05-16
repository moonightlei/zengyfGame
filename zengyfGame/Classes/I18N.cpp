#include"I18N.h"
//I18N * I18N::m_I18N = NULL;
//
//I18N* I18N::getInstance()
//{
//	if (m_I18N == NULL) {
//		m_I18N = new I18N;
//		if (m_I18N && m_I18N->init()) {
//			m_I18N->autorelease();
//			m_I18N->retain();
//		}
//		else{
//			CC_SAFE_DELETE(m_I18N);
//			m_I18N = NULL;
//		}
//	}
//	return m_I18N;
//}
//
//bool I18N::init()
//{
//	return true;
//}
//
//const char* I18N::getCStringByKey(int ikey)
//{
//	return m_StringMap.at(ikey).c_str();
//}
//
//void I18N::loadStringFromConf(const char* filePath)
//{
//	CsvUtil::getInstance()->loadFile(filePath);
//
//	Size size = CsvUtil::getInstance()->getFileRowColNum(filePath);
//
//	int iRowNum = size.width;
//	int iColNum = size.height;
//
//	if (iColNum < 2) return;
//
//	//将配置文件的所有字符串存放到字典中（忽略第一行）
//	for (int i = 1; i < iRowNum; ++i) {
//		int key = CsvUtil::getInstance()->getInt(i, 0, filePath);
//		std::string value = CsvUtil::getInstance()->get(i, 1, filePath);
//
//		m_StringMap[key] = value;
//	}
//
//}