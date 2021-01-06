/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename:Vehicle.h
Version 1.0
Author Yongtak Jun
Revision History
-----------------------------------------------------------
Date			Reason
2020/July/25	Preliminary release
2020/Aug/05		Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor
provided to complete this program.
-----------------------------------------------------------*/


#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include "ReadWritable.h"
#include "Utils.h"

namespace sdds
{
	class Vehicle : public ReadWritable
	{
		char m_licensePlate[9];
		char* m_makeAndModel;
		int m_parkingSpotNumber;
	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char* makeAndModel);
	public:
		Vehicle();
		Vehicle(const char* licensePlate, const char* makeAndModel);
		Vehicle(const Vehicle& copy) = delete;
		Vehicle& operator=(const Vehicle& copy) = delete;
		virtual ~Vehicle();
		int getParkingSpot() const;
		void setParkingSpot(int parkingSpotNumber);
		bool operator==(const char* licensePlate) const; //check if license plate is identical
		bool operator==(const Vehicle& anotherVehicle) const; //check if license plate is identical
		std::istream& read(std::istream& istr = std::cin); //it will be used within >> operator which is declared in ReadWritable.h
		std::ostream& write(std::ostream& ostr = std::cout)const; //it will be used within << operator which is declared in ReadWritable.h
		//
	};
}
#endif // !SDDS_VEHICLE_H
