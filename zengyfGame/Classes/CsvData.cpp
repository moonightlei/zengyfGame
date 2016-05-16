#include"CsvData.h"

bool CsvData::init()
{
	return true;
}

void CsvData::addLineData(ValueVector lineData)
{
	m_allLineVec.push_back(Value(lineData));
	//m_iColNum = lineData.size();
}

ValueVector CsvData::getSingleLineData(int iLine)
{
	return m_allLineVec.at(iLine).asValueVector();
}

Size CsvData::getRowColNum()
{
	Size size = Size();
	size.width = m_allLineVec.size();
	if (size.width > 0) {
		size.height = m_allLineVec.at(0).asValueVector().size();
	}
	return size;
}