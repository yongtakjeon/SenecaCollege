#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds
{
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;


	struct Gift
	{
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;
		struct Wrapping* m_wrap;
		int m_wrapLayers;
	};

	struct Wrapping
	{
		char* m_pattern;
	};


	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);
	bool wrap(Gift& theGift);
	bool unwrap(Gift& theGift);
	void gifting(Gift& theGift);

}

#endif