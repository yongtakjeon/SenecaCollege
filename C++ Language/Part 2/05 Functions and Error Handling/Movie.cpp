/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/21/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip>
#include "Movie.h"


namespace sdds
{
	void Movie::trim(string& str)const
	{
		size_t i = 0;


		//removing leading spaces
		for (i = 0; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);


		//removing trailing spaces
		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}

	Movie::Movie() {};
	const std::string& Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		size_t sPos = 0;
		size_t ePos = strMovie.find(',');
		m_title = strMovie.substr(sPos, ePos - sPos);
		trim(m_title);

		sPos = ePos + 1;
		ePos = strMovie.find(',', sPos);
		m_year = stoi(strMovie.substr(sPos, ePos - sPos));

		sPos = ePos + 1;
		m_desc = strMovie.substr(sPos);
		trim(m_desc);
	}

	ostream& operator<<(ostream& os, const Movie& res)
	{
		os << setw(40) << res.m_title << " | " << setw(4) << res.m_year << " | " << res.m_desc << endl;

		return os;
	}
}