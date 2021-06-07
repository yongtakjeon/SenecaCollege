/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/13/2020
*/

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include"MotorVehicle.h"

namespace sdds
{
	class Truck : public MotorVehicle
	{
		double m_maxWeight;
		double m_currentWeight;
		//

	public:
		Truck();
		Truck(const char* liNumber, int vehicleYear, double maxWeight, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& in = std::cin);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& s);
	std::istream& operator>>(std::istream& is, Truck& s);
}
#endif
