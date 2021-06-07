// Name: Yongtak Jun
// Seneca Student ID: 137350195
// Seneca email: yjun4@myseneca.ca
// Date of completion: Apr/09/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Workstation.h"

namespace sdds
{
	deque<CustomerOrder> pending{}; //customer orders to be filled
	deque<CustomerOrder> completed{}; //customer orders filled
	deque<CustomerOrder> incomplete{}; //customer orders not completely filled


	Workstation::Workstation() {}

	Workstation::Workstation(const string& record) :Station(record) {}

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
			//m_orders[0].fillItem(*this, os);
			m_orders.front().fillItem(*this, os);
			
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool isMoved = false;

		if (!m_orders.empty())
		{

			//if the order requires no more service at this station or if the order cannot be filled (not enough inventory)
			if (m_orders.front().isItemFilled(this->getItemName())|| this->getQuantity() == 0)
			{
				isMoved = true;

				if (m_pNextStation)
					*m_pNextStation += move(m_orders.front());

				else if(m_orders.front().isFilled())
					completed.push_back(move(m_orders.front()));

				else
					incomplete.push_back(move(m_orders.front()));
				
				m_orders.pop_front(); //a deque object has member function, pop_front()
			}
		}

		return isMoved;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation)
			os << this->getItemName() << " --> " << m_pNextStation->getItemName() << endl;
		else
			os << this->getItemName() << " --> End of Line" << endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(move(newOrder));

		return *this;
	}
}

