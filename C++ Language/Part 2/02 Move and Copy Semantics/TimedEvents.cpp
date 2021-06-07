/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Jan/30/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/



#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{
	TimedEvents::TimedEvents()
	{

	}
	// start timer
	//
	void TimedEvents::startClock()
	{
		startTime = std::chrono::steady_clock::now();
	}

	// stop timer
	//
	void TimedEvents::stopClock()
	{
		endTime = std::chrono::steady_clock::now();
	}

	// record an event
	//
	void TimedEvents::addEvent(const char* eventName)
	{
		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
		if (noOfEvents < MAX_EVENTS)
		{
			this->events[noOfEvents].eventName = eventName;
			this->events[noOfEvents].timeUnits = "nanoseconds";
			this->events[noOfEvents].duration = ms;
			noOfEvents++;
		}
	}

	// report the set of times recorded
	// 
	std::ostream& operator<<(std::ostream& out, const TimedEvents& events)
	{
		out << "--------------------------\n";
		out << "Execution Times:\n";
		out << "--------------------------\n";
		for (int i = 0; i < events.noOfEvents; i++)
		{
			out << std::setw(21) << std::left
				<< events.events[i].eventName << ' ' << std::setw(13) << std::right
				<< events.events[i].duration.count() << ' '
				<< events.events[i].timeUnits << '\n';
		}
		out << "--------------------------\n";
		return out;
	}
}