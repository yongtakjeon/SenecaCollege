/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Mar/12/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Racecar.h"

namespace sdds
{

	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
			{
				if (test(*it))
				{
					vehicles.push_back(*it);
				}
			}
		}
	};
}
#endif // !SDDS_AUTOSHOP_H
