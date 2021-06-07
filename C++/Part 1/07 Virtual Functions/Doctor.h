/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/21/2020
*/

#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H
#include<iostream>
#include"Employee.h"

namespace sdds
{
	class Doctor : public Employee
	{
		char m_type[32];
		bool m_specialist;

	public:
		Doctor(const char* type, double salary, const int minHours, bool specialist = false);
		double getSalary(int workedHours);
		std::ostream& display(std::ostream& out);
	};
}

#endif // !

