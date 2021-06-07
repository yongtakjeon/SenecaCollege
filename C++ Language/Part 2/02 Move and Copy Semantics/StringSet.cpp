/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Jan/30/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "StringSet.h"
#include <fstream>

using namespace std;

namespace sdds
{
	StringSet::StringSet()
	{
		bunchOfStrings = nullptr;
	}
	StringSet::StringSet(const char* str)
	{
		ifstream fin(str);
		
		while (!fin.eof())
		{
			fin.ignore(2000, ' ');
			noOfStrings++;
		}
		bunchOfStrings = new string[noOfStrings];
		fin.close();

		ifstream fin2(str);
		for (size_t i = 0; i < noOfStrings; i++)
		{
			getline(fin2, bunchOfStrings[i], ' ');
		}
		fin2.close();
	}
	StringSet::StringSet(StringSet& src)
	{
		noOfStrings = src.noOfStrings;

		if (src.bunchOfStrings != nullptr)
		{
			bunchOfStrings = nullptr;
			bunchOfStrings = new string[noOfStrings];

			for (size_t i = 0; i < noOfStrings; i++)
			{
				bunchOfStrings[i] = src.bunchOfStrings[i];
			}
		}
		else
		{
			bunchOfStrings = nullptr;
		}
	}
	StringSet& StringSet::operator=(StringSet& src)
	{
		if (this != &src)
		{
			noOfStrings = src.noOfStrings;

			delete[] bunchOfStrings;

			if (src.bunchOfStrings != nullptr)
			{
				bunchOfStrings = nullptr;
				bunchOfStrings = new string[noOfStrings];

				for (size_t i = 0; i < noOfStrings; i++)
				{
					bunchOfStrings[i] = src.bunchOfStrings[i];
				}
			}
			else
			{
				bunchOfStrings = nullptr;
			}
		}
		return *this;
	}
	StringSet::StringSet(StringSet&& src)
	{
		noOfStrings = src.noOfStrings;
		bunchOfStrings = src.bunchOfStrings;
		src.bunchOfStrings = nullptr;
		src.noOfStrings = 0;
	}
	StringSet& StringSet::operator=(StringSet&& src)
	{
		if (this != &src)
		{
			noOfStrings = src.noOfStrings;

			delete[] bunchOfStrings;
			bunchOfStrings = src.bunchOfStrings;
			src.bunchOfStrings = nullptr;
			src.noOfStrings = 0;
		}
		return *this;
	}
	size_t StringSet::size()
	{
		return noOfStrings;
	}
	std::string StringSet::operator[](size_t index)
	{
		string rt{};
		if (index < 0 || index >= noOfStrings)
		{
			rt = "";
		}
		else
		{
			rt = bunchOfStrings[index];
		}
		return rt;
	}
	StringSet::~StringSet()
	{
		delete[] bunchOfStrings;
	}
}