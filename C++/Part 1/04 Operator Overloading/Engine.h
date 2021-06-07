/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: June/21/2020
*/

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{
	const int TYPE_MAX_SIZE = 30;

	class Engine
	{
		double m_size;
		char m_type[TYPE_MAX_SIZE + 1];

	public:
		Engine();
		Engine(const char* type, double size);
		double get() const;
		void display() const;
	};

}
#endif
