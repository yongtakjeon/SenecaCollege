/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Feb/14/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#include "ConfirmationSender.h"


namespace sdds
{
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool already = false;
		for (size_t i = 0; i < m_cnt && !already; i++)
		{
			if (allRes[i] == &res)
			{
				already = true;
			}
		}

		if (!already)
		{
			const Reservation** temp{ nullptr };
			temp = new const Reservation * [m_cnt + 1];

			for (size_t i = 0; i < m_cnt; i++)
			{
				temp[i] = allRes[i];
			}
			temp[m_cnt] = &res;

			
			delete[] allRes;

			allRes = temp;
			temp = nullptr;

			m_cnt++;
		}

		return *this;

	}


	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool found = false;
		for (size_t i = 0; i < m_cnt && !found; i++)
		{
			if (allRes[i] == &res)
			{
				found = true;

				// delete & resize
				const Reservation** temp{ nullptr };
				temp = new const Reservation * [m_cnt - 1];

				bool f = false;

				for (size_t j = 0; j < m_cnt - 1; j++)
				{
					if (j == i)
						f = true;


					if (f)
					{
						temp[j] = allRes[j + 1];
					}
					else
					{
						temp[j] = allRes[j];
					}
				}

				delete[] allRes;


				allRes = temp;
				temp = nullptr;

				m_cnt--;
			}
		}

		return *this;
	}
	ostream& operator<<(ostream& os, const ConfirmationSender& sender)
	{

		os << "--------------------------" << endl;
		os << "Confirmations to Send" <<endl;
		os << "--------------------------" << endl;

		if (sender.m_cnt)
		{
			for (size_t i = 0; i < sender.m_cnt; i++)
			{
				os << *(sender.allRes[i]);
			}
		}
		else
		{
			os << "There are no confirmations to send!" << endl;
		}

		os << "--------------------------" << endl;


		return os;
	}

	ConfirmationSender::ConfirmationSender()
	{

	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{
		*this = move(src);
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src)
		{
			m_cnt = src.m_cnt;

			delete[] allRes;
			allRes = nullptr;

			allRes = new const Reservation * [m_cnt];

			for (size_t i = 0; i < m_cnt; i++)
			{
				allRes[i] = src.allRes[i];
			}

		}

		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src)
		{
			delete[] allRes;

			m_cnt = src.m_cnt;
			allRes = src.allRes;

			src.allRes = nullptr;
			src.m_cnt = 0;
		}

		return *this;
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] allRes;
	}
}