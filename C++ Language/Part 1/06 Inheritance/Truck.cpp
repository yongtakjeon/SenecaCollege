/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/13/2020
*/

#include<iostream>
#include "Truck.h"

using namespace std;

namespace sdds
{
	Truck::Truck()
	{
		m_maxWeight = -1;
		m_currentWeight = -1;
	}
	Truck::Truck(const char* liNumber, int vehicleYear, double maxWeight, const char* address) : MotorVehicle(liNumber, vehicleYear)
	{
		if (maxWeight < 0 || address == nullptr || address[0] == '\0')
		{
			m_maxWeight = -1;
			m_currentWeight = -1;
		}
		else
		{
			m_maxWeight = maxWeight;
			m_currentWeight = 0;
			moveTo(address);
		}
	}
	bool Truck::addCargo(double cargo)
	{
		double newWeight;
		newWeight = m_currentWeight + cargo;
		if (newWeight > m_maxWeight)
		{
			newWeight = m_maxWeight;
		}

		bool loading = newWeight != m_currentWeight ? true : false;
		m_currentWeight = newWeight;

		return loading;
	}
	bool Truck::unloadCargo()
	{
		double newWeight = 0;
		
		bool unloading = newWeight != m_currentWeight ? true : false;
		m_currentWeight = newWeight;

		return unloading;
	}
	std::ostream& Truck::write(std::ostream& os) const
	{
		MotorVehicle::write(os);
		os << " | " << m_currentWeight << "/" << m_maxWeight;
		return os;
	}
	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_maxWeight;
		cout << "Cargo: ";
		in >> m_currentWeight;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const Truck& s)
	{
		s.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Truck& s)
	{
		s.read(is);
		return is;
	}
}