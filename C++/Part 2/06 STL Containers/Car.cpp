/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Mar/12/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include <cctype>
#include "Car.h"

namespace sdds
{
	void Car::trim(string& str)const
	{
		size_t i = 0;


		//removing leading spaces
		for (i = 0; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);


		//removing trailing spaces
		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}
	bool Car::isNumber(const string& s) const
	{
		string::const_iterator iter = s.begin();
		while (iter != s.end() && isdigit(*iter)) //if it is a number, it returns true.
			++iter;

		return !s.empty() && iter == s.end();
	}
	Car::Car()
	{

	}

	Car::Car(std::istream& is)
	{
		getline(is, m_maker, ',');
		trim(m_maker);

		getline(is, m_condition, ',');
		trim(m_condition);
		if (m_condition.empty())
			m_condition = "n";
		if (m_condition != "n" && m_condition != "u" && m_condition != "b")
		{
			is.ignore(2000, '\n');
			throw "Invalid record!";
		}


		string tempSpeed{};
		char ch = is.get();
		while (ch != ',' && ch != '\n' && !is.eof())
		{
			tempSpeed += ch;
			ch = is.get();
		}
		trim(tempSpeed);

		if (isNumber(tempSpeed))
		{
			m_topSpeed = stoi(tempSpeed);
		}
		else
		{
			is.ignore(2000, '\n');
			throw "Invalid record!";
		}

		
	}

	std::string Car::condition() const
	{
		string condition{};
		if (m_condition == "n")
		{
			condition = "new";
		}
		else if (m_condition == "u")
		{
			condition = "used";
		}
		else if (m_condition == "b")
		{
			condition = "broken";
		}

		return condition;
	}
	
	double Car::topSpeed() const
	{
		return static_cast<double>(m_topSpeed);
	}

	void Car::display(std::ostream& out) const
	{
		out << "| " << setw(10) << m_maker << " | " << left << setw(6) << condition() << right << " | ";
		out.setf(ios::fixed);
		out.precision(2);
		out << setw(6) << topSpeed() << " |";

		out.unsetf(ios::fixed);
		out.precision(6);
	}
}


