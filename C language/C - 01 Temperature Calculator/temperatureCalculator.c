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


/* OUTPUT EXAMPLE:
---=== IPC Temperature Calculator V2.0 ===---
Please enter the number of days, between 3 and 10, inclusive: 11

Invalid entry, please enter a number between 3 and 10, inclusive: 5

Day 1 - High: 6
Day 1 - Low: -2
Day 2 - High: 9
Day 2 - Low: -1
Day 3 - High: 7
Day 3 - Low: -3
Day 4 - High: 8
Day 4 - Low: -9
Day 5 - High: 5
Day 5 - Low: -8

Day Hi Low
1	6	-2
2	9	-1
3	7	-3
4	8	-9
5	5	-8

The highest temperature was 9, on day 2
The lowest temperature was -9, on day 4

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: 6

Invalid entry, please enter a number between 1 and 5, inclusive: 7

Invalid entry, please enter a number between 1 and 5, inclusive: 3

The average temperature up to day 3 is: 2.67

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: 0

Invalid entry, please enter a number between 1 and 5, inclusive: 0

Invalid entry, please enter a number between 1 and 5, inclusive: 1

The average temperature up to day 1 is: 2.00

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: 2

The average temperature up to day 2 is: 3.00

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: 5

The average temperature up to day 5 is: 1.20

Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: -8

Goodbye!

*/