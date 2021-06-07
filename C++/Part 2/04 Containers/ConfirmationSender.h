/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/14/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

using namespace std;

namespace sdds
{
	class ConfirmationSender
	{
		const sdds::Reservation** allRes{ nullptr };
		size_t m_cnt{};
	public:
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend ostream& operator<<(ostream& os, const ConfirmationSender& sender);
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		~ConfirmationSender();
	};



}
#endif // !SDDS_CONFIRMATIONSENDER_H
