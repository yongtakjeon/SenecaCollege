/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/14/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

using namespace std;

namespace sdds
{
	class Restaurant
	{
		Reservation* manyRes{ nullptr };
		size_t numOfRes{};
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		size_t size() const;
		friend ostream& operator<<(ostream& os, const Restaurant& restaurant);

		Restaurant();
		Restaurant(const Restaurant& src);
		Restaurant(Restaurant&& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant& operator=(Restaurant&& src);
		~Restaurant();
	};


}
#endif // !SDDS_RESTAURANT_H
