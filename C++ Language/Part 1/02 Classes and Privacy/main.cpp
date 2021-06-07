#include <iostream>
#include "Cargo.h"
#include "Cargo.h" // intentional
#include "Train.h"
#include "Train.h" // intentional
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
		printHeader("T1: Checking Constants");

		cout << "MAX_NAME: " << sdds::MAX_NAME << endl;
		cout << "MAX_DESC: " << sdds::MAX_DESC << endl;
		cout << "MAX_WEIGHT: " << sdds::MAX_WEIGHT << endl;
		cout << "MIN_WEIGHT: " << sdds::MIN_WEIGHT << endl;
		cout << endl;
	}

	sdds::Cargo c1;
	sdds::Train t1;

	{
		printHeader("T2: Valid Train");

		c1.initialize("Boxes", -5000);
		t1.initialize("Birthday Train", 1);

		t1.display();
		cout << endl;

		t1.loadCargo(c1);
		t1.display();
		cout << endl;
	}

	{
		printHeader("T3: Increase Weight");

		if (t1.increaseCargo(50))
			cout << "t1 cargo was correctly increased" << endl;
		if (t1.increaseCargo(999))
			cout << "t1 cargo was correctly increased to " << sdds::MAX_WEIGHT << endl;
		if (!t1.increaseCargo(999))
			cout << "t1 cargo was correctly not increased" << endl;
		cout << endl;
		t1.display();
		cout << endl;
	}

	Train t2;
	Cargo c2;

	{
		printHeader("T4: Decrease Weight");

		t2.initialize("Choo Choo Train", 2);
		c2.initialize("Flowers", 5000);

		if (!t2.decreaseCargo(25))
			cout << "t2 doesn't have cargo was correctly not touched\n" << endl;

		t2.display();
		cout << endl;

		t2.loadCargo(c1);
		t2.display();
		cout << endl;

		t2.loadCargo(c2);
		t2.display();
		cout << endl;

		if (!t2.decreaseCargo(25))
			cout << "t2's cargo correctly not decreased below "
			     << sdds::MIN_WEIGHT << endl << endl;
		t2.display();
		cout << endl;

		t2.increaseCargo(50);
		t2.display();
		cout << endl;

		if (t2.decreaseCargo(10))
			cout << "t2 decreased weight correctly\n" << endl;
		t2.display();
		cout << endl;
	}

	{
		printHeader("T5: Swap cargo");

		t1.swapCargo(t2);
		t1.display();
		cout << endl;

		t2.display();
		cout << endl;
	}

	{
		printHeader("T6: Unload Cargo");

		t1.unloadCargo();
		t2.unloadCargo();
		t1.display();
		cout << endl;
		t2.display();
		cout << endl;

		if (!t1.swapCargo(t2))
			cout << "correctly did not attempt to swap train without cargo\n" << endl;
	}

	return 0;
}

/* EXPECTED OUTPUT:

----------------------------------------
|> T1: Checking Constants
----------------------------------------
MAX_NAME: 30
MAX_DESC: 20
MAX_WEIGHT: 777.555
MIN_WEIGHT: 44.2222

----------------------------------------
|> T2: Valid Train
----------------------------------------
***Train Summary***
	Name: Birthday Train
	  ID: 1
No cargo on this train.

***Train Summary***
	Name: Birthday Train
	  ID: 1
   Cargo: Boxes
  Weight: 44.22

----------------------------------------
|> T3: Increase Weight
----------------------------------------
t1 cargo was correctly increased
t1 cargo was correctly increased to 777.555
t1 cargo was correctly not increased

***Train Summary***
	Name: Birthday Train
	  ID: 1
   Cargo: Boxes
  Weight: 777.55

----------------------------------------
|> T4: Decrease Weight
----------------------------------------
t2 doesn't have cargo was correctly not touched

***Train Summary***
	Name: Choo Choo Train
	  ID: 2
No cargo on this train.

***Train Summary***
	Name: Choo Choo Train
	  ID: 2
   Cargo: Boxes
  Weight: 44.22

***Train Summary***
	Name: Choo Choo Train
	  ID: 2
   Cargo: Flowers
  Weight: 44.22

t2's cargo correctly not decreased below 44.2222

***Train Summary***
	Name: Choo Choo Train
	  ID: 2
   Cargo: Flowers
  Weight: 44.22

***Train Summary***
	Name: Choo Choo Train
	  ID: 2
   Cargo: Flowers
  Weight: 94.22

t2 decreased weight correctly

***Train Summary***
	Name: Choo Choo Train
	  ID: 2
   Cargo: Flowers
  Weight: 84.22

----------------------------------------
|> T5: Swap cargo
----------------------------------------
***Train Summary***
	Name: Birthday Train
	  ID: 1
   Cargo: Flowers
  Weight: 84.22

***Train Summary***
	Name: Choo Choo Train
	  ID: 2
   Cargo: Boxes
  Weight: 777.55

----------------------------------------
|> T6: Unload Cargo
----------------------------------------
***Train Summary***
	Name: Birthday Train
	  ID: 1
No cargo on this train.

***Train Summary***
	Name: Choo Choo Train
	  ID: 2
No cargo on this train.

correctly did not attempt to swap train without cargo

*/