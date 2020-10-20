// Workshop 5: Operator Overloading
// Version: 2.0
// Date: 2/2/2020
// Author: Elnaz Delpisheh
// Update: 10.05.2020 by Cornel
// Description:
// This file tests lab section of your workshp
/////////////////////////////////////////////



#include <iostream>
#include "Ship.h"
#include "Ship.h"
#include "Engine.h"
#include "Engine.h"

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

int main()
{
	{
		printHeader("T1: Testing Constants");

		cout << "TYPE_MAX_SIZE: " << sdds::TYPE_MAX_SIZE << endl;
		cout << "MIN_STD_POWER: " << sdds::MIN_STD_POWER << endl;
		cout << "MAX_STD_POWER: " << sdds::MAX_STD_POWER << endl;
		cout << endl;
	}

	{
		printHeader("T2: Testing Default Constructor");

		Ship invalid;
		invalid.display();
		invalid += Engine("D2", 2.1);
		cout << endl;
	}

	Engine engines[] = {
		Engine("V8", 4.4),
		Engine("V8", 5.0),
		Engine("Inline", 4.1),
		Engine("D3", 7.0),
		Engine("D0", 2.0),
		Engine("D1", 3.2),
	};

	{
		printHeader("T3: Testing Custom Constructor");
		
		Ship titanic("cruiser", engines, 6);
		titanic.display();
		cout << endl;
	}

	{
		printHeader("T4: Testing Conversion to Bool Operator");
		Ship invalid;
		Ship titanic("liner", engines, 1);

		if (invalid)
			cout << "1. Test Failed! Object should be invalid.\n";
		else
			cout << "1. Test succeeded!\n";

		if (titanic)
			cout << "2. Test succeeded!\n";
		else
			cout << "3. Test Failed! Object should be valid.\n";
		
		cout << endl;
	}

	{
		printHeader("T5: Testing += and < Operators");

		Ship titanic("liner", engines, 3);

		char type[]{ "D0" };
		while (titanic < sdds::MIN_STD_POWER)
		{
			type[1]++;
			cout << "Ship not up to standard. Required power: "
			     << sdds::MIN_STD_POWER << endl;
			titanic += Engine(type, 2.1);
		}

		titanic.display();

		if (sdds::MAX_STD_POWER < titanic)
			cout << "Too much power." << endl;
		else
			cout << "Ship doesn't exceed power regulation of: "
			     << sdds::MAX_STD_POWER << endl;
	}

	return 0;
}


/* EXPECTED OUTPUT:

----------------------------------------
|> T1: Testing Constants
----------------------------------------
TYPE_MAX_SIZE: 30
MIN_STD_POWER: 90.111
MAX_STD_POWER: 99.999

----------------------------------------
|> T2: Testing Default Constructor
----------------------------------------
No available data
The object is not valid! Engine cannot be added!

----------------------------------------
|> T3: Testing Custom Constructor
----------------------------------------
cruiser - 128.50
4.40 liters - V8
5.00 liters - V8
4.10 liters - Inline
7.00 liters - D3
2.00 liters - D0
3.20 liters - D1

----------------------------------------
|> T4: Testing Conversion to Bool Operator
----------------------------------------
1. Test succeeded!
2. Test succeeded!

----------------------------------------
|> T5: Testing += and < Operators
----------------------------------------
Ship not up to standard. Required power: 90.111
Ship not up to standard. Required power: 90.111
Ship not up to standard. Required power: 90.111
liner -  99.00
4.40 liters - V8
5.00 liters - V8
4.10 liters - Inline
2.10 liters - D1
2.10 liters - D2
2.10 liters - D3
Ship doesn't exceed power regulation of: 99.999

*/