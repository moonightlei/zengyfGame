#include"CsvUtil.h"

CsvUtil* CsvUtil::m_CsvUtil = NULL;

CsvUtil* CsvUtil::getInstance()
{
	if (m_CsvUtil == NULL) {
		m_CsvUtil = new CsvUtil();
		if (m_CsvUtil && m_CsvUtil->init()) {
			m_CsvUtil->autorelease();
			m_CsvUtil->retain();
		}
		else {
			CC_SAFE_DELETE(m_CsvUtil);
			m_CsvUtil = NULL;
		}
	}
	return m_CsvUtil;
}

bool CsvUtil::init()
{
	return true;
}

void CsvUtil::loadFile(const char* sPath)
{
	CsvData* csvData = CsvData::create();

	std::string str = FileUtils::getInstance()->getStringFromFile(sPath);
	ValueVector lineList = StringUtil::getInstance()->split(str.c_str(), "\n");

	for (auto value : lineList) {
		//生成csvdata的二维表格
		ValueVector tArr = StringUtil::getInstance()->split(value.asString().c_str(), ",");
		csvData->addLineData(tArr);
	}
	m_CsvMap.insert(sPath, csvData);
}

const Size CsvUtil::getFileRowColNum(const char* csvFilePath)
{
	auto csvData = m_CsvMap.at(csvFilePath);

	if (csvData == nullptr) {
		loadFile(csvFilePath);
		csvData = m_CsvMap.at(csvFilePath);
	}
	Size size = csvData->getRowColNum();
	return size;
}

Value CsvUtil::getValue(int iRow, int iCol, const char* csvFilePath)
{
	auto csvData = m_CsvMap.at(csvFilePath);

	if (csvData == nullptr) {
		loadFile(csvFilePath);
		csvData = m_CsvMap.at(csvFilePath);
	}

	ValueVector rowVector = csvData->getSingleLineData(iRow);
	Value colValue = rowVector.at(iCol);

	return colValue;
}