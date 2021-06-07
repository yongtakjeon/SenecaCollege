/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Jan/30/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H
#include <iostream>
#include <string>
namespace sdds
{

	class StringSet
	{
		std::string* bunchOfStrings;
		size_t noOfStrings{ 0 };
	public:
		StringSet();
		StringSet(const char* str);
		StringSet(StringSet& src);
		StringSet& operator=(StringSet& src);
		StringSet(StringSet&& src);
		StringSet& operator=(StringSet&& src);
		size_t size();
		std::string operator[](size_t index);
		~StringSet();
	};


}

#endif // !SDDS_STRINGSET_H



