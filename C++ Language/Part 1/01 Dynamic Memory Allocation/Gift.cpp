#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Gift.h"

using namespace std;

namespace sdds
{
	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC+1);
		cin >> desc;
	}

	void gifting(double& price)
	{
		cout << "Enter gift price: ";
		cin >> price;
		while (price < 0 || price > MAX_PRICE)
		{
			cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			cout << "Enter gift price: ";
			cin >> price;
		}
	}

	void gifting(int& units)
	{
		cout << "Enter gift units: ";
		cin >> units;
		while (units < 1)
		{
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> units;
		}
	}

	void display(const Gift& theGift)
	{
		if (theGift.m_wrapLayers < 1)
		{
			cout << "Gift Details:" << endl;
			cout << " Description: " << theGift.m_description << endl;
			cout << "       Price: " << theGift.m_price << endl;
			cout << "       Units: " << theGift.m_units << endl;
			cout << "Unwrapped!" << endl;
		}
		else
		{
			cout << "Gift Details:" << endl;
			cout << " Description: " << theGift.m_description << endl;
			cout << "       Price: " << theGift.m_price << endl;
			cout << "       Units: " << theGift.m_units << endl;
			cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{
				cout << "Wrap #" << i + 1 << " -> " << theGift.m_wrap[i].m_pattern << endl;
			}
		}
		
	}

	bool wrap(Gift& theGift)
	{
		bool wrapping = true;

		if (theGift.m_wrapLayers > 0)
		{
			cout << "Gift is already wrapped!" << endl;
			wrapping = false;
		}
		else
		{
			cout << "Wrapping gifts..." << endl;
			cout << "Enter the number of wrapping layers for the Gift: ";
			cin >> theGift.m_wrapLayers;
			while (theGift.m_wrapLayers < 1)
			{
				cout << "Layers at minimum must be 1, try again." << endl;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> theGift.m_wrapLayers;
			}


			theGift.m_wrap = nullptr;
			theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];

			for (int i = 0; i < theGift.m_wrapLayers; ++i)
			{
				char tempPattern[100] = { 0 };
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> tempPattern;
				theGift.m_wrap[i].m_pattern = nullptr;
				theGift.m_wrap[i].m_pattern = new char[strlen(tempPattern) + 1];
				strcpy(theGift.m_wrap[i].m_pattern, tempPattern);
			}
		}

		return wrapping;
	}

	bool unwrap(Gift& theGift)
	{
		bool unwrapping = true;

		if (theGift.m_wrapLayers < 1)
		{
			cout << "Gift isn't wrapped! Cannot unwrap." << endl;
			unwrapping = false;
		}
		else
		{
			cout << "Gift being unwrapped." << endl;
			
			for (int i = 0; i < theGift.m_wrapLayers; ++i)
			{
				delete[] theGift.m_wrap[i].m_pattern;
				theGift.m_wrap[i].m_pattern = nullptr;
			}
		
			delete[] theGift.m_wrap;
			theGift.m_wrap = nullptr;
			theGift.m_wrapLayers = 0;
		}
		return unwrapping;
	}

	void gifting(Gift& theGift)
	{
		cout << "Preparing a gift..." << endl;
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);
		wrap(theGift);
	}


}