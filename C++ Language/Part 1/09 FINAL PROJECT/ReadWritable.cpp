/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename:ReadWritable.cpp
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


#include "ReadWritable.h"

namespace sdds
{
	ReadWritable::ReadWritable()
	{
		commaSeparated = false;
	}
	ReadWritable::~ReadWritable()
	{

	}
	bool ReadWritable::isCsv()const
	{
		return commaSeparated;
	}
	void ReadWritable::setCsv(bool value)
	{
		if (value == true || value == false)
		{
			commaSeparated = value ? true : false;
		}
	}
	std::istream& operator >> (std::istream& is, ReadWritable& s)
	{
		s.read(is);
		return is;
	}
	std::ostream& operator<<(std::ostream& os, ReadWritable& s)
	{
		s.write(os);
		return os;
	}
}