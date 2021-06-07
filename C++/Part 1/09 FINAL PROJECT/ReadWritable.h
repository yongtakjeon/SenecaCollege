/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename:ReadWritable.h
Version 1.0
Author Yongtak Jun
Revision History
-----------------------------------------------------------
Date			Reason
2020/July/25	Preliminary release
2020/Aug/05		Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor
provided to complete this program.
-----------------------------------------------------------*/

#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
#include<iostream>

namespace sdds
{
	class ReadWritable
	{
		bool commaSeparated;
		//

	public:
		ReadWritable();
		virtual ~ReadWritable();
		bool isCsv()const; //check if it is comma seperated
		void setCsv(bool value);
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
	};
	std::istream& operator >> (std::istream& is, ReadWritable& s);
	std::ostream&operator<<(std::ostream&os, ReadWritable&s);
}
#endif // !SDDS_READWRITABLE_H
