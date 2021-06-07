/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: June/21/2020
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Engine.h"

using namespace std;

namespace sdds
{
	Engine::Engine()
	{
		m_size = 0.0;
		m_type[0] = '\0';
	}

	Engine::Engine(const char* type, double size)
	{
		if (type == nullptr || type[0] == '\0')
		{
			m_size = 0.0;
			m_type[0] = '\0';
		}
		else
		{
			strncpy(m_type, type, TYPE_MAX_SIZE);
			m_size = size;
		}
	}

	double Engine:: get() const
	{
		return m_size;
	}

	void Engine::display() const
	{
		cout << m_size << " liters - " << m_type << endl;
	}

}
