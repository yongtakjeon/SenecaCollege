// Final Project
// Milestone 3
// ms3_prof.cpp
// Winter 2021
// Chris Szalwinski

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Station.h"
#include "Station.h"
#include "Workstation.h"
#include "Workstation.h"
#include "CustomerOrder.h"
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Utilities.h"
#include "LineManager.h"
#include "LineManager.h"

using namespace std;
using namespace sdds;

template<typename T>
static void loadFromFile(const char*, vector<T>&);
template<typename T>
static void loadFromFile(const char*, vector<T*>&);


int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;
	if (argc != 5) {
		cerr << "ERROR: Incorrect number of arguments\n";
		return 1;
	}

	vector<Workstation*> theStations;
	vector<CustomerOrder> theOrders;

	try {
		Utilities::setDelimiter(',');
		loadFromFile(argv[1], theStations);
		Utilities::setDelimiter('|');
		loadFromFile(argv[2], theStations);

		cout << "========================================" << endl;
		cout << "=         Stations (summary)           =" << endl;
		cout << "========================================" << endl;
		for (const auto* station : theStations)
			station->Station::display(cout, false);
		cout << endl << endl;

		cout << "========================================" << endl;
		cout << "=          Stations (full)             =" << endl;
		cout << "========================================" << endl;
		for (const auto* station : theStations)
			station->Station::display(cout, true);
		cout << endl << endl;

		//Select an object and verify all the functionality it working
		cout << "========================================" << endl;
		cout << "=          Manual Validation           =" << endl;
		cout << "========================================" << endl;
		cout << "getItemName(): " << theStations[0]->getItemName() << endl;
		cout << "getNextSerialNumber(): " << theStations[0]->getNextSerialNumber() << endl;
		cout << "getNextSerialNumber(): " << theStations[0]->getNextSerialNumber() << endl;
		cout << "getQuantity(): " << theStations[0]->getQuantity() << endl;
		theStations[0]->updateQuantity();
		cout << "getQuantity(): " << theStations[0]->getQuantity() << endl;
		cout << endl << endl;


		loadFromFile<CustomerOrder>(argv[3], theOrders);

		cout << "========================================" << endl;
		cout << "=                Orders                =" << endl;
		cout << "========================================" << endl;
		for (auto& order : theOrders) {
			order.display(std::cout);
			pending.push_back(std::move(order));
		}
		cout << endl << endl;

		cout << "========================================" << endl;
		cout << "=       Display Stations (loaded)      =" << endl;
		cout << "========================================" << endl;
		LineManager lm(argv[4], theStations);
		lm.display(cout);
		cout << endl << endl;

		cout << "========================================" << endl;
		cout << "=      Display Stations (ordered)      =" << endl;
		cout << "========================================" << endl;
		lm.linkStations();
		lm.display(cout);
		cout << endl << endl;

		cout << "========================================" << endl;
		cout << "=           Filling Orders             =" << endl;
		cout << "========================================" << endl;
		//run the assembly line until all orders processed
		while (!lm.run(cout));		
		cout << endl << endl;
	}
	catch (const string& msg) {
		cerr << msg << '\n';
		return 2;
	}

	cout << "========================================" << endl;
	cout << "=           Processed Orders           =" << endl;
	cout << "========================================" << endl;
	for (const auto& o : completed)
		o.display(cout);
	for (const auto& o : incomplete)
		o.display(cout);
	cout << endl << endl;

	cout << "========================================" << endl;
	cout << "=          Inventory (full)            =" << endl;
	cout << "========================================" << endl;
	for (const Station* theItem : theStations)
		theItem->display(cout, true);
	cout << endl;

	// cleanup
	for (auto station : theStations)
		delete station;

	return 0;
}

template<typename T>
static void loadFromFile(const char* filename, vector<T>& theCollection)
{
	if (!filename) {
		throw string("ERROR: No filename provided.");
	}
	ifstream file(filename);
	if (!file)
		throw string("Unable to open [") + filename + "] file.";

	string record;
	while (!file.eof())
	{
		std::getline(file, record);
		T elem(record);
		theCollection.push_back(std::move(elem));
	}

	file.close();
}

template<typename T>
static void loadFromFile(const char* filename, vector<T*>& theCollection)
{
	if (!filename) {
		throw string("ERROR: No filename provided.");
	}
	ifstream file(filename);
	if (!file)
		throw string("Unable to open [") + filename + "] file.";

	string record;
	while (!file.eof())
	{
		std::getline(file, record);
		theCollection.push_back(new T(record));
	}

	file.close();
}


/* EXPECTED OUTPUT:

Command Line: ./a.out Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt

========================================
=         Stations (summary)           =
========================================
[001] Item: CPU          [123456]
[002] Item: Memory       [654321]
[003] Item: GPU          [056789]
[004] Item: WiFi         [000887]
[005] Item: SSD          [987654]
[006] Item: Power Supply [147852]
[007] Item: Monitor      [000987]


========================================
=          Stations (full)             =
========================================
[001] Item: CPU          [123456] Quantity: 5            Description: Central Processing Unit
[002] Item: Memory       [654321] Quantity: 10           Description: Basic Flash Memory
[003] Item: GPU          [056789] Quantity: 7            Description: Graphic Processing Unit
[004] Item: WiFi         [000887] Quantity: 5            Description: Network Card with WiFi
[005] Item: SSD          [987654] Quantity: 5            Description: Solid State Drive
[006] Item: Power Supply [147852] Quantity: 20           Description: Basic AC Power Supply
[007] Item: Monitor      [000987] Quantity: 5            Description: Monitor size 32 inches, 4K


========================================
=          Manual Validation           =
========================================
getItemName(): CPU
getNextSerialNumber(): 123456
getNextSerialNumber(): 123457
getQuantity(): 5
getQuantity(): 4


========================================
=                Orders                =
========================================
Elliott C. - Gaming PC
[000000] CPU              - TO BE FILLED
[000000] Memory           - TO BE FILLED
[000000] GPU              - TO BE FILLED
[000000] GPU              - TO BE FILLED
[000000] GPU              - TO BE FILLED
[000000] SSD              - TO BE FILLED
[000000] Power Supply     - TO BE FILLED
[000000] Monitor          - TO BE FILLED
[000000] Monitor          - TO BE FILLED
Chris S. - Laptop
[000000] CPU              - TO BE FILLED
[000000] Memory           - TO BE FILLED
[000000] SSD              - TO BE FILLED
[000000] Power Supply     - TO BE FILLED
[000000] WiFi             - TO BE FILLED
Mary-Lynn M. - Desktop PC
[000000] CPU              - TO BE FILLED
[000000] Memory           - TO BE FILLED
[000000] Power Supply     - TO BE FILLED
[000000] WiFi             - TO BE FILLED
[000000] Monitor          - TO BE FILLED
Chris T. - Micro Controller
[000000] GPU              - TO BE FILLED
[000000] WiFi             - TO BE FILLED
[000000] GPU              - TO BE FILLED
[000000] Power Supply     - TO BE FILLED
[000000] SSD              - TO BE FILLED


========================================
=       Display Stations (loaded)      =
========================================
CPU --> GPU
Memory --> SSD
Power Supply --> CPU
GPU --> Memory
WiFi --> End of Line
SSD --> Monitor
Monitor --> WiFi


========================================
=      Display Stations (ordered)      =
========================================
Power Supply --> CPU
CPU --> GPU
GPU --> Memory
Memory --> SSD
SSD --> Monitor
Monitor --> WiFi
WiFi --> End of Line


========================================
=           Filling Orders             =
========================================
Line Manager Iteration: 1
	Filled Elliott C., Gaming PC [Power Supply]
Line Manager Iteration: 2
	Filled Chris S., Laptop [Power Supply]
	Filled Elliott C., Gaming PC [CPU]
Line Manager Iteration: 3
	Filled Mary-Lynn M., Desktop PC [Power Supply]
	Filled Chris S., Laptop [CPU]
	Filled Elliott C., Gaming PC [GPU]
	Filled Elliott C., Gaming PC [GPU]
	Filled Elliott C., Gaming PC [GPU]
Line Manager Iteration: 4
	Filled Chris T., Micro Controller [Power Supply]
	Filled Mary-Lynn M., Desktop PC [CPU]
	Filled Elliott C., Gaming PC [Memory]
Line Manager Iteration: 5
	Filled Chris S., Laptop [Memory]
	Filled Elliott C., Gaming PC [SSD]
Line Manager Iteration: 6
	Filled Chris T., Micro Controller [GPU]
	Filled Chris T., Micro Controller [GPU]
	Filled Mary-Lynn M., Desktop PC [Memory]
	Filled Chris S., Laptop [SSD]
	Filled Elliott C., Gaming PC [Monitor]
	Filled Elliott C., Gaming PC [Monitor]
Line Manager Iteration: 7
Line Manager Iteration: 8
	Filled Chris T., Micro Controller [SSD]
	Filled Mary-Lynn M., Desktop PC [Monitor]
	Filled Chris S., Laptop [WiFi]
Line Manager Iteration: 9
	Filled Mary-Lynn M., Desktop PC [WiFi]
Line Manager Iteration: 10
	Filled Chris T., Micro Controller [WiFi]


========================================
=           Processed Orders           =
========================================
Elliott C. - Gaming PC
[123458] CPU              - FILLED
[654321] Memory           - FILLED
[056789] GPU              - FILLED
[056790] GPU              - FILLED
[056791] GPU              - FILLED
[987654] SSD              - FILLED
[147852] Power Supply     - FILLED
[000987] Monitor          - FILLED
[000988] Monitor          - FILLED
Chris S. - Laptop
[123459] CPU              - FILLED
[654322] Memory           - FILLED
[987655] SSD              - FILLED
[147853] Power Supply     - FILLED
[000887] WiFi             - FILLED
Mary-Lynn M. - Desktop PC
[123460] CPU              - FILLED
[654323] Memory           - FILLED
[147854] Power Supply     - FILLED
[000888] WiFi             - FILLED
[000989] Monitor          - FILLED
Chris T. - Micro Controller
[056792] GPU              - FILLED
[000889] WiFi             - FILLED
[056793] GPU              - FILLED
[147855] Power Supply     - FILLED
[987656] SSD              - FILLED


========================================
=          Inventory (full)            =
========================================
[001] Item: CPU          [123461] Quantity: 1            Description: Central Processing Unit
[002] Item: Memory       [654324] Quantity: 7            Description: Basic Flash Memory
[003] Item: GPU          [056794] Quantity: 2            Description: Graphic Processing Unit
[004] Item: WiFi         [000890] Quantity: 2            Description: Network Card with WiFi
[005] Item: SSD          [987657] Quantity: 2            Description: Solid State Drive
[006] Item: Power Supply [147856] Quantity: 16           Description: Basic AC Power Supply
[007] Item: Monitor      [000990] Quantity: 2            Description: Monitor size 32 inches, 4K

*/