/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: Yongtak Jun
Date: July/29/2020
*/

template <typename T>
bool validate(T& min, T arr[], int cnt, bool validation[])
{
	bool result = true;
	for (int i = 0; i < cnt; i++)
	{
		if (arr[i] >= min)
		{
			validation[i] = true;
		}
		else
		{
			validation[i] = false;
			result = false;
		}
	}

	return result;
}