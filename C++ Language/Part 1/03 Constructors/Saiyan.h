/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jeon
Date: June/20/2020
*/


#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds
{
	class Saiyan
	{
		char* m_name;
		int m_dob;
		int m_power;
		bool m_super;
		int m_level;

	public:
		Saiyan();
		Saiyan(const char* name, int birth, int power);
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(Saiyan& other);
		~Saiyan();
	};


}

#endif