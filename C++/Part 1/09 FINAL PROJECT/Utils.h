/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename:Utils.h
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

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds
{
	int getInt(void);
	int getIntInRange(int min, int max);
	bool yesOrno();
	bool strCaseCmp(const char* str1, const char* str2); //strcmp case insensitive
	void strToUpper(char* str); //change the string to upper case
}
#endif
