/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/04/2020
*/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

namespace sdds
{
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};


	class Basket
	{
		Fruit* m_fruits;
		int m_cnt;
		double m_price;
	public:
		Basket();
		Basket(Fruit* fruits, int cnt, double price);
		Basket(const Basket& copy);
		Basket& operator=(const Basket& copy);
		~Basket();
		void setPrice(double price);
		operator bool() const;
		Basket& operator+=(const Fruit adding);
		friend std::ostream& operator<<(std::ostream& os, const Basket& s);
	};

	
}


#endif

