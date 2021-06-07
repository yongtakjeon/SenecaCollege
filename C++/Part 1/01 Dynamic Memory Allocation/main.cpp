#include <iostream>
#include "Gift.h"
#include "Gift.h" // intentional
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

int main() {

	Gift g1; // Unwrapped Gift

	{
		printHeader("T1: Checking Constants");

		cout << "MAX_DESC: " << sdds::MAX_DESC << endl;
		cout << "MAX_PRICE: " << sdds::MAX_PRICE << endl;
		cout << "MAX_WRAP: " << sdds::MAX_WRAP << endl;
		cout << endl;
	}

	{
		printHeader("T2: Display Wrapped Gift");

		gifting(g1.m_description);
		gifting(g1.m_price);
		gifting(g1.m_units);
		cout << endl;

		g1.m_wrap = nullptr;
		g1.m_wrapLayers = 0;
		display(g1);
		cout << endl;
	}

	{
		printHeader("T3: Wrap a gift");

		if (wrap(g1))
			cout << "Test succeeded!";
		else
			cout << "Test failed: wrapping didn't happen!" << endl;
		cout << endl << endl;
	}

	{
		printHeader("T4: Re-wrap a gift");
		
		cout << "Attempting to rewrap the previous Gift: "
		     << g1.m_description << endl;

		if (wrap(g1) == false)
			cout << "Test succeeded!";
		else
			cout << "Test failed: gift it's already wrapped, cannot wrap again!";
		cout << endl << endl;
	}

	{
		printHeader("T5: Unwrap a gift");

		cout << "Attempting to unwrap the previous gift: "
		     << g1.m_description << endl;
		if (unwrap(g1))
			cout << "Test succeeded!";
		else
			cout << "Test failed: you should be able to unwrap!";
		cout << endl << endl;
	}


	{
		printHeader("T6: Unwrap again");

		cout << "Attempting to un-unwrap the previous gift: "
		     << g1.m_description << endl;

		if (!unwrap(g1))
			cout << "Test succeeded!";
		else
			cout << "Test failed: you should not be able to unwrap again!";
		cout << endl << endl;
	}

	Gift g2; // Unwrapped Gift
	{
		printHeader("T7: Prepare another gift");
		g2.m_wrap = nullptr;
		g2.m_wrapLayers = 0;
		gifting(g2);
		
		cout << endl;
		display(g2);
		cout << endl;
	}

	{
		printHeader("T8: Unwrap the second gift");

		unwrap(g2);
	}

	return 0;
}

/*  SAMPLE OUTPUT:

----------------------------------------
|> T1: Checking Constants
----------------------------------------
MAX_DESC: 15
MAX_PRICE: 999.999
MAX_WRAP: 20

----------------------------------------
|> T2: Display Wrapped Gift
----------------------------------------
Enter gift description: Roses
Enter gift price: 5.99
Enter gift units: 5

Gift Details:
 Description: Roses
	   Price: 5.99
	   Units: 5
Unwrapped!

----------------------------------------
|> T3: Wrap a gift
----------------------------------------
Wrapping gifts...
Enter the number of wrapping layers for the Gift: -1
Layers at minimum must be 1, try again.
Enter the number of wrapping layers for the Gift: 0
Layers at minimum must be 1, try again.
Enter the number of wrapping layers for the Gift: 3
Enter wrapping pattern #1: Spots
Enter wrapping pattern #2: Stripes
Enter wrapping pattern #3: Zigzags
Test succeeded!

----------------------------------------
|> T4: Re-wrap a gift
----------------------------------------
Attempting to rewrap the previous Gift: Roses
Gift is already wrapped!
Test succeeded!

----------------------------------------
|> T5: Unwrap a gift
----------------------------------------
Attempting to unwrap the previous gift: Roses
Gift being unwrapped.
Test succeeded!

----------------------------------------
|> T6: Unwrap again
----------------------------------------
Attempting to un-unwrap the previous gift: Roses
Gift isn't wrapped! Cannot unwrap.
Test succeeded!

----------------------------------------
|> T7: Prepare another gift
----------------------------------------
Preparing a gift...
Enter gift description: Hand-knit-scarf
Enter gift price: 0
Enter gift units: 1
Wrapping gifts...
Enter the number of wrapping layers for the Gift: 1
Enter wrapping pattern #1: Hearts

Gift Details:
 Description: Hand-knit-scarf
	   Price: 0
	   Units: 1
Wrap Layers: 1
Wrap #1 -> Hearts

----------------------------------------
|> T8: Unwrap the second gift
----------------------------------------
Gift being unwrapped.

*/