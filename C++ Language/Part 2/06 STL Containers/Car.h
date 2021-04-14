/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Mar/12/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

using namespace std;

namespace sdds
{
	class Car : public Vehicle
	{
		string m_maker{};
		string m_condition;
		size_t m_topSpeed{};
		void trim(string& str)const;
		bool isNumber(const string& s) const;
	public:
		Car();
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};

}

#endif // !
