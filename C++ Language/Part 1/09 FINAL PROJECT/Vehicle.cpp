/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename:Vehicle.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring> //for strlen, strcpy
#include "Vehicle.h"

using namespace std;

namespace sdds
{
	Vehicle::Vehicle()
	{
		m_licensePlate[0] = '\0';
		m_makeAndModel = nullptr;
		m_parkingSpotNumber = -1;
	}
	Vehicle::Vehicle(const char* licensePlate, const char* makeAndModel)
	{
		if (licensePlate == nullptr || licensePlate[0] == '\0' || strlen(licensePlate) > 8 || makeAndModel == nullptr || makeAndModel[0] == '\0' || strlen(makeAndModel) < 2)
		{
			m_makeAndModel = nullptr; //clearing the garbage value
			setEmpty();
		}
		else
		{
			strcpy(m_licensePlate, licensePlate);
			m_makeAndModel = nullptr;
			m_makeAndModel = new char[strlen(makeAndModel) + 1];
			strcpy(m_makeAndModel, makeAndModel);
			m_parkingSpotNumber = 0;
		}
	}
	Vehicle::~Vehicle()
	{
		if (m_makeAndModel)
		{
			delete[] m_makeAndModel;
		}
	}
	void Vehicle::setEmpty()
	{
		m_licensePlate[0] = '\0';
		if (m_makeAndModel)
		{
			delete[] m_makeAndModel;
		}
		m_makeAndModel = nullptr;
		m_parkingSpotNumber = -1;
	}
	bool Vehicle::isEmpty() const
	{
		return (m_licensePlate[0] == '\0' || m_makeAndModel == nullptr || m_makeAndModel[0] == '\0' || m_parkingSpotNumber < 0);
	}
	const char* Vehicle::getLicensePlate() const
	{
		return m_licensePlate;
	}
	const char* Vehicle::getMakeModel() const
	{
		return m_makeAndModel;
	}
	void Vehicle::setMakeModel(const char* makeAndModel)
	{
		if (makeAndModel == nullptr || makeAndModel[0] == '\0')
		{
			setEmpty();
		}
		else
		{
			if (m_makeAndModel)
			{
				delete[] m_makeAndModel;
			}
			m_makeAndModel = nullptr;
			m_makeAndModel = new char[strlen(makeAndModel) + 1];
			strcpy(m_makeAndModel, makeAndModel);
		}
	}
	int Vehicle::getParkingSpot()const
	{
		return m_parkingSpotNumber;
	}
	void Vehicle::setParkingSpot(int parkingSpotNumber)
	{
		if (parkingSpotNumber < 0)
		{
			setEmpty();
		}
		else
		{
			m_parkingSpotNumber = parkingSpotNumber;
		}
	}
	bool Vehicle::operator==(const char* licensePlate) const //check if license plate is identical
	{
		bool value;
		if (m_licensePlate[0] == '\0' || licensePlate == nullptr || licensePlate[0] == '\0')
		{
			value = false;
		}
		else
		{
			value = strCaseCmp(m_licensePlate, licensePlate);
		}
		return value;
	}
	bool Vehicle::operator==(const Vehicle& anotherVehicle) const //check if license plate is identical
	{
		bool value;
		if (m_licensePlate[0] == '\0' || anotherVehicle.m_licensePlate[0] == '\0')
		{
			value = false;
		}
		else
		{
			value = strCaseCmp(m_licensePlate, anotherVehicle.m_licensePlate);
		}
		return value;
	}
	std::istream& Vehicle::read(std::istream& istr)
	{
		if (isCsv()) //if the Vehicle is set to Comma Separated mode
		{
			istr >> m_parkingSpotNumber;
			istr.ignore(); //for discarding '\n' from input buffer

			char tempPlate[9];
			istr.getline(tempPlate, 9, ','); // ',' delimiter - accepts up to 8 chars and adds a null byte
			strToUpper(tempPlate);
			strcpy(m_licensePlate, tempPlate);
			
			char tempMakeModel[61];
			istr.getline(tempMakeModel, 61, ','); // ',' delimiter - accepts up to 60 chars and adds a null byte
			if (m_makeAndModel)
			{
				delete[] m_makeAndModel;
			}
			m_makeAndModel = nullptr;
			m_makeAndModel = new char[strlen(tempMakeModel) + 1];
			strcpy(m_makeAndModel, tempMakeModel);
		}
		else //if the Vehicle's Comma Separated mode is off
		{
			m_parkingSpotNumber = 0; //setting the Parking Spot number to 0.

			cout << "Enter Licence Plate Number: ";   //receiving Licence Plate Number
			char tempPlate[10];
			istr.get(tempPlate, 10); // newline delimiter - accepts up to 9 chars and adds a null byte, and leave the delimiter in input buffer (not being removed)
			while (strlen(tempPlate) < 2 || strlen(tempPlate) == 9)
			{
				cout << "Invalid Licence Plate, try again: ";
				istr.clear();
				istr.ignore(2000, '\n');
				istr.get(tempPlate, 10);
			}
			strToUpper(tempPlate);
			strcpy(m_licensePlate, tempPlate);
			istr.ignore(2000, '\n'); //clearing the input buffer before receiving the Make and Model

			cout << "Enter Make and Model: ";  //receiving Make and Model
			char tempMakeModel[62];
			istr.get(tempMakeModel,62);
			while (strlen(tempMakeModel) < 2 || strlen(tempMakeModel) == 61)
			{
				cout << "Invalid Make and model, try again: ";
				istr.clear();
				istr.ignore(2000, '\n');
				istr.get(tempMakeModel, 62);
			}
			istr.ignore(2000, '\n'); //clearing the input buffer before this function is finshed

			if (m_makeAndModel)
			{
				delete[] m_makeAndModel;
			}
			m_makeAndModel = nullptr;
			m_makeAndModel = new char[strlen(tempMakeModel) + 1];
			strcpy(m_makeAndModel, tempMakeModel);
		}
		if (!istr) //Then in any mode (comma separated or not), the read function will check if the istream object failed while reading, and if it's true, it will set the Vehicle object to an invalid empty state.
		{
			setEmpty();
		}

		return istr;
	}
	std::ostream& Vehicle::write(std::ostream& ostr)const
	{
		if (isEmpty())
		{
			ostr << "Invalid Vehicle Object" << endl;
		}
		else
		{
			if (isCsv()) //if the Vehicle is set to Comma Separated mode
			{
				ostr << m_parkingSpotNumber << "," << m_licensePlate << "," << m_makeAndModel << ",";
			}
			else
			{
				ostr << "Parking Spot Number: ";
				if (m_parkingSpotNumber == 0)
				{
					ostr << "N/A" << endl;
				}
				else
				{
					ostr << m_parkingSpotNumber << endl;
				}
				ostr << "Licence Plate: " << m_licensePlate << endl;
				ostr << "Make and Model: " << m_makeAndModel << endl;
			}
		}

		return ostr;
	}
}