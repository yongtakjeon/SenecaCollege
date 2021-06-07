/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jeon
Date: June/20/2020
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Saiyan.h"

using namespace std;

namespace sdds
{
	Saiyan::Saiyan()
	{
		m_name = nullptr;
		m_dob = -1;
		m_power = -1;
		m_super = false;
		m_level = -1;
	}

	Saiyan::Saiyan(const char* name, int birth, int power)
	{
		m_name = nullptr;
		set(name, birth, power);
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super)
	{
		if (name == nullptr || name[0] == '\0' || dob > 2020 || power < 0)
		{
			m_name = nullptr;
			m_dob = -1;
			m_power = -1;
			m_super = false;
			m_level = -1;
		}
		else
		{
			
			if (m_name)
			{
				delete[] m_name;
				m_name = nullptr;
			}
			
			m_name = new char[strlen(name)+1];
			
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_level = level;
			m_super = super;
		}
	}

	bool Saiyan::isValid() const
	{
		return (m_name != nullptr && m_dob != -1 && m_power != -1 && m_level != -1);
	}

	void Saiyan::display() const
	{
		if (isValid() && m_super)
		{ 
			cout << m_name << endl;
			cout << right << setw(10) << "DOB: " << m_dob << endl;
			cout << right << setw(10) << "Power: " << m_power << endl;
			cout << right << setw(10) << "Super: " << "yes" << endl;
			cout << right << setw(10) << "Level: " << m_level << endl;
		}
		else if (isValid() && !m_super)
		{
			cout << m_name << endl;
			cout << right << setw(10) << "DOB: " << m_dob << endl;
			cout << right << setw(10) << "Power: " << m_power << endl;
			cout << right << setw(10) << "Super: " << "no" << endl;
		}
		else
		{
			cout << "Invalid Saiyan!" << endl;
		}
	}

	bool Saiyan::fight(Saiyan& other)
	{
		bool win = false;

		if (m_super)
		{
			m_power = m_power + m_power * (0.1 * m_level);
		}
		if (other.m_super)
		{
			other.m_power = other.m_power + other.m_power * (0.1 * other.m_level);
		}

		if (isValid() && other.isValid() && m_power > other.m_power)
		{
			win = true;
		}
		return win;
	}

	Saiyan::~Saiyan()
	{
		delete[] m_name;
	}

}