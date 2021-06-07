// Name: Yongtak Jun
// Seneca Student ID: 137350195
// Seneca email: yjun4@myseneca.ca
// Date of completion: Apr/09/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <fstream>
#include <vector>
#include <algorithm>
#include "Workstation.h"



namespace sdds
{
	class LineManager
	{
		std::vector<Workstation*> activeLine{}; //the collection of workstations for the current assembly line
		size_t m_cntCustomerOrder{}; //the total number of CustomerOrder objects
		Workstation* m_firstStation{}; // points to the first active station on the current assembly line
	public:
		LineManager();
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations(); //reorders the workstations present in the instance variable activeLine
		bool run(std::ostream& os);
		void display(std::ostream& os) const; //this query displays all active stations on the assembly line in their current order
	};
}

#endif // !
