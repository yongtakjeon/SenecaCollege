/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: June/21/2020
*/

#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H

#include "Engine.h"


namespace sdds
{

	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;

	class Ship
	{
		Engine *m_engines;
		char *m_type;
		int	m_engCnt;
		double getPower() const;
	public:
		Ship();
		Ship(const char* type, Engine* engines, int engCnt);
		explicit operator bool() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		friend bool operator<(double power, const Ship& theShip);
		~Ship();
	};
}

#endif
