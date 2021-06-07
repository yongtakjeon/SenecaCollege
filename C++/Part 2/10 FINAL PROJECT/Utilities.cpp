// Name: Yongtak Jun
// Seneca Student ID: 137350195
// Seneca email: yjun4@myseneca.ca
// Date of completion: Mar/23/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Utilities.h"

namespace sdds
{
	char Utilities::m_delimiter = 0;

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
	{
		string next_pos_char = str.substr(next_pos, 1);
		if (next_pos_char[0] == m_delimiter)
		{
			more = false;
			throw "A delimiter is found at next_pos.";
		}

		string extractedToken{};
		size_t end_pos = str.find(m_delimiter, next_pos);
		if (end_pos != string::npos)	//if the delimiter is found
		{
			extractedToken = str.substr(next_pos, end_pos - next_pos);
			next_pos = end_pos + 1;
			more = true;
		}
		else							//if the delimiter is not found
		{
			extractedToken = str.substr(next_pos);
			more = false;
		}

		if (m_widthField < extractedToken.length())
			m_widthField = extractedToken.length();


		return extractedToken;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}