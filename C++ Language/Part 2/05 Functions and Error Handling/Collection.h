/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/21/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds
{
	template<typename T>
	class Collection
	{
		string m_name;
		T* m_items;
		size_t m_cnt;
		void (*fp)(const Collection<T>&, const T&);
	public:
		Collection(const std::string& name)
		{
			m_name = name;
			m_items = nullptr;
			m_cnt = 0;
			fp = nullptr;
		}

		Collection(const Collection& copy) = delete;
		Collection& operator=(const Collection& copy) = delete;

		~Collection()
		{
			delete[] m_items;
		}

		const std::string& name() const
		{
			return m_name;
		}

		size_t size() const
		{
			return m_cnt;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			fp = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			//check if there is a same itme
			bool found = false;
			for (size_t i = 0; i < m_cnt && !found; i++)
			{
				if (m_items[i].title() == item.title())
				{
					found = true;
				}
			}

			if (!found)
			{
				T* temp_items = new T[m_cnt + 1];

				for (size_t i = 0; i < m_cnt; i++)
				{
					temp_items[i] = m_items[i];
				}
				temp_items[m_cnt] = item;

				delete[] m_items;
				m_items = nullptr;

				m_items = temp_items;
				temp_items = nullptr;

				m_cnt++;

				if (fp != nullptr)
				{
					fp(*this, item);
				}
			}
			
			return *this;
		}

		T& operator[](size_t idx) const
		{
			if (idx >= m_cnt)
				throw std::out_of_range("Bad index [" + to_string(idx) + "]. Collection has [" + to_string(m_cnt) + "] items.");

			return m_items[idx];
		}
		T* operator[](const std::string& title) const
		{
			T* returnAddress = nullptr;

			for (size_t i = 0; i < m_cnt; i++)
			{
				if (m_items[i].title() == title)
					returnAddress = &(m_items[i]);
			}

			return returnAddress;
		}
	};

	template <typename T>
	ostream& operator<<(ostream& os, const Collection<T>& res)
	{

		for (size_t i = 0; i < res.size(); i++)
		{
			os << res[i];
		}

		return os;
	}

}
#endif // !SDDS_COLLECTION_H
