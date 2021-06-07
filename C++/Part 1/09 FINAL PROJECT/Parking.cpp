/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
*/
/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename:Parking.cpp
Version 1.0
Author Yongtak Jun
Revision History
-----------------------------------------------------------
Date			Reason
2020/July/16	Preliminary release
2020/Aug/05		Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor
provided to complete this program.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include<cstring>
#include <iomanip>
#include"Parking.h"

using namespace std;

namespace sdds
{
	Parking::Parking()
	{
		m_fileName = nullptr;
		m_numOfSpots = -1;
		for (int i = 0; i < maxParkingSpots; i++)
		{
			m_parkingSpots[i] = nullptr;
		}
		m_numOfParked = -1;
	}
	Parking::Parking(const char* datafile, int noOfSpots)
		//noOfSpots is maximum number of Vehicle the Parking can accept.
	{
		if (datafile == nullptr || datafile[0] == '\0' ||
			noOfSpots < 10 || noOfSpots > maxParkingSpots)
		{
			setParkingEmpty();
		}
		else
		{
			m_fileName = nullptr; //clearing the garbage value;
			setFileName(datafile);
			m_numOfSpots = noOfSpots;
			for (int i = 0; i < maxParkingSpots; i++)
			{
				m_parkingSpots[i] = nullptr;
			}
			m_numOfParked = 0;
		}

		if (loadDataFile())
		{
			Menu tempMainMenu("Parking Menu, select an action:", 0);
			tempMainMenu.add("Park Vehicle");
			tempMainMenu.add("Return Vehicle");
			tempMainMenu.add("List Parked Vehicles");
			tempMainMenu.add("Close Parking (End of day)");
			tempMainMenu.add("Exit Program");
			mainMenu = tempMainMenu;

			Menu tempSubMenu("Select type of the vehicle:", 1);
			tempSubMenu.add("Car");
			tempSubMenu.add("Motorcycle");
			tempSubMenu.add("Cancel");
			subMenu1 = tempSubMenu;
		}
		else
		{
			cout << "Error in data file" << endl;
			setParkingEmpty();
		}
	}
	Parking::~Parking()
	{
		saveDataFile();

		delete[] m_fileName;
		for (int i = 0; i < m_numOfSpots; i++)
		{
			if (m_parkingSpots[i] != nullptr)
			{
				delete m_parkingSpots[i];
			}
		}
	}
	void Parking::setParkingEmpty()
	{
		m_fileName = nullptr;
		m_numOfSpots = -1;
		for (int i = 0; i < maxParkingSpots; i++)
		{
			m_parkingSpots[i] = nullptr;
		}
		m_numOfParked = -1;
	}
	Parking::operator bool() const
	{
		return (m_fileName != nullptr);
	}
	bool Parking::loadDataFile()
	{
		bool loading = true;

		if (*this)
		{
			ifstream fin(m_fileName);

			if (!fin)
			{
				fin.clear();
			}
			else
			{
				char vehicleType[2];

				while (m_numOfParked < m_numOfSpots && loading && !fin.eof())
				{
					fin.get(vehicleType,2); //The delimiter is remaining.
					fin.ignore(); //discarding the delimiter

					if (vehicleType[0] == 'M')
					{
						Vehicle* motorcycle = new Motorcycle;
						motorcycle->setCsv(true);
						motorcycle->read(fin);

						if (!fin)
						{
							loading = false;
							delete motorcycle;
							fin.clear();
						}
						else
						{
							m_parkingSpots[motorcycle->getParkingSpot() - 1] = motorcycle;
							m_numOfParked++;
						}
					}
					else if (vehicleType[0] == 'C')
					{
						Vehicle* car = new Car;
						car->setCsv(true);
						car->read(fin);

						if (!fin)
						{
							loading = false;
							delete car;
							fin.clear();
						}
						else
						{
							m_parkingSpots[car->getParkingSpot() - 1] = car;
							m_numOfParked++;
						}
					}
				}
			}

			fin.close();
		}
		
		return loading;
	}
	void Parking::setFileName(const char* fileName)
	{
		if (fileName == nullptr || fileName[0] == '\0')
		{
			setParkingEmpty();
		}
		else
		{
			if (m_fileName)
			{
				delete[] m_fileName;
			}

			m_fileName = nullptr;
			m_fileName = new char[strlen(fileName) + 1];
			strcpy(m_fileName, fileName);
		}
	}
	void Parking::saveDataFile()
	{
		ofstream fout(m_fileName);

		if (!fout)
		{
			fout.clear();
		}
		else
		{
			for (int i = 0; i < m_numOfSpots; i++)
			{
				if (m_parkingSpots[i] != nullptr)
				{
					m_parkingSpots[i]->setCsv(true);
					m_parkingSpots[i]->write(fout);
				}
			}
		}

		fout.close();
	}
	bool Parking::isEmpty()
	{
		return !(*this);
	}
	void Parking::parkingStatus()
	{
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: " << left << setw(4) << m_numOfSpots - m_numOfParked << " *****" << endl;
	}
	void Parking::parkVehicle()
	{
		if (m_numOfSpots - m_numOfParked < 1)
		{
			cout << "Parking is full" << endl;
		}
		else
		{
			int selection = subMenu1.run();

			if (selection == 1)
			{
				Vehicle* car = new Car;
				car->read();

				bool notFound = true;
				
				for (int i = 0; i < m_numOfSpots && notFound; i++)
				{
					if (m_parkingSpots[i] == nullptr)
					{
						notFound = false;
						int index = i;
						m_parkingSpots[index] = car;
						m_parkingSpots[index]->setParkingSpot(index + 1);
						cout << "\nParking Ticket" << endl;
						m_parkingSpots[index]->write();
					}
				}
				cout << endl;
				m_numOfParked++;
			}
			else if (selection == 2)
			{
				Vehicle* motorcycle = new Motorcycle;
				motorcycle->read();

				bool notFound = true;

				for (int i = 0; i < m_numOfSpots && notFound; i++)
				{
					if (m_parkingSpots[i] == nullptr)
					{
						notFound = false;
						int index = i;
						m_parkingSpots[index] = motorcycle;
						m_parkingSpots[index]->setParkingSpot(index + 1);
						cout << "\nParking Ticket" << endl;
						m_parkingSpots[index]->write();
					}
				}
				cout << endl;
				m_numOfParked++;
			}
			else if (selection ==3)
			{
				cout << "Parking cancelled" << endl;
				
			}
		}
	}
	void Parking::returnVehicle()
	{
		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		char plateNum[10];
		cin.get(plateNum, 10);
		while (strlen(plateNum) == 9 || strlen(plateNum) < 1)
		{
			cout << "Invalid Licence Plate, try again: ";
			cin.clear();
			cin.ignore(2000, '\n');
			cin.get(plateNum, 10);
		}
		cin.ignore(2000, '\n'); //clearing the input buffer

		bool notFound = true;
		for (int i = 0; i < m_numOfParked; i++)
		{
			if (*m_parkingSpots[i] == plateNum)
			{
				notFound = false;
				cout << "\nReturning: \n";
				m_parkingSpots[i]->setCsv(false);
				m_parkingSpots[i]->write();
				delete m_parkingSpots[i];
				m_parkingSpots[i] = nullptr;
				m_numOfParked--;
			}
		}
		if (notFound)
		{
			cout << "License plate " << plateNum << " Not found" << endl;
		}
		cout << endl;
	}
	void Parking::listParkedVehicle()
	{
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < m_numOfSpots; i++)
		{
			if (m_parkingSpots[i] != nullptr)
			{
				m_parkingSpots[i]->setCsv(false);
				m_parkingSpots[i]->write();
				cout << "-------------------------------" << endl;
			}
		}
	}
	bool Parking::closeParking()
	{
		bool close = true;
		if (m_numOfParked == 0)
		{
			cout << "Closing Parking" << endl;
		}
		else
		{
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			if (yesOrno())
			{
				cout << "Closing Parking" << endl;
				for (int i = 0; i < m_numOfSpots; i++)
				{
					if (m_parkingSpots[i] != nullptr)
					{
						cout << "\nTowing request" << endl;
						cout << "*********************" << endl;
						m_parkingSpots[i]->write();
						delete m_parkingSpots[i];
						m_parkingSpots[i] = nullptr;
					}
				}
			}
			else
			{
				cout << "Aborted!" << endl;
				close = false;
			}
		}
		return close;
	}
	bool Parking::exitParkingApp()
	{
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		
		return yesOrno();
	}
	int Parking::run()
	{
		if (*this)
		{
			bool closing = false;
			do
			{
				parkingStatus();
				switch (mainMenu.run())
				{
				case 1:
					parkVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					listParkedVehicle();
					break;
				case 4:
					closing = closeParking();
					break;
				case 5:
					closing = exitParkingApp();
					if (closing == true)
					{
						cout << "Exiting program!" << endl;
					}
					break;
				}
			} while (!closing);
		}

		int valid = *this ? 0 : 1;
		return valid;
	}
}