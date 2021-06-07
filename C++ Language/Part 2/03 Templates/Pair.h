/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/06/2021
*/


#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

namespace sdds
{
	template <class V, class K>
	class Pair
	{
		K m_key;
		V m_value;
	public:
		Pair() : m_key{}, m_value{}
		{

		}
		Pair(const K& key, const V& value) : m_key(key), m_value(value)
		{

		}
		const V& value() const
		{
			return m_value;
		}

		const K& key() const
		{
			return m_key;
		}

		virtual void display(std::ostream& os) const
		{
			os << m_key << " : " << m_value << std::endl;
		}
	};


	template <typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair)
	{
		pair.display(os);
		return os;
	}
}

#endif // !SDDS_PAIR_H
