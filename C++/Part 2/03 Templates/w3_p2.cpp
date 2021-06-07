// Workshop 3 - Templates
// 2019/01/23 - Chris Szalwinski
// 2019/09/20 - Cornel
// 2020/01/23 - Cornel
// 2020/09/30 - Chris Szalwinski
// 2021/01/14 - Chris

#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include "SetSummable.h"
#include "PairSummable.h"
#include "SetSummable.h"
#include "PairSummable.h"


int main(int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc != 3) {
		std::cerr << "ERROR: Insufficient number of arguments.\n";
		return 2;
	}

	// Process the first file
	// The values in this file will be interpreted as strings
	//     Sumation means string concatenation.
	{
		sdds::SetSummable<15, sdds::PairSummable<std::string, std::string>> products;

		// get the data from the file
		{
			std::ifstream input(argv[1]);
			if (!input)
			{
				std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
				return 3;
			}
			do
			{
				char label[64], value[64];
				input >> label >> value;
				if (input)
				{
					sdds::PairSummable<std::string, std::string> record(label, value);
					products += record;
				}
			} while (input);
			input.close();
		}

		std::cout << "Individual Index Entries\n"
		          << "--------------------------\n";
		for (size_t i = 0; i < products.size(); ++i)
			std::cout << products.get(i);
		std::cout << std::endl;

		std::cout << "Collated Index Entries\n"
		          << "--------------------------\n";
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "      Tools: " << products.accumulate("Tools").value() << std::endl;
		std::cout << "  Groceries: " << products.accumulate("Groceries").value() << std::endl;
		std::cout << " Electrnics: " << products.accumulate("Electrnics").value() << std::endl;
		std::cout << "Electronics: " << products.accumulate("Electronics").value() << std::endl;
		std::cout << std::endl;
	}

	// Process the second file
	// The values in this file will be interpreted as numbers
	//     Sumation means mathematical addition of numbers.
	{
		sdds::SetSummable<25, sdds::PairSummable<int, std::string>> ticketSales;

		// get the data from the file
		{
			std::ifstream input(argv[2]);
			if (!input)
			{
				std::cerr << "ERROR: Cannot open file [" << argv[2] << "].\n";
				return 4;
			}
			do
			{
				char ticketType[64];
				int number;
				input >> ticketType >> number;
				if (input)
				{
					sdds::PairSummable<int, std::string> record(ticketType, number);
					ticketSales += record;
				}
			} while (input);
			input.close();
		}

		std::cout << "Detail Ticket Sales\n"
		          << "--------------------------\n";
		for (size_t i = 0; i < ticketSales.size(); ++i)
			std::cout << ticketSales.get(i);
		std::cout << std::endl;

		double studentFare = 2.06;
		double adultFare = 3.33;
		double seniorFare = 2.5;

		std::cout << "Summary of Ticket Sales\n"
		          << "--------------------------\n";
		std::cout << std::fixed << std::setprecision(2) << std::right;
		std::cout << "Student Tickets  = " << std::setw(7) << ticketSales.accumulate("Student").value() * studentFare << std::endl;
		std::cout << "  Adult Tickets  = " << std::setw(7) << ticketSales.accumulate("Adult").value() * adultFare << std::endl;
		std::cout << " Senior Tickets  = " << std::setw(7) << ticketSales.accumulate("Senior").value() * seniorFare << std::endl;
	}

	// done
	return 0;
}


/* EXPECTED OUTPUT:
Command Line:
--------------------------
  1: ./a.out
  2: products.txt
  3: sales.txt
--------------------------

Individual Index Entries
--------------------------
Groceries   : tomatoes
Electronics : computer
Tools       : hammer
Groceries   : lettuce
Groceries   : potatoes
Electronics : Multimedia_Player
Electronics : HDD
Groceries   : meat
Tools       : jigsaw

Collated Index Entries
--------------------------
	  Tools: hammer, jigsaw
  Groceries: tomatoes, lettuce, potatoes, meat
 Electrnics:
Electronics: computer, Multimedia_Player, HDD

Detail Ticket Sales
--------------------------
Student : 25
Adult   : 13
Student : 12
Adult   : 6
Student : 5
Adult   : 14
Adult   : 1
Adult   : 2
Adult   : 3
Student : 1
Student : 2
Adult   : 5
Adult   : 6

Summary of Ticket Sales
--------------------------
Student Tickets  =   92.70
  Adult Tickets  =  166.50
 Senior Tickets  =    0.00

*/