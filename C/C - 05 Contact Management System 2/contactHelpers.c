#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"



// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5



//--------------------------------
// Function Definitions
//--------------------------------

// clearKeyboard
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}


// getInt:
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


// getIntInRange:
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


// yes:
int yes(void)
{
    char yesno, newline;
    int value;

    scanf("%c%c", &yesno, &newline);

    while ((newline != '\n') || (yesno != 'Y' && yesno != 'y' && yesno != 'N' && yesno != 'n'))
    {
        if (newline != '\n')
        {
            clearKeyboard();
        }
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        scanf("%c%c", &yesno, &newline);
    }

    if (yesno == 'Y' || yesno == 'y')
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    return value;
}


// menu:
int menu(void)
{

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");

    return getIntInRange(0, 6);
}


// contactManagerSystem:
void contactManagerSystem(void)
{
    struct Contact members[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" }, { 11, "Trailer Park", 0, "A7A 2J2", "King City" }, { "4161112222", "4162223333", "4163334444" } },                                                       { { "Maggie", "R.", "Greene" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9051112222", "9052223333", "9053334444" } },
                                            { { "Morgan", "A.", "Jones" }, { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, { "7051112222", "7052223333", "7053334444" } },
                                            { { "Sasha", {'\0'}, "Williams" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9052223333", "9052223333", "9054445555" } } };
    int exit = 1;

    do
    {
        switch (menu())
        {
        case 1:
            puts("");
            displayContacts(members, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 2:
            puts("");
            addContact(members, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 3:
            puts("");
            updateContact(members, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 4:
            puts("");
            deleteContact(members, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 5:
            puts("");
            searchContacts(members, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 6:
            puts("");
            sortContacts(members, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 0:
            puts("");
            printf("Exit the program? (Y)es/(N)o: ");

            if (yes())
            {
                puts("");
                printf("Contact Management System: terminated\n");
                exit = 0;
            }
            puts("");

            break;
        }

    } while (exit);

}


// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;
    int i;

    while (needInput == 1)
    {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            needInput = 0;

            for (i = 0; i < strlen(phoneNum); i++)
            {
                if (!(phoneNum[i] >= '0' && phoneNum[i] <= '9'))
                {
                    needInput = 1;
                }
            }
        }

        if (needInput == 1)
        {
            printf("Enter a 10-digit phone number: ");
        }

    }
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i, flag = 1, result = -1;

    for (i = 0; i < size && flag; i++)
    {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
        {
            result = i;
            flag = 0;
        }
    }

    return result;
}


// displayContactHeader
void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}


// displayContact:
void displayContact(const struct Contact* contact)
{
    printf(" %s", contact->name.firstName);
    if (contact->name.middleInitial[0] != '\0')
    {
        printf(" %s", contact->name.middleInitial);
    }
    printf(" %s\n", contact->name.lastName);

    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0)
    {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
    int i, count = 0;

    displayContactHeader();

    for (i = 0; i < size; i++)
    {
        if (contacts[i].numbers.cell[0] > 0)
        {
            count++;
            displayContact(&contacts[i]);
        }
    }

    displayContactFooter(count);
}


// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
    char cellNumber[11] = { 0 };
    int index;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNumber);
    index = findContactIndex(contacts, size, cellNumber);

    if (index != -1)
    {
        puts("");
        displayContact(&contacts[index]);
        puts("");
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
        puts("");
    }

}


// addContact:
void addContact(struct Contact contacts[], int size)
{
    char cellNumber[11] = { 0 };
    int index = findContactIndex(contacts, size, cellNumber);
    

        if (index != -1)
        {
            getContact(&contacts[index]);
            printf("--- New contact added! ---\n");
        }
        else
        {
            printf("*** ERROR: The contact list is full! ***\n");
        }

        puts("");
}


// updateContact:
void updateContact(struct Contact contacts[], int size)
{
    char cellNumber[11] = { 0 };
    int index;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNumber);
    index = findContactIndex(contacts, size, cellNumber);

    if (index != -1)
    {
        puts("");
        printf("Contact found:");
        puts("");
        displayContact(&contacts[index]);
        puts("");

        printf("Do you want to update the name? (y or n): ");
        if (yes())
        {
            getName(&contacts[index].name);
        }
        printf("Do you want to update the address? (y or n): ");
        if (yes())
        {
            getAddress(&contacts[index].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes())
        {
            getNumbers(&contacts[index].numbers);
        }

        printf("--- Contact Updated! ---\n");
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    puts("");
}


// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
    char cellNumber[11] = { 0 };
    int index;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNumber);
    index = findContactIndex(contacts, size, cellNumber);

    if (index != -1)
    {
        puts("");
        printf("Contact found:");
        puts("");
        displayContact(&contacts[index]);
        puts("");

        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes())
        {
            contacts[index].numbers.cell[0] = '\0';
            printf("--- Contact deleted! ---\n");
        }
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    puts("");
}


// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
    /*
    Selection Sort:
    In the inside loop, it keeps comparing two numbers,
    and whenever there is a less number than m, 'm = j' will be executed so that 'm' will be the least number in the end.
    */
    int i, j, m;
    struct Contact temp;

    for (i = 0; i < size; i++)
    {
        m = i;
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(contacts[j].numbers.cell, contacts[m].numbers.cell) < 0)
            {
                m = j;
            }
        }
        if (m != i)
        {
            temp = contacts[i];
            contacts[i] = contacts[m];
            contacts[m] = temp;
        }
    }


    /*
    Bubble Sort:
    Each time the inside loop is done, the largest number will be placed in the last element.

    int i, j;
    struct Contact temp;

    for (i = size - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0)
            {
                temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }
    */
    printf("--- Contacts sorted! ---\n");
    puts("");
}