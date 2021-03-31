/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/21/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

using namespace std;

namespace sdds
{
	class SpellChecker
	{
		string m_badWords[6]{};
		string m_goodWords[6]{};
		size_t cntReplaced[6]{};
		void trim(string& str) const;

	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};



}


#endif // !SDDS_SPELLCHECKER_H
