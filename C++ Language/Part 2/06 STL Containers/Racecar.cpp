/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Mar/12/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(std::istream& in):Car(in)
	{
		string tempBooster{};
		getline(in, tempBooster);

		m_booster = stod(tempBooster);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + Car::topSpeed() * m_booster;
	}

}