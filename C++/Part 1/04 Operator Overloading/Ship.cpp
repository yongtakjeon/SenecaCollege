/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: June/21/2020
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include"Ship.h"

using namespace std;

namespace sdds
{
	Ship::Ship()
	{
		m_engines = nullptr;
		m_type = nullptr;
		m_engCnt = 0;
	}

	Ship::Ship(const char* type, Engine* engines, int engCnt)
	{
		
		if (type == nullptr || type[0] == '\0' || engines[0].get() == 0.0 || engCnt < 1)
		{
			m_engines = nullptr;
			m_type = nullptr;
			m_engCnt = 0;
		}
		else
		{
			m_type = nullptr;
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);

			m_engines = nullptr;
			m_engines = new Engine[engCnt];
			for (int i = 0; i < engCnt; i++)
			{
				m_engines[i] = engines[i];
			}

			m_engCnt = engCnt;
		}
	}

	Ship::operator bool() const
	{
		return !(m_engines == nullptr|| m_engines[0].get() == 0.0 || 
					m_type == nullptr||m_type[0] == '\0' || m_engCnt == 0);
	}

	Ship& Ship::operator+=(Engine engine)
	{
		if (*this)
		{
			
			Engine *temp = nullptr;
			temp = new Engine[m_engCnt + 1];

			for (int i = 0; i < m_engCnt; i++)
			{
				temp[i] = m_engines[i];
			}

			temp[m_engCnt++] = engine;

			delete[] m_engines;
			m_engines = nullptr;

			m_engines = temp;

			temp = nullptr;
		}
		else
		{
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}

		return *this;
	}

	double Ship::getPower() const
	{
		double power = 0;
		for (int i = 0; i < m_engCnt; i++)
		{
			power = power + m_engines[i].get() * 5;
		}
		return power;
	}
	
	bool Ship::operator<(double power) const
	{
		return (getPower() < power);
	}

	void Ship::display() const
	{
		if (*this)
		{
			cout.setf(ios::fixed);
			cout.precision(2);

			cout << m_type << " - " << right << setw(6) << getPower() << endl;
			for (int i = 0; i < m_engCnt; i++)
			{
				m_engines[i].display();
			}

			cout.unsetf(ios::fixed);
			cout.precision(6);
		}
		else
		{
			cout << "No available data" << endl;
		}
	}

	bool operator<(double power, const Ship& theShip)
	{
		return power < theShip.getPower();
	}

	Ship::~Ship()
	{
		delete[] m_engines;
		delete[] m_type;
	}

}