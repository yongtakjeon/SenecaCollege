/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/13/2020
*/

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

namespace sdds
{
	class MotorVehicle
	{
		char m_liNumber[32];
		char m_veAddress[64];
		int m_vehicleYear;
		//
		void setEmptystateM();
	public:
		MotorVehicle();
		MotorVehicle(const char*liNumber, int vehicleYear);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& in = std::cin);
	};

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& s);
	std::istream& operator>>(std::istream& is, MotorVehicle& s);
}


#endif

