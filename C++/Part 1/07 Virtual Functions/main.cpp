// Workshop 8: Virtual Functions
// Date: 05.07.2020
// Author: Cornel
// Description:
// Tests the Employee and its derived classes via virtual functions
/////////////////////////////////////////////
#include <iostream>
#include "Doctor.h"
#include "Doctor.h"
#include "Engineer.h"
#include "Engineer.h"
#include "Employee.h"

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
    Employee* employees[]{
        new Doctor("Family doctor", 90, 30),
        new Doctor("Internal medicine", 150, 25, false),
        new Doctor("Neuro-surgeon", 325, 12, true),
        new Engineer(75, 12),
        new Engineer(60, 25)
    };

    {
        printHeader("T1: Checking display()");
        for (auto i = 0; i < 5; ++i)
            employees[i]->display();
        cout << endl;
    }

    {
        printHeader("T2: Doctor's weekly income");
        for (auto i = 0; i < 3; ++i)
        {
            cout << "Employee " << i + 1 << endl;
            cout << "  Under-time: " << employees[i]->getSalary(10) << endl;
            cout << "   Over-time: " << employees[i]->getSalary(40) << endl;
        }
        cout << endl;
    }

    {
        printHeader("T2: Engineer's weekly income");
        for (auto i = 3; i < 5; ++i)
        {
            cout << "Employee " << i + 1 << endl;
            cout << "     Under-time: " << employees[i]->getSalary(10) << endl;
            cout << "  Overtime-time: " << employees[i]->getSalary(40) << endl;
        }
        cout << endl;
    }

   // Cleaning up the memory
   for (auto i = 0; i < 5; ++i)
      delete employees[i];
   return 0;
}



/* EXPECTED OUTPUT:

----------------------------------------
|> T1: Checking display()
----------------------------------------
Doctor
          Type: Family doctor
      Pay Rate: 90
     Min Hours: 30
Doctor
          Type: Internal medicine
      Pay Rate: 150
     Min Hours: 25
Doctor
          Type: Neuro-surgeon (specialist)
      Pay Rate: 325
     Min Hours: 12
Engineer
             Level: 12
          Pay Rate: 75
         Min Hours: 30
Engineer
             Level: 25
          Pay Rate: 60
         Min Hours: 30

----------------------------------------
|> T2: Doctor's weekly income
----------------------------------------
Employee 1
  Under-time: 900
   Over-time: 4050
Employee 2
  Under-time: 1500
   Over-time: 7125
Employee 3
  Under-time: 5250
   Over-time: 19550

----------------------------------------
|> T2: Engineer's weekly income
----------------------------------------
Employee 4
     Under-time: 984
  Overtime-time: 3480
Employee 5
     Under-time: 1280
  Overtime-time: 3400

*/