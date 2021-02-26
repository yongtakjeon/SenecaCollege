/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Jan/30/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H


#include <iostream>
#include <chrono>
#include <string>

namespace sdds
{
	const int MAX_EVENTS = 10;

	class TimedEvents {
		int noOfEvents{ 0 };
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		struct Event {
			std::string eventName{};
			std::string timeUnits{};
			std::chrono::steady_clock::duration duration{};
		} events[MAX_EVENTS];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
	};

}
#endif // !SDDS_TIMEDEVENTS_H