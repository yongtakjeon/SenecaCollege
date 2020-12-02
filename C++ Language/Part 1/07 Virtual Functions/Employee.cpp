/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/21/2020
*/

#include"Employee.h"

using namespace std;

namespace sdds
{
	const int Employee::getMinHours()
	{
		return m_minHours;
	}
	double Employee::getHourlySalary()
	{
		return m_hourlySalary;
	}
	Employee::Employee(double hourlySalary, const int minHours)
		: m_minHours(minHours), m_hourlySalary(hourlySalary) { }
	Employee::~Employee() { }

	std::ostream& operator<<(std::ostream& os, Employee& s)
	{
		s.display(os);
		return os;
	}

}