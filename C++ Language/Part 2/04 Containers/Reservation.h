/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/14/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>

using namespace std;

namespace sdds
{
	class Reservation
	{
		string id{};
		string name{};
		string email{};
		size_t numOfPpl{};
		size_t day{};
		size_t hour{};

		void trim(string& str)const;
	public:
		Reservation();
		Reservation(const std::string& res);
		friend ostream& operator<<(ostream& os, const Reservation& res);
	};


}
#endif // !SDDS_RESERVATION_H
