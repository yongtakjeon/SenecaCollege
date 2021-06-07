/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/21/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds
{
	
	class Book
	{
		string m_author{};
		string m_title{};
		string m_country{};
		size_t m_year{};
		double m_price{};
		string m_desc{};
		void trim(string& str)const;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		friend ostream& operator<<(ostream& os, const Book& res);

		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_desc);
		}
	};




}
#endif // !SDDS_BOOK_H
