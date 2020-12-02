/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/21/2020
*/

#include <iomanip>
#include"Engineer.h"

using namespace std;

namespace sdds
{
	Engineer::Engineer(double hourlySalary, int level, const int minHours)
		: Employee(hourlySalary, minHours), m_level(level) { }

	double Engineer::getSalary(int workedHours)
	{
		double salary = getHourlySalary() * workedHours;
		salary += m_level * 40;
		if (workedHours < getMinHours())
		{
			salary = salary * 0.8;
		}
		return salary;
	}
	std::ostream& Engineer::display(std::ostream& out)
	{
		cout << "Engineer" << endl;
		cout << right << setw(20) << "Level: " << m_level << endl;
		cout << right << setw(20) << "Pay Rate: " << getHourlySalary() << endl;
		cout << right << setw(20) << "Min Hours: " << getMinHours() << endl;

		return out;
	}
}