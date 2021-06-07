/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Jan/23/2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H


namespace sdds
{
	class Event
	{
		char* eventDesc;
		size_t startSec;

	public:
		Event();
		Event(const Event& copy);
		~Event();
		Event& operator=(const Event& copy);
		void setEventEmpty();
		void display();
		void set(const char* desc = nullptr);
	};
}

#endif // !SDDS_EVENT_H


