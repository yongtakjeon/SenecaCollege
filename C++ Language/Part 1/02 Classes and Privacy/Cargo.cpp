#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Cargo.h"

namespace sdds
{
	void Cargo::initialize(const char* desc, double weight)
	{
		setDesc(desc);
		setWeight(weight);
	}

	const char* Cargo::getDesc() const
	{
		return cargoDesc;
	}

	double Cargo::getWeight() const
	{
		return cargoWeight;
	}

	void Cargo::setDesc(const char* description)
	{
		if (description == nullptr || description[0] == '\0')
		{
			cargoDesc[0] = '\0';
		}
		else
		{
			strncpy(cargoDesc, description, MAX_DESC);
		}
	}

	void Cargo::setWeight(double weight)
	{
		if (weight < MIN_WEIGHT || weight > MAX_WEIGHT)
		{
			cargoWeight = MIN_WEIGHT;
		}
		else
		{
			cargoWeight = weight;
		}
	}
}