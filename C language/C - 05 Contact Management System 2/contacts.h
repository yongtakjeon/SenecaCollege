// ----------------------------------------------------------------------------
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

//--------------------------------
// Structure Types
//--------------------------------

// Structure type Name declaration
struct Name
{
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};


// Structure type Address declaration
struct Address
{
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};


// Structure type Numbers declaration
struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};


// Structure type Contact declaration
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};


//--------------------------------
// Function Prototypes
//--------------------------------

// getName:
void getName(struct Name* name);

// getAddress:
void getAddress(struct Address* address);

// getNumbers:
void getNumbers(struct Numbers* numbers);

// getContact:
void getContact(struct Contact* contact);


// ----------------------------------------------------------------------------
// closing of the "safeguard" condition
#endif // !CONTACTS_H_
