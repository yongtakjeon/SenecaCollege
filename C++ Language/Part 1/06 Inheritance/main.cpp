// Workshop 7: Inheritance
// Version: 1.0
// Date: 29.06.2020
// Author: Cornel
/////////////////////////////////////////////

#include<iostream>
#include "Truck.h"
#include "Truck.h" // intentional
#include "MotorVehicle.h"
#include "MotorVehicle.h" // intentional

using namespace std;
using namespace sdds;

void printHeader(const char* title)
{
	char oldFill = cout.fill('-');
	cout.width(40);
	cout << "" << endl;

	cout << "|> " << title << endl;

	cout.fill('-');
	cout.width(40);
	cout << "" << endl;
	cout.fill(oldFill);
}

void moveAndLoad(Truck& aTruck, const char* destination, double cargo)
{
	//cout << aTruck << endl;
	aTruck.moveTo(destination);
	if (aTruck.addCargo(cargo))
		cout << "Cargo loaded!\n";
	else
		cout << "Adding cargo failed!\n";
	cout << aTruck << endl << endl;
}

void moveAndUnload(Truck& aTruck, const char* destination)
{
	//cout << aTruck << endl;
	aTruck.moveTo(destination);
	if (aTruck.unloadCargo())
		cout << "Cargo unloaded!\n";
	else
		cout << "Unloading cargo failed!\n";
	cout << aTruck << endl << endl;
}

int main()
{
	{
		printHeader("T1: Vehicle");

		MotorVehicle aVehicle("VVV-111", 2010);
		cout << aVehicle << endl << endl;

		aVehicle.moveTo("Downtown Toronto");
		aVehicle.moveTo("Mississauga");
		aVehicle.moveTo("North York");

		cout << endl << aVehicle << endl << endl;

		printHeader("T2: Read/Write");
		cin >> aVehicle;
		cout << endl << aVehicle << endl << endl;
	}

	{
		printHeader("T3: Truck");

		Truck aTruck("T-1111", 2015, 5432, "Toronto HQ");
		cout << endl;

		moveAndLoad(aTruck, "Toronto Deposit", 2345);

		moveAndLoad(aTruck, "Montreal", 3456);

		moveAndLoad(aTruck, "New York", 4567);

		moveAndUnload(aTruck, "New Jersey");

		moveAndUnload(aTruck, "Toronto");


		printHeader("T4: Read/Write");
		cin >> aTruck;
		cout << endl << (MotorVehicle)aTruck;
		cout << endl << aTruck << endl << endl;
	}
}

/* EXPECTED OUTPUT:

----------------------------------------
|> T1: Vehicle
----------------------------------------
| 2010 | VVV-111 | Factory

|   VVV-111| |             Factory --->--- Downtown Toronto    |
|   VVV-111| |    Downtown Toronto --->--- Mississauga         |
|   VVV-111| |         Mississauga --->--- North York          |

| 2010 | VVV-111 | North York

----------------------------------------
|> T2: Read/Write
----------------------------------------
Built year: 2010
License plate: aaa-111
Current location: toronto

| 2010 | aaa-111 | toronto

----------------------------------------
|> T3: Truck
----------------------------------------
|    T-1111| |             Factory --->--- Toronto HQ          |

|    T-1111| |          Toronto HQ --->--- Toronto Deposit     |
Cargo loaded!
| 2015 | T-1111 | Toronto Deposit | 2345/5432

|    T-1111| |     Toronto Deposit --->--- Montreal            |
Cargo loaded!
| 2015 | T-1111 | Montreal | 5432/5432

|    T-1111| |            Montreal --->--- New York            |
Adding cargo failed!
| 2015 | T-1111 | New York | 5432/5432

|    T-1111| |            New York --->--- New Jersey          |
Cargo unloaded!
| 2015 | T-1111 | New Jersey | 0/5432

|    T-1111| |          New Jersey --->--- Toronto             |
Unloading cargo failed!
| 2015 | T-1111 | Toronto | 0/5432

----------------------------------------
|> T4: Read/Write
----------------------------------------
Built year: 2015
License plate: bbb-222
Current location: montreal
Capacity: 2345
Cargo: 1234

| 2015 | bbb-222 | montreal
| 2015 | bbb-222 | montreal | 1234/2345

*/