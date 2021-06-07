/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename:Menu.h
Version 1.0
Author Yongtak Jun
Revision History
-----------------------------------------------------------
Date			Reason
2020/July/06	Preliminary release
2020/Aug/05		Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor
provided to complete this program.
-----------------------------------------------------------*/


#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include<iostream>
#include"Utils.h"

namespace sdds
{
	const int MAX_NO_OF_ITEMS = 10;

	class MenuItem
	{
		char* m_value;

		friend class Menu; //This lets Menu class access to Menu Item's private member.
		MenuItem();
		MenuItem(const char*value);
		MenuItem(const MenuItem& copy) = delete;
		MenuItem& operator=(const MenuItem& copy) = delete;
		~MenuItem();
		std::ostream& displayMenuItem(std::ostream& os = std::cout) const;
		//
		void setMenuItem(const char* value);
		void setMenuItemEmpty();
	};

	class Menu
	{
		char* m_title;
		MenuItem* m_item;
		int m_itemCnt;
		int m_indentation;
	public:
		Menu();
		Menu(const char * title, int indentation = 0);
		Menu(const Menu& copy);
		Menu& operator=(const Menu& copy);
		operator bool()const; //conversion operator which allows this class to be used in place of an bool type
		bool isEmpty() const;
		std::ostream& displayMenu(std::ostream& os = std::cout) const;
		Menu& operator=(const char* title);
		void add(const char* value);  //adding MenuItem
		Menu& operator<<(const char* value); //adding MenuItem using 'add' method
		int run() const;  //getting selection number
		operator int() const; //conversion operator which allows this class to be used in place of an int type
		~Menu();
		//
		void setMenu(const char* title, const int indentation = 0);
		void setMenuItemS(const MenuItem* item, const int itemCnt);
		void setMenuEmpty();
		void clearMenuItems(); //clearing all the elements of menuitems
	};

}


#endif
