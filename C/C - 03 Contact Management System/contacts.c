#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"


// Get and store from standard input the values for Name
void getName(struct Name* name)
{
    char choice;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf(" %c", &choice);
    if (choice != 'n' && choice != 'N')
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %6[^\n]", name->middleInitial);
    }

    printf("Please enter the contact's last name: ");
    scanf(" %35[^\n]", name->lastName);
}


// Get and store from standard input the values for Address
void getAddress(struct Address* address)
{
    char choice;

    do
    {
        printf("Please enter the contact's street number: ");
        scanf(" %d", &address->streetNumber);
    } while (address->streetNumber <= 0);

    printf("Please enter the contact's street name: ");
    scanf(" %40[^\n]", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    scanf(" %c", &choice);
    if (choice != 'n' && choice != 'N')
    {
        do
        {
            printf("Please enter the contact's apartment number: ");
            scanf(" %d", &address->apartmentNumber);
        } while (address->apartmentNumber <= 0);
    }

    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]", address->postalCode);

    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]", address->city);
}


// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers)
{
    char choice;

    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf(" %c", &choice);
    if (choice != 'n' && choice != 'N')
    {
        printf("Please enter the contact's cell phone number: ");
        scanf(" %10[^\n]", numbers->cell);
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    scanf(" %c", &choice);
    if (choice != 'n' && choice != 'N')
    {
        printf("Please enter the contact's home phone number: ");
        scanf(" %10[^\n]", numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &choice);
    if (choice != 'n' && choice != 'N')
    {
        printf("Please enter the contact's business phone number: ");
        scanf(" %10[^\n]", numbers->business);
    }
    printf("\n");
}