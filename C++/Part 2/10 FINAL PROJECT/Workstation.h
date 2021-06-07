// Name: Yongtak Jun
// Seneca Student ID: 137350195
// Seneca email: yjun4@myseneca.ca
// Date of completion: Apr/09/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include "CustomerOrder.h"

namespace sdds
{
	extern deque<CustomerOrder> pending; //customer orders to be filled
	extern deque<CustomerOrder> completed; //customer orders filled
	extern deque<CustomerOrder> incomplete; //customer orders not completely filled


	// A Workstation is a Station that the LineManager has activated on the user's request.
	// Each Workstation is-a-kind-of Station.
	// Since a Workstation object represents a single location on the assembly line for filling customer orders with items, the object cannot be copied or moved.
	class Workstation : public Station
	{
		deque<CustomerOrder> m_orders{}; //a current order at this Workstation
		Workstation* m_pNextStation{}; //a pointer to the next Workstation on the assembly line
	public:
		Workstation();
		Workstation(const string& record); //receives a record and passes it to the Station base class
		Workstation(const Workstation& src) = delete;
		Workstation(Workstation&& src) = delete;
		Workstation& operator=(const Workstation& src) = delete;
		Workstation& operator=(Workstation&& src) = delete;
		void fill(std::ostream& os); //This modifier fills the order at the front of the queue, if there are CustomerOrders in the queue; otherwise, does nothing.
		bool attemptToMoveOrder(); //attempts to move the order at the front of the queue to the next station in the assembly line
		void setNextStation(Workstation* station = nullptr); //stores the address of Workstation in the parameter to the m_pNextStation
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder); //moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
	};
}




#endif // !SDDS_WORKSTATION_H
