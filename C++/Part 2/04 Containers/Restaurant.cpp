/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/14/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#include "Restaurant.h"


namespace sdds
{
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		numOfRes = cnt;

		manyRes = nullptr;
		manyRes = new Reservation[numOfRes];

		for (size_t i = 0; i < numOfRes; i++)
		{
			manyRes[i] = *reservations[i];
		}
	}
	size_t Restaurant::size() const
	{
		return numOfRes;
	}

	ostream& operator<<(ostream& os, const Restaurant& restaurant)
	{
		static int numberOfCall = 1;

		os << "--------------------------" << endl;
		os << "Fancy Restaurant" << " (" << numberOfCall << ")" << endl;
		os << "--------------------------" << endl;

		if (restaurant.numOfRes)
		{
			for (size_t i = 0; i < restaurant.numOfRes; i++)
			{
				os << restaurant.manyRes[i];
			}
		}
		else
		{
			os << "This restaurant is empty!" << endl;
		}

		os << "--------------------------" << endl;

		numberOfCall++;

		return os;
	}


	Restaurant::Restaurant()
	{

	}
	Restaurant::Restaurant(const Restaurant& src)
	{
		*this = src;
	}
	Restaurant::Restaurant(Restaurant&& src)
	{
		*this = move(src);
	}
	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src)
		{
			numOfRes = src.numOfRes;

			delete[] manyRes;

			manyRes = nullptr;
			manyRes = new Reservation[numOfRes];

			for (size_t i = 0; i < numOfRes; i++)
			{
				manyRes[i] = src.manyRes[i];
			}

		}

		return *this;
	}
	Restaurant& Restaurant::operator=(Restaurant&& src)
	{
		if (this != &src)
		{
			delete[] manyRes;

			numOfRes = src.numOfRes;
			manyRes = src.manyRes;

			src.numOfRes = 0;
			src.manyRes = nullptr;

		}

		return *this;
	}
	Restaurant::~Restaurant()
	{
		delete[] manyRes;
	}

}