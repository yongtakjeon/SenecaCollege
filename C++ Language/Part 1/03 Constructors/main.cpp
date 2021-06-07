// Workshop 4: Constructors 
// File: SaiyanMain.cpp
// Version: 1.1
// Date: 1/24/2020
// Author: Mohammad Shamas
// Description:
// This file tests lab section of your workshp
/////////////////////////////////////////////

#include <iostream>
#include "Saiyan.h"
#include "Saiyan.h"  // this is on purpose

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
        printHeader("T1: Checking default constructor");

        Saiyan theSayan;
        theSayan.display();
        cout << endl;
    }

    {
        printHeader("T2: Checking custom constructor");

        Saiyan army[] = {
          Saiyan("Nappa", 2025, 1),
          Saiyan("Vegeta", 2018, -1),
          Saiyan("Goku", 1990, 200),
          Saiyan(nullptr, 2015, 1),
          Saiyan("", 2018, 5)
        };

        cout << "Only #2 should be valid:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "  Sayan #" << i << ": " << (army[i].isValid() ? "valid" : "invalid") << endl;
        }
        for (int i = 0; i < 5; i++)
        {
            army[i].display();
        }
        cout << endl;
    }

    // valid saiyans
    Saiyan s1("Goku", 1990, 2000);
    Saiyan s2;
    s2.set("Vegeta", 1989, 2200);

    {
        printHeader("T3: Checking the fight");
        s1.display();
        s2.display();

        cout << "S1 attacking S2, Battle " << (s1.fight(s2) ? "Won" : "Lost") << endl;
        cout << "S2 attacking S1, Battle " << (s2.fight(s1) ? "Won" : "Lost") << endl;
        cout << endl;
    }

    {
        printHeader("T4: Checking powerup");
        s1.set("Goku", 1990, 1900, 1, true);
        int round = 0;
        bool gokuWins = false;
        while (!gokuWins) // with every fight, the super saiyan should power up
        {
            cout << "Round #" << ++round << endl;
            gokuWins = s1.fight(s2);
            s1.display();
            s2.display();
        }

        cout << "Bonus round. Is s2 winning? " << (s2.fight(s1) ? "yes" : "no") << endl;
        s1.display();
        s2.display();
        cout << endl;
    }

    {
        printHeader("T5: Upgrading s2");
        s2.set("Vegeta", 1990, 2200, 3, true);

        cout << "Super Battle. Is s2 winning? " << (s2.fight(s1) ? "yes" : "no") << endl;
        s1.display();
        s2.display();
        cout << endl;
    }
 
    return 0;
}


/* EXPECTED OUTPUT:

----------------------------------------
|> T1: Checking default constructor
----------------------------------------
Invalid Saiyan!

----------------------------------------
|> T2: Checking custom constructor
----------------------------------------
Only #2 should be valid:
  Sayan #0: invalid
  Sayan #1: invalid
  Sayan #2: valid
  Sayan #3: invalid
  Sayan #4: invalid
Invalid Saiyan!
Invalid Saiyan!
Goku
     DOB: 1990
   Power: 200
   Super: no
Invalid Saiyan!
Invalid Saiyan!

----------------------------------------
|> T3: Checking the fight
----------------------------------------
Goku
     DOB: 1990
   Power: 2000
   Super: no
Vegeta
     DOB: 1989
   Power: 2200
   Super: no
S1 attacking S2, Battle Lost
S2 attacking S1, Battle Won

----------------------------------------
|> T4: Checking powerup
----------------------------------------
Round #1
Goku
     DOB: 1990
   Power: 2090
   Super: yes
   Level: 1
Vegeta
     DOB: 1989
   Power: 2200
   Super: no
Round #2
Goku
     DOB: 1990
   Power: 2299
   Super: yes
   Level: 1
Vegeta
     DOB: 1989
   Power: 2200
   Super: no
Bonus round. Is s2 winning? no
Goku
     DOB: 1990
   Power: 2528
   Super: yes
   Level: 1
Vegeta
     DOB: 1989
   Power: 2200
   Super: no

----------------------------------------
|> T5: Upgrading s2
----------------------------------------
Super Battle. Is s2 winning? yes
Goku
     DOB: 1990
   Power: 2780
   Super: yes
   Level: 1
Vegeta
     DOB: 1990
   Power: 2860
   Super: yes
   Level: 3

*/