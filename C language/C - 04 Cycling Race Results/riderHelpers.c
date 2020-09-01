#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "riderHelpers.h"

#define MAXRIDERS 5000



void clearKeyboard(void)
{
	while (getchar() != '\n');
}


int getInt(void)
{
	int value;
	char newline;

	scanf("%d%c", &value, &newline);
	while (newline != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &value, &newline);
	}

	return value;
}


int getIntInRange(int min, int max)
{
	int integer;
	integer = getInt();

	while (integer < min || integer > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		integer = getInt();
	}
	return integer;
}


int menu(void)
{
	printf("What would you like to do?\n");
	printf("0 - Exit\n");
	printf("1 - Print top 3 riders in a category\n");
	printf("2 - Print all riders in a category\n");
	printf("3 - Print last 3 riders in a category\n");
	printf("4 - Print winners in all categories\n");
	printf(": ");


	return getIntInRange(0, 4);
}


void loadRidersData(struct RiderInfo riders[])
{
	int i;
	FILE* fp = NULL;


	fp = fopen("data.txt", "r");
	if (fp != NULL)
	{
		for (i = 0; i < MAXRIDERS && !readFileRecord(fp, &riders[i]); i++)
		{
			;
		}

		fclose(fp);
		fp = NULL;
	}
	else
	{
		printf("Failed to load the data.\n");
	}

}


char getCategory(void)
{
	char category, newline;

	scanf("%c%c", &category, &newline);

	while ((newline != '\n') || (category != 'S' && category != 's' && category != 'M' && category != 'm' && category != 'L' && category != 'l'))
	{
		if (newline != '\n')
		{
			clearKeyboard();
		}
		printf("Enter a correct category (S, M, L): ");
		scanf("%c%c", &category, &newline);
	}

	puts("");

	return toupper(category);
}


void displayAgeGroup(int age)
{
	if (age >= 16 && age <= 20)
	{
		printf("%7s", "Junior");
	}
	else if (age >= 21 && age <= 34)
	{
		printf("%7s", "Adult");
	}
	else if (age >= 35)
	{
		printf("%7s", "Senior");
	}
}


void displayRecordTime(double startTime, double finishTime)
{
	double recordTime = finishTime - startTime;
	int recordHours, recordMins;

	recordHours = (int)recordTime;
	recordMins = ((int)((recordTime + 0.005) * 60.0)) % 60;

	printf("%2d:%02d", recordHours, recordMins);
}


void top3Riders(struct RiderInfo riders[])
{
	char category;
	int i, m, j;
	struct RiderInfo temp;
	int display = 0, numberOfDisplay = 3;

	printf("Which category (S, M, L): ");
	category = getCategory();


	for (i = 0; riders[i].name[0] != '\0'; i++)
	{
		if (category == riders[i].raceLength)
		{
			m = i;
			for (j = i + 1; riders[j].name[0] != '\0'; j++)
			{
				if (riders[j].finishTime - riders[j].startTime < riders[m].finishTime - riders[m].startTime)
				{
					m = j;
				}
			}
			if (m != i)
			{
				temp = riders[i];
				riders[i] = riders[m];
				riders[m] = temp;
			}
		}
	}

	printf("Rider                    Age Group Time\n");
	printf("---------------------------------------\n");


	for (i = 0; riders[i].name[0] != '\0' && display < numberOfDisplay; i++)
	{
		if (category == riders[i].raceLength && !riders[i].withdrawn)
		{
			printf("%-27s", riders[i].name);
			displayAgeGroup(riders[i].age);
			displayRecordTime(riders[i].startTime, riders[i].finishTime); 
			puts("");
			display++;
		}
	}

	puts("");
}


void allRiders(struct RiderInfo riders[])
{
	char category;
	int i, j, m;
	struct RiderInfo temp;
	
	printf("Which category (S, M, L): ");
	category = getCategory();


	for (i = 0; riders[i].name[0] != '\0'; i++)
	{
		if (category == riders[i].raceLength)
		{
			m = i;
			for (j = i + 1; riders[j].name[0] != '\0'; j++)
			{
				if (riders[j].finishTime - riders[j].startTime < riders[m].finishTime - riders[m].startTime)
				{
					m = j;
				}
			}
			if (m != i)
			{
				temp = riders[i];
				riders[i] = riders[m];
				riders[m] = temp;
			}
		}
	}


	printf("Rider                    Age Group Time Withdrew\n");
	printf("------------------------------------------------\n");

	for (i = 0; riders[i].name[0] != '\0'; i++)
	{
		if (category == riders[i].raceLength && !riders[i].withdrawn)
		{
			printf("%-27s", riders[i].name);
			displayAgeGroup(riders[i].age);
			displayRecordTime(riders[i].startTime, riders[i].finishTime);
			printf("%9s\n", "No");

		}
	}
	
	for (i = 0; riders[i].name[0] != '\0'; i++)
	{
		if (category == riders[i].raceLength && riders[i].withdrawn)
		{
			printf("%-27s", riders[i].name);
			displayAgeGroup(riders[i].age);
			printf("%5s %8s\n", "N/A", "Yes");

		}
	}

	puts("");
}


void last3Riders(struct RiderInfo riders[])
{
	char category;
	int i, m, j;
	struct RiderInfo temp;
	int display = 0, numberOfDisplay = 3;
	int displayIndex[3] = { -1, -1, -1 };

	printf("Which category (S, M, L): ");
	category = getCategory();


	for (i = 0; riders[i].name[0] != '\0'; i++)
	{
		if (category == riders[i].raceLength)
		{
			m = i;
			for (j = i + 1; riders[j].name[0] != '\0'; j++)
			{
				if (riders[j].finishTime - riders[j].startTime > riders[m].finishTime - riders[m].startTime)
				{
					m = j;
				}
			}
			if (m != i)
			{
				temp = riders[i];
				riders[i] = riders[m];
				riders[m] = temp;
			}
		}
	}

	printf("Rider                    Age Group Time\n");
	printf("---------------------------------------\n");


	for (i = 0; riders[i].name[0] != '\0' && display < numberOfDisplay; i++)
	{
		if (category == riders[i].raceLength && !riders[i].withdrawn)
		{
			displayIndex[display] = i;
			display++;
		}
	}

	for (i = numberOfDisplay - 1; i >= 0; i--)
	{
		if (displayIndex[i] != -1)
		{
			printf("%-27s", riders[displayIndex[i]].name);
			displayAgeGroup(riders[displayIndex[i]].age);
			displayRecordTime(riders[displayIndex[i]].startTime, riders[displayIndex[i]].finishTime);
			puts("");

		}
	}

	puts("");
}


void winners(struct RiderInfo riders[])
{
	int i, m, j;
	struct RiderInfo temp;
	int exit = 1;


	for (i = 0; riders[i].name[0] != '\0'; i++)
	{
			m = i;
			for (j = i + 1; riders[j].name[0] != '\0'; j++)
			{
				if (riders[j].finishTime - riders[j].startTime < riders[m].finishTime - riders[m].startTime)
				{
					m = j;
				}
			}
			if (m != i)
			{
				temp = riders[i];
				riders[i] = riders[m];
				riders[m] = temp;
			}
	}


	printf("Rider                    Age Group Category Time\n");
	printf("------------------------------------------------\n");


	for (i = 0; riders[i].name[0] != '\0' && exit; i++)
	{
		if ('S' == riders[i].raceLength && !riders[i].withdrawn)
		{
			printf("%-27s", riders[i].name);
			displayAgeGroup(riders[i].age);
			printf("%9s", "50 km");
			displayRecordTime(riders[i].startTime, riders[i].finishTime);
			puts("");
			exit = 0;
		}
	}
	if (exit == 1)
	{
		printf("%-33s %9s\n","Not Awarded", "50 km");
	}

	for (i = 0, exit = 1; riders[i].name[0] != '\0' && exit; i++)
	{
		if ('M' == riders[i].raceLength && !riders[i].withdrawn)
		{
			printf("%-27s", riders[i].name);
			displayAgeGroup(riders[i].age);
			printf("%9s", "75 km");
			displayRecordTime(riders[i].startTime, riders[i].finishTime);
			puts("");
			exit = 0;
		}
	}
	if (exit == 1)
	{
		printf("%-33s %9s\n", "Not Awarded", "75 km");
	}

	for (i = 0, exit = 1; riders[i].name[0] != '\0' && exit; i++)
	{
		if ('L' == riders[i].raceLength && !riders[i].withdrawn)
		{
			printf("%-27s", riders[i].name);
			displayAgeGroup(riders[i].age);
			printf("%9s", "100 km");
			displayRecordTime(riders[i].startTime, riders[i].finishTime);
			puts("");
			exit = 0;
		}
	}
	if (exit == 1)
	{
		printf("%-33s %9s\n", "Not Awarded", "100 km");
	}

	puts("");
}



void riderManagerSystem(void)
{
	struct RiderInfo riders[MAXRIDERS] = { "" };
	int exit = 1;

	printf("******************** Cycling Race Results ********************\n");


	loadRidersData(riders);
	


	do
	{
		switch (menu())
		{
		case 1:
			puts("");
			top3Riders(riders);
			break;
		case 2:
			puts("");
			allRiders(riders);
			break;
		case 3:
			puts("");
			last3Riders(riders);
			break;
		case 4:
			puts("");
			winners(riders);
			break;
		case 0:
			puts("");
			printf("Keep on Riding!\n");
			exit = 0;

			break;

		}

	} while (exit);

}