/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename:Utils.cpp
Version 1.0
Author Yongtak Jun
Revision History
-----------------------------------------------------------
Date			Reason
2020/July/06	Preliminary release
2020/Aug/05 	Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor
provided to complete this program.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring> //for strlen
#include<cctype> //for tolower, toupper
#include"Utils.h"

using namespace std;

namespace sdds
{
    int getInt(void)
    {
        int num;

        cin >> num;
        while (!cin) //if there is an error about input using cin, operator "!" returns true.
        {
            cout << "Invalid Integer, try again: ";
            cin.clear(); //initializing the flag
            cin.ignore(1000, '\n'); //clearing input buffer including '\n'
            cin >> num;
        }
        cin.ignore(1000, '\n'); //clearing the input buffer to execute the pause() properly.

        return num;
    }

    int getIntInRange(int min, int max)
    {
        int integer;
        integer = getInt();

        while (integer < min || integer > max) //call the getInt() until it is in the valid range.
        {
            cout << "Invalid selection, try again: ";
            integer = getInt();
        }
        return integer;
    }
    bool yesOrno()
    {
        char selection[3];
        cin.get(selection, 3);  //get the characters up to 2 characters to make sure it contains only 1 character
        while (strlen(selection) != 1 || (selection[0] != 'Y' && selection[0] != 'y' && selection[0] != 'N' && selection[0] != 'n')) //and check if it contains only 1 character
        {
            cin.ignore(1000, '\n');

            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            cin.get(selection, 3);
        }

        cin.ignore(1000, '\n'); // clear the input buffer before exit the function.

        bool yesno = (selection[0] == 'Y' || selection[0] == 'y') ? true : false;

        return yesno;
    }
    bool strCaseCmp(const char* str1, const char* str2)
    {
        bool identical;
        if (strlen(str1) != strlen(str2))
        {
            identical = false;
        }
        else
        {
            identical = true;
            for (int i = 0, length = strlen(str1); i < length; i++)
            {
                if (tolower(str1[i]) != tolower(str2[i]))
                {
                    identical = false;
                }
            }
        }
        return identical;
    }
    void strToUpper(char* str)
    {
        for (int i = 0, length = strlen(str); i < length; i++)
        {
            str[i] = toupper(str[i]);
        }

    }
}