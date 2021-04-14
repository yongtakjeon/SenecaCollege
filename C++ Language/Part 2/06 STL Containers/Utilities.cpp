/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Mar/12/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Utilities.h"


namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* newVehicle = nullptr;

		char tag{};
		in >> tag;
		in.ignore(2000, ',');

		if (tag == 'c' || tag == 'C')
		{
			newVehicle = new Car(in);
		}
		else if (tag == 'r' || tag == 'R')
		{
			newVehicle = new Racecar(in);
		}
		else
		{
			if (!in.eof())
			{
				in.ignore(2000, '\n');
				throw tag;
			}
		}

		return newVehicle;
	}
}