/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/06/2021
*/

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds
{
	template <size_t N, class T>
	class Set
	{
		T collection[N];
		size_t noOfElements{ 0 };

	public:
		size_t size()const
		{
			return noOfElements;
		}

		const T& get(size_t idx) const
		{
			return collection[idx];
		}

		void operator+=(const T& item)
		{
			if (noOfElements < N)
			{
				collection[noOfElements++] = item;
			}
		}
	};

}
#endif // !SDDS_SET_H
