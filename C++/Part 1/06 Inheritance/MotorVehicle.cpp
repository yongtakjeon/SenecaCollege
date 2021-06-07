/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/13/2020
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include<iomanip>
#include"MotorVehicle.h"

using namespace std;

namespace sdds
{
	MotorVehicle::MotorVehicle()
	{
		m_liNumber[0] = '\0';
		m_veAddress[0] = '\0';
		m_vehicleYear = -1;
	}
	MotorVehicle::MotorVehicle(const char* liNumber, int vehicleYear)
	{
		if (liNumber == nullptr || liNumber[0] == '\0' || vehicleYear < 0)
		{
			setEmptystateM();
		}
		else
		{
			strcpy(m_liNumber, liNumber);
			m_vehicleYear = vehicleYear;
			strcpy(m_veAddress, "Factory");
		}
	}
	void MotorVehicle::setEmptystateM()
	{
		m_liNumber[0] = '\0';
		m_veAddress[0] = '\0';
		m_vehicleYear = -1;
	}
	void MotorVehicle::moveTo(const char* address)
	{
		if (address == nullptr || address[0] == '\0')
		{
			
		}
		else
		{
			if (strcmp(m_veAddress, address))
			{
				cout << "|" << right << setw(10) << m_liNumber << "| |" << right << setw(20) << m_veAddress << " --->--- " << left << setw(20) << address << "|" << endl;
				strcpy(m_veAddress, address);
			}
		}
	}
	ostream& MotorVehicle::write(ostream& os) const
	{
		os << "| " << m_vehicleYear << " | " << m_liNumber << " | " << m_veAddress;
		return os;
	}
	istream& MotorVehicle::read(istream& in)
	{
		cout << "Built year: ";
		in >> m_vehicleYear;
		cout << "License plate: ";
		in >> m_liNumber;
		cout << "Current location: ";
		in >> m_veAddress;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& s)
	{
		s.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, MotorVehicle& s)
	{
		s.read(is);
		return is;
	}

}