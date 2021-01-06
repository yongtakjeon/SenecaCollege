/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename:Motorcycle.cpp
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
#include "Motorcycle.h"

using namespace std;

namespace sdds
{
	Motorcycle::Motorcycle()
	{
		Vehicle();
	}
	Motorcycle::Motorcycle(const char* licensePlate, const char* makeAndModel)
		: Vehicle(licensePlate, makeAndModel)
	{

	}

	std::istream& Motorcycle::read(std::istream& istr)
	{
		if (isCsv()) //if the Vehicle is set to Comma Separated mode
		{
			Vehicle::read(istr);
			istr >> m_hasSidecar;
			istr.ignore(2000, '\n');
		}
		else //if the Vehicle's Comma Separated mode is off
		{
			cout << "\nMotorcycle information entry" << endl;
			Vehicle::read(istr);

			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: "; //receiving the m_hasSidecar value
			char yesNo[3];
			istr.get(yesNo, 3);

			while (strlen(yesNo) == 2 ||
				(yesNo[0] != 'y' && yesNo[0] != 'Y' && yesNo[0] != 'n' && yesNo[0] != 'N'))
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
				istr.get(yesNo, 3);
			}
			m_hasSidecar = toupper(yesNo[0]) == 'Y' ? true : false;
		}
		return istr;
	}

	std::ostream& Motorcycle::write(std::ostream& ostr)const
	{
		if (isEmpty())
		{
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else
		{
			if (isCsv()) //if the Vehicle is set to Comma Separated mode
			{
				ostr << "M,";
				Vehicle::write(ostr);
				ostr << m_hasSidecar << endl;
			}
			else
			{
				ostr << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(ostr);
				if (m_hasSidecar)
				{
					ostr << "With Sidecar" << endl;
				}
			}
		}
		return ostr;
	}
}