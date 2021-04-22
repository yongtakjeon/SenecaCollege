// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Element.h"
#include "List.h"
#include "Utilities.h"

const int FWC = 5;
const int FWD = 12;
const int FWP = 8;

using namespace sdds;
using namespace std;

size_t Product::idGenerator = 0;
bool Product::Trace = true;

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	if (argc != 4) {
		cerr << endl << "***Incorrect number of arguments***" << endl;
		return 1;
	}

	try {
		sdds::List<sdds::Description> desc(argv[1]);
		sdds::List<sdds::Price> priceBad(argv[2]);
		sdds::List<sdds::Price> priceGood(argv[3]);

		cout << setw(FWC) << "Code" << setw(FWD) << "Description" << endl;
		cout << desc << endl;

		cout << "********************************************" << endl
			<< "* Good Prices" << endl
			<< "********************************************" << endl;
		cout << setw(FWC) << "Code" << setw(FWP) << "Price" << endl;
		cout << priceGood << endl;

		cout << "********************************************" << endl
			<< "* Bad Prices" << endl
			<< "********************************************" << endl;
		cout << setw(FWC) << "Code" << setw(FWP) << "Price" << endl;
		cout << priceBad << endl;

		Product::Trace = true;
		cout << "********************************************" << endl
			<< "* Merging bad prices using Raw Pointers" << endl
			<< "********************************************" << endl;
		try {
			List<Product> priceList = mergeRaw(desc, priceBad);
		}
		catch (const string& msg) {
			cout << "ERROR: " << msg << std::endl;
			cout << "NOTE: An exception occurred while creating the list of products!" << endl
				<< "      You should notice that not all objects are deleted." << endl;
		}

		cout << endl;
		cout << "********************************************" << endl
			<< "* Merging bad prices using Smart Pointers" << endl
			<< "********************************************" << endl;
		try {
			List<Product> priceList = mergeSmart(desc, priceBad);
		}
		catch (const string& msg) {
			cout << "ERROR: " << msg << std::endl;
			cout << "NOTE: An exception occurred while creating the list of products!" << endl
				<< "      You should notice that ALL objects are deleted." << endl;
		}

		Product::Trace = false;
		cout << endl << endl;
		// no exceptions should be generated from the code below.
		cout << "********************************************" << endl
			<< "* Merging good prices using Raw Pointers" << endl
			<< "********************************************" << endl;
		{
			List<Product> priceList = mergeRaw(desc, priceGood);
			cout << setw(FWD) << "Description" << setw(FWP) << "Price" << endl;
			cout << priceList << endl;
		}

		cout << "********************************************" << endl
			<< "* Merging good prices using Smart Pointers" << endl
			<< "********************************************" << endl;
		{
			List<Product> priceList = mergeSmart(desc, priceGood);
			cout << setw(FWD) << "Description" << setw(FWP) << "Price" << endl;
			cout << priceList << endl;
		}
	}
	catch (...) {
		cout << "ERROR: Unknown error!";
	}
}

/* EXPECTED OUTPUT:
Command Line: ./a.out Descriptions.dat BadPrices.dat Prices.dat

 Code Description
 4662    tomatoes
 4039   cucumbers
 4056     brocoli
 4067      lemons
 4068     oranges

********************************************
* Good Prices
********************************************
 Code   Price
 4067    0.99
 4068    0.67
 4039    1.99
 4056    2.49

********************************************
* Bad Prices
********************************************
 Code   Price
 4067    0.99
 4068    0.67
 4039    1.99
 4056   -2.49

********************************************
* Merging bad prices using Raw Pointers
********************************************
	 C [1]
	CC [2] from [1]
	~D [1]
	 C [3]
	~D [2]
ERROR: *** Negative prices are invalid ***
NOTE: An exception occurred while creating the list of products!
	  You should notice that not all objects are deleted.

********************************************
* Merging bad prices using Smart Pointers
********************************************
	 C [4]
	CC [5] from [4]
	~D [4]
	 C [6]
	~D [6]
	~D [5]
ERROR: *** Negative prices are invalid ***
NOTE: An exception occurred while creating the list of products!
	  You should notice that ALL objects are deleted.


********************************************
* Merging good prices using Raw Pointers
********************************************
 Description   Price
   cucumbers    1.99
	 brocoli    2.49
	  lemons    0.99
	 oranges    0.67

********************************************
* Merging good prices using Smart Pointers
********************************************
 Description   Price
   cucumbers    1.99
	 brocoli    2.49
	  lemons    0.99
	 oranges    0.67

*/