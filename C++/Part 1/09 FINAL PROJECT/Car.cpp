/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename:Car.cpp
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

#include <cstring>
#include <cctype>
#include"Car.h"
using namespace std;
namespace sdds
{
	Car::Car()
	{
		Vehicle();
	}
	Car::Car(const char* licensePlate, const char* makeAndModel)
		: Vehicle(licensePlate, makeAndModel)
	{

	}
	std::istream& Car::read(std::istream& istr)
	{
		if (isCsv()) //if the Vehicle is set to Comma Separated mode
		{
			Vehicle::read(istr);
			istr >> m_carWash;
			istr.ignore(2000, '\n');
		}
		else //if the Vehicle's Comma Separated mode is off
		{
			cout << "\nCar information entry" << endl;
			Vehicle::read(istr);

			cout << "Carwash while parked? (Y)es/(N)o: "; //receiving the m_carWash value
			char yesNo[3];
			istr.get(yesNo, 3); //newline delimiter - accepts up to 2 chars and adds a null byte, and leave the delimiter in input buffer (not being removed)
			
			while (strlen(yesNo) == 2 || 
				(yesNo[0] != 'y' && yesNo[0] != 'Y' && yesNo[0] != 'n' && yesNo[0] != 'N'))
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
				istr.get(yesNo, 3);
			}
			m_carWash = toupper(yesNo[0]) == 'Y' ? true : false;
		}
		return istr;
	}

	std::ostream& Car::write(std::ostream& ostr)const
	{
		if (isEmpty())
		{
			ostr << "Invalid Car Object" << endl;
		}
		else
		{
			if (isCsv()) //if the Vehicle is set to Comma Separated mode
			{
				ostr << "C,";
				Vehicle::write(ostr);
				ostr << m_carWash << endl;
			}
			else
			{
				ostr << "Vehicle type: Car" << endl;
				Vehicle::write(ostr);
				if (m_carWash)
				{
					ostr << "With Carwash" << endl;
				}
				else
				{
					ostr << "Without Carwash" << endl;
				}
			}
		}
		cout << endl;
		return ostr;
	}
}