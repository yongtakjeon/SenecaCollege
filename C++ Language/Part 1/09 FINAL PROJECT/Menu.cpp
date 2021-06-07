/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename:Menu.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip> //for setw
#include <cstring> //for strlen, strcpy
#include "Menu.h"

using namespace std;

namespace sdds
{
	//MenuItem Class
	MenuItem::MenuItem()
	{
		m_value = nullptr;
	}
	MenuItem::MenuItem(const char* value)
	{
		m_value = nullptr; //removing the garbage value to prevent from error when setMenuItem() is executed.
		setMenuItem(value);
	}
	std::ostream& MenuItem::displayMenuItem(std::ostream& os) const
	{
		if (m_value != nullptr && m_value[0] != '\0')
		{
			os << m_value << endl;
		}
		return os;
	}
	MenuItem::~MenuItem()
	{
		delete[] m_value;
	}
	void MenuItem::setMenuItem(const char* value)
	{
		if (value == nullptr || value[0] == '\0')
		{
			setMenuItemEmpty();
		}
		else
		{
			if (m_value) //if m_value is not nullptr
			{
				delete[] m_value;
			}

			m_value = nullptr;
			m_value = new char[strlen(value)+1];
			strcpy(m_value, value); //deep copy
		}
	}
	void MenuItem::setMenuItemEmpty()
	{
		if (m_value)
		{
			delete[] m_value;
		}
		m_value = nullptr;
	}



	//Menu Class
	Menu::Menu()
	{
		m_title = nullptr;
		m_item = nullptr;
		m_itemCnt = -1;
		m_indentation = -1;
	}
	Menu::Menu(const char* title, int indentation)
	{
		m_title = nullptr; //removing the garbage value to prevent from error when setMenu() is executed.
		setMenu(title, indentation);
		m_item = nullptr;
		m_itemCnt = 0;
	}
	void Menu::setMenu(const char* title, int indentation)
	{
		if (title == nullptr || title[0] == '\0')
		{
			setMenuEmpty();
		}
		else
		{
			if (m_title) //if m_title is not nullptr
			{
				delete[] m_title;
			}

			m_title = nullptr;
			m_title = new char[strlen(title)+1];

			strcpy(m_title, title);
			m_indentation = indentation;
		}
	}
	void Menu::setMenuItemS(const MenuItem* item, const int itemCnt)
	{
		clearMenuItems();

		if (item != nullptr)
		{
			m_item = new MenuItem[itemCnt];
			for (int i = 0; i < itemCnt; i++)
			{
				m_item[i].m_value = nullptr;
				m_item[i].setMenuItem(item[i].m_value);
			}
			m_itemCnt = itemCnt;
		}
		
	}

	Menu::Menu(const Menu& copy)
	{
		if (copy.isEmpty())
		{
			setMenuEmpty();
		}
		else
		{
			m_title = nullptr; //removing the garbage value to prevent from error when setMenu() is executed.
			setMenu(copy.m_title, copy.m_indentation);

			m_item = nullptr; //removing the garbage value to prevent from error when setMenuItems() is executed.
			setMenuItemS(copy.m_item, copy.m_itemCnt);
		}
	}
	Menu& Menu::operator=(const Menu& copy)
	{
		if (this != &copy)
		{
			if (copy.isEmpty())
			{
				setMenuEmpty();
			}
			else
			{
				setMenu(copy.m_title, copy.m_indentation);
				setMenuItemS(copy.m_item, copy.m_itemCnt);
			}
		}
		return *this;
	}
	Menu::operator bool()const //conversion operator which allows this class to be used in place of an bool type
	{
		return (m_title != nullptr && m_title[0] != '\0' &&  m_indentation != -1);
	}
	bool Menu::isEmpty() const
	{
		return (m_title == nullptr || m_title[0] == '\0' || m_indentation == -1);
	}
	std::ostream& Menu::displayMenu(std::ostream& os) const
	{
		if (isEmpty())
		{
			os << "Invalid Menu!" << endl;
		}
		else
		{
			if (m_indentation > 0)
			{
				os << right << setw(4 * m_indentation) << " " << m_title << endl;

				if (m_item != nullptr && m_itemCnt > 0)
				{
					for (int i = 0; i < m_itemCnt; i++)
					{
						os << right << setw(4 * m_indentation) << " " << i + 1 << "- " << m_item[i].m_value << endl;
					}
					os << right << setw(4 * m_indentation) << " " << "> ";
				}
				else
				{
					os << "No Items to display!" << endl;
				}
			}
			else
			{
				os << m_title << endl;

				if (m_item != nullptr && m_itemCnt > 0)
				{
					for (int i = 0; i < m_itemCnt; i++)
					{
						os << i + 1 << "- " << m_item[i].m_value << endl;
					}
					os << "> ";
				}
				else
				{
					os << "No Items to display!" << endl;
				}
			}
		}
		return os;
	}
	Menu& Menu::operator=(const char* title)
	{
		if (title == nullptr || title[0] == '\0')
		{
			setMenuEmpty();
		}
		else
		{
			if (m_title)
			{
				delete[] m_title;
			}

			m_title = nullptr;
			m_title = new char[strlen(title)+1];

			strcpy(m_title, title);
		}
		return *this;
	}
	void Menu::add(const char* value)  //addMenuItem function
	{
		if (!isEmpty())
		{
			if (value == nullptr || value[0] == '\0')
			{
				setMenuEmpty();
			}
			else
			{
				if (m_itemCnt < MAX_NO_OF_ITEMS)
				{
					MenuItem* temp = nullptr;
					temp = new MenuItem[m_itemCnt + 1];
					for (int i = 0; i < m_itemCnt; i++)
					{
						temp[i].setMenuItem(m_item[i].m_value);
					}
					temp[m_itemCnt++].setMenuItem(value);

					int tempCnt = m_itemCnt;
					
					clearMenuItems();
					m_item = temp;
					m_itemCnt = tempCnt;

					temp = nullptr;
				}
			}
		}
	}
	Menu& Menu::operator<<(const char* value)
	{
		add(value);
		return *this;
	}
	int Menu::run() const  //getting selection number
	{
		int selection = 0;
		displayMenu();
		if (m_itemCnt > 0)
		{
			selection = getIntInRange(1, m_itemCnt);
		}
		return selection;
	}
	Menu::operator int() const //conversion operator which allows this class to be used in place of an int type
	{
		return run();
	}
	Menu::~Menu()
	{
		delete[] m_title;

		if (m_item)
		{
			delete[] m_item;
		}
	}
	void Menu::setMenuEmpty()
	{
		if (m_title)
		{
			delete[] m_title;
		}
		m_title = nullptr;
		m_indentation = -1;

		clearMenuItems();
	}
	void Menu::clearMenuItems()
	{
		if (m_item)
		{
			delete[] m_item;
		}
		m_item = nullptr;
		m_itemCnt = -1;
	}
}