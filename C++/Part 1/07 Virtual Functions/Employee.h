/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/21/2020
*/

#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

#include<iostream>

namespace sdds
{
	class Employee
	{
		const int m_minHours;
		double m_hourlySalary;

	protected:
		const int getMinHours();
		double getHourlySalary();
	public:
		Employee(double hourlySalary, const int minHours);
		virtual double getSalary(int workedHours) = 0;
		virtual std::ostream& display(std::ostream& out = std::cout) = 0;
		virtual ~Employee();
	};

	std::ostream& operator<<(std::ostream& os, Employee& s);
}





#endif