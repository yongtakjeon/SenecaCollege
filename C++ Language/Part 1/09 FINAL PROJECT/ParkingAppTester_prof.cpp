#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Parking.h"
using namespace std;
using namespace sdds;
void runParking() {
   Parking P("ParkingData.csv", 11);
   P.run();
}
void pause() {
   cout << "<------------------------" << endl << "Press Enter to continue...";
   cin.ignore(1000, '\n');
}
void ShowDatafile() {
   char ch;
   ifstream file("ParkingData.csv");
   cout << endl << "Content of ParkingData.csv after the program exits" << endl;
   cout << "-----------------------------------------------------------" << endl;
   while (file.get(ch)) {
      cout <<char(tolower(ch));
   }
   cout <<  "-----------------------------------------------------------" << endl;
}
int main() {
   cout << "Pass 1: ------->" << endl;
   runParking();
   ShowDatafile();
   pause();
   cout << "Pass 2: ------->" << endl;
   runParking();
   ShowDatafile();
   pause();
   cout << "Pass 3: ------->" << endl;
   runParking();
   ShowDatafile();
   return 0;
}


/* EXPECTED OUTPUT:

Data Entries are in RED
Pass 1: ------->
****** Seneca Valet Parking ******
***** Available spots: 2 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 3
*** List of parked vehicles ***
Vehicle type: Car
Parking Spot Number: 1
Licence Plate: ASD123
Make and Model: Honda Civic
Without Carwash

-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 2
Licence Plate: AS12
Make and Model: Honda 125
With Sidecar
-------------------------------
Vehicle type: Car
Parking Spot Number: 3
Licence Plate: QWE123
Make and Model: BMW 320
With Carwash

-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 4
Licence Plate: ZXC123
Make and Model: Suzuki 750
-------------------------------
Vehicle type: Car
Parking Spot Number: 5
Licence Plate: ASDASD
Make and Model: Ford F150
Without Carwash

-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 6
Licence Plate: ZXC
Make and Model: Ninja 650
-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 7
Licence Plate: QWE
Make and Model: Ninja H2
-------------------------------
Vehicle type: Car
Parking Spot Number: 8
Licence Plate: GVAA123
Make and Model: Tesla Model 3
With Carwash

-------------------------------
Vehicle type: Car
Parking Spot Number: 9
Licence Plate: QWEASD
Make and Model: Cadilac XT5
Without Carwash

-------------------------------
****** Seneca Valet Parking ******
***** Available spots: 2 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 1

Car information entry
Enter Licence Plate Number: <ENTER>
Invalid Licence Plate, try again: 123456789
Invalid Licence Plate, try again: aaaa1234
Enter Make and Model: a
Invalid Make and model, try again: ab
Carwash while parked? (Y)es/(N)o: yes
Invalid response, only (Y)es or (N)o are acceptable, retry: n

Parking Ticket
Vehicle type: Car
Parking Spot Number: 10
Licence Plate: AAAA1234
Make and Model: ab
Without Carwash


****** Seneca Valet Parking ******
***** Available spots: 1 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 2

Motorcycle information entry
Enter Licence Plate Number: aaa
Enter Make and Model: bbb bbb
Does the Motorcycle have a side car? (Y)es/(N)o: NO
Invalid response, only (Y)es or (N)o are acceptable, retry: n

Parking Ticket
Vehicle type: Motorcycle
Parking Spot Number: 11
Licence Plate: AAA
Make and Model: bbb bbb

****** Seneca Valet Parking ******
***** Available spots: 0 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
Parking is full
****** Seneca Valet Parking ******
***** Available spots: 0 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 3
*** List of parked vehicles ***
Vehicle type: Car
Parking Spot Number: 1
Licence Plate: ASD123
Make and Model: Honda Civic
Without Carwash

-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 2
Licence Plate: AS12
Make and Model: Honda 125
With Sidecar
-------------------------------
Vehicle type: Car
Parking Spot Number: 3
Licence Plate: QWE123
Make and Model: BMW 320
With Carwash

-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 4
Licence Plate: ZXC123
Make and Model: Suzuki 750
-------------------------------
Vehicle type: Car
Parking Spot Number: 5
Licence Plate: ASDASD
Make and Model: Ford F150
Without Carwash

-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 6
Licence Plate: ZXC
Make and Model: Ninja 650
-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 7
Licence Plate: QWE
Make and Model: Ninja H2
-------------------------------
Vehicle type: Car
Parking Spot Number: 8
Licence Plate: GVAA123
Make and Model: Tesla Model 3
With Carwash

-------------------------------
Vehicle type: Car
Parking Spot Number: 9
Licence Plate: QWEASD
Make and Model: Cadilac XT5
Without Carwash

-------------------------------
Vehicle type: Car
Parking Spot Number: 10
Licence Plate: AAAA1234
Make and Model: ab
Without Carwash

-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 11
Licence Plate: AAA
Make and Model: bbb bbb
-------------------------------
****** Seneca Valet Parking ******
***** Available spots: 0 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 5
This will terminate the program!
Are you sure? (Y)es/(N)o: Y
Exiting program!







Content of ParkingData.csv after the program exits
-----------------------------------------------------------
c,1,asd123,honda civic,0
m,2,as12,honda 125,1
c,3,qwe123,bmw 320,1
m,4,zxc123,suzuki 750,0
c,5,asdasd,ford f150,0
m,6,zxc,ninja 650,0
m,7,qwe,ninja h2,0
c,8,gvaa123,tesla model 3,1
c,9,qweasd,cadilac xt5,0
c,10,aaaa1234,ab,0
m,11,aaa,bbb bbb,0
-----------------------------------------------------------
<------------------------
Press Enter to continue...<ENTER>
Pass 2: ------->
****** Seneca Valet Parking ******
***** Available spots: 0 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
Parking is full
****** Seneca Valet Parking ******
***** Available spots: 0 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 4
This will Remove and tow all remaining vehicles from the parking!
Are you sure? (Y)es/(N)o: n
Aborted!
****** Seneca Valet Parking ******
***** Available spots: 0 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 2
Return Vehicle
Enter Licence Plate Number: aaa

Returning:
Vehicle type: Motorcycle
Parking Spot Number: 11
Licence Plate: AAA
Make and Model: bbb bbb

****** Seneca Valet Parking ******
***** Available spots: 1 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 2
Return Vehicle
Enter Licence Plate Number: asd123

Returning:
Vehicle type: Car
Parking Spot Number: 1
Licence Plate: ASD123
Make and Model: Honda Civic
Without Carwash


****** Seneca Valet Parking ******
***** Available spots: 2 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 3
*** List of parked vehicles ***
Vehicle type: Motorcycle
Parking Spot Number: 2
Licence Plate: AS12
Make and Model: Honda 125
With Sidecar
-------------------------------
Vehicle type: Car
Parking Spot Number: 3
Licence Plate: QWE123
Make and Model: BMW 320
With Carwash

-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 4
Licence Plate: ZXC123
Make and Model: Suzuki 750
-------------------------------
Vehicle type: Car
Parking Spot Number: 5
Licence Plate: ASDASD
Make and Model: Ford F150
Without Carwash

-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 6
Licence Plate: ZXC
Make and Model: Ninja 650
-------------------------------
Vehicle type: Motorcycle
Parking Spot Number: 7
Licence Plate: QWE
Make and Model: Ninja H2
-------------------------------
Vehicle type: Car
Parking Spot Number: 8
Licence Plate: GVAA123
Make and Model: Tesla Model 3
With Carwash

-------------------------------
Vehicle type: Car
Parking Spot Number: 9
Licence Plate: QWEASD
Make and Model: Cadilac XT5
Without Carwash

-------------------------------
Vehicle type: Car
Parking Spot Number: 10
Licence Plate: AAAA1234
Make and Model: ab
Without Carwash

-------------------------------
****** Seneca Valet Parking ******
***** Available spots: 2 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 3
Parking cancelled
****** Seneca Valet Parking ******
***** Available spots: 2 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 1

Car information entry
Enter Licence Plate Number: asd
Enter Make and Model: Ford
Carwash while parked? (Y)es/(N)o: n

Parking Ticket
Vehicle type: Car
Parking Spot Number: 1
Licence Plate: ASD
Make and Model: Ford
Without Carwash


****** Seneca Valet Parking ******
***** Available spots: 1 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 4
This will Remove and tow all remaining vehicles from the parking!
Are you sure? (Y)es/(N)o: y
Closing Parking

Towing request
*********************
Vehicle type: Car
Parking Spot Number: 1
Licence Plate: ASD
Make and Model: Ford
Without Carwash


Towing request
*********************
Vehicle type: Motorcycle
Parking Spot Number: 2
Licence Plate: AS12
Make and Model: Honda 125
With Sidecar

Towing request
*********************
Vehicle type: Car
Parking Spot Number: 3
Licence Plate: QWE123
Make and Model: BMW 320
With Carwash


Towing request
*********************
Vehicle type: Motorcycle
Parking Spot Number: 4
Licence Plate: ZXC123
Make and Model: Suzuki 750

Towing request
*********************
Vehicle type: Car
Parking Spot Number: 5
Licence Plate: ASDASD
Make and Model: Ford F150
Without Carwash


Towing request
*********************
Vehicle type: Motorcycle
Parking Spot Number: 6
Licence Plate: ZXC
Make and Model: Ninja 650

Towing request
*********************
Vehicle type: Motorcycle
Parking Spot Number: 7
Licence Plate: QWE
Make and Model: Ninja H2

Towing request
*********************
Vehicle type: Car
Parking Spot Number: 8
Licence Plate: GVAA123
Make and Model: Tesla Model 3
With Carwash


Towing request
*********************
Vehicle type: Car
Parking Spot Number: 9
Licence Plate: QWEASD
Make and Model: Cadilac XT5
Without Carwash


Towing request
*********************
Vehicle type: Car
Parking Spot Number: 10
Licence Plate: AAAA1234
Make and Model: ab
Without Carwash


Content of ParkingData.csv after the program exits
-----------------------------------------------------------
-----------------------------------------------------------
<------------------------
Press Enter to continue...<ENTER>
Pass 3: ------->
****** Seneca Valet Parking ******
***** Available spots: 11 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 1
    Select type of the vehicle:
    1- Car
    2- Motorcycle
    3- Cancel
    > 2

Motorcycle information entry
Enter Licence Plate Number: aaa
Enter Make and Model: bbb bbb
Does the Motorcycle have a side car? (Y)es/(N)o: y

Parking Ticket
Vehicle type: Motorcycle
Parking Spot Number: 1
Licence Plate: AAA
Make and Model: bbb bbb
With Sidecar

****** Seneca Valet Parking ******
***** Available spots: 10 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 3
*** List of parked vehicles ***
Vehicle type: Motorcycle
Parking Spot Number: 1
Licence Plate: AAA
Make and Model: bbb bbb
With Sidecar
-------------------------------
****** Seneca Valet Parking ******
***** Available spots: 10 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 5
This will terminate the program!
Are you sure? (Y)es/(N)o: y
Exiting program!

Content of ParkingData.csv after the program exits
-----------------------------------------------------------
m,1,aaa,bbb bbb,1
-----------------------------------------------------------

*/