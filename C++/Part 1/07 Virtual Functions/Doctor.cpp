/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/21/2020
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iomanip>
#include<cstring>
#include"Doctor.h"

using namespace std;

namespace sdds
{
	Doctor::Doctor(const char* type, double salary, const int minHours, bool specialist)
		: Employee(salary, minHours)
	{
		if (type == nullptr || type[0] == '\0')
		{
			m_type[0] = '\0';
			m_specialist = false;
		}
		else
		{
			strcpy(m_type, type);
			m_specialist = specialist;
		}
	}
	double Doctor::getSalary(int workedHours)
	{
		double salary;
		if (workedHours <= getMinHours())
		{
			salary = workedHours * getHourlySalary();
		}
		else
		{
			salary = (getMinHours() * getHourlySalary()) + (workedHours - getMinHours()) * (getHourlySalary() * 1.5);
		}
		
		salary = m_specialist ? salary + 2000 : salary;

		return salary;
	}
	std::ostream& Doctor::display(std::ostream& out)
	{
		if (m_specialist)
		{
			cout << "Doctor" << endl;
			cout << right << setw(16) << "Type: " << m_type << " (specialist)" << endl;
			cout << right << setw(16) << "Pay Rate: " << getHourlySalary() << endl;
			cout << right << setw(16) << "Min Hours: " << getMinHours() << endl;
		}
		else
		{
			cout << "Doctor" << endl;
			cout << right << setw(16) << "Type: " << m_type << endl;
			cout << right << setw(16) << "Pay Rate: " << getHourlySalary() << endl;
			cout << right << setw(16) << "Min Hours: " << getMinHours() << endl;
		}
		return out;
	}
}