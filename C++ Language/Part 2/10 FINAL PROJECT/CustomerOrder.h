// Name: Yongtak Jun
// Seneca Student ID: 137350195
// Seneca email: yjun4@myseneca.ca
// Date of completion: Apr/01/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"

using namespace std;

namespace sdds
{

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name{};		//the name of the customer
		std::string m_product{};	//the name of the product being assembled
		size_t m_cntItem{};			//a count of the number of items in the customer's order
		Item** m_lstItem{};			//a dynamically allocated array of pointers. Each element of the array points to a dynamically allocated object of type Item.

		static size_t m_widthField; //used for display purposes
	public:
		CustomerOrder();
		CustomerOrder(const string &record);
		CustomerOrder(const CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;
		CustomerOrder(CustomerOrder&& src) noexcept;
		CustomerOrder& operator=(CustomerOrder&& src) noexcept;
		~CustomerOrder();

		bool isFilled() const; //check if all the items in the order have been filled
		bool isItemFilled(const std::string& itemName) const; //if all items specified by itemName have been filled
		void fillItem(Station& station, std::ostream& os); //fill all items in the current order that the Station specified in the first parameter handles
		void display(std::ostream& os) const;
	};
}


#endif // !SDDS_CUSTOMERORDER_H


