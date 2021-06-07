#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H
#include "Cargo.h"

namespace sdds
{
	const int MAX_NAME = 30;

	class Train
	{
		char trainName[MAX_NAME + 1];
		int trainID;
		Cargo *cargo;

	public:
		void initialize(const char* name, int id);
		bool isValid() const;
		void loadCargo(Cargo car);
		void unloadCargo();
		void display() const;
		bool swapCargo(Train& other);
		bool increaseCargo(double weight);
		bool decreaseCargo(double weight);
	};


}
#endif