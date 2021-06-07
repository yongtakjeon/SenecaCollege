/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Jan/23/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14

#include <iostream>
#include <fstream>
#include "event.h"
#include "event.h"

extern size_t g_sysClock;

/* input file format: a comma separated set of fields; some fields have a single parameter
T175,SComputer Starting,P,

codes
	T - time (parameter: a number representing the time--measured in seconds--when the following codes apply)
	S - start event (parameter: a string representing the description for the event that starts)
	E - end the event
	P - print to screen
	A - archive
*/

// TODO: write the prototype for the main function
//         to accept command line arguments
int main(int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	// TODO: print the command line here, in the format
	// 1: first argument
	// 2: second argument
	// 3: third argument
	for (int i = 0; i < argc; i++)
	{
		std::cout << i + 1 << ": " << argv[i] << std::endl;
	}

	std::cout << std::endl;


	// the archive can store maximum 10 events
	sdds::Event archive[10];
	// the index of the next available position in the archive
	size_t idxArchive = 0;

	sdds::Event currentEvent;

	const size_t secInDay = 60u * 60u * 24u;// day has 86400 seconds

	for (auto day = 1; day < argc; ++day)
	{
		// each parameter for an application contains the events from one day
		// process each one
		std::cout << "--------------------\n";
		std::cout << "    Day " << day << '\n';
		std::cout << "--------------------\n";
		std::ifstream in(argv[day]);
		char opcode = '\0';
		size_t time = secInDay + 1;
		in >> opcode >> time;

		// starting at midnight, until the end of the day
		for (::g_sysClock = 0u; ::g_sysClock < secInDay; ++::g_sysClock)
		{
			// what should happen this second
			while (time == ::g_sysClock)
			{
				// skip the delimiter
				in.ignore();
				// read the next opcode
				in >> opcode;

				// end of the file
				if (in.fail())
					break;

				// handle the operation code
				switch (opcode)
				{
				case 'T': // a new time code, this is the exit from while loop (back to for loop)
					in >> time;
					break;
				case 'S': // start a new event, the old event is automatically finished
					char buffer[1024];
					in.get(buffer, 1024, ',');
					currentEvent.set(buffer);
					break;
				case 'E': // end the current event
					currentEvent.set();
					break;
				case 'P': // print to scren the information about the current event
					currentEvent.display();
					break;
				case 'A': // add a copy of the current event to the archive
					sdds::Event copy(currentEvent);
					archive[idxArchive++] = copy;
					break;
				}
			}
		}
	}

	// print the archive
	std::cout << "--------------------\n";
	std::cout << "    Archive\n";
	std::cout << "--------------------\n";
	for (auto i = 0u; i < idxArchive; ++i)
		archive[i].display();
	std::cout << "--------------------\n";
}


/* EXPECTED OUTPUT:

Command Line:
1: ./a.out
2: monday.txt
3: tuesday.txt

--------------------
    Day 1
--------------------
 1. 00:02:55 => Computer Starting
 2. 00:02:55 => Computer Starting
 3. | No Event |
 4. 01:15:34 => User logging in
 5. 01:20:09 => User logging in
 6. 09:01:04 => Browser closed
 7. 17:33:33 => User checks email
--------------------
    Day 2
--------------------
 8. 01:02:23 => User starts working on homework
 9. | No Event |
10. 01:20:34 => User takes a break
11. 01:22:30 => User plays Sudoku
12. 01:26:40 => User resumes homework
--------------------
    Archive
--------------------
13. | No Event |
14. 01:20:00 => Authentication failed
15. 01:23:20 => Browser starts
16. 09:01:04 => Browser closed
17. 17:33:33 => User checks email
18. 01:02:23 => User starts working on homework
19. 01:22:30 => User plays Sudoku
20. | No Event |
21. 01:26:40 => User resumes homework
--------------------

*/