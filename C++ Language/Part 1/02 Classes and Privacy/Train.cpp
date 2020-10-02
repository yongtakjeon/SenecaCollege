#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <iomanip>
#include "Train.h"
#include "Cargo.h"

using namespace std;

namespace sdds
{
	void Train::initialize(const char* name, int id)
	{
		if (name == nullptr || name[0] == '\0' || id <= 0)
		{
			trainName[0] = '\0';
			trainID = 0;
			cargo = nullptr;
		}
		else
		{
			strncpy(trainName, name, MAX_NAME);
			trainID = id;
			cargo = nullptr;
		}
	}

	bool Train::isValid() const
	{
		return !(trainName == nullptr || trainName[0] == '\0' || trainID <= 0);
	}

	void Train::loadCargo(Cargo car)
	{
		unloadCargo();
		cargo = new Cargo;
		cargo->initialize(car.getDesc(), car.getWeight());

	}

	void Train::unloadCargo()
	{
		delete cargo;
		cargo = nullptr;
	}


	void Train::display() const
	{
		if (isValid())
		{
			if (cargo)
			{
				cout << "***Train Summary***" << endl;
				cout << right << setw(10) << "Name: " << trainName << endl;
				cout << right << setw(10) << "ID: " << trainID << endl;
				cout << right << setw(10) << "Cargo: " << cargo->getDesc() << endl;
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << right << setw(10) << "Weight: " << cargo->getWeight() << endl;
				cout.unsetf(ios::fixed);
				cout.precision(6);
			}
			else
			{
				cout << "***Train Summary***" << endl;
				cout << right << setw(10) << "Name: " << trainName << endl;
				cout << right << setw(10) << "ID: " << trainID << endl;
				cout << "No cargo on this train." << endl;
			}
		}
		else
		{
			cout << "***Train Summary***\n" << "This is an invalid train.\n";
		}
	}

	bool Train::swapCargo(Train& other)
	{
		bool swap = false;
		Cargo* temp;

		if (isValid() && other.isValid() && cargo && other.cargo)
		{
			temp = cargo;
			cargo = other.cargo;
			other.cargo = temp;

			swap = true;
		}

		return swap;
	}

	bool Train::increaseCargo(double weight)
	{
		bool increase = false;
		
		if (isValid() && cargo)
		{
			double originalWeight = cargo->getWeight();
			double newWeight = cargo->getWeight() + weight;

			if (newWeight > MAX_WEIGHT) newWeight = MAX_WEIGHT;

			cargo->setWeight(newWeight);

			if (originalWeight != newWeight) increase = true;
		}

		return increase;
	}

	bool Train::decreaseCargo(double weight)
	{
		bool decrease = false;

		if (isValid() && cargo)
		{
			double originalWeight = cargo->getWeight();
			double newWeight = cargo->getWeight() - weight;

			if (newWeight < MIN_WEIGHT) newWeight = MIN_WEIGHT;

			cargo->setWeight(newWeight);

			if (originalWeight != newWeight) decrease = true;
		}

		return decrease;
	}
}