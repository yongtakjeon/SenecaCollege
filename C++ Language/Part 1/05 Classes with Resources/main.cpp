// Workshop 6: Classes with Resources
// Version: 2.1
// Date: 02/28/2020
// Author: Nargis Khan
// Update: 10.05.2020 by Cornel
// Description:
// This file tests lab section of your workshop
/////////////////////////////////////////////

#include<iostream>
#include<cstring>
#include"Basket.h"
#include"Basket.h" //intentional

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
	sdds::Fruit fruits[]{
		{"apple",  0.65},
		{"banana", 1.25},
		{"pear",   0.50},
		{"mango",  0.75},
		{"plum",   2.00},
	};

	{
		printHeader("T1: Default Constructor");

		Basket aBasket;
		cout << aBasket;

		// conversion to bool operator
		if (aBasket)
			cout << "Test failed: the basket should be empty!\n";
		else
			cout << "Test succeeded: operator said the basket is empty!\n";

		cout << endl;
	}

	{
		printHeader("T2: Custom Constructor");

		Basket aBasket(fruits, 2, 6.99);
		cout << aBasket;

		// conversion to bool operator
		if (aBasket)
			cout << "Test succeeded: operator said the basket has content!\n";
		else
			cout << "Test failed: the basket should NOT be empty!\n";

		cout << endl;
	}

	{
		printHeader("T3: += operator");

		Basket aBasket;
		aBasket += fruits[2];
		(aBasket += fruits[0]) += fruits[4];
		aBasket.setPrice(12.234);

		cout << aBasket;
		cout << endl;
	}
	
	{
		printHeader("T4: Copy Constructor");

		Basket b1;
		Basket b2(b1);

		cout << "Basket #1 -> " << b1;
		cout << "Basket #2 -> " << b2;

		b1 += fruits[3];
		b1.setPrice(3.50);

		Basket b3(b1);
		cout << "Basket #3 -> " << b3;
		cout << endl;
	}

	{
		printHeader("T5: Copy Assignment");

		Basket b1, b2, b3(fruits, 5, 19.95);

		b1 = b2;
		cout << "Basket #1 -> " << b1;
		cout << "Basket #2 -> " << b2;

		b1 = b3;
		cout << "Basket #1 -> " << b1;

		b3 = b2;
		cout << "Basket #3 -> " << b3;
	}

	return 0;
}


/* EXPECTED OUTPUT:

----------------------------------------
|> T1: Default Constructor
----------------------------------------
The basket is empty!
Test succeeded: operator said the basket is empty!

----------------------------------------
|> T2: Custom Constructor
----------------------------------------
Basket Content:
	 apple: 0.65kg
	banana: 1.25kg
Price: 6.99
Test succeeded: operator said the basket has content!

----------------------------------------
|> T3: += operator
----------------------------------------
Basket Content:
	  pear: 0.50kg
	 apple: 0.65kg
	  plum: 2.00kg
Price: 12.23

----------------------------------------
|> T4: Copy Constructor
----------------------------------------
Basket #1 -> The basket is empty!
Basket #2 -> The basket is empty!
Basket #3 -> Basket Content:
	 mango: 0.75kg
Price: 3.50

----------------------------------------
|> T5: Copy Assignment
----------------------------------------
Basket #1 -> The basket is empty!
Basket #2 -> The basket is empty!
Basket #1 -> Basket Content:
	 apple: 0.65kg
	banana: 1.25kg
	  pear: 0.50kg
	 mango: 0.75kg
	  plum: 2.00kg
Price: 19.95
Basket #3 -> The basket is empty!

*/