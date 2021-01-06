/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename:Car.h
Version 1.0
Author Yongtak Jun
Revision History
-----------------------------------------------------------
Date			Reason
2020/Aug/01		Preliminary release
2020/Aug/05		Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor
provided to complete this program.
-----------------------------------------------------------*/


#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
namespace sdds
{
	class Car : public Vehicle
	{
		bool m_carWash;
	public:
		Car();
		Car(const char* licensePlate, const char* makeAndModel);
		Car(Car& copy) = delete;
		Car& operator=(Car& copy) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;
	};
}
#endif // !SDDS_CAR_H
