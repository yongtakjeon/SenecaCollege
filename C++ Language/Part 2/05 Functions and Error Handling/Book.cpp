/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/21/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include "Book.h"


namespace sdds
{
	void Book::trim(string& str)const
	{
		size_t i = 0;


		//removing leading spaces
		for (i = 0; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);


		//removing trailing spaces
		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}
	Book::Book(){}
	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}

	Book::Book(const std::string& strBook)
	{
		size_t sPos = 0;
		size_t ePos = strBook.find(',');
		m_author = strBook.substr(sPos, ePos - sPos);
		trim(m_author);

		sPos = ePos + 1;
		ePos = strBook.find(',', sPos);
		m_title = strBook.substr(sPos, ePos - sPos);
		trim(m_title);

		sPos = ePos + 1;
		ePos = strBook.find(',', sPos);
		m_country = strBook.substr(sPos, ePos - sPos);
		trim(m_country);

		sPos = ePos + 1;
		ePos = strBook.find(',', sPos);
		m_price = stod(strBook.substr(sPos, ePos - sPos));

		sPos = ePos + 1;
		ePos = strBook.find(',', sPos);
		m_year = stoi(strBook.substr(sPos, ePos - sPos));

		sPos = ePos + 1;
		m_desc = strBook.substr(sPos);
		trim(m_desc);

	}


	ostream& operator<<(ostream& os, const Book& res)
	{
		os << setw(20) << res.m_author << " | " << setw(22) << res.m_title << " | " << setw(5) << res.m_country << " | " << setw(4) << res.m_year << " | ";

		os.setf(ios::fixed);
		os.precision(2);
		os << setw(6) << res.m_price << " | " << res.m_desc << endl;
		os.precision(6);
		os.unsetf(ios::fixed);

		return os;
	}
}