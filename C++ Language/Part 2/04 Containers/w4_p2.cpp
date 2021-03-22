// Workshop 4 - Containers
// 2020/01/28 - Cornel
// 2021/01/19 - Chris
// 2021/02/05 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Restaurant.h"
#include "Restaurant.h"
#include "ConfirmationSender.h"
#include "ConfirmationSender.h"
#include "Reservation.h"
#include "Reservation.h"


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n";

	const sdds::Reservation** ppReservations = nullptr;
	size_t cnt = 0;

	// Process the file
	if (argc > 1) {
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}

		std::string strReservation;
		// count how many records are in the file
		do
		{
			std::getline(file, strReservation);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strReservation[0] != '#')
					++cnt;
			}
		} while (file);

		ppReservations = new const sdds::Reservation*[cnt];
		cnt = 0;

		// read again from the file, but this time load and store data
		file.clear();
		file.seekg(std::ios::beg);
		do
		{
			std::getline(file, strReservation);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strReservation[0] != '#')
				{
					ppReservations[cnt] = new const sdds::Reservation(strReservation);
					++cnt;
				}
			}
		} while (file);
		file.close();
	}
	std::cout << "\nReservations\n--------------------------\n";
	for (auto i = 0u; i < cnt; ++i)
	{
		std::cout << *ppReservations[i];
	}
	std::cout << "--------------------------\n\n";

	{
		std::cout << "R: Testing Constructor\n";
		std::cout << "==========================\n";
		sdds::Restaurant res1(ppReservations, cnt);
		std::cout << res1;  // 1
		std::cout << "==========================\n\n";

		std::cout << "R: Testing Copy Constructor\n";
		std::cout << "==========================\n";
		sdds::Restaurant res2(res1);
		std::cout << res1;  // 2
		std::cout << res2;  // 3
		std::cout << "==========================\n\n";

		{
			std::cout << "R: Testing Copy Assign\n";
			std::cout << "==========================\n";
			res2 = res2;
			std::cout << res1;  // 4
			std::cout << res2;  // 5
			sdds::Restaurant res3(ppReservations + 3, 4);
			res2 = res3;
			std::cout << res2;  // 6
			std::cout << res3;  // 7
			std::cout << "==========================\n\n";
		}

		std::cout << "R: Testing Move Constructor\n";
		std::cout << "==========================\n";
		sdds::Restaurant res3(std::move(res2));
		std::cout << res2;  // 8
		std::cout << res3;  // 9
		std::cout << "==========================\n\n";

		std::cout << "R: Testing Move Assign\n";
		std::cout << "==========================\n";
		res3 = std::move(res3);
		std::cout << res2;  // 10
		std::cout << res3;  // 11
		res2 = std::move(res3);
		std::cout << res2;  // 12
		std::cout << res3;  // 13
		std::cout << "==========================\n\n";
	}


	// Confirmation Sender
	{
		std::cout << "CS: Testing Constructor\n";
		std::cout << "==========================\n";
		sdds::ConfirmationSender sender1;
		std::cout << sender1;
		std::cout << "==========================\n\n";

		std::cout << "CS: Testing Operators\n";
		std::cout << "==========================\n";
		sender1 += *ppReservations[5];
		sender1 += *ppReservations[16];
		sender1 += *ppReservations[16];
		sender1 += *ppReservations[8];
		sender1 += *ppReservations[10];
		sender1 += *ppReservations[9];
		std::cout << sender1;
		sender1 -= *ppReservations[8];
		sender1 -= *ppReservations[9];
		sender1 -= *ppReservations[7];
		std::cout << sender1;
		std::cout << "==========================\n\n";

		std::cout << "CS: Testing Copy Constructor\n";
		std::cout << "==========================\n";
		sdds::ConfirmationSender sender2(sender1);
		std::cout << sender1;
		std::cout << sender2;
		std::cout << "==========================\n\n";

		sender2 = sender2;

		std::cout << "CS: Testing Move Constructor\n";
		std::cout << "==========================\n";
		sdds::ConfirmationSender sender3(std::move(sender1));
		std::cout << sender1;
		std::cout << sender3;
		std::cout << "==========================\n\n";

		sender3 = std::move(sender3);
	}
	// cleanup
	for (auto i = 0u; i < cnt; ++i)
		delete ppReservations[i];
	delete[] ppReservations;

	return 0;
}


/*EXPECTED OUTPUT:
Command Line:
--------------------------
  1: ./a.out
  2: data.txt
--------------------------

Reservations
--------------------------
Reservation       1234:                 John  <john@email.com>        Drinks on day 3 @ 5:00 for 2 people.
Reservation ab defghij:                David  <david@email.com>       Breakfast on day 4 @ 6:00 for 1 person.
Reservation    RES-003:                 Sara  <sara@email.com>        Breakfast on day 5 @ 7:00 for 2 people.
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
Reservation    RES-008:                 Mike  <mike@email.com>        Lunch on day 5 @ 12:00 for 8 people.
Reservation    RES-009:                  Dan  <dan@email.com>         Lunch on day 3 @ 13:00 for 2 people.
Reservation    RES-010:                Donna  <donna@email.com>       Lunch on day 5 @ 14:00 for 5 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
Reservation    RES-012:             Jon Snow  <john@email.com>        Drinks on day 5 @ 16:00 for 2 people.
Reservation    RES-013:                 Sara  <sara@email.com>        Dinner on day 3 @ 17:00 for 6 people.
Reservation    RES-014:             Jennifer  <jenn@email.com>        Dinner on day 5 @ 18:00 for 6 people.
Reservation    RES-015:                 Stan  <stan@email.com>        Dinner on day 4 @ 19:00 for 5 people.
Reservation    RES-016:                Chris  <chris@email.com>       Dinner on day 4 @ 20:00 for 3 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-018:                David  <david@email.com>       Drinks on day 5 @ 22:00 for 4 people.
Reservation    RES-019:                Chris  <chris@email.com>       Drinks on day 3 @ 23:00 for 1 person.
Reservation    RES-020:                Donna  <donna@email.com>       Drinks on day 4 @ 24:00 for 3 people.
--------------------------

R: Testing Constructor
==========================
--------------------------
Fancy Restaurant (1)
--------------------------
Reservation       1234:                 John  <john@email.com>        Drinks on day 3 @ 5:00 for 2 people.
Reservation ab defghij:                David  <david@email.com>       Breakfast on day 4 @ 6:00 for 1 person.
Reservation    RES-003:                 Sara  <sara@email.com>        Breakfast on day 5 @ 7:00 for 2 people.
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
Reservation    RES-008:                 Mike  <mike@email.com>        Lunch on day 5 @ 12:00 for 8 people.
Reservation    RES-009:                  Dan  <dan@email.com>         Lunch on day 3 @ 13:00 for 2 people.
Reservation    RES-010:                Donna  <donna@email.com>       Lunch on day 5 @ 14:00 for 5 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
Reservation    RES-012:             Jon Snow  <john@email.com>        Drinks on day 5 @ 16:00 for 2 people.
Reservation    RES-013:                 Sara  <sara@email.com>        Dinner on day 3 @ 17:00 for 6 people.
Reservation    RES-014:             Jennifer  <jenn@email.com>        Dinner on day 5 @ 18:00 for 6 people.
Reservation    RES-015:                 Stan  <stan@email.com>        Dinner on day 4 @ 19:00 for 5 people.
Reservation    RES-016:                Chris  <chris@email.com>       Dinner on day 4 @ 20:00 for 3 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-018:                David  <david@email.com>       Drinks on day 5 @ 22:00 for 4 people.
Reservation    RES-019:                Chris  <chris@email.com>       Drinks on day 3 @ 23:00 for 1 person.
Reservation    RES-020:                Donna  <donna@email.com>       Drinks on day 4 @ 24:00 for 3 people.
--------------------------
==========================

R: Testing Copy Constructor
==========================
--------------------------
Fancy Restaurant (2)
--------------------------
Reservation       1234:                 John  <john@email.com>        Drinks on day 3 @ 5:00 for 2 people.
Reservation ab defghij:                David  <david@email.com>       Breakfast on day 4 @ 6:00 for 1 person.
Reservation    RES-003:                 Sara  <sara@email.com>        Breakfast on day 5 @ 7:00 for 2 people.
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
Reservation    RES-008:                 Mike  <mike@email.com>        Lunch on day 5 @ 12:00 for 8 people.
Reservation    RES-009:                  Dan  <dan@email.com>         Lunch on day 3 @ 13:00 for 2 people.
Reservation    RES-010:                Donna  <donna@email.com>       Lunch on day 5 @ 14:00 for 5 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
Reservation    RES-012:             Jon Snow  <john@email.com>        Drinks on day 5 @ 16:00 for 2 people.
Reservation    RES-013:                 Sara  <sara@email.com>        Dinner on day 3 @ 17:00 for 6 people.
Reservation    RES-014:             Jennifer  <jenn@email.com>        Dinner on day 5 @ 18:00 for 6 people.
Reservation    RES-015:                 Stan  <stan@email.com>        Dinner on day 4 @ 19:00 for 5 people.
Reservation    RES-016:                Chris  <chris@email.com>       Dinner on day 4 @ 20:00 for 3 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-018:                David  <david@email.com>       Drinks on day 5 @ 22:00 for 4 people.
Reservation    RES-019:                Chris  <chris@email.com>       Drinks on day 3 @ 23:00 for 1 person.
Reservation    RES-020:                Donna  <donna@email.com>       Drinks on day 4 @ 24:00 for 3 people.
--------------------------
--------------------------
Fancy Restaurant (3)
--------------------------
Reservation       1234:                 John  <john@email.com>        Drinks on day 3 @ 5:00 for 2 people.
Reservation ab defghij:                David  <david@email.com>       Breakfast on day 4 @ 6:00 for 1 person.
Reservation    RES-003:                 Sara  <sara@email.com>        Breakfast on day 5 @ 7:00 for 2 people.
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
Reservation    RES-008:                 Mike  <mike@email.com>        Lunch on day 5 @ 12:00 for 8 people.
Reservation    RES-009:                  Dan  <dan@email.com>         Lunch on day 3 @ 13:00 for 2 people.
Reservation    RES-010:                Donna  <donna@email.com>       Lunch on day 5 @ 14:00 for 5 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
Reservation    RES-012:             Jon Snow  <john@email.com>        Drinks on day 5 @ 16:00 for 2 people.
Reservation    RES-013:                 Sara  <sara@email.com>        Dinner on day 3 @ 17:00 for 6 people.
Reservation    RES-014:             Jennifer  <jenn@email.com>        Dinner on day 5 @ 18:00 for 6 people.
Reservation    RES-015:                 Stan  <stan@email.com>        Dinner on day 4 @ 19:00 for 5 people.
Reservation    RES-016:                Chris  <chris@email.com>       Dinner on day 4 @ 20:00 for 3 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-018:                David  <david@email.com>       Drinks on day 5 @ 22:00 for 4 people.
Reservation    RES-019:                Chris  <chris@email.com>       Drinks on day 3 @ 23:00 for 1 person.
Reservation    RES-020:                Donna  <donna@email.com>       Drinks on day 4 @ 24:00 for 3 people.
--------------------------
==========================

R: Testing Copy Assign
==========================
--------------------------
Fancy Restaurant (4)
--------------------------
Reservation       1234:                 John  <john@email.com>        Drinks on day 3 @ 5:00 for 2 people.
Reservation ab defghij:                David  <david@email.com>       Breakfast on day 4 @ 6:00 for 1 person.
Reservation    RES-003:                 Sara  <sara@email.com>        Breakfast on day 5 @ 7:00 for 2 people.
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
Reservation    RES-008:                 Mike  <mike@email.com>        Lunch on day 5 @ 12:00 for 8 people.
Reservation    RES-009:                  Dan  <dan@email.com>         Lunch on day 3 @ 13:00 for 2 people.
Reservation    RES-010:                Donna  <donna@email.com>       Lunch on day 5 @ 14:00 for 5 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
Reservation    RES-012:             Jon Snow  <john@email.com>        Drinks on day 5 @ 16:00 for 2 people.
Reservation    RES-013:                 Sara  <sara@email.com>        Dinner on day 3 @ 17:00 for 6 people.
Reservation    RES-014:             Jennifer  <jenn@email.com>        Dinner on day 5 @ 18:00 for 6 people.
Reservation    RES-015:                 Stan  <stan@email.com>        Dinner on day 4 @ 19:00 for 5 people.
Reservation    RES-016:                Chris  <chris@email.com>       Dinner on day 4 @ 20:00 for 3 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-018:                David  <david@email.com>       Drinks on day 5 @ 22:00 for 4 people.
Reservation    RES-019:                Chris  <chris@email.com>       Drinks on day 3 @ 23:00 for 1 person.
Reservation    RES-020:                Donna  <donna@email.com>       Drinks on day 4 @ 24:00 for 3 people.
--------------------------
--------------------------
Fancy Restaurant (5)
--------------------------
Reservation       1234:                 John  <john@email.com>        Drinks on day 3 @ 5:00 for 2 people.
Reservation ab defghij:                David  <david@email.com>       Breakfast on day 4 @ 6:00 for 1 person.
Reservation    RES-003:                 Sara  <sara@email.com>        Breakfast on day 5 @ 7:00 for 2 people.
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
Reservation    RES-008:                 Mike  <mike@email.com>        Lunch on day 5 @ 12:00 for 8 people.
Reservation    RES-009:                  Dan  <dan@email.com>         Lunch on day 3 @ 13:00 for 2 people.
Reservation    RES-010:                Donna  <donna@email.com>       Lunch on day 5 @ 14:00 for 5 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
Reservation    RES-012:             Jon Snow  <john@email.com>        Drinks on day 5 @ 16:00 for 2 people.
Reservation    RES-013:                 Sara  <sara@email.com>        Dinner on day 3 @ 17:00 for 6 people.
Reservation    RES-014:             Jennifer  <jenn@email.com>        Dinner on day 5 @ 18:00 for 6 people.
Reservation    RES-015:                 Stan  <stan@email.com>        Dinner on day 4 @ 19:00 for 5 people.
Reservation    RES-016:                Chris  <chris@email.com>       Dinner on day 4 @ 20:00 for 3 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-018:                David  <david@email.com>       Drinks on day 5 @ 22:00 for 4 people.
Reservation    RES-019:                Chris  <chris@email.com>       Drinks on day 3 @ 23:00 for 1 person.
Reservation    RES-020:                Donna  <donna@email.com>       Drinks on day 4 @ 24:00 for 3 people.
--------------------------
--------------------------
Fancy Restaurant (6)
--------------------------
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
--------------------------
--------------------------
Fancy Restaurant (7)
--------------------------
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
--------------------------
==========================

R: Testing Move Constructor
==========================
--------------------------
Fancy Restaurant (8)
--------------------------
This restaurant is empty!
--------------------------
--------------------------
Fancy Restaurant (9)
--------------------------
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
--------------------------
==========================

R: Testing Move Assign
==========================
--------------------------
Fancy Restaurant (10)
--------------------------
This restaurant is empty!
--------------------------
--------------------------
Fancy Restaurant (11)
--------------------------
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
--------------------------
--------------------------
Fancy Restaurant (12)
--------------------------
Reservation    RES-004:                  Ana  <ana@email.com>         Breakfast on day 5 @ 8:00 for 1 person.
Reservation    RES-005:                 John  <john@email.com>        Breakfast on day 4 @ 9:00 for 1 person.
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES 007:                 Mike  <mike@email.com>        Lunch on day 4 @ 11:00 for 4 people.
--------------------------
--------------------------
Fancy Restaurant (13)
--------------------------
This restaurant is empty!
--------------------------
==========================

CS: Testing Constructor
==========================
--------------------------
Confirmations to Send
--------------------------
There are no confirmations to send!
--------------------------
==========================

CS: Testing Operators
==========================
--------------------------
Confirmations to Send
--------------------------
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-009:                  Dan  <dan@email.com>         Lunch on day 3 @ 13:00 for 2 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
Reservation    RES-010:                Donna  <donna@email.com>       Lunch on day 5 @ 14:00 for 5 people.
--------------------------
--------------------------
Confirmations to Send
--------------------------
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
--------------------------
==========================

CS: Testing Copy Constructor
==========================
--------------------------
Confirmations to Send
--------------------------
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
--------------------------
--------------------------
Confirmations to Send
--------------------------
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
--------------------------
==========================

CS: Testing Move Constructor
==========================
--------------------------
Confirmations to Send
--------------------------
There are no confirmations to send!
--------------------------
--------------------------
Confirmations to Send
--------------------------
Reservation    RES-006:              Vanessa  <vanessa@email.com>     Drinks on day 3 @ 10:00 for 2 people.
Reservation    RES-017:              Vanessa  <vanessa@email.com>     Dinner on day 4 @ 21:00 for 4 people.
Reservation    RES-011:                  Ana  <ana@email.com>         Lunch on day 4 @ 15:00 for 4 people.
--------------------------
==========================

*/