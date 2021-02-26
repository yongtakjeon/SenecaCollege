// Workshop 2 - Copy and Move Semantics
// w2.cpp
// 2019/01/10 - Chris Szalwinski
// 2019/09/13 - Cornel
// 2020/01/14 - Cornel
// 2021/01/14 - Chris

#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include "StringSet.h"
#include "StringSet.h" // intentional
#include "TimedEvents.h"
#include "TimedEvents.h" // intentional

using namespace sdds;


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc == 1)
	{
		std::cerr << "ERROR: Missing file name!\n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cerr << "ERROR: Too many arguments!\n";
		return 2;
	}

	sdds::TimedEvents t;
	{
		t.startClock();
		sdds::StringSet a;
		t.stopClock();
		t.addEvent("  0-arg Constructor");
		std::cout << "  0-arg Constructor - a.size = "
			<< std::setw(7) << a.size() << " strings -> ";
		std::cout << std::setw(20) << "(a) String     1: [" << a[  0] << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << a[ 99] << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << a[999] << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << a[a.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << a[a.size() + 0] << "]\n\n";


		t.startClock();
		StringSet b(argv[1]);
		t.stopClock();
		t.addEvent("  1-arg Constructor");
		std::cout << "  1-arg Constructor - b.size = "
			<< std::setw(7) << b.size() << " strings -> ";
		std::cout << std::setw(20) << "(b) String     1: [" << b[  0] << "]\n";
		std::cout << std::setw(70) << "(b) String   100: [" << b[ 99] << "]\n";
		std::cout << std::setw(70) << "(b) String  1000: [" << b[999] << "]\n";
		std::cout << std::setw(70) << "(b) String  last: [" << b[b.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(b) String last+: [" << b[b.size() + 1] << "]\n\n";


		t.startClock();
		StringSet c{ b };
		t.stopClock();
		t.addEvent("  Copy Constructor");
		std::cout << "  Copy Constructor  - c.size = "
			<< std::setw(7) << c.size() << " strings -> ";
		std::cout << std::setw(20) << "(c) String     1: [" << c[  0] << "]\n";
		std::cout << std::setw(70) << "(c) String   100: [" << c[ 99] << "]\n";
		std::cout << std::setw(70) << "(c) String  1000: [" << c[999] << "]\n";
		std::cout << std::setw(70) << "(c) String  last: [" << c[c.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(c) String last+: [" << c[c.size() + 2] << "]\n\n";


		t.startClock();
		a = b;
		t.stopClock();
		t.addEvent("  Copy Assignment");
		std::cout << "  Copy Assignment   - a.size = "
			<< std::setw(7) << a.size() << " strings -> ";
		std::cout << std::setw(20) << "(a) String     1: [" << a[  0] << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << a[ 99] << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << a[999] << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << a[a.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << a[a.size() + 3] << "]\n\n";


		a = a;


		t.startClock();
		StringSet d = std::move(a);
		t.stopClock();
		t.addEvent("  Move Constructor");
		std::cout << "  Move Constructor  - d.size = "
			<< std::setw(7) << d.size() << " strings -> ";
		std::cout << std::setw(20) << "(a) String     1: [" << a[  0] << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << a[ 99] << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << a[999] << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << a[a.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << a[a.size() + 4] << "]\n\n";
		std::cout << std::setw(70) << "(d) String     1: [" << d[  0] << "]\n";
		std::cout << std::setw(70) << "(d) String   100: [" << d[ 99] << "]\n";
		std::cout << std::setw(70) << "(d) String  1000: [" << d[999] << "]\n";
		std::cout << std::setw(70) << "(d) String  last: [" << d[d.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(d) String last+: [" << d[d.size() + 5] << "]\n\n";


		d = std::move(d);


		t.startClock();
		a = std::move(d);
		t.stopClock();
		t.addEvent("  Move Assignment");
		std::cout << "  Move Assignment   - a.size = "
			<< std::setw(7) << a.size() << " strings -> ";
		std::cout << std::setw(20) << "(a) String     1: [" << a[  0] << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << a[ 99] << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << a[999] << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << a[a.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << a[a.size() + 6] << "]\n\n";
		std::cout << std::setw(70) << "(d) String     1: [" << d[ 0] << "]\n";
		std::cout << std::setw(70) << "(d) String   100: [" << d[ 99] << "]\n";
		std::cout << std::setw(70) << "(d) String  1000: [" << d[999] << "]\n";
		std::cout << std::setw(70) << "(d) String  last: [" << d[d.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(d) String last+: [" << d[d.size() + 7] << "]\n";


		t.startClock();
	}
	t.stopClock();
	t.addEvent("  Destructor");

	std::cout << t;
}

/* EXPECTED OUTPUT:
Command Line:
--------------------------
  1: ./a.out
  2: gutenberg_shakespeare
--------------------------

  0-arg Constructor - a.size =       0 strings ->  (a) String     1: []
												   (a) String   100: []
												   (a) String  1000: []
												   (a) String  last: []
												   (a) String last+: []

  1-arg Constructor - b.size = 1293934 strings ->  (b) String     1: [This]
												   (b) String   100: [OR]
												   (b) String  1000: [provide]
												   (b) String  last: [Shakespeare]
												   (b) String last+: []

  Copy Constructor  - c.size = 1293934 strings ->  (c) String     1: [This]
												   (c) String   100: [OR]
												   (c) String  1000: [provide]
												   (c) String  last: [Shakespeare]
												   (c) String last+: []

  Copy Assignment   - a.size = 1293934 strings ->  (a) String     1: [This]
												   (a) String   100: [OR]
												   (a) String  1000: [provide]
												   (a) String  last: [Shakespeare]
												   (a) String last+: []

  Move Constructor  - d.size = 1293934 strings ->  (a) String     1: []
												   (a) String   100: []
												   (a) String  1000: []
												   (a) String  last: []
												   (a) String last+: []

												   (d) String     1: [This]
												   (d) String   100: [OR]
												   (d) String  1000: [provide]
												   (d) String  last: [Shakespeare]
												   (d) String last+: []

  Move Assignment   - a.size = 1293934 strings ->  (a) String     1: [This]
												   (a) String   100: [OR]
												   (a) String  1000: [provide]
												   (a) String  last: [Shakespeare]
												   (a) String last+: []

												   (d) String     1: []
												   (d) String   100: []
												   (d) String  1000: []
												   (d) String  last: []
												   (d) String last+: []
--------------------------
Execution Times:
--------------------------
  0-arg Constructor            1100 nanoseconds
  1-arg Constructor      2897519700 nanoseconds
  Copy Constructor       1013874700 nanoseconds
  Copy Assignment         991872400 nanoseconds
  Move Constructor              900 nanoseconds
  Move Assignment               900 nanoseconds
  Destructor             1610129100 nanoseconds
--------------------------

*/