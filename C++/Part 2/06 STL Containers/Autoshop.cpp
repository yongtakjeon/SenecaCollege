/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Mar/12/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Autoshop.h"

using namespace std;

namespace sdds
{
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);

		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;

		//for (vector<Vehicle*>::const_iterator iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++)
		for (auto iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++)
		{
			(**iter).display(out);
			out << endl;
		}

		out << "--------------------------------" << endl;
	}
	Autoshop::~Autoshop()
	{
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
		{
			delete *it;
		}
	}
}