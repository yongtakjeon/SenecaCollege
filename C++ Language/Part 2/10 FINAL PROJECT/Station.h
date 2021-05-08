// Name: Yongtak Jun
// Seneca Student ID: 137350195
// Seneca email: yjun4@myseneca.ca
// Date of completion: Mar/23/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iomanip>
#include "Utilities.h"

using namespace std;

namespace sdds
{
	class Station // Each station handles a specific item for filling customer orders.
	{
		size_t m_id{};							// the id of the satation
		string m_itemName{};
		string m_desc{};
		size_t m_serialNum{};					// the next serial number available
		size_t m_qtyOfItems{};
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station();
		Station(const string str);				// takes a record from the items file and parses the data

		const std::string& getItemName() const;
		size_t getNextSerialNumber();			// Returns the next serial number available
		size_t getQuantity() const;
		void updateQuantity();					// Removes 1 from the quantity
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !SDDS_STATION_H
