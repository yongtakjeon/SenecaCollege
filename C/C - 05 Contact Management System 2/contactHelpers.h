/*----------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks.
----------------------------------------------------------------------*/

#include "contacts.h"


//--------------------------------
// Function Prototypes
//--------------------------------


// Clear the standard input buffer
// clearKeyboard:
void clearKeyboard(void);


// pause:
void pause(void);


// getInt:
int getInt(void);


// getIntInRange:
int getIntInRange(int min, int max);


// yes:
int yes(void);


// menu:
int menu(void);


// contactManagerSystem:
void contactManagerSystem(void);


// Generic function to get a ten-digit phone number:
// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[]);


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader:
void displayContactHeader(void);


// displayContactFooter:
void displayContactFooter(int count);


// displayContact:
void displayContact(const struct Contact* contact);


// displayContacts:
void displayContacts(const struct Contact contacts[], int size);


// searchContacts:
void searchContacts(const struct Contact contacts[], int size);


// addContact:
void addContact(struct Contact contacts[], int size);


// updateContact:
void updateContact(struct Contact contacts[], int size);


// deleteContact:
void deleteContact(struct Contact contacts[], int size);


// sortContacts:
void sortContacts(struct Contact contacts[], int size);
