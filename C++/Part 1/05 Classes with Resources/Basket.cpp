/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/04/2020
*/

#include <iostream>
#include <iomanip>
#include "Basket.h"

using namespace std;

namespace sdds
{
	Basket::Basket()
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}
	Basket::Basket(Fruit* fruits, int cnt, double price)
	{
		if (fruits == nullptr || cnt <= 0 || price <= 0)
		{
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0;
		}
		else
		{
			m_fruits = nullptr;
			m_fruits = new Fruit[cnt];

			for (int i = 0; i < cnt; i++)
			{
				m_fruits[i] = fruits[i];
			}

			m_cnt = cnt;
			m_price = price;
		}
	}

	Basket::Basket(const Basket& copy)
	{
		if (copy.m_cnt <= 0 || copy.m_price <= 0 || copy.m_fruits == nullptr)
		{
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0;
		}
		else
		{
			m_cnt = copy.m_cnt;
			m_price = copy.m_price;

			m_fruits = nullptr;
			m_fruits = new Fruit[m_cnt];

			for (int i = 0; i < m_cnt; i++)
			{
				m_fruits[i] = copy.m_fruits[i];
			}
		}
	}

	Basket& Basket::operator=(const Basket& copy)
	{
		if (this != &copy)
		{
			if (m_fruits)
			{
				delete[] m_fruits;
			}

			if (copy.m_cnt <= 0 || copy.m_price <= 0 || copy.m_fruits == nullptr)
			{
				m_fruits = nullptr;
				m_cnt = 0;
				m_price = 0;
			}
			else
			{
				m_cnt = copy.m_cnt;
				m_price = copy.m_price;

				m_fruits = nullptr;
				m_fruits = new Fruit[m_cnt];

				for (int i = 0; i < m_cnt; i++)
				{
					m_fruits[i] = copy.m_fruits[i];
				}
			}
		}

		return *this;
	}

	Basket::~Basket()
	{
		delete[] m_fruits;
	}
	void Basket::setPrice(double price)
	{
		m_price = price;
	}
	Basket::operator bool() const
	{
		return (m_fruits != nullptr && m_cnt > 0 && m_price > 0);
	}
	Basket& Basket::operator+=(const Fruit adding)
	{
		Fruit* temp = nullptr;
		temp = new Fruit[m_cnt + 1];

		for (int i = 0; i < m_cnt; i++)
		{
			temp[i] = m_fruits[i];
		}

		delete[] m_fruits;
		m_fruits = nullptr;

		temp[m_cnt++] = adding;

		m_fruits = temp;
		temp = nullptr;
		
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Basket& s)
	{
		if (s)
		{
			os.setf(ios::fixed);
			os.precision(2);

			os << "Basket Content:" << endl;
			for (int i = 0; i < s.m_cnt; i++)
			{
				os << right << setw(10) << s.m_fruits[i].m_name << ": " << s.m_fruits[i].m_qty << "kg" << endl;
			}
			os << "Price: " << s.m_price << endl;

			os.unsetf(ios::fixed);
			os.precision(6);
		}
		else
		{
			os << "The basket is empty!" << endl;
		}
		return os;
	}
}