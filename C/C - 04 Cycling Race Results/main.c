#define _CRT_SECURE_NO_WARNINGS

#include "file_helper.h"
#include "riderHelpers.h"

int main(void)
{

	riderManagerSystem();

	return 0;
}

/*  SAMPLE OUTPUT:

******************** Cycling Race Results ********************
What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
3 – Print last 3 riders in a category
4 – Print winners in all categories
: 1

Which category (S, M, L): s

Rider                    Age Group Time
---------------------------------------
Angus Young                 Senior 1:50
Eddie Van Halen             Senior 2:35
Billy F. Gibbons            Senior 3:08

What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
3 – Print last 3 riders in a category
4 – Print winners in all categories
: 2

Which category (S, M, L): S

Rider                    Age Group Time Withdrew
------------------------------------------------
Angus Young                 Senior 1:50       No
Eddie Van Halen             Senior 2:35       No
Billy F. Gibbons            Senior 3:08       No
Nikki Sixx                  Senior 3:38       No
Charlie Watt                Senior 4:19       No
Jocelyn Lovell              Senior  N/A      Yes

What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
3 – Print last 3 riders in a category
4 – Print winners in all categories
: 3

Which category (S, M, L): S

Rider                    Age Group Time
---------------------------------------
Billy F. Gibbons            Senior 3:08
Nikki Sixx                  Senior 3:38
Charlie Watt                Senior 4:19

What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
3 – Print last 3 riders in a category
4 – Print winners in all categories
: 4

Rider                    Age Group Category Time
------------------------------------------------
Angus Young                 Senior    50 km 1:50
Eddy Mercx                  Senior    75 km 1:48
Cecilie Ledwig               Adult   100 km 1:38

What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
3 – Print last 3 riders in a category
4 – Print winners in all categories
: 0

Keep on Riding!
*/