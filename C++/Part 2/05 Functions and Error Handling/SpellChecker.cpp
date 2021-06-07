/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/21/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#include <fstream>
#include <iomanip>
#include "SpellChecker.h"


namespace sdds
{
	void SpellChecker::trim(string& str)const
	{
		size_t i = 0;


		//removing leading spaces
		for (i = 0; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);


		//removing trailing spaces
		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}

	SpellChecker::SpellChecker() {}
	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream file(filename);

		if (!file)
			throw "Bad file name!";
		else
		{
			string strChecker{};
			size_t index{};

			do
			{
				getline(file, strChecker);

				if (file)
				{
					size_t sPos = 0;
					size_t ePos = strChecker.find(' ');
					m_badWords[index] = strChecker.substr(sPos, ePos - sPos);
					trim(m_badWords[index]);

					sPos = ePos + 1;
					m_goodWords[index] = strChecker.substr(sPos);
					trim(m_goodWords[index]);

					index++;
				}
			}while(file);

			file.close();
		}


	}


	void SpellChecker::operator()(std::string& text)
	{

		for (size_t i = 0; i < sizeof(m_goodWords)/sizeof(m_goodWords[0]); i++)
		{

			size_t index{};

			index = text.find(m_badWords[i]);

			while (index != string::npos)
			{
				cntReplaced[i]++;

				text.replace(index, m_badWords[i].length(), m_goodWords[i]);
				index = text.find(m_badWords[i]);
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;
		for (size_t i = 0; i < sizeof(m_goodWords) / sizeof(m_goodWords[0]); i++)
		{
			out << setw(15) << m_badWords[i] << ": " << cntReplaced[i] << " replacements" << endl;
		}
		
	}
}