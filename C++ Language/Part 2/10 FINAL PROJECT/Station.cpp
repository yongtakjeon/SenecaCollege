// Name: Yongtak Jun
// Seneca Student ID: 137350195
// Seneca email: yjun4@myseneca.ca
// Date of completion: Mar/23/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"


namespace sdds
{
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station() {};

	Station::Station(const string str)
	{
		m_id = ++id_generator;

		Utilities util;
		bool more = false; //to check if there are more tokens in the input string
		size_t next_pos = 0u; // position of the next token in the input string


		if (str.empty())
		{
			m_itemName = "";
			m_serialNum = 0;
			m_qtyOfItems = 0;
		}
		else
		{
			string token = util.extractToken(str, next_pos, more);
			m_itemName = token;

			if (more)
			{
				token = util.extractToken(str, next_pos, more);
				m_serialNum = stoi(token);
			}
			
			if (more)
			{
				token = util.extractToken(str, next_pos, more);
				m_qtyOfItems = stoi(token);
			}
			
			if (m_widthField < util.getFieldWidth())
				m_widthField = util.getFieldWidth();

			if (more)
			{
				token = util.extractToken(str, next_pos, more);
				m_desc = token;
			}
			
		}
	}

	const string& Station::getItemName() const
	{
		return m_itemName;
	}

	size_t Station::getNextSerialNumber()
	{
		return m_serialNum++;
	}

	size_t Station::getQuantity() const
	{
		return m_qtyOfItems;
	}

	void Station::updateQuantity()
	{
		if (m_qtyOfItems >= 1)
			m_qtyOfItems--;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		if (full)
		{
			os << "[" << setfill('0') << setw(3) << m_id << setfill(' ') << "] Item: " << left << setw(m_widthField) << m_itemName << right << " [" << setfill('0') << setw(6) << m_serialNum << setfill(' ') << "] Quantity: " << left << setw(m_widthField) << m_qtyOfItems << right << " Description: " << m_desc << endl;
		}
		else
		{
			os << "[" << setfill('0') << setw(3) << m_id << setfill(' ') << "] Item: " << left << setw(m_widthField) << m_itemName << right << " [" << setfill('0') << setw(6) << m_serialNum << setfill(' ') << "]" << endl;
		}
	}
}
