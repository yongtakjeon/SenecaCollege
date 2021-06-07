/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/21/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include<string>

using namespace std;

namespace sdds
{
	class Movie
	{
		string m_title{};
		size_t m_year{};
		string m_desc{};
		void trim(string& str)const;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		friend ostream& operator<<(ostream& os, const Movie& res);

		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_desc);
		}
	};
}

#endif // !SDDS_MOVIE_H
