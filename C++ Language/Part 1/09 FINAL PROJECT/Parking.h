/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename:Parking.h
Version 1.0
Author Yongtak Jun
Revision History
-----------------------------------------------------------
Date			Reason
2020/July/14	Preliminary release
2020/Aug/05		Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor
provided to complete this program.
-----------------------------------------------------------*/

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include"Menu.h"
#include "Car.h"
#include "Motorcycle.h"

namespace sdds
{
	const int maxParkingSpots = 100;

	class Parking
	{
		char* m_fileName;
		Menu mainMenu;
		Menu subMenu1;
		int m_numOfSpots;
		Vehicle* m_parkingSpots[maxParkingSpots]; //address will be assigned to each element
		int m_numOfParked; //always less than numOfSpots

		
		bool loadDataFile();
		void saveDataFile();
		bool isEmpty();
		void parkingStatus();
		void parkVehicle(); //main menu selection 1 (subMenu1)
		void returnVehicle(); //main menu selection 2
		void listParkedVehicle(); //main menu selection 3
		bool closeParking(); //main menu selection 4
		bool exitParkingApp(); //main menu selection 5
		//
		void setParkingEmpty();
		operator bool() const; //to check if the Parking class is valid
		void setFileName(const char* fileName); //set only file name using dynamic memory allocation

	public:
		Parking();
		Parking(const char* datafile, int noOfSpots); 
		~Parking();
		Parking(const Parking& copy) = delete;
		Parking& operator=(const Parking& copy) = delete;

		int run();
	};



}


#endif
