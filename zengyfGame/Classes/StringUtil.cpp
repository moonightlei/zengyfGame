#include"StringUtil.h"

StringUtil* StringUtil::m_StringUtil = NULL;

StringUtil* StringUtil::getInstance()
{
	if (m_StringUtil == NULL) {
		m_StringUtil = new StringUtil();
		if (m_StringUtil && m_StringUtil->init()){ 
			m_StringUtil->autorelease();
			m_StringUtil->retain();
		}
		else{ 
			CC_SAFE_DELETE(m_StringUtil);
			m_StringUtil = NULL;
		}
	}
	return m_StringUtil;
}

bool StringUtil::init()
{
	return true;
}

ValueVector StringUtil::split(const char* srcStr, const char* sSep)
{
	ValueVector stringList;
	int size = strlen(srcStr);

	Value str = Value(srcStr);

	int startIndex = 0;
	int endIndex = 0;
	endIndex = str.asString().find(sSep);

	std::string lineStr;

	while (endIndex > 0) {
		lineStr = str.asString().substr(startIndex, endIndex);
		stringList.push_back(Value(lineStr));
		str = Value(str.asString().substr(endIndex + 1, size));

		endIndex = str.asString().find(sSep);
	}

	if (str.asString().compare("") != 0) {
		stringList.push_back(Value(str.asString()));
	}

	return stringList;
}