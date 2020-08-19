#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN 3
#define MAX 10


int main()
{

	int days, i;
	int high[MAX] = { 0 };
	int low[MAX] = { 0 };
	int highest, highday, lowest, lowday;
	int meanDays;
	int total = 0;


	printf("---=== Temperature Calculator ===---\n");

	printf("Please enter the number of days, between %d and %d, inclusive: ", MIN, MAX);
	scanf("%d", &days);
	printf("\n");

	while (!(days >= MIN && days <= MAX))
	{
		printf("Invalid entry, please enter a number between %d and %d, inclusive: ", MIN, MAX);
		scanf("%d", &days);
		printf("\n");
	}

	for (i = 0; i < days; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);

		if (i == 0)
		{
			highest = high[i];
			highday = i + 1;
			lowest = low[i];
			lowday = i + 1;
		}

		else if (high[i] > highest)
		{
			highest = high[i];
			highday = i + 1;
		}

		else if (low[i] < lowest)
		{
			lowest = low[i];
			lowday = i + 1;
		}
	}


	printf("\n");

	printf("Day  Hi  Low\n");
	for (i = 0; i < days; i++)
	{
		printf("%d%5d%6d\n", i + 1, high[i], low[i]);
	}

	printf("\n");

	printf("The highest temperature was %d, on day %d\n", highest, highday);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowday);


	do
	{
		printf("\n");
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
		scanf("%d", &meanDays);


		while (meanDays == 0 || meanDays > days)
		{
			printf("\n");
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", days);
			scanf("%d", &meanDays);
		}

		if (meanDays >= 1 && meanDays <= days)
		{
			for (i = 0; i < meanDays; i++)
			{
				total = total + high[i] + low[i];
			}
			printf("\n");
			printf("The average temperature up to day %d is: %.2lf\n", meanDays, (double)total / (meanDays * 2));
			total = 0;
		}

	} while (!(meanDays <= -1));

	printf("\n");
	printf("Goodbye!\n");

	return 0;
}