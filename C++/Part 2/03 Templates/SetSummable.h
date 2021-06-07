/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/07/2021
*/


#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H


#include "Set.h"

namespace sdds
{
	template <size_t N, class T>
	class SetSummable : public Set<N, T>
	{
	public:
		T accumulate(const std::string& filter) const
		{
			T accumulatedObject(filter);

			for (size_t i = 0; i < this->size(); i++)
			{
				if (this->get(i).isCompatibleWith(accumulatedObject))
				{
					accumulatedObject += this->get(i);
				}
			}
			return accumulatedObject;
		}
	};
}
#endif // !SDDS_SETSUMMABLE_H
