//==============================================
// Name:           Yongtak Jun
// Email:          yjun4@myseneca.ca
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define SIZE 4


// Declare Struct Employee 
struct Employee
{
	int id;
	int age;
	double salary;
};


/* main program */
int main(void)
{
	int option = 0;

	// Declare a struct Employee array "emp" with SIZE elements
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { { 0 } };
	int i;
	int Enterid, flag;



	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1: // Display Employee Data

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0
			for (i = 0; i < SIZE; i++)
			{
				if (emp[i].id > 0)
				{
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			}
			printf("\n");
			break;

		case 2:	// Adding Employee

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly.
			flag = 1;

			for (i = 0; i < SIZE; i++)
			{
				if (emp[i].id == 0 && flag == 1)
				{
					printf("Enter Employee ID: ");
					scanf("%d", &emp[i].id);
					printf("Enter Employee Age: ");
					scanf("%d", &emp[i].age);
					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[i].salary);
					flag = 0;
				}
			}

			if (flag == 1)
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}

			printf("\n");

			break;
		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");
			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &Enterid);

				flag = 1;

				for (i = 0; i < SIZE; i++)
				{
					if (emp[i].id == Enterid)
					{
						flag = 0;
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);
					}
				}

				if (flag == 1)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
				}

			} while (flag);

			printf("\n");

			break;

		case 4:

			printf("Remove Employee\n");
			printf("===============\n");

			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &Enterid);

				flag = 1;

				for (i = 0; i < SIZE; i++)
				{
					if (emp[i].id == Enterid)
					{
						flag = 0;
						printf("Employee %d will be removed\n", emp[i].id);
						emp[i].id = 0;
					}
				}

				if (flag == 1)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
				}

			} while (flag);

			printf("\n");

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
			break;
		}

	} while (option != 0);

	return 0;
}


// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 222
Enter Employee Age: 22
Enter Employee Salary: 22222.22

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 333
Enter Employee Age: 33
Enter Employee Salary: 33333.33

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 444
Enter Employee Age: 44
Enter Employee Salary: 44444.44

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 555
Enter Employee Age: 55
Enter Employee Salary: 55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   33333.33
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 123
*** ERROR: Employee ID not found! ***
Enter Employee ID: 321
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
The current salary is 33333.33
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   99999.99
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 789
*** ERROR: Employee ID not found! ***
Enter Employee ID: 987
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
Employee 333 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 666
Enter Employee Age: 66
Enter Employee Salary: 66666.66

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
666       66   66666.66
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
