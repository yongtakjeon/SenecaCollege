/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/21/2020
*/

#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H
#include<iostream>
#include "Employee.h"

namespace sdds
{
	class Engineer : public Employee
	{
		int m_level;

	public:
		Engineer(double hourlySalary, int level, const int minHours = 30);
		double getSalary(int workedHours);
		std::ostream& display(std::ostream& out);
	};

}


#endif