/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Jan/23/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

size_t g_sysClock;

using namespace std;

namespace sdds
{
	Event::Event()
	{
		eventDesc = nullptr;
	}
	Event::Event(const Event& copy)
	{
		if (copy.eventDesc == nullptr || copy.eventDesc[0] == '\0')
		{
			eventDesc = nullptr;
			setEventEmpty();
		}
		else
		{
			eventDesc = nullptr;
			eventDesc = new char[strlen(copy.eventDesc) + 1];
			strcpy(eventDesc, copy.eventDesc);

			startSec = copy.startSec;
		}
	}
	Event::~Event()
	{
		delete[] eventDesc;
	}
	Event& Event::operator=(const Event& copy)
	{
		if (this != &copy)
		{
			if (copy.eventDesc == nullptr || copy.eventDesc[0] == '\0')
			{
				setEventEmpty();
			}
			else
			{
				if (eventDesc)
				{
					setEventEmpty();
				}

				eventDesc = new char[strlen(copy.eventDesc) + 1];
				strcpy(eventDesc, copy.eventDesc);

				startSec = copy.startSec;
			}
		}

		return *this;
	}
	void Event::setEventEmpty()
	{
		delete[] eventDesc;
		eventDesc = nullptr;
	}
	void Event::display()
	{
		static int noOfCall = 0;
		++noOfCall;

		int h = startSec / 3600;
		int m = (startSec - (3600 * h)) / 60;
		int s = (startSec - (3600 * h) - (60 * m));

		if (eventDesc == nullptr || eventDesc[0] == '\0')
		{
			cout << right << setw(2) << noOfCall << ". "
				<< "| No Event |" << endl;
		}
		else
		{
			cout << right << setw(2) << noOfCall << ". "
				<< setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << setfill(' ') << " => " << eventDesc << endl;
		}
	}
	void Event::set(const char* desc)
	{
		if (desc != nullptr && desc[0] != '\0')
		{
			if (eventDesc)
			{
				setEventEmpty();
			}

			eventDesc = new char[strlen(desc) + 1];
			strcpy(eventDesc, desc);

			startSec = g_sysClock;
		}
		else
		{
			setEventEmpty();
		}
	}
}
