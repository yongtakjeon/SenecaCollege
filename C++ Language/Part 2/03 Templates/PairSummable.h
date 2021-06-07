/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/06/2021
*/


#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include <iomanip>
#include <string>
#include "Pair.h"

using namespace std;

namespace sdds
{
	template <typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
		static V initial;
		static size_t minFieldWidth;
	public:
		PairSummable(){}
		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value)
		{
			if (key.size() > minFieldWidth)
			{
				minFieldWidth = key.size();
			}
		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const
		{
			return (this->key() == b.key()) ? true : false;
		}

		PairSummable<V, K>& operator+=(const PairSummable<V, K>& src)
			//Assume that the current object and the parameter have the same key.
		{
			*this = PairSummable<V, K>(this->key(), this->value() + src.value());
			return *this;
		}

		void display(std::ostream& os) const
		{
			os << left << setw(minFieldWidth);
			Pair<V, K>::display(os);
			os << right;
		}

	};

	template <typename V, typename K>
	size_t PairSummable<V, K>::minFieldWidth{ 0 }; //initialization with 0

	template <typename V, typename K>
	V PairSummable<V, K>::initial{}; //initialization with default value


	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& src)
	{
		if (this->value().length() == 0)
		{
			*this = PairSummable<std::string, std::string>(this->key(), src.value());
		}
		else
		{
			*this = PairSummable<std::string, std::string>(this->key(), this->value() + ", " + src.value());
		}

		return *this;
	}
}
#endif // !SDDS_PAIRSUMMABLE_H
