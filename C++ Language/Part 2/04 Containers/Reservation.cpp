/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/14/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip>
#include "Reservation.h"


namespace sdds
{
	void Reservation::trim(string& str)const
	{
		size_t i = 0;


		//removing leading spaces
		for (i = 0; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);


		//removing trailing spaces
		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}
	Reservation::Reservation()
	{

	}

	Reservation::Reservation(const std::string& res)
	{
		size_t startPosition = 0;
		size_t endPosition = res.find(':');
		id = res.substr(startPosition, endPosition - startPosition);
		trim(id);

		startPosition = endPosition + 1;
		endPosition = res.find(',', startPosition);
		name = res.substr(startPosition, endPosition - startPosition);
		trim(name);

		startPosition = endPosition + 1;
		endPosition = res.find(',', startPosition);
		email = res.substr(startPosition, endPosition - startPosition);
		trim(email);

		startPosition = endPosition + 1;
		endPosition = res.find(',', startPosition);
		numOfPpl = stoi(res.substr(startPosition, endPosition - startPosition));

		startPosition = endPosition + 1;
		endPosition = res.find(',', startPosition);
		day = stoi(res.substr(startPosition, endPosition - startPosition));

		startPosition = endPosition + 1;
		hour = stoi(res.substr(startPosition));
	}

	ostream& operator<<(ostream& os, const Reservation& res)
	{
		string email = "<" + res.email + ">";
		os << "Reservation " << setw(10) << res.id << ": " << setw(20) << right << res.name << "  " << setw(20) << left << email << right;

		if (6 <= res.hour && res.hour <= 9)
		{
			os << "    Breakfast ";
		}
		else if (11 <= res.hour && res.hour <= 15)
		{
			os << "    Lunch ";
		}
		else if (17 <= res.hour && res.hour <= 21)
		{
			os << "    Dinner ";
		}
		else
		{
			os << "    Drinks ";
		}

		os << "on day " << res.day << " @ " << res.hour << ":00 for " << res.numOfPpl << (res.numOfPpl > 1 ? " people" : " person") << ".\n";

		return os;
	}


}









