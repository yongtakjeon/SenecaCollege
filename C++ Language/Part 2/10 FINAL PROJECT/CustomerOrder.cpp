// Name: Yongtak Jun
// Seneca Student ID: 137350195
// Seneca email: yjun4@myseneca.ca
// Date of completion: Apr/01/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"


namespace sdds
{
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() {}

	CustomerOrder::CustomerOrder(const string &record)
	{
		if (record.empty())
		{
			m_name = "";
			m_product = "";
			m_cntItem = 0;
		}
		else
		{
			Utilities util;
			bool more = false; // to check if there are more tokens in the record
			size_t next_pos = 0u; // position of the next token in the record

			m_name = util.extractToken(record, next_pos, more);

			if (more)
				m_product = util.extractToken(record, next_pos, more);
			
			string strItems = record.substr(next_pos);
			m_cntItem = std::count(strItems.begin(), strItems.end(), Utilities::getDelimiter()) + 1;
			//std::count() is defined in <algorithm> header file

			m_lstItem = new Item * [m_cntItem];
			for (size_t i = 0; i < m_cntItem && more; ++i)
				m_lstItem[i] = new Item(util.extractToken(record, next_pos, more));

			if (m_widthField < util.getFieldWidth())
				m_widthField = util.getFieldWidth();

		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw "CustomerOrder object is not allowed to copy.";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			for (size_t i = 0; i < m_cntItem; ++i)
			{
				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			}
			delete[] m_lstItem;
			m_lstItem = nullptr;

			m_lstItem = src.m_lstItem;
			src.m_lstItem = nullptr;

			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;

			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			delete m_lstItem[i];
			m_lstItem[i] = nullptr;
		}

		delete[] m_lstItem;
	}

	bool CustomerOrder::isFilled() const
	{
		bool isFilled = true;
		for (size_t i = 0; i < m_cntItem && isFilled; ++i)
		{
			if (m_lstItem[i]->m_isFilled == false)
				isFilled = false;
		}

		return isFilled;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool isFilled = true;

		for (size_t i = 0; i < m_cntItem && isFilled; ++i)
		{
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == false)
				isFilled = false;
		}

		return isFilled;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName()) //if the order doesn't contain the item handled by the station, this function does nothing
			{
				if (station.getQuantity() > 0) //if the Station's inventory contains at least one item
				{
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else //if the order contains items handled but unfilled, and the inventory is empty
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << endl;
		
		for (size_t i = 0; i < m_cntItem; ++i)
		{
			string isFilled = m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED";
			os << "[" << setfill('0') << setw(6) << m_lstItem[i]->m_serialNumber << "] " << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName << right << " - " << isFilled << endl;
		}
	}
}
