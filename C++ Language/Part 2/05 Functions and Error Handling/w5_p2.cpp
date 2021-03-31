/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/21/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Collection<sdds::Book> library("Bestsellers");
	if (argc == 5) {
		// TODO: load the first 4 books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the collection "library" (use the += operator)
		//       - lines that start with "#" are considered comments and should be ignored
		//       - if the file cannot be open, print a message to standard error console and
		//                exit from application with error code "AppErrors::CannotOpenFile"

		ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			exit(AppErrors::CannotOpenFile);
		}

		string strBook{};
		size_t cnt = 0;
		do
		{
			getline(file, strBook); //the default delimiter is the endline character

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strBook[0] != '#')
				{
					library += Book(strBook);
					cnt++;
				}
			}

		} while (file && cnt < 4);
		



		/*
		 Hey, I just met you,      
		 And this is crazy,        
		 But here's my number.         (register the observer)
		 So, if something happens,     (event)
		 Call me, maybe?               (callback)
		 */
		library.setObserver(bookAddedObserver);

		// TODO: add the rest of the books from the file.
		do
		{
			getline(file, strBook); //the default delimiter is the endline character

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strBook[0] != '#')
				{
					library += Book(strBook);
				}
			}

		} while (file);

		file.close();
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: (from part #1) create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto updatePrice = [=](Book& book)
	{
		if (book.country() == "US")
		{
			book.price() = book.price() * usdToCadRate;
		}
		else if (book.country() == "UK" && 1990 <= book.year() && book.year() <= 1999)
		{
			book.price() = book.price() * gbpToCadRate;
		}
	};



	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// TODO (from part #1): iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (int i = 0; i < 7; i++)
	{
		updatePrice(library[i]);
	}


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	if (argc > 2) {
		// TODO: load 5 movies from the file "argv[2]".
		//       - read one line at a time, and pass it to the Movie constructor
		//       - store each movie read into the array "movies"
		//       - lines that start with "#" are considered comments and should be ignored
		ifstream file(argv[2]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[2] << "].\n";
		}

		string strMovie{};
		size_t idx = 0;
		do
		{
			getline(file, strMovie); //the default delimiter is the endline character

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strMovie[0] != '#')
				{
					movies[idx++] = Movie(strMovie);
				}
			}

		} while (file);
		file.close();

	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	if (argc > 2) {
		// Add a few movies to collection; no observer is set
		((theCollection += movies[0]) += movies[1]) += movies[2];
		theCollection += movies[1];
		// add more movies; now we get a callback from the collection
		theCollection.setObserver(movieAddedObserver);
		theCollection += movies[3];
		theCollection += movies[3];
		theCollection += movies[4];
	}
	else {
		std::cout << "** No movies in the Collection\n";
	}
	std::cout << "-----------------------------------------\n\n";
	
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";


		// TODO: The following loop can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//** EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.

	try
	{
		for (auto i = 0u; i < 10; ++i)
			std::cout << theCollection[i];
	}
	catch (const std::out_of_range& oor)
	{
		std::cerr << "** EXCEPTION: " << oor.what() << endl;
	}
		

	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3; i < argc; ++i)
	{
			// TODO: The following statement can generate generate an exception
			//         write code to handle the exception
			//       If an exception occurs print a message in the following format
			//** EXCEPTION: ERROR_MESSAGE<endl>
			//         where ERROR_MESSAGE is extracted from the exception object.
		try
		{
			SpellChecker sp(argv[i]);
			for (auto j = 0u; j < library.size(); ++j)
				library[j].fixSpelling(sp);
			sp.showStatistics(std::cout);

			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);
			sp.showStatistics(std::cout);
		}
		catch (const std::out_of_range& oor)
		{
			std::cerr << "** EXCEPTION: " << oor.what() << endl;
		}
		catch (const char* msg)
		{
			std::cerr << "** EXCEPTION: " << msg << endl;
		}
			
	}
	if (argc < 3) {
		std::cout << "** Spellchecker is empty\n";
		std::cout << "-----------------------------------------\n";
	}
	std::cout << "\n";

	std::cout << "=========================================\n";
	std::cout << "Wrapping up this workshop\n";
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "** Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In this collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n\n";

	return 0;
}


/* EXPECTED OUTPUT:
Command Line:
--------------------------
  1: ./a.out
  2: books.txt
  3: movies.txt
  4: missing_file.txt
  5: words.txt
--------------------------

Book "Harry Potter" added!
Book "The Da Vinci Code" added!
Book "The Catcher in teh Rye" added!
-----------------------------------------
The library content
-----------------------------------------
 Miguel de Cervantes |            Don Quixote | Spain | 1612 |   9.99 | The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.
	 Charles Dickens |   A Tale of Two Cities |    UK | 1859 |  12.32 | A historical novel, set in London and Paris at teh begiming and during the French Revolution.
  George R.R. Martin | A Song of Ice and Fire |    US | 1997 |  99.90 | Nine noble famillies begim fighting for control over teh mythical lands of Westeros.
	  J.R.R. Tolkien |  The Lord of the Rings |    UK | 1993 |  21.11 | Sauron has gathered to him all teh Rings of Power, and he intends to use them to rule Middle-earth.
		J.K. Rowling |           Harry Potter |    UK | 1997 |  45.99 | Harry realizes his life is far from ordinary.
		   Dan Brown |      The Da Vinci Code |    US | 2003 |   7.88 | While in Paris, Harvard symbologist Robert Langdon is awakened by a phone call in teh night.
	   J.D. Salinger | The Catcher in teh Rye |    US | 1951 |  12.21 | The story of a teen named Holden Caulfield and his struggle to find his voice in an adult world.
-----------------------------------------

-----------------------------------------
The library content (updated prices)
-----------------------------------------
 Miguel de Cervantes |            Don Quixote | Spain | 1612 |   9.99 | The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.
	 Charles Dickens |   A Tale of Two Cities |    UK | 1859 |  12.32 | A historical novel, set in London and Paris at teh begiming and during the French Revolution.
  George R.R. Martin | A Song of Ice and Fire |    US | 1997 | 129.87 | Nine noble famillies begim fighting for control over teh mythical lands of Westeros.
	  J.R.R. Tolkien |  The Lord of the Rings |    UK | 1993 |  31.66 | Sauron has gathered to him all teh Rings of Power, and he intends to use them to rule Middle-earth.
		J.K. Rowling |           Harry Potter |    UK | 1997 |  68.98 | Harry realizes his life is far from ordinary.
		   Dan Brown |      The Da Vinci Code |    US | 2003 |  10.24 | While in Paris, Harvard symbologist Robert Langdon is awakened by a phone call in teh night.
	   J.D. Salinger | The Catcher in teh Rye |    US | 1951 |  15.87 | The story of a teen named Holden Caulfield and his struggle to find his voice in an adult world.
-----------------------------------------

-----------------------------------------
Testing addition and callback function
-----------------------------------------
Movie "Star Wars: The Rise of Skywalker" added to collection "Action Movies" (4 items).
Movie "Terminator: Dork Fate" added to collection "Action Movies" (5 items).
-----------------------------------------

-----------------------------------------
Testing exceptions and operator[]
-----------------------------------------
						 Game of Thrones | 2011 | Nine noble famillies begim fighting for control over teh mythical lands of Westeros.
					   Avengers: Endgame | 2019 | With the help of remaining allies, teh Avengers assemble once more in order to reverse Thanos' actions.
							Dork Phoenix | 2019 | Jean Grey begims to develop incredible Dork powers that corrupt and turn her into a Dork Phoenix.
		Star Wars: The Rise of Skywalker | 2019 | The surviving Resistance faces the First Order once more in the final chapter of the Skywalker saga.
				   Terminator: Dork Fate | 2019 | Sarah Connor and a hibrid cyborg human must protect a young girl from a newly modiffied liquid Terminator.
** EXCEPTION: Bad index [5]. Collection has [5] items.
-----------------------------------------

-----------------------------------------
Testing the functor
-----------------------------------------
** EXCEPTION: Bad file name!
Spellchecker Statistics
			teh: 4 replacements
	  modiffied: 0 replacements
		  begim: 2 replacements
	  famillies: 1 replacements
		   Dork: 0 replacements
		 hibrid: 0 replacements
Spellchecker Statistics
			teh: 6 replacements
	  modiffied: 1 replacements
		  begim: 4 replacements
	  famillies: 2 replacements
		   Dork: 4 replacements
		 hibrid: 1 replacements

=========================================
Wrapping up this workshop
--------------- Movies ------------------
						 Game of Thrones | 2011 | Nine noble families begin fighting for control over the mythical lands of Westeros.
					   Avengers: Endgame | 2019 | With the help of remaining allies, the Avengers assemble once more in order to reverse Thanos' actions.
							Dark Phoenix | 2019 | Jean Grey begins to develop incredible Dark powers that corrupt and turn her into a Dark Phoenix.
		Star Wars: The Rise of Skywalker | 2019 | The surviving Resistance faces the First Order once more in the final chapter of the Skywalker saga.
				   Terminator: Dark Fate | 2019 | Sarah Connor and a hybrid cyborg human must protect a young girl from a newly modified liquid Terminator.
--------------- Books -------------------
 Miguel de Cervantes |            Don Quixote | Spain | 1612 |   9.99 | The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.
	 Charles Dickens |   A Tale of Two Cities |    UK | 1859 |  12.32 | A historical novel, set in London and Paris at the begining and during the French Revolution.
  George R.R. Martin | A Song of Ice and Fire |    US | 1997 | 129.87 | Nine noble families begin fighting for control over the mythical lands of Westeros.
	  J.R.R. Tolkien |  The Lord of the Rings |    UK | 1993 |  31.66 | Sauron has gathered to him all the Rings of Power, and he intends to use them to rule Middle-earth.
		J.K. Rowling |           Harry Potter |    UK | 1997 |  68.98 | Harry realizes his life is far from ordinary.
		   Dan Brown |      The Da Vinci Code |    US | 2003 |  10.24 | While in Paris, Harvard symbologist Robert Langdon is awakened by a phone call in the night.
	   J.D. Salinger | The Catcher in teh Rye |    US | 1951 |  15.87 | The story of a teen named Holden Caulfield and his struggle to find his voice in an adult world.
-----------------------------------------
Testing operator[] (the other overload)
-----------------------------------------
** Movie Terminator 2 not in collection.
In this collection:
							Dark Phoenix | 2019 | Jean Grey begins to develop incredible Dark powers that corrupt and turn her into a Dark Phoenix.
-----------------------------------------

*/